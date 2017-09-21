#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"
#include "intmsg.h"

#include "persona1.h"

#define debug true

using namespace std;


Persona1::Persona1(const string &name) :
Atomic(name),
name(name),
infect(addInputPort("infect")),  
in0(addInputPort("in0")),
out0(addOutputPort("out0")),
nvecinos(1),
recuperado(false),
estadoActual(S),
gen(this->rd())
{

	 vecinos2port[0] = &out0;
}


Model &Persona1::initFunction()
{
	if (debug) cout << name << ":(b):init " << endl; 
	this->estadoActual = S;
	setearRelojDeVacunacion();
	if (debug) cout << name << ":(e):init " << endl; 
	return *this;
}

int Persona1::infectados(Estado vecinos[]){
	int result = 0;
	for(int i = 0; i < nvecinos;i++){
		if (vecinos[i]==I){
			result++;
		}
	}
	return result;
}

int Persona1::susceptibles(Estado vecinos[]){
	int result = 0;
	for(int i = 0; i < nvecinos;i++){
		if (vecinos[i]==S){
			result++;
		}
	}
	return result;
}

void Persona1::setearRelojDeInfeccion(){
	double temp = rho+susceptibles(this->vecinos)*gamma;
	std::exponential_distribution<> exponential(temp); 
	holdIn(AtomicState::active,toVTime(exponential(this->gen)));
	std::uniform_real_distribution<> unif(0,temp);
	int x = unif(this->gen);
	if (x < rho) { 
		this->recuperado = true;
	} else {
		this->recuperado = false;
	}
}

void Persona1::setearRelojDeVacunacion(){
	if (infectados(vecinos) == 0){
		passivate();
		return;
	}
	double pi = nu/nvecinos* infectados(this->vecinos);
	std::exponential_distribution<> exponential(pi);
	holdIn(AtomicState::active,toVTime(exponential(this->gen)));
}

Model &Persona1::externalFunction(const ExternalMessage &msg)
{
	if (debug) cout << name << ":(b):ext-trans" << endl;
	switch(stoi(msg.value()->asString())){
		case 1: //un vecino se infecto
		
		if (debug) cout << name << ":(b):sick-neigh" << endl;
		vecinos[damePuerto(msg.port().name())] = I; 
		switch(this->estadoActual){
			case S: 
			{
				setearRelojDeVacunacion();
			}
			break;
			case I:
			{
				setearRelojDeInfeccion();
			}
			break;
		
			default:
			holdIn(AtomicState::active,this->nextChange());
			break;
		}
		if (debug) cout << name << ":(e):sick-neigh" << endl;
		break;

		case 2:
			//me infectaron
		{
			if (debug) cout << name << ":(b):got-infected" << endl;
			this->estadoActual = PI;
				//TODO: check if this is how you set ta = 0
			VTime now(0,0,0,0);
			holdIn(AtomicState::active,now);
			if (debug) cout << name << ":(b):got-infected" << endl;

		}

		break;
		case 3:
			//un vecino se vacuno
		{
			if (debug) cout << name << ":(b):neigh-vaccine" << endl;
			vecinos[damePuerto(msg.port().name())] = V;
			switch(this->estadoActual){
				case I:
						//tengo que recalcular mi reloj de infeccion
				{
					setearRelojDeInfeccion();
				}
				break;
				default:
						//keep the clock running
				holdIn(AtomicState::active,this->nextChange());
				break;

			}	
		}
		if (debug) cout << name << ":(e):neigh-vaccine" << endl;	
		break;
		case 4:
			//un vecino se recupero
		{
			if (debug) cout << name << ":(b):recovered-neigh" << endl;
			vecinos[damePuerto(msg.port().name())] = R;
			switch(this->estadoActual){
				case S:
						//recalcular el reloj de vacunacion
				{
					setearRelojDeVacunacion();
				}
				break;
				default:
						//keep the clock running
				holdIn(AtomicState::active,this->nextChange());
				break;
			}

		}
		if (debug) cout << name << ":(e):recovered-neigh" << endl;

		break;

		default:
		cout << "error: se recibio un mensaje con numero no esperado" << endl;
		throw std::exception();
		;
			//error handling

	}
	if (debug) cout << name << "(e):ext-trans" << endl;
	return *this;
}


Model &Persona1::internalFunction(const InternalMessage &)
{
	if (debug) cout << name << "(b):int-trans" << endl;
	switch(this->estadoActual){
		case S:
		{
			this->estadoActual = V;
			passivate();
		}
		break;
		case PI:
		{
			this->estadoActual= I;
			setearRelojDeInfeccion();
		}
		break;
		case I:
		{
			if (this->recuperado){
				this->estadoActual = R;
				passivate();
			}else {
					passivate(); //esperamos a que el infectado nos despierte en tiempo cero
				}
			}
			break;
			default:
			cerr << "error: se ejecuto una delta interna en un estado invalido" << endl;
			throw std::exception();
			;
		}
		if (debug) cout << name << "(e):int-trans" << endl;
		return *this ;
	}


	Model &Persona1::outputFunction(const CollectMessage &msg)
	{
		if (debug) cout << name << "(b):lambda" << endl;
		switch(this->estadoActual){
			case S:
			{
				for(int i= 0; i < nvecinos; i++){
					if (vecinos[i]==S || vecinos[i] == I){
						sendOutput(msg.time(),*vecinos2port[i],me_vacune());
					}
				}
			}
			break;
			case PI: 
			{
				for(int i= 0; i < nvecinos; i++){
					if (vecinos[i]==S){
						sendOutput(msg.time(),*vecinos2port[i],me_infectaron());
					}
				}
			}
			break;
			case I:
			{
				if(this->recuperado){
					for(int i= 0; i < nvecinos; i++){
						if (vecinos[i]==S){
							sendOutput(msg.time(),*vecinos2port[i],me_recupere());
						}
					}
				}else {
					//tengo que infectar a uno de mis vecinos susceptibles
					if (susceptibles(vecinos)>0){
						//TODO: mover a otra funcion
						vector<int> susc_index(susceptibles(vecinos));
						int j = 0;
						for(int  i= 0; i < nvecinos; i++){
							if (vecinos[i]==S){
								susc_index[j] = i;
								j++;
							}
						}
						std::uniform_int_distribution<> dunif(0,susc_index.size());
						sendOutput(msg.time(),*vecinos2port[susc_index[dunif(this->gen)]],te_infecte());			
					}
				}

			}
			break;
			default:
			cerr<< "error: delta de un estado invalido" <<endl;
			throw std::exception();
			;
		}
		if (debug) cout << name << "(e):lambda" << endl;
		return *this ;
	}
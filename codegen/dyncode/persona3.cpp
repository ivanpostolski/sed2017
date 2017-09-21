#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"
#include "intmsg.h"

#include "persona3.h"

#define debug true

using namespace std;


Persona3::Persona3(const string &name) :
Atomic(name),
name(name),
infect(addInputPort("infect")),  
in0(addInputPort("in0")),
out0(addOutputPort("out0")), 
in1(addInputPort("in1")),
out1(addOutputPort("out1")), 
in2(addInputPort("in2")),
out2(addOutputPort("out2")),
nvecinos(3),
recuperado(false),
estadoActual(S),
gen(this->rd())
{

	 vecinos2port[0] = &out0;
	 vecinos2port[1] = &out1;
	 vecinos2port[2] = &out2;
}


Model &Persona3::initFunction()
{
	if (debug) cout << name << ":(b):init " << endl; 
	this->estadoActual = S;
	setearRelojDeVacunacion();
	if (debug) cout << name << ":(e):init " << endl; 
	return *this;
}

int Persona3::infectados(Estado vecinos[]){
	int result = 0;
	for(int i = 0; i < nvecinos;i++){
		if (vecinos[i]==I){
			result++;
		}
	}
	return result;
}

int Persona3::susceptibles(Estado vecinos[]){
	int result = 0;
	for(int i = 0; i < nvecinos;i++){
		if (vecinos[i]==S){
			result++;
		}
	}
	return result;
}

void Persona3::setearRelojDeInfeccion(){
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

void Persona3::setearRelojDeVacunacion(){
	if (infectados(vecinos) == 0){
		passivate();
		return;
	}
	double pi = nu/nvecinos* infectados(this->vecinos);
	std::exponential_distribution<> exponential(pi);
	holdIn(AtomicState::active,toVTime(exponential(this->gen)));
}

Model &Persona3::externalFunction(const ExternalMessage &msg)
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
			//TODO: agregar a la spec?
			switch(this->estadoActual){
				case S:
					{
						if (debug) cout << name << ":(b):got-infected" << endl;
						this->estadoActual = PI;
							//TODO: check if this is how you set ta = 0
						VTime now(0,0,0,0);
						holdIn(AtomicState::active,now);
						if (debug) cout << name << ":(b):got-infected" << endl;
					}
					break;
				default: 
				holdIn(AtomicState::active,this->nextChange());
				break;

			}
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


Model &Persona3::internalFunction(const InternalMessage &)
{
	if (debug) cout << name << "(b):int-trans" << endl;
	switch(this->estadoActual){
		case S:
		{
			if (debug) cout << name << "(b):got-vaccinated" << endl;
			this->estadoActual = V;
			passivate();
			if (debug) cout << name << "(e):got-vaccinated" << endl;
		}
		break;
		case PI:
		{
			if (debug) cout << name << "(b):pre-infected" << endl;
			this->estadoActual= I;
			setearRelojDeInfeccion();
			if (debug) cout << name << "(e):pre-infected" << endl;
		}
		break;
		case I:
		{
			if (this->recuperado){
				if (debug) cout << name << "(b):is-recovered" << endl;
				this->estadoActual = R;
				passivate();
				if (debug) cout << name << "(e):is-recovered" << endl;
			}else {
				if (debug) cout << name << "(b):infected-someone" << endl;
				//TODO: cambiar la spec, no funciona con colisiones esto
				// passivate(); //esperamos a que el infectado nos despierte en tiempo cero
				setearRelojDeInfeccion();
				if (debug) cout << name << "(e):infected-someone" << endl;
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


	Model &Persona3::outputFunction(const CollectMessage &msg)
	{
		if (debug) cout << name << "(b):lambda" << endl;
		switch(this->estadoActual){
			case S:
			{
				if (debug) cout << name << "(b):report-vaccination" << endl;
				for(int i= 0; i < nvecinos; i++){
					if (vecinos[i]==S || vecinos[i] == I){
						sendOutput(msg.time(),*vecinos2port[i],me_vacune());
					}
				}
				if (debug) cout << name << "(e):report-vaccination" << endl;

			}
			break;
			case PI: 
			{
				if (debug) cout << name << "(b):report-infection" << endl;
				for(int i= 0; i < nvecinos; i++){
					if (vecinos[i]==S){
						sendOutput(msg.time(),*vecinos2port[i],me_infectaron());
					}
				}
				if (debug) cout << name << "(e):report-infection" << endl;
			}
			break;
			case I:
			{
				if(this->recuperado){
					if (debug) cout << name << "(b):report-recovering" << endl;
					for(int i= 0; i < nvecinos; i++){
						if (vecinos[i]==S){
							sendOutput(msg.time(),*vecinos2port[i],me_recupere());
						}
					}
					if (debug) cout << name << "(e):report-recovering" << endl;
				}else {
					//tengo que infectar a uno de mis vecinos susceptibles
					if (debug) cout << name << "(b):report-infection" << endl;
					if (susceptibles(vecinos)>0){
						//TODO: mover a otra funcion
						if (debug) cout << name << ":has " <<susceptibles(vecinos) << " S" << endl;
						vector<int> susc_index(susceptibles(vecinos));
						int j = 0;
						for(int  i= 0; i < nvecinos; i++){
							if (vecinos[i]==S){
								susc_index[j] = i;
								j++;
							}
						}
						std::uniform_int_distribution<> dunif(0,susc_index.size()-1);
						int index = dunif(this->gen);
						Port* p =  vecinos2port[susc_index[index]];
						sendOutput(msg.time(),*vecinos2port[susc_index[index]],te_infecte());
						if (debug) cout << name << ":sent infect over port "<< p->name() << endl;			
					} else {
						if (debug) cout << name << "(b):report-infection-no-neighbors-to-infect" << endl;
					}
					if (debug) cout << name << "(e):report-infection" << endl;
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
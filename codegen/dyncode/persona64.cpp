#include <random>
#include <string>

#include "message.h"
#include "parsimu.h"
#include "real.h"
#include "tuple_value.h"
#include "intmsg.h"

#include "persona64.h"

#define debug true

using namespace std;


Persona64::Persona64(const string &name) :
Atomic(name),
name(name),
infect(addInputPort("infect")),  
in0(addInputPort("in0")),
out0(addOutputPort("out0")), 
in1(addInputPort("in1")),
out1(addOutputPort("out1")), 
in2(addInputPort("in2")),
out2(addOutputPort("out2")), 
in3(addInputPort("in3")),
out3(addOutputPort("out3")), 
in4(addInputPort("in4")),
out4(addOutputPort("out4")), 
in5(addInputPort("in5")),
out5(addOutputPort("out5")), 
in6(addInputPort("in6")),
out6(addOutputPort("out6")), 
in7(addInputPort("in7")),
out7(addOutputPort("out7")), 
in8(addInputPort("in8")),
out8(addOutputPort("out8")), 
in9(addInputPort("in9")),
out9(addOutputPort("out9")), 
in10(addInputPort("in10")),
out10(addOutputPort("out10")), 
in11(addInputPort("in11")),
out11(addOutputPort("out11")), 
in12(addInputPort("in12")),
out12(addOutputPort("out12")), 
in13(addInputPort("in13")),
out13(addOutputPort("out13")), 
in14(addInputPort("in14")),
out14(addOutputPort("out14")), 
in15(addInputPort("in15")),
out15(addOutputPort("out15")), 
in16(addInputPort("in16")),
out16(addOutputPort("out16")), 
in17(addInputPort("in17")),
out17(addOutputPort("out17")), 
in18(addInputPort("in18")),
out18(addOutputPort("out18")), 
in19(addInputPort("in19")),
out19(addOutputPort("out19")), 
in20(addInputPort("in20")),
out20(addOutputPort("out20")), 
in21(addInputPort("in21")),
out21(addOutputPort("out21")), 
in22(addInputPort("in22")),
out22(addOutputPort("out22")), 
in23(addInputPort("in23")),
out23(addOutputPort("out23")), 
in24(addInputPort("in24")),
out24(addOutputPort("out24")), 
in25(addInputPort("in25")),
out25(addOutputPort("out25")), 
in26(addInputPort("in26")),
out26(addOutputPort("out26")), 
in27(addInputPort("in27")),
out27(addOutputPort("out27")), 
in28(addInputPort("in28")),
out28(addOutputPort("out28")), 
in29(addInputPort("in29")),
out29(addOutputPort("out29")), 
in30(addInputPort("in30")),
out30(addOutputPort("out30")), 
in31(addInputPort("in31")),
out31(addOutputPort("out31")), 
in32(addInputPort("in32")),
out32(addOutputPort("out32")), 
in33(addInputPort("in33")),
out33(addOutputPort("out33")), 
in34(addInputPort("in34")),
out34(addOutputPort("out34")), 
in35(addInputPort("in35")),
out35(addOutputPort("out35")), 
in36(addInputPort("in36")),
out36(addOutputPort("out36")), 
in37(addInputPort("in37")),
out37(addOutputPort("out37")), 
in38(addInputPort("in38")),
out38(addOutputPort("out38")), 
in39(addInputPort("in39")),
out39(addOutputPort("out39")), 
in40(addInputPort("in40")),
out40(addOutputPort("out40")), 
in41(addInputPort("in41")),
out41(addOutputPort("out41")), 
in42(addInputPort("in42")),
out42(addOutputPort("out42")), 
in43(addInputPort("in43")),
out43(addOutputPort("out43")), 
in44(addInputPort("in44")),
out44(addOutputPort("out44")), 
in45(addInputPort("in45")),
out45(addOutputPort("out45")), 
in46(addInputPort("in46")),
out46(addOutputPort("out46")), 
in47(addInputPort("in47")),
out47(addOutputPort("out47")), 
in48(addInputPort("in48")),
out48(addOutputPort("out48")), 
in49(addInputPort("in49")),
out49(addOutputPort("out49")), 
in50(addInputPort("in50")),
out50(addOutputPort("out50")), 
in51(addInputPort("in51")),
out51(addOutputPort("out51")), 
in52(addInputPort("in52")),
out52(addOutputPort("out52")), 
in53(addInputPort("in53")),
out53(addOutputPort("out53")), 
in54(addInputPort("in54")),
out54(addOutputPort("out54")), 
in55(addInputPort("in55")),
out55(addOutputPort("out55")), 
in56(addInputPort("in56")),
out56(addOutputPort("out56")), 
in57(addInputPort("in57")),
out57(addOutputPort("out57")), 
in58(addInputPort("in58")),
out58(addOutputPort("out58")), 
in59(addInputPort("in59")),
out59(addOutputPort("out59")), 
in60(addInputPort("in60")),
out60(addOutputPort("out60")), 
in61(addInputPort("in61")),
out61(addOutputPort("out61")), 
in62(addInputPort("in62")),
out62(addOutputPort("out62")), 
in63(addInputPort("in63")),
out63(addOutputPort("out63")),
nvecinos(64),
recuperado(false),
estadoActual(S),
gen(this->rd())
{

	 vecinos2port[0] = &out0;
	 vecinos2port[1] = &out1;
	 vecinos2port[2] = &out2;
	 vecinos2port[3] = &out3;
	 vecinos2port[4] = &out4;
	 vecinos2port[5] = &out5;
	 vecinos2port[6] = &out6;
	 vecinos2port[7] = &out7;
	 vecinos2port[8] = &out8;
	 vecinos2port[9] = &out9;
	 vecinos2port[10] = &out10;
	 vecinos2port[11] = &out11;
	 vecinos2port[12] = &out12;
	 vecinos2port[13] = &out13;
	 vecinos2port[14] = &out14;
	 vecinos2port[15] = &out15;
	 vecinos2port[16] = &out16;
	 vecinos2port[17] = &out17;
	 vecinos2port[18] = &out18;
	 vecinos2port[19] = &out19;
	 vecinos2port[20] = &out20;
	 vecinos2port[21] = &out21;
	 vecinos2port[22] = &out22;
	 vecinos2port[23] = &out23;
	 vecinos2port[24] = &out24;
	 vecinos2port[25] = &out25;
	 vecinos2port[26] = &out26;
	 vecinos2port[27] = &out27;
	 vecinos2port[28] = &out28;
	 vecinos2port[29] = &out29;
	 vecinos2port[30] = &out30;
	 vecinos2port[31] = &out31;
	 vecinos2port[32] = &out32;
	 vecinos2port[33] = &out33;
	 vecinos2port[34] = &out34;
	 vecinos2port[35] = &out35;
	 vecinos2port[36] = &out36;
	 vecinos2port[37] = &out37;
	 vecinos2port[38] = &out38;
	 vecinos2port[39] = &out39;
	 vecinos2port[40] = &out40;
	 vecinos2port[41] = &out41;
	 vecinos2port[42] = &out42;
	 vecinos2port[43] = &out43;
	 vecinos2port[44] = &out44;
	 vecinos2port[45] = &out45;
	 vecinos2port[46] = &out46;
	 vecinos2port[47] = &out47;
	 vecinos2port[48] = &out48;
	 vecinos2port[49] = &out49;
	 vecinos2port[50] = &out50;
	 vecinos2port[51] = &out51;
	 vecinos2port[52] = &out52;
	 vecinos2port[53] = &out53;
	 vecinos2port[54] = &out54;
	 vecinos2port[55] = &out55;
	 vecinos2port[56] = &out56;
	 vecinos2port[57] = &out57;
	 vecinos2port[58] = &out58;
	 vecinos2port[59] = &out59;
	 vecinos2port[60] = &out60;
	 vecinos2port[61] = &out61;
	 vecinos2port[62] = &out62;
	 vecinos2port[63] = &out63;
}


Model &Persona64::initFunction()
{
	if (debug) cout << name << ":(b):init " << endl; 
	this->estadoActual = S;
	setearRelojDeVacunacion();
	if (debug) cout << name << ":(e):init " << endl; 
	return *this;
}

int Persona64::infectados(Estado vecinos[]){
	int result = 0;
	for(int i = 0; i < nvecinos;i++){
		if (vecinos[i]==I){
			result++;
		}
	}
	return result;
}

int Persona64::susceptibles(Estado vecinos[]){
	int result = 0;
	for(int i = 0; i < nvecinos;i++){
		if (vecinos[i]==S){
			result++;
		}
	}
	return result;
}

void Persona64::setearRelojDeInfeccion(){
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

void Persona64::setearRelojDeVacunacion(){
	if (infectados(vecinos) == 0){
		passivate();
		return;
	}
	double pi = nu/nvecinos* infectados(this->vecinos);
	std::exponential_distribution<> exponential(pi);
	holdIn(AtomicState::active,toVTime(exponential(this->gen)));
}

Model &Persona64::externalFunction(const ExternalMessage &msg)
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
			switch(this->estadoActual){
				case S:
					{
						if (debug) cout << name << ":(b):got-infected" << endl;
						this->estadoActual = PI;
						VTime now(0,0,0,0);
						holdIn(AtomicState::active,now);
						if (debug) cout << name << ":(e):got-infected" << endl;
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


Model &Persona64::internalFunction(const InternalMessage &)
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


	Model &Persona64::outputFunction(const CollectMessage &msg)
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
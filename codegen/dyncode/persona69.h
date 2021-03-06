#ifndef _PERSONA_69
#define _PERSONA_69

#include <random>

#include "atomic.h"
#include "VTime.h"
#include "helpers.h"


class Persona69 : public Atomic {
  public:
    
    Persona69(const string &name = "persona69" );
    virtual string className() const {  return "persona69" ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    std::string name;
    const Port &infect;
     
    const Port &in0;
    Port &out0; 
    const Port &in1;
    Port &out1; 
    const Port &in2;
    Port &out2; 
    const Port &in3;
    Port &out3; 
    const Port &in4;
    Port &out4; 
    const Port &in5;
    Port &out5; 
    const Port &in6;
    Port &out6; 
    const Port &in7;
    Port &out7; 
    const Port &in8;
    Port &out8; 
    const Port &in9;
    Port &out9; 
    const Port &in10;
    Port &out10; 
    const Port &in11;
    Port &out11; 
    const Port &in12;
    Port &out12; 
    const Port &in13;
    Port &out13; 
    const Port &in14;
    Port &out14; 
    const Port &in15;
    Port &out15; 
    const Port &in16;
    Port &out16; 
    const Port &in17;
    Port &out17; 
    const Port &in18;
    Port &out18; 
    const Port &in19;
    Port &out19; 
    const Port &in20;
    Port &out20; 
    const Port &in21;
    Port &out21; 
    const Port &in22;
    Port &out22; 
    const Port &in23;
    Port &out23; 
    const Port &in24;
    Port &out24; 
    const Port &in25;
    Port &out25; 
    const Port &in26;
    Port &out26; 
    const Port &in27;
    Port &out27; 
    const Port &in28;
    Port &out28; 
    const Port &in29;
    Port &out29; 
    const Port &in30;
    Port &out30; 
    const Port &in31;
    Port &out31; 
    const Port &in32;
    Port &out32; 
    const Port &in33;
    Port &out33; 
    const Port &in34;
    Port &out34; 
    const Port &in35;
    Port &out35; 
    const Port &in36;
    Port &out36; 
    const Port &in37;
    Port &out37; 
    const Port &in38;
    Port &out38; 
    const Port &in39;
    Port &out39; 
    const Port &in40;
    Port &out40; 
    const Port &in41;
    Port &out41; 
    const Port &in42;
    Port &out42; 
    const Port &in43;
    Port &out43; 
    const Port &in44;
    Port &out44; 
    const Port &in45;
    Port &out45; 
    const Port &in46;
    Port &out46; 
    const Port &in47;
    Port &out47; 
    const Port &in48;
    Port &out48; 
    const Port &in49;
    Port &out49; 
    const Port &in50;
    Port &out50; 
    const Port &in51;
    Port &out51; 
    const Port &in52;
    Port &out52; 
    const Port &in53;
    Port &out53; 
    const Port &in54;
    Port &out54; 
    const Port &in55;
    Port &out55; 
    const Port &in56;
    Port &out56; 
    const Port &in57;
    Port &out57; 
    const Port &in58;
    Port &out58; 
    const Port &in59;
    Port &out59; 
    const Port &in60;
    Port &out60; 
    const Port &in61;
    Port &out61; 
    const Port &in62;
    Port &out62; 
    const Port &in63;
    Port &out63; 
    const Port &in64;
    Port &out64; 
    const Port &in65;
    Port &out65; 
    const Port &in66;
    Port &out66; 
    const Port &in67;
    Port &out67; 
    const Port &in68;
    Port &out68;
    int nvecinos;
    
    bool recuperado = false;
    Estado estadoActual; 
    Estado vecinos[69] = {S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S};
    std::map<int, Port*> vecinos2port;
    //construct the generator
    std::random_device rd;
    std::default_random_engine gen;

    int infectados(Estado vecinos[]);
    int susceptibles(Estado vecinos[]);
    void setearRelojDeInfeccion();
    void setearRelojDeVacunacion();

};

#endif
#ifndef _PERSONA_21
#define _PERSONA_21

#include <random>

#include "atomic.h"
#include "VTime.h"
#include "helpers.h"


class Persona21 : public Atomic {
  public:
    
    Persona21(const string &name = "persona21" );
    virtual string className() const {  return "persona21" ;}
  
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
    int nvecinos;
    
    bool recuperado = false;
    Estado estadoActual; 
    Estado vecinos[21] = {S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S, S};
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
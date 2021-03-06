#ifndef _PERSONA_4
#define _PERSONA_4

#include <random>

#include "atomic.h"
#include "VTime.h"
#include "helpers.h"


class Persona4 : public Atomic {
  public:
    
    Persona4(const string &name = "persona4" );
    virtual string className() const {  return "persona4" ;}
  
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
    int nvecinos;
    
    bool recuperado = false;
    Estado estadoActual; 
    Estado vecinos[4] = {S, S, S, S};
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
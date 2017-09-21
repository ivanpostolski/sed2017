#ifndef _PERSONA_2
#define _PERSONA_2

#include <random>

#include "atomic.h"
#include "VTime.h"
#include "helpers.h"


class Persona2 : public Atomic {
  public:
    
    Persona2(const string &name = "persona2" );
    virtual string className() const {  return "persona2" ;}
  
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
    int nvecinos;
    
    bool recuperado = false;
    Estado estadoActual; 
    Estado vecinos[2] = {S, S};
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
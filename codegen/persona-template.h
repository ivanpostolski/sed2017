#ifndef _PERSONA_{{n}}
#define _PERSONA_{{n}}

#include <random>

#include "atomic.h"
#include "VTime.h"
#include "helpers.h"


class Persona{{n}} : public Atomic {
  public:
    
    Persona{{n}}(const string &name = "persona{{n}}" );
    virtual string className() const {  return "persona{{n}}" ;}
  
  protected:
    Model &initFunction();
    Model &externalFunction( const ExternalMessage & );
    Model &internalFunction( const InternalMessage & );
    Model &outputFunction( const CollectMessage & );

  private:
    std::string name;
    const Port &infect;
    {%for i in range(0,n)%} 
    const Port &in{{i}};
    Port &out{{i}};{%endfor%}
    int nvecinos;
    
    bool recuperado = false;
    Estado estadoActual; 
    Estado vecinos[{{n}}] = {{vecinos}};
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

#ifndef _HELPERS_
#define _HELPERS_


#define nu 1000
#define rho 1000
#define gamma 1000

#include "intmsg.h"
#include "VTime.h"

enum Estado {S,PI,I,R,V};

int damePuerto(std::string nombreDelPuerto);

VTime toVTime(float f);

BasicMsgValue* me_infectaron();
BasicMsgValue* te_infecte();
BasicMsgValue* me_vacune();
BasicMsgValue* me_recupere();


#endif
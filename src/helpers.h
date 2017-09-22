#ifndef _HELPERS_
#define _HELPERS_


#include "intmsg.h"
#include "VTime.h"
#include "constants.h"

enum Estado {S,PI,I,R,V};

int damePuerto(std::string nombreDelPuerto);

VTime toVTime(double f);

BasicMsgValue* me_infectaron();
BasicMsgValue* te_infecte();
BasicMsgValue* me_vacune();
BasicMsgValue* me_recupere();


#endif
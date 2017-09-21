#include <random>
#include <string>

#include "VTime.h"
#include "helpers.h"
#include "message.h"

using namespace std;

int damePuerto(std::string nombreDelPuerto){
	return stoi(nombreDelPuerto.substr(2));
}

VTime toVTime(float f){
	VTime res(0,0,0,f);
	return res;
}

//integer message attemp
// BasicMsgValue* infectaron = new IntMsg(1);
// BasicMsgValue* infecte = new IntMsg(2);
// BasicMsgValue* vacune = new IntMsg(3);
// BasicMsgValue* recupere = new IntMsg(4);

BasicMsgValue* me_infectaron(){
	return new RealMsgValue(1.0);
} 

BasicMsgValue* te_infecte(){
	return new RealMsgValue(2.0);
} 


BasicMsgValue* me_vacune(){
	return new RealMsgValue(3.0);
} 

BasicMsgValue* me_recupere(){
	return new RealMsgValue(4.0);
} 

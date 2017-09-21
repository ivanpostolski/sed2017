#include <random>
#include <string>

#include "VTime.h"
#include "helpers.h"
#include "message.h"
#include <time.h>
#include <iostream>

using namespace std;

int damePuerto(std::string nombreDelPuerto){
	return stoi(nombreDelPuerto.substr(2));
}



VTime toVTime(double f){
	if (debug) cout << "ta= " << round(f*100000) << " (sec)" << endl;
	
	time_t seconds(round(f*100000)); // you have to convert your input_seconds into time_t
	tm *p = gmtime(&seconds); // convert to broken down time
	VTime res(p->tm_yday,p->tm_hour,p->tm_min,p->tm_sec);
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

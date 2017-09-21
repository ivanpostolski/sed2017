#include <random>
#include <string>

#include "intmsg.h"

using namespace std;

IntMsg::IntMsg(int value) {
	this->value = value;
}

int IntMsg::valueSize() const {
	return sizeof(IntMsg);
}

string IntMsg::asString(){
	 return std::to_string(this->value);
}

BasicMsgValue* IntMsg::clone() const{
	return new IntMsg(*this);
}

IntMsg::IntMsg( const IntMsg& intmsg) {
	this->value = intmsg.value;
}
#ifndef _INTMSG
#define _INTMSG

#include <random>


#include "message.h"


class IntMsg : public BasicMsgValue {
public:
	IntMsg(int value);
	~IntMsg() {};
	int valueSize() const;
	std::string asString();
	IntMsg( const IntMsg&);
	int value;
	BasicMsgValue* clone() const;
};

#endif
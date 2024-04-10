#ifndef _CBIRD_H_
#define _CBIRD_H_
#include "CAnimal.h"

class CBird :public CAnimal {
	char** shape;
public:
	CBird(int, int);
	~CBird();
	char** getShape();
	int getWidth(){
		return 4;
	}
	int getType() {
		return 0;
	}
	void printBlankBird();
	virtual void Move(int);
	virtual void printAnimal();
};

#endif 


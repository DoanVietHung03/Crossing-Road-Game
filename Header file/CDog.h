#ifndef _CDOG_H_
#define _CDOG_H_
#include "CAnimal.h"

class CDog: public CAnimal {
	char** shape;
public:
	CDog(int,int);
	~CDog();
	char** getShape();
	int getWidth(){
		return 9;
	}
	int getType() {
		return 1;
	}
	virtual void Move(int);
	virtual void printAnimal();
	void printBlankDog();
};

#endif // !_DINOSAUR_H_


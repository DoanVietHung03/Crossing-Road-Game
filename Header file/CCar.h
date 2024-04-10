#ifndef _CCAR_H_
#define _CCAR_H_
#include "CVehicle.h"

class CCar :public CVehicle {
	char** shape;

public:
	CCar(int, int);
	~CCar();
	char** getShape();
	int getWidth() {
		return 13;
	}
	int getType() {
		return 2;
	}
	virtual void Move(int);
	virtual void printVehicle();
	void printBlankCar();
};

#endif

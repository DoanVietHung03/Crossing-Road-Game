#ifndef _CTRUCK_H_
#define _CTRUCK_H_
#include "CVehicle.h"

class CTruck :public CVehicle {
	char** shape;
public:
	CTruck(int, int);
	~CTruck();
	char** getShape();
	int getWidth() {
		return 18;
	}
	int getType() {
		return 3;
	}
	virtual void Move(int);
	virtual void printVehicle();
	void printBlankTruck();
};

#endif

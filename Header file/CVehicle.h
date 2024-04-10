#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_
#include "Board.h"

class CVehicle {
protected:
	int mX, mY;
	int direction;
	bool outMap;
public:
	CVehicle(int x, int y) {
		mX = x;
		mY = y;
		outMap = false;
	}
	virtual void Move(int) = 0;
	int getX() {
		return mX;
	}
	int getY() {
		return mY;
	}
	virtual int getType() = 0;
	void setDirection(int d) {
		direction = d;
	};
	int getDirection() {
		return direction;
	}
	virtual void printVehicle() = 0;
	bool getOutMapV() {
		return outMap;
	}
};

#endif
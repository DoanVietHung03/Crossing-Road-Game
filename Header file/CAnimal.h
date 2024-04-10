#ifndef _CANIMAL_H_
#define _CANIMAL_H_
#include "Board.h"

class CAnimal {
protected:
	int mX, mY;
	int direction;
	bool outMap;
public:
	CAnimal(int x, int y) { mX = x, mY = y; outMap = false; }
	virtual void Move(int) = 0;
	//virtual void Tell() = 0;
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
	virtual void printAnimal() = 0;
	bool getOutMapA() {
		return outMap;
	}
};

#endif 


#ifndef _CPEOPLE_H_
#define _CPEOPLE_H_
#include "CAnimal.h"
#include "CVehicle.h"

class CPeople {
	int mX, mY;
	char** shape;
	bool mState; 
public:
	/*~CPeople() {
		delete[] shape;
	}*/

	CPeople();
	void Up();
	void Left();
	void Right();
	void Down();
	void printPeople();
	int getX() {
		return mX;
	}
	int getY() {
		return mY;
	}
	void setX(int X) {
		mX = X;
	}
	void setY(int Y) {
		mY = Y;
	}
	bool isImpact(const vector<CVehicle*>&);
	bool isImpact(const vector<CAnimal*>&);
	bool isFinish();
	bool isDead();
	void kill();
	void revive();
};


#endif // !_CPEOPLE_H_

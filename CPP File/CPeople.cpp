#include "CPeople.h"

CPeople::CPeople() : mState(true) {
	mX = 113;
	mY = 36;
	shape = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		shape[i] = new char[5];
	}

	//Row1
	shape[0][0] = '0';
	shape[0][1] = ' ';
	shape[0][2] = ' ';
	shape[0][3] = ' ';
	shape[0][4] = '7';

	//Row2
	shape[1][0] = ' ';
	shape[1][1] = '\\';
	shape[1][2] = 'o';
	shape[1][3] = '/';
	shape[1][4] = ' ';

	//Row3
	shape[2][0] = ' ';
	shape[2][1] = ' ';
	shape[2][2] = '|';
	shape[2][3] = ' ';
	shape[2][4] = ' ';

	//Row4
	shape[3][0] = ' ';
	shape[3][1] = '/';
	shape[3][2] = ' ';
	shape[3][3] = '\\';
	shape[3][4] = ' ';
}


void CPeople::Up() {
	//sound();
	if (mY <= 1) return;
	else mY -= 5;
}

void CPeople::Down() {
	//sound();
	if (mY >= 36) return;
	else mY += 5;
}

void CPeople::Left() {
	//sound();
	if (mX <= 7) return;
	else mX -= 5;
}

void CPeople::Right() {
	//sound();
	if (mX >= 110) return;
	else mX += 5;
}


void CPeople::printPeople() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			GotoXY(this->mX+j, this->mY+i);
			cout << shape[i][j];
		}
		cout << endl;
	}
}


bool CPeople::isImpact(const vector<CAnimal*>& lA) {
	for (int i = 0; i < lA.size(); i++) {
		if (lA[i]->getType() == 0) {
			if(((lA[i]->getX() - mX <= 5 && lA[i]->getX() - mX >= 0) || (mX - lA[i]->getX() < 4 && mX - lA[i]->getX() >= 0)) && mY == lA[i]->getY()) {
				return true;
				mState = false;
			}
		}
		else {
			if (((lA[i]->getX() - mX <= 5 && lA[i]->getX() - mX >= 0) || (mX - lA[i]->getX() < 9 && mX - lA[i]->getX() >= 0)) && mY == lA[i]->getY()) {
				return true;
				mState = false;
			}
		}
	}
	return false;
}

bool CPeople::isImpact(const vector<CVehicle*>& lV) {
	for (int i = 0; i < lV.size(); i++) {
		if (lV[i]->getType() == 2) {
			if (((lV[i]->getX() - mX <= 5 && lV[i]->getX() - mX >= 0) || (mX - lV[i]->getX() < 13 && mX - lV[i]->getX() >= 0)) && mY == lV[i]->getY()) {
				return true;
			}
		}
		else {
			if (((lV[i]->getX() - mX <= 5 && lV[i]->getX() - mX >= 0) || (mX - lV[i]->getX() < 18 && mX - lV[i]->getX() >= 0)) && mY == lV[i]->getY()) {
				return true;
			}
		}
	}
	return false;
}

bool CPeople::isFinish() {
	if (mY == 1)
		return true;
	else
		return false;
}

bool CPeople::isDead() {
	return (mState == false);
}

void CPeople::kill() {
	mState = false;
}

void CPeople::revive() {
	mState = true;
}

#include "CCar.h"

CCar::CCar(int x, int y): CVehicle(x,y) {
	shape = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		shape[i] = new char[13];
	}

	//Row1
	shape[0][0] = ' ';
	shape[0][1] = ' ';
	shape[0][2] = ' ';
	shape[0][3] = ' ';
	shape[0][4] = ' ';
	shape[0][5] = '_';
	shape[0][6] = '_';
	shape[0][7] = '_';
	shape[0][8] = '_';
	shape[0][9] = '_';
	shape[0][10] = '_';
	shape[0][11] = ' ';
	shape[0][12] = ' ';

	//Row2
	shape[1][0] = ' ';
	shape[1][1] = '_';
	shape[1][2] = '_';
	shape[1][3] = '.';
	shape[1][4] = '*';
	shape[1][5] = '/';
	shape[1][6] = '_';
	shape[1][7] = '|';
	shape[1][8] = '|';
	shape[1][9] = '_';
	shape[1][10] = '|';
	shape[1][11] = '\\';
	shape[1][12] = ' ';

	//Row3
	shape[2][0] = '/';
	shape[2][1] = '_';
	shape[2][2] = ' ';
	shape[2][3] = '_';
	shape[2][4] = ' ';
	shape[2][5] = ' ';
	shape[2][6] = ' ';
	shape[2][7] = ' ';
	shape[2][8] = '_';
	shape[2][9] = ' ';
	shape[2][10] = ' ';
	shape[2][11] = ' ';
	shape[2][12] = ')';
	
	//Row4
	shape[3][0] = '\'';
	shape[3][1] = '-';
	shape[3][2] = '(';
	shape[3][3] = '_';
	shape[3][4] = ')';
	shape[3][5] = '-';
	shape[3][6] = '-';
	shape[3][7] = '(';
	shape[3][8] = '_';
	shape[3][9] = ')';
	shape[3][10] = '-';
	shape[3][11] = '*';
	shape[3][12] = ' ';
}



CCar::~CCar() {
	for (int i = 0; i < 4; i++)
		delete[] shape[i];
	delete[] shape;
}

char** CCar::getShape() {
	return shape;
}

void CCar::printBlankCar() {
	char** blank;
	blank = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		blank[i] = new char[13];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++)
			blank[i][j] = ' ';
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (mX + j == 3 && (mY + i == 11 || mY + i == 26)) {}
			if ((mX + j > 2) && (mX + j < 119)) {
				GotoXY(mX + j, mY + i);
				cout << blank[i][j];
			}
			else if ((mX + j == 2) || (mX + j == 119)) {
				GotoXY(mX + j, mY + i);
				SetColor(colorBlack);
				cout << (char)219;
				SetColor(colorBlue);
			}
			else {}
		}
		cout << endl;
	}
}

void CCar::Move(int huong){// huong = 0 : tu trai qua phai, huong = 1: tu phai qua trai
	if (huong == 0) {
		printBlankCar();
		mX += 4;
		if (mX >= 119)
			outMap = true;
	}
	if (huong == 1) {
		printBlankCar();
		mX -= 4;
		if (mX + 12 <= 2)
			outMap = true;
	}
}

void CCar::printVehicle() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (mX + j == 3 && (mY + i == 11 || mY + i == 26)) {}

			else if ((mX + j > 2) && (mX + j < 119)) {
				GotoXY(mX + j, mY + i);
				cout << shape[i][j];
			}
			else if ((mX + j == 2) || (mX + j == 119)) {
				GotoXY(mX + j, mY + i);
				SetColor(colorBlack);
				cout << (char)219;
				SetColor(colorBlue);
			}
			else {
				/*GotoXY(mX + j, mY + i);
				cout << ' ';*/
			}
		}
		cout << endl;
	}
}
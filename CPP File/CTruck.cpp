#include "CTruck.h"

CTruck::CTruck(int x, int y) : CVehicle(x, y) {
	shape = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		shape[i] = new char[18];
	}
	//Row1
	shape[0][0] = ' ';
	shape[0][1] = ' ';
	shape[0][2] = ' ';
	shape[0][3] = ' ';
	shape[0][4] = ' ';
	shape[0][5] = ' ';
	shape[0][6] = '_';
	shape[0][7] = '_';
	shape[0][8] = '_';
	shape[0][9] = '_';
	shape[0][10] = ' ';
	shape[0][11] = ' ';
	shape[0][12] = ' ';
	shape[0][13] = ' ';
	shape[0][14] = ' ';
	shape[0][15] = ' ';
	shape[0][16] = ' ';
	shape[0][17] = ' ';

	//Row2
	shape[1][0] = ' ';
	shape[1][1] = '_';
	shape[1][2] = '_';
	shape[1][3] = '_';
	shape[1][4] = '_';
	shape[1][5] = '/';
	shape[1][6] = '/';
	shape[1][7] = '_';
	shape[1][8] = ']';
	shape[1][9] = '|';
	shape[1][10] = '_';
	shape[1][11] = '_';
	shape[1][12] = '_';
	shape[1][13] = '_';
	shape[1][14] = '_';
	shape[1][15] = '_';
	shape[1][16] = '_';
	shape[1][17] = '_';

	//Row3
	shape[2][0] = '(';
	shape[2][1] = 'o';
	shape[2][2] = ' ';
	shape[2][3] = '_';
	shape[2][4] = ' ';
	shape[2][5] = '|';
	shape[2][6] = ' ';
	shape[2][7] = ' ';
	shape[2][8] = '-';
	shape[2][9] = '|';
	shape[2][10] = ' ';
	shape[2][11] = ' ';
	shape[2][12] = ' ';
	shape[2][13] = '_';
	shape[2][14] = ' ';
	shape[2][15] = ' ';
	shape[2][16] = 'o';
	shape[2][17] = '|';

	//Row4
	shape[3][0] = ' ';
	shape[3][1] = '`';
	shape[3][2] = '(';
	shape[3][3] = '_';
	shape[3][4] = ')';
	shape[3][5] = '-';
	shape[3][6] = '-';
	shape[3][7] = '-';
	shape[3][8] = '-';
	shape[3][9] = '-';
	shape[3][10] = '-';
	shape[3][11] = '-';
	shape[3][12] = '(';
	shape[3][13] = '_';
	shape[3][14] = ')';
	shape[3][15] = '-';
	shape[3][16] = '-';
	shape[3][17] = '\'';
}


CTruck::~CTruck() {
	for (int i = 0; i < 4; i++)
		delete[] shape[i];
	delete[] shape;
}


char** CTruck::getShape() {
	return shape;
}

void CTruck::printBlankTruck() {
	char** blank;
	blank = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		blank[i] = new char[18];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 18; j++)
			blank[i][j] = ' ';
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 18; j++) {
			if (mX + j == 3 && (mY + i == 21 || mY + i == 31)) {}

			else if ((mX + j > 2) && (mX + j < 119)) {
				GotoXY(mX + j, mY + i);
				cout << blank[i][j];
			}
			else if ((mX + j == 2) || (mX + j == 119)) {
				GotoXY(mX + j, mY + i);
				SetColor(colorBlack);
				cout << (char)219;
				SetColor(colorAqua);
			}
			else {
				/*GotoXY(mX + j, mY + i);
				cout << ' ';*/
			}
		}
		cout << endl;
	}
}

void CTruck::Move(int huong) {
	if (huong == 0) {
		printBlankTruck();
		mX += 5;
		if (mX >= 119)
			outMap = true;
	}
	else {
		printBlankTruck();
		mX -= 5;
		if (mX + 18 <= 2)
			outMap = true;
	}
}

void CTruck::printVehicle() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 18; j++) {
			if (mX + j == 3 && (mY + i == 31 || mY + i == 21)) {}

			else if ((mX + j > 2) && (mX + j < 119)) {
				GotoXY(mX + j, mY + i);
				cout << shape[i][j];
			}
			else if ((mX + j == 2) || (mX + j == 119)) {
				GotoXY(mX + j, mY + i);
				SetColor(colorBlack);
				cout << (char)219;
				SetColor(colorAqua);
			}
			else {
				/*GotoXY(mX + j, mY + i);
				cout << ' ';*/
			}
		}
		cout << endl;
	}
}
#include "CDog.h"



CDog::~CDog(){
	for (int i = 0; i < 4; i++)
		delete[] shape[i];
	delete[] shape;
}

CDog::CDog(int x, int y) : CAnimal(x,y){
	shape = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		shape[i] = new char[9];
	}

	//Row1
	shape[0][0] = ' ';
	shape[0][1] = ' ';
	shape[0][2] = ' ';
	shape[0][3] = ' ';
	shape[0][4] = ' ';
	shape[0][5] = '_';
	shape[0][6] = '_';
	shape[0][7] = ' ';
	shape[0][8] = ' ';

	//Row2
	shape[1][0] = '(';
	shape[1][1] = '_';
	shape[1][2] = '_';
	shape[1][3] = '_';
	shape[1][4] = '(';
	shape[1][5] = ')';
	shape[1][6] = '\'';
	shape[1][7] = '`';
	shape[1][8] = ';';

	//Row3
	shape[2][0] = '/';
	shape[2][1] = ',';
	shape[2][2] = ' ';
	shape[2][3] = ' ';
	shape[2][4] = ' ';
	shape[2][5] = ' ';
	shape[2][6] = '/';
	shape[2][7] = ' ';
	shape[2][8] = ' ';

	//Row4
	shape[3][0] = '\\';
	shape[3][1] = '\\';
	shape[3][2] = '"';
	shape[3][3] = '-';
	shape[3][4] = '-';
	shape[3][5] = '\\';
	shape[3][6] = '\\';
	shape[3][7] = ' ';
	shape[3][8] = ' ';
}


char** CDog::getShape() {
	return shape;
}

void CDog::printBlankDog() {
	char** blank;
	blank = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		blank[i] = new char[9];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 9; j++)
			blank[i][j] = ' ';
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 9; j++) {
			if ((mX + j > 2) && (mX + j < 118)) {
				GotoXY(mX + j, mY + i);
				cout << blank[i][j];
			}
			else if ((mX + j == 2) || (mX + j == 118)) {
				GotoXY(mX + j, mY + i);
				SetColor(colorBlack);
				cout << (char)219;
				SetColor(colorYellow);
			}
			else {
				/*GotoXY(mX + j, mY + i);
				cout << ' ';*/
			}
		}
		cout << endl;
	}
}

void CDog::Move(int huong) {
	if (huong == 0) {
		printBlankDog();
		mX += 3;
		if (mX >= 119)
			outMap = true;
	}
	else {
		printBlankDog();
		mX -= 3;
		if (mX +9 <= 2)
			outMap = true;
	}
}

void CDog::printAnimal() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 9; j++) {
			if ((mX + j > 2) && (mX + j < 118)) {
				GotoXY(mX + j, mY + i);
				cout << shape[i][j];
			}
			else if ((mX + j == 2) || (mX + j == 118)) {
				GotoXY(mX + j, mY + i);
				SetColor(colorBlack);
				cout << (char)219;
				SetColor(colorYellow);
			}
			else {
				/*GotoXY(mX + j, mY + i);
				cout << ' ';*/
			}
		}
		cout << endl;
	}
}


#include "CBird.h"


char** CBird::getShape() {
	return shape;
}

CBird::CBird(int x, int y): CAnimal(x,y) {
	shape = new char* [4];
	for (int i = 0; i < 4; i++)
		shape[i] = new char[4];

	//Row1
	shape[0][0] = ' ';
	shape[0][1] = '_';
	shape[0][2] = '_';
	shape[0][3] = ' ';
	
	//Row2
	shape[1][0] = '(';
	shape[1][1] = ' ';
	shape[1][2] = 'o';
	shape[1][3] = '>';

	//Row3
	shape[2][0] = '/';
	shape[2][1] = '/';
	shape[2][2] = '/';
	shape[2][3] = '\\';

	//Row4
	shape[3][0] = '\\';
	shape[3][1] = 'V';
	shape[3][2] = '_';
	shape[3][3] = '/';
}


CBird::~CBird() {
	for (int i = 0; i < 4; i++)
		delete[] shape[i];
	delete[] shape;
}

void CBird::printBlankBird() {
	char** blank;
	blank = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		blank[i] = new char[4];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			blank[i][j] = ' ';
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((mX + j > 2) && (mX + j < 118)) {
				GotoXY(mX + j, mY + i);
				cout << blank[i][j];
			}
			else if ((mX + j == 2) || (mX + j == 118)) {
				GotoXY(mX + j, mY + i);
				SetColor(colorBlack);
				cout << char(219);
				SetColor(colorPurple);
			}
			else {
				/*GotoXY(mX + j, mY + i);
				cout << ' ';*/
			}
		}
		cout << endl;
	}
}

void CBird::Move(int huong) {
	if (huong == 0) {
		printBlankBird();
		mX += 2;
		if (mX >= 119)
			outMap = true;
	}
	else {
		printBlankBird();
		mX -= 2;
		if (mX + 4 <= 2)
			outMap = true;
	}
}

void CBird::printAnimal() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((mX + j > 2) && (mX + j < 118)) {
				GotoXY(mX + j, mY + i);
				cout << shape[i][j];
			}
			else if ((mX + j == 2) || (mX + j == 118)) {
				GotoXY(mX + j, mY + i);
				SetColor(colorBlack);
				cout << (char)219;
				SetColor(colorPurple);
			}
			else {
				/*GotoXY(mX + j, mY + i);
				cout << ' ';*/
			}
		}
		cout << endl;
	}
}


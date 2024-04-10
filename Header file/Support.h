#ifndef  _SUPPORT_H_
#define _SUPPORT_H_
#include "Console.h"





class Ambulance {
	char** shape;
	int mX, mY;
	char game[5][39] = { {' ', '_', '_', '_','_','_','_',' ',' ',' ','_', '_', '_','_','_','_',' ',' ',' ','_','_',' ',' ',' ',' ','_','_',' ',' ',' ','_','_','_','_','_','_',' ',' ',' '}, {'/','\\',' ',' ','_','_','_','\\',' ','/','\\',' ',' ','_','_',' ','\\',' ','/','\\',' ','\"','-','.','/',' ',' ','\\',' ','/','\\',' ',' ','_','_','_','\\',' ',' '},{'\\',' ','\\',' ','\\','_','_',' ','\\','\\',' ','\\',' ',' ','_','_',' ','\\','\\',' ','\\',' ','\\','-','.','/','\\',' ','\\','\\',' ','\\',' ',' ','_','_','\\',' ',' '}, {' ','\\',' ','\\','_','_','_','_','_','\\','\\',' ','\\','_','\\',' ','\\','_','\\','\\',' ','\\','_','\\',' ','\\',' ','\\','_','\\','\\',' ', '\\','_','_','_','_','_','\\'}, {' ',' ','\\','/','_','_','_','_','_','/',' ','\\','/','_','/','\\','/','_','/',' ','\\','/','_','/',' ',' ','\\','/','_','/',' ','\\','/','_','_','_','_','_','/'} };
	
	char over[5][36] = { {' ','_','_','_','_','_','_',' ',' ',' ','_','_',' ',' ',' ','_','_',' ','_','_','_','_','_','_',' ',' ',' ', '_','_','_','_','_','_',' ',' ',' '},{'/','\\',' ',' ','_','_',' ','\\',' ','/','\\',' ','\\',' ','/',' ','/','/','\\',' ',' ','_','_','_','\\',' ','/','\\',' ',' ','=','=',' ','\\',' ',' '},{'\\',' ','\\',' ','\\','/','\\',' ','\\','\\',' ','\\',' ','\\','\'','/',' ','\\',' ','\\',' ',' ','_','_','\\',' ','\\',' ','\\',' ',' ','_','_','<',' '},{' ','\\',' ','\\','_','_','_','_','_','\\','\\',' ','\\','_','_','|',' ',' ','\\',' ','\\','_','_','_','_','_','\\','\\',' ','\\','_','\\',' ','\\','_','\\'},{' ',' ','\\','/','_','_','_','_','_','/',' ','\\','/','_','/',' ',' ',' ',' ','\\','/','_','_','_','_','_','/',' ','\\','/','_','/',' ','/','_','/'} };

public:
	Ambulance(int y) {

		mX = 3;
		mY = y - 1;
		shape = new char* [6];
		for (int i = 0; i < 6; i++)
			shape[i] = new char[26];

		shape[0][0] = ' ';
		shape[0][1] = '_';
		shape[0][2] = '_';
		shape[0][3] = '_';
		shape[0][4] = '_';
		shape[0][5] = '_';
		shape[0][6] = '_';
		shape[0][7] = '_';
		shape[0][8] = '_';
		shape[0][9] = '_';
		shape[0][10] = '_';
		shape[0][11] = '_';
		shape[0][12] = '_';
		shape[0][13] = '_';
		shape[0][14] = '_';
		shape[0][15] = '[';
		shape[0][16] = ' ';
		shape[0][17] = '\\';
		shape[0][18] = '_';
		shape[0][19] = ' ';
		shape[0][20] = ' ';
		shape[0][21] = ' ';
		shape[0][22] = ' ';
		shape[0][23] = ' ';
		shape[0][24] = ' ';
		shape[0][25] = ' ';

		shape[1][0] = '/';
		shape[1][1] = ' ';
		shape[1][2] = ' ';
		shape[1][3] = 220;
		shape[1][4] = 219;
		shape[1][5] = 220;
		shape[1][6] = ' ';
		shape[1][7] = ' ';
		shape[1][8] = ' ';
		shape[1][9] = ' ';
		shape[1][10] = ' ';
		shape[1][11] = ' ';
		shape[1][12] = '.';
		shape[1][13] = '-';
		shape[1][14] = '-';
		shape[1][15] = '.';
		shape[1][16] = '.';
		shape[1][17] = '-';
		shape[1][18] = '-';
		shape[1][19] = '\\';
		shape[1][20] = ' ';
		shape[1][21] = ' ';
		shape[1][22] = ' ';
		shape[1][23] = ' ';
		shape[1][24] = ' ';
		shape[1][25] = ' ';

		shape[2][0] = '|';
		shape[2][1] = ' ';
		shape[2][2] = ' ';
		shape[2][3] = ' ';
		shape[2][4] = 219;
		shape[2][5] = ' ';
		shape[2][6] = ' ';
		shape[2][7] = ' ';
		shape[2][8] = ' ';
		shape[2][9] = ' ';
		shape[2][10] = ' ';
		shape[2][11] = ' ';
		shape[2][12] = '[';
		shape[2][13] = '_';
		shape[2][14] = '_';
		shape[2][15] = ']';
		shape[2][16] = '[';
		shape[2][17] = '_';
		shape[2][18] = '_';
		shape[2][19] = '_';
		shape[2][20] = '\\';
		shape[2][21] = '_';
		shape[2][22] = '_';
		shape[2][23] = '_';
		shape[2][24] = ' ';
		shape[2][25] = ' ';

		shape[3][0] = '|';
		shape[3][1] = ' ';
		shape[3][2] = ' ';
		shape[3][3] = ' ';
		shape[3][4] = ' ';
		shape[3][5] = '_';
		shape[3][6] = '_';
		shape[3][7] = ' ';
		shape[3][8] = ' ';
		shape[3][9] = '|';
		shape[3][10] = ' ';
		shape[3][11] = ' ';
		shape[3][12] = ' ';
		shape[3][13] = ' ';
		shape[3][14] = '-';
		shape[3][15] = '|';
		shape[3][16] = '-';
		shape[3][17] = ' ';
		shape[3][18] = ' ';
		shape[3][19] = ' ';
		shape[3][20] = '_';
		shape[3][21] = '_';
		shape[3][22] = ' ';
		shape[3][23] = ' ';
		shape[3][24] = '\\';
		shape[3][25] = ' ';

		shape[4][0] = '|';
		shape[4][1] = ' ';
		shape[4][2] = ' ';
		shape[4][3] = ' ';
		shape[4][4] = '/';
		shape[4][5] = ' ';
		shape[4][6] = ' ';
		shape[4][7] = '\\';
		shape[4][8] = ' ';
		shape[4][9] = '|';
		shape[4][10] = ' ';
		shape[4][11] = ' ';
		shape[4][12] = ' ';
		shape[4][13] = ' ';
		shape[4][14] = ' ';
		shape[4][15] = '|';
		shape[4][16] = ' ';
		shape[4][17] = ' ';
		shape[4][18] = ' ';
		shape[4][19] = '/';
		shape[4][20] = ' ';
		shape[4][21] = ' ';
		shape[4][22] = '\\';
		shape[4][23] = ' ';
		shape[4][24] = '[';
		shape[4][25] = ')';

		shape[5][0] = '`';
		shape[5][1] = '\'';
		shape[5][2] = '-';
		shape[5][3] = '-';
		shape[5][4] = '\\';
		shape[5][5] = '_';
		shape[5][6] = '_';
		shape[5][7] = '/';
		shape[5][8] = '-';
		shape[5][9] = '-';
		shape[5][10] = '-';
		shape[5][11] = '-';
		shape[5][12] = '-';
		shape[5][13] = '-';
		shape[5][14] = '-';
		shape[5][15] = '-';
		shape[5][16] = '-';
		shape[5][17] = '-';
		shape[5][18] = '-';
		shape[5][19] = '\\';
		shape[5][20] = '_';
		shape[5][21] = '_';
		shape[5][22] = '/';
		shape[5][23] = '-';
		shape[5][24] = '-';
		shape[5][25] = '\'';
	}

	~Ambulance() {
		delete[]shape;
	}

	bool checkOutMap() {
		if (mX >= 118) {
			return true;
		}
		else
			return false;
	}

	void printGameOver(int x) {
		SetColor(colorRed);
		if (x >= 20 && x < 59) {
			for (int i = 0; i < 5; i++) {
				GotoXY(x, mY + i);
				cout << game[i][x - 20];
			}
		}
		else if (x >= 60 && x < 96) {
			for (int i = 0; i < 5; i++) {
				GotoXY(x, mY + i);
				cout << over[i][x - 60];
			}
		}
		else {
			SetColor(colorBlack);
			return;
		}
		SetColor(colorBlack);
	}

	void printBlankAmbulance() {
		char** blank;
		blank = new char* [6];
		for (int i = 0; i < 6; i++)
		{
			blank[i] = new char[26];
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 26; j++)
				blank[i][j] = ' ';
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 26; j++) {
				if ((mX + j > 2) && (mX + j < 118)) {
					GotoXY(mX + j, mY + i);
					cout << blank[i][j];
				}
				else if ((mX + j == 2) || (mX + j == 118)) {
					GotoXY(mX + j, mY + i);
					cout << char(219);
				}
				else {}
			}
			cout << endl;
		}
	}

	void printAmbulance() {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 26; j++) {
				if ((mX + j > 2) && (mX + j < 118)) {
					if ((i == 1 && (j == 3 || j == 4 || j == 5)) || (i == 2 && j == 4)) {
						GotoXY(mX + j, mY + i);
						SetColor(colorRed);
						cout << shape[i][j];
						SetColor(colorBlack);
					}
					else {
						if (i == 0 && j >= 19){
							cout << "-";
						}
						else if (i == 1 && j >= 20) {}
						else {
							GotoXY(mX + j, mY + i);
							SetColor(colorBlack);
							cout << shape[i][j];
						}
					}
				}
				else if ((mX + j == 2) || (mX + j == 118)) {
					GotoXY(mX + j, mY + i);
					SetColor(colorBlack);
					cout << (char)219;
					//SetColor(colorPurple);
				}
				else {
					/*GotoXY(mX + j, mY + i);
					cout << ' ';*/
				}
			}
		}
	}

	void move() {
		printBlankAmbulance();
		mX += 1;
	}
};


class Frame {
    int h, w;
    char** shape;
public:
	void createFrame(int height, int width) {
		h = height;
		w = width;
		shape = new char* [height];
		for (int i = 0; i < height; i++) {
			shape[i] = new char[width];
		}
		for (int i = 0; i < width; i++) {
			shape[0][i] = 220;
			shape[height - 1][i] = 223;
		}

		for (int i = 1; i < height - 1; i++) {
			shape[i][0] = shape[i][width - 1] = 219;
		}

		for (int i = 1; i < height - 1; ++i) {
			for (int j = 1; j < width - 1; ++j) {
				shape[i][j] = ' ';
			}
		}
	}

	void printFrame(int x, int y) {
		SetColor(colorBlack);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				GotoXY(x + j, y + i);
				cout << shape[i][j];
			}
		}
	}
};

#endif // ! _LEVEL_H_

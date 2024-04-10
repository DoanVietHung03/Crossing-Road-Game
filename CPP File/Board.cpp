#include "Board.h"

Board::Board() : width(116), height(39) {
	for (int i = 0; i <= width; i++) {
		map[0][i] = 220;
		map[height + 1][i] = 223;
	}
	map[0][width + 1] = map[height + 1][width + 1] = ' ';
	for (int i = 1; i <= height; ++i) {
		map[i][0] = map[i][width] = 219;
		map[i][width + 1] = ' ';
		for (int j = 1; j < width; ++j) {
			if (i % 5 == 0)
				map[i][j] = '-';
			else
				map[i][j] = ' ';
		}
	}
}

void Board::printBoard() {
	system("cls");
	GotoXY(0, 0);
	for (int i = 0; i <= height + 1; ++i) {
		cout << "  ";
		for (int j = 0; j <= width + 1; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}

	/*GotoXY(135, ); 
	cout << "\t<Crossing Road Game>" << endl;*/

	//GotoXY(125, 3); cout << "LV. " << level.getLevel() << endl;
	GotoXY(135, 13); cout << "CONTROL MANUAL" << endl;
	GotoXY(135, 14); cout << "[ W ]: UP" << endl;
	GotoXY(135, 15); cout << "[ S ]: DOWN" << endl;
	GotoXY(135, 16); cout << "[ A ]: LEFT" << endl;
	GotoXY(135, 17); cout << "[ D ]: RIGHT" << endl;
	GotoXY(135, 18); cout << "COMMANDS" << endl;
	GotoXY(135, 19); cout << "[ L ]: Save game" << endl;
	GotoXY(135, 20); cout << "[ T ]: Load game" << endl;
	GotoXY(135, 21); cout << "[ O ]: Pause game" << endl;
}
#ifndef _BOARD_H_
#define _BOARD_H_
#include "Console.h"

class Board {
	const int width = 116, height = 39;
	char map[41][118];
public:
	Board();
	~Board() = default;
	void printBoard();
	
};

#endif

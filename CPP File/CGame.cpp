#include "CGame.h"
#include "Console.h"


int LEFT = 3;

char Level0[7][9] = { { ' ',':',':',':',':',':',':',':',' ' }, { ':','+',':',' ',' ',' ',':','+',':' }, { '+',':','+',' ',' ',' ','+',':','+' }, { '+','#','+',' ',' ',' ','+',':','+' }, { '+','#','+',' ',' ',' ','+','#','+' }, { '#','+','#',' ',' ',' ','#','+','#' }, { ' ','#','#','#','#','#','#','#',' ' } };
char Level01[7][7] = { {' ',' ', ':', ':', ':', ' ', ' '}, {':','+',':','+',':', ' ',' '}, {' ',' ','+',':','+',' ',' '}, {' ',' ','+','#','+',' ',' '}, {' ',' ','+','#','+',' ',' '}, {' ',' ','#','+','#',' ',' '}, {'#','#','#','#','#','#','#'} };
char Level02[7][10] = { {' ',':', ':', ':', ':', ':', ':', ':', ':', ' '}, {':','+',':',' ',' ', ' ',' ', ':', '+', ':'}, {' ',' ',' ',' ',' ', ' ', '+',':','+',' '}, {' ',' ',' ',' ','+', '#', '+',' ',' ',' '}, {' ',' ','+','#','+', ' ', ' ',' ',' ',' '}, {' ','#','+','#',' ', ' ', ' ',' ',' ',' '}, {'#','#','#','#','#','#','#','#','#','#'} };
char Level03[7][10] = { {' ',':', ':', ':', ':', ':', ':', ':', ':', ' '}, {':','+',':',' ',' ', ' ',' ', ':', '+', ':'}, {' ',' ',' ',' ',' ', ' ', ' ','+',':','+'}, {' ',' ',' ',' ','+', '#', '+','+',':',' '}, {' ',' ',' ',' ',' ', ' ', ' ','+','#','+'}, {'#','+','# ',' ',' ', ' ', ' ','#','+','#'}, {' ','#','#','#','#','#','#','#','#',' '} };
char Level04[7][11] = { {' ',' ', ' ', ' ', ':', ':', ':', ' ', ' ', ' ', ' '}, {' ',' ',' ',':','+', ':',' ', ' ', ' ', ' ', ' '}, {' ',' ','+',':','+', ' ', '+',':','+',' ', ' '}, {' ','+','#','+',' ', ' ', '+',':','+',' ',' '}, {'+','#','+','#','+', '#', '+','#','+','#', '+'}, {' ',' ',' ',' ',' ', ' ', '#','+','#',' ', ' '}, {' ',' ',' ',' ',' ',' ','#','#','#',' ',' '} };
char Level05[7][10] = { {':',':', ':', ':', ':', ':', ':', ':', ':', ':'}, {':','+',':',' ',' ', ' ',' ', ':', '+', ':'}, {'+',':','+',' ',' ', ' ', ' ',' ',' ',' '}, {'+','#','+','+',':', '+', '+','#','+',' '}, {' ',' ',' ',' ',' ', ' ', ' ','+','#','+'}, {'#','+','#',' ',' ', ' ', ' ','#','+','#'}, {' ','#','#','#','#','#','#','#','#',' '} };
char Level06[7][10] = { {' ',':', ':', ':', ':', ':', ':', ':', ':', ' '}, {':','+',':',' ',' ', ' ',' ', ':', '+', ':'}, {'+',':','+',' ',' ', ' ', ' ',' ',' ',' '}, {'+','#','+','+',':', '+', '+','#','+',' '}, {'+','#','+',' ',' ', ' ', ' ','+','#','+'}, {'#','+','# ',' ',' ', ' ', ' ','#','+','#'}, {' ','#','#','#','#','#','#','#','#',' '} };
char Level07[7][11] = { {':',':', ':', ':', ':', ':', ':', ':', ':', ':', ':'}, {':','+',':',' ',' ', ' ',' ', ' ', ':', '+', ':'}, {' ',' ',' ',' ',' ', ' ', ' ','+',':','+', ' '}, {' ',' ',' ',' ',' ', ' ', '+','#','+',' ',' '}, {' ',' ',' ',' ',' ', '+','#','+',' ',' ', ' '}, {' ',' ',' ',' ','#', '+', '#',' ',' ',' ', ' '}, {' ',' ',' ',' ','#','+','#',' ',' ',' ',' '} };
char Level08[7][10] = { {' ',':', ':', ':', ':', ':', ':', ':', ':', ' '}, {':','+',':',' ',' ', ' ',' ', ':', '+', ':'}, {'+',':','+',' ',' ', ' ', ' ','+',':','+'}, {' ','+','#','+','+',':', '+', '+','#',' '}, {'+','#','+',' ',' ', ' ', ' ','+','#','+'}, {'#','+','# ',' ',' ', ' ', ' ','#','+','#'}, {' ','#','#','#','#','#','#','#','#',' '} };
char Level09[7][10] = { {' ',':', ':', ':', ':', ':', ':', ':', ':', ' '}, {':','+',':',' ',' ', ' ',' ', ':', '+', ':'}, {'+',':','+',' ',' ', ' ', ' ','+',':','+'}, {' ','+','#','+','+',':', '+', '+','#','+'}, {' ',' ',' ',' ',' ', ' ', ' ','+','#','+'}, {'#','+','# ',' ',' ', ' ', ' ','#','+','#'}, {' ','#','#','#','#','#','#','#','#',' '} };



//Ham in khoang trang
void printBlank(int x, int y) {
	char** blank;
	blank = new char* [4];
	for (int i = 0; i < 4; i++)
	{
		blank[i] = new char[5];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++)
			blank[i][j] = ' ';
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			GotoXY(x + j, y + i);
			cout << blank[i][j];
		}
		cout << endl;
	}
}


CGame::CGame() :cn(){
	srand(time(NULL));
	listAnimal.clear();
	listVehicle.clear();
	level = 1;
	mode = 1;
	//resetGame();
}

CGame::CGame(int l) {
	srand(time(NULL));
	listAnimal.clear();
	listVehicle.clear();
	level = l;
	mode = 1;
	//resetGame();
}

CGame::~CGame() {
	clearGame();
}

void CGame::setLevel(int l){
	level = l;
}

int CGame::getLevel() {
	return level;
}

void CGame::setMode(int m) {
	mode = m;
}

int CGame::getMode() {
	return mode;
}

void CGame::clearGame() {
	//printBlank(cn.getX(), cn.getY());
	cn.~cn();
	listAnimal.clear();
	listVehicle.clear();
}

void CGame::resetGame(bool& is_running){
	is_running = true;
	clearGame();
	setCursor(0, 0);
	Board a;
	a.printBoard();
	printLevel();
	cn.revive();
	cn.setX(113);
	cn.setY(36);
	//level = l;
	for (int i = 1; i < 7; i++) {
		if (i == 1)
			CAnimal* a = getNewBird(1 + i * 5);
		else if (i == 3) {
			CAnimal* a = getNewDog(1 + i * 5);
		}
		else if (i == 2 || i == 5)
			CVehicle* v = getNewCar(1 + i * 5);
		else
			CVehicle* v = getNewTruck(1 + i * 5);
	}
}

void printLight(bool light) {
	if (light) {
		SetColor(colorGreen);
	}
	else {
		SetColor(colorRed);
	}
	GotoXY(3, 11);
	cout << (char)219;
	GotoXY(3, 21);
	cout << (char)219;
	GotoXY(3, 26);
	cout << (char)219;
	GotoXY(3, 31);
	cout << (char)219;
	SetColor(colorBlack);
}

void CGame::drawGame(bool light) { //Ve tro choi sau khi da co du lieu
	setCursor(0, 0);
	printLight(light);
	printLevel();
	drawPeople();
	printEnemy();
}

CPeople CGame::getPeople() {
	return cn;
}

vector<CVehicle*> CGame::getVehicle() {
	return listVehicle;
}

vector<CAnimal*> CGame::getAnimal() {
	return listAnimal;
}




void CGame::exitGame(bool& is_running) {
	is_running = false;
	cn.setX(113);
	cn.setY(36);
	listVehicle.clear();
	listAnimal.clear();
}

void CGame::killPeople() {
	cn.kill();
}

void CGame::revivePeople() {
	cn.revive();
}

void print0() {
	int x = 135, y = 3;
	SetColor(colorPurple);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 9; j++) {
			GotoXY(x + j, y + i);
			cout << Level0[i][j];
		}
	}
}

void CGame::printLevel() {
	int x = 147, y = 3;
	print0();
	SetColor(colorPurple);
	if (level == 1) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				GotoXY(x + j, y + i);
				cout << Level01[i][j];
			}
		}
	}
	else if (level == 4 || level == 7) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 11; j++) {
				GotoXY(x + j, y + i);
				if (level == 4) {
					cout << Level04[i][j];
				}
				else
					cout << Level07[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 10; j++) {
				GotoXY(x + j, y + i);
				if (level == 2) {
					cout << Level02[i][j];
				}
				else if (level == 3)
					cout << Level03[i][j];
				else if (level == 5)
					cout << Level05[i][j];
				else if (level == 6)
					cout << Level06[i][j];
				else if (level == 8)
					cout << Level08[i][j];
				else
					cout << Level09[i][j];
			}
		}
	}
	SetColor(colorBlack);
}

CAnimal* CGame::getNewBird(int y) {
	CAnimal* temp = new CBird(3, y);
	temp->setDirection(0);
	listAnimal.push_back(temp);
	return temp;
}

CAnimal* CGame::getNewDog(int y) {
	CAnimal* temp = new CDog(3, y);
	temp->setDirection(0);
	listAnimal.push_back(temp);
	return temp;
}

CVehicle* CGame::getNewCar(int y) {
	CVehicle* temp = new CCar(105, y);
	temp->setDirection(1);
	listVehicle.push_back(temp);
	return temp;
}

CVehicle* CGame::getNewTruck(int y) {
	CVehicle* temp = new CTruck(100, y);
	temp->setDirection(1);
	listVehicle.push_back(temp);
	return temp;
}

void CGame::startGame(bool &is_running) {
	resetGame(is_running);
}

void CGame::pauseGame(bool &is_pause) {
	is_pause = true;
}

void CGame::resumeGame(bool& is_pause) {
	is_pause = false;
}


void CGame::loseGame() {
	Ambulance am(cn.getY());
	int posX = 3;
	while (am.checkOutMap() != true) {
		am.printAmbulance();
		Sleep(50);
		am.move();
		am.printGameOver(posX);
		posX++;
	}
	Frame frame;
	frame.createFrame(12, 40);
	frame.printFrame(125, 25);
	GotoXY(130, 29);
	cout << "You lose! Want to try again?";
	GotoXY(137, 31);
	SetColor(colorLightRed);
	cout << "Yes";
	SetColor(colorBlack);
	GotoXY(149, 31);
	cout << "No";
}


void CGame::printEnemy() {
	for (int i = 0; i < listAnimal.size(); i++) {
		if (listAnimal[i]->getType() == 0) {
			SetColor(colorPurple);
		}
		else {
			SetColor(colorYellow);
		}
		listAnimal[i]->printAnimal();
	}


	for (int i = 0; i < listVehicle.size(); i++) {
		if (listVehicle[i]->getType() == 2) {
			SetColor(colorBlue);
		}
		else {
			SetColor(colorAqua);
		}
		listVehicle[i]->printVehicle();
	}
	SetColor(colorBlack);

}


void CGame::saveGame(string filename) {
	fstream fs;
	fs.open(filename + ".txt", ios::out);
	fs << mode << endl;
	fs << level << endl;
	fs.close();
}

void CGame::loadGame(string filename) {
	int temp;
	fstream fs;
	fs.open(filename + ".txt", ios::in);
	if (fs.is_open()) {
		fs >> temp;
		setMode(temp);
		fs.ignore();
		fs >> temp;
		setLevel(temp);
	}
	else {
		cout << "Can not open file!";
	}
	fs.close();
}

void CGame::drawPeople() {
	SetColor(colorGrey);
	cn.printPeople();
	SetColor(colorBlack);
}

void CGame::levelUp(){
	level++;
}

void CGame::updatePosPeople(char move) {
	switch (move) {
	case 'W':
		printBlank(cn.getX(), cn.getY());
		cn.Up();
		break;
	case 'S':
		printBlank(cn.getX(), cn.getY());
		cn.Down();
		break;
	case 'A':
		printBlank(cn.getX(), cn.getY());
		cn.Left();
		break;
	case 'D':
		printBlank(cn.getX(), cn.getY());
		cn.Right();
		break;
	case 72:
		printBlank(cn.getX(), cn.getY());
		cn.Up();
		break;
	case 80:
		printBlank(cn.getX(), cn.getY());
		cn.Down();
		break;
	case 75:
		printBlank(cn.getX(), cn.getY());
		cn.Left();
		break;
	case 77:
		printBlank(cn.getX(), cn.getY());
		cn.Right();
		break;
	default:
		break;
	}
}


void CGame::updatePosVehicle(int &numC, int &numT) {
	for (int i = 0; i < listVehicle.size(); i++) {
		listVehicle[i]->Move(listVehicle[i]->getDirection());
		if (listVehicle[i]->getOutMapV() && listVehicle[i]->getType() == 2) {
			numC -= 1;
			delete listVehicle[i];
			listVehicle.erase(listVehicle.begin() + i--);
		}
		else if (listVehicle[i]->getOutMapV() && listVehicle[i]->getType() == 3) {
			numT -= 1;
			delete listVehicle[i];
			listVehicle.erase(listVehicle.begin() + i--);
		}
	}
}

void CGame::updatePosAnimal(int &numB, int &numD) {
	for (int i = 0; i < listAnimal.size(); i++) {
		listAnimal[i]->Move(listAnimal[i]->getDirection());
		if (listAnimal[i]->getOutMapA() && listAnimal[i]->getType() == 0) {
			numB -= 1;
			delete listAnimal[i];
			listAnimal.erase(listAnimal.begin() + i--);
		}
		else if (listAnimal[i]->getOutMapA() && listAnimal[i]->getType() == 1) {
			numD -= 1;
			delete listAnimal[i];
			listAnimal.erase(listAnimal.begin() + i--);
		}
	}
}





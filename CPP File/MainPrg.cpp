#include "Console.h"
#include "CGame.h"
#include "Board.h"

vector <string> command1 = { "  Play", "  Load", "Settings", "About us", "  Exit" };
vector <string> Mode = { "Easy", "Medium", "Hard" };
vector <string> musicStatus1 = { "ON", "OFF", "ON", "OFF" };


CGame cg;
char moving;
bool is_running = true;
long Time = 500;
int numOfAnimal = 6;
int numOfVehicle = 16;
bool light = true;
bool is_pause = false;


void LightChanging() {
	while (is_running) {
		if (is_pause == false) {
			Sleep(5000);
			light = false;
			Sleep(3000);
			light = true;
		}
		else{}
	}
}

void RunGame() {
	int rand1, numB = 1, numD = 1, numC = 2, numT = 2;
	int moveB = 0, moveD = 0, moveT = 0, moveC = 0;
	while (is_running){//!cg.getPeople().isDead()) {
		if (is_pause == false) {
			if (!cg.getPeople().isDead()) {
				cg.updatePosPeople(moving);//Cập nhật vị trí người theo thông tin từ main
			}
			moving = ' ';

			if (light) {
				cg.updatePosVehicle(numC, numT);//Cập nhật vị trí xe
				moveT += 1;
				moveC += 1;
			}

			cg.updatePosAnimal(numB, numD);//Cập nhật vị trí thú
			moveB += 1;
			moveD += 1;

			for (int i = 1; i < 7; i++) {
				rand1 = rand() % 4;
				if (rand1 == 0) {
					if (i == 1 && cg.getAnimal().size() < numOfAnimal && numB <= numOfAnimal / 2 && moveB >= 4) {
						CAnimal* a = cg.getNewBird(1 + i * 5);
						numB += 1;
						moveB = 0;
					}
					else if (i == 3 && cg.getAnimal().size() < numOfAnimal && numD <= numOfAnimal / 2 && moveD >= 4) {
						CAnimal* a = cg.getNewDog(1 + i * 5);
						numD += 1;
						moveD = 0;
					}
					else if ((i == 2 || i == 5) && cg.getVehicle().size() < numOfVehicle && numC <= numOfVehicle / 4 && light && moveC >= 4) {
						CVehicle* v = cg.getNewCar(1 + i * 5);
						numC += 1;
						moveC = 0;
					}
					else if ((i == 4 || i == 6) && cg.getVehicle().size() < numOfVehicle && numT <= numOfVehicle / 4 && light && moveT >= 4) {
						CVehicle* v = cg.getNewTruck(1 + i * 5);
						numT += 1;
						moveT = 0;
					}
				}
				else {}
			}
			cg.drawGame(light);
			if (cg.getPeople().isImpact(cg.getVehicle()) || cg.getPeople().isImpact(cg.getAnimal())) {
				crashSound(getSST());
				is_running = false;
				is_pause = true;
				moving = ' ';
				cg.killPeople();
				cg.setLevel(1);
			}
			if (cg.getPeople().isFinish()) {
				numT = numC = 2;
				numB = numD = 1;
				numOfAnimal = 6+ 2*cg.getLevel();
				numOfVehicle = 16+ 4*cg.getLevel();
				cg.levelUp();
				win(getSST());
				cg.resetGame(is_running);
				moveB = moveD = moveC = moveT = 0;
			}
			Sleep(Time);
		}
		else {}
	}
}

void printLoad() {
	system("cls");
	string filename;
	char temp;
	Frame frame;
	frame.createFrame(10, 80);
	frame.printFrame(45, 15);
	GotoXY(52, 19);
	cout << "Enter your filename: ";
	GotoXY(80, 19);
	getline(cin, filename);
	cg.loadGame(filename);
	if (cg.getMode() == 1)
		Time = 500;
	else if (cg.getMode() == 2)
		Time = 300;
	else
		Time = 200;
	is_pause = false;
	cg.startGame(is_running);
	cg.drawGame(light);
	thread t1(LightChanging);
	thread t2(RunGame);
	thread t3(gameMusic);
	while (true) {
		if (cg.getPeople().isDead() == false) {
			temp = toupper(_getch());
			if (temp == 'O') {
				cg.pauseGame(is_pause);
			}
			else if (temp == 'R') {
				cg.resumeGame(is_pause);
			}
			else if (temp == 'L') {
				cg.pauseGame(is_pause);
				Frame frame;
				frame.createFrame(7, 42);
				frame.printFrame(125, 28);
				GotoXY(127, 30);
				cout << "Enter your filename: ";
				GotoXY(127, 31);
				getline(cin, filename);
				for (int i = 0; i < 7; i++) {
					for (int j = 0; j < 42; j++) {
						GotoXY(125 + j, 28 + i);
						cout << ' ';
					}
				}
				cg.saveGame(filename);

				cg.resumeGame(is_pause);

			}
			else if (temp == 'T') {
				is_running = false;
				Frame frame;
				frame.createFrame(7, 42);
				frame.printFrame(125, 28);
				GotoXY(127, 30);
				cout << "Enter your filename: ";
				GotoXY(127, 31);
				getline(cin, filename);
				for (int i = 0; i < 7; i++) {
					for (int j = 0; j < 42; j++) {
						GotoXY(125 + j, 28 + i);
						cout << ' ';
					}
				}
				cg.loadGame(filename);
				if (cg.getMode() == 1)
					Time = 500;
				else if (cg.getMode() == 2)
					Time = 300;
				else
					Time = 200;
				cg.resetGame(is_running);
				t1.detach();
				t2.detach();
				t3.detach();
				t1 = thread(LightChanging);
				t2 = thread(RunGame);
				t3 = thread(gameMusic);
			}
			else {
				if (is_pause == false) {
					moving = temp;
				}
			}
		}
		else {
			AmbulanceSound(getSST());
			cg.loseGame();
			loseSound(getSST());
			int x = 137, y = 31;
			GotoXY(x, y);
			int a = 0;
			while (a == 0) {
				char temp1 = toupper(_getch());
				switch (temp1) {
				case 'A': case keyLeft: {
					if (x == 149) {
						GotoXY(x, y);
						SetColor(colorBlack);
						cout << "No";
						x = 137;
						GotoXY(x, y);
						SetColor(colorLightRed);
						cout << "Yes";
						SetColor(colorBlack);
					}
					break;
				}
				case 'D': case keyRight: {
					if (x == 137) {
						GotoXY(x, y);
						SetColor(colorBlack);
						cout << "Yes";
						x = 149;
						GotoXY(x, y);
						SetColor(colorLightRed);
						cout << "No";
						SetColor(colorBlack);
					}
					break;
				}
				case keySpace: case keyEnter: {
					if (x == 137) {
						//temp = ' ';
						a = 1;
						system("cls");
						cg.resetGame(is_running);
						t1.detach();
						t2.detach();
						t3.detach();
						is_pause = false;
						t1 = thread(LightChanging);
						t2 = thread(RunGame);
						t3 = thread(gameMusic);
						break;
					}
					else {
						a = 1;
						cg.exitGame(is_running);
						t1.detach();
						t2.detach();
						t3.detach();
						system("cls");
						SetGameTitle2();
						SetFrame2();
						printMenu();
						break;
					}
					break;
				}
				}
			}
		}
	}
}

void printPlay() {
	int x, y;
	int mode = 0;

	system("cls");
	drawBorder(100, 18, 25, 6, colorYellow);
	x = 73; y = 6;
	GotoXY(x, y);
	for (int i = 0; i < 17; i++) {
		y++;
		GotoXY(x, y);
		cout << char(219);
	}

	printHowToPlay();
	x = 48, y = 13;

	//print level
	GotoXY(32, 11);
	SetColor(colorBlack);
	cout << "Choose the mode that you want to play!" << endl;
	GotoXY(x, y);
	SetColor(colorLightRed);
	cout << Mode[0];
	//print list of levels
	for (int i = 1; i < 3; i++) {
		SetColor(colorBlack);
		y += 2;
		GotoXY(x, y);
		cout << Mode[i];
	}
	y = 13;
	GotoXY(40, 13);
	do {
		int k = toupper(_getch()); //key from keyboard
		switch (k) {
		case 'W': case keyUp: {
			if (y > 13) {
				move(getSST());
				GotoXY(x, y);
				SetColor(colorBlack);
				cout << Mode[(y - 13) / 2];
				y -= 2;
				GotoXY(x, y);
				SetColor(colorLightRed);
				cout << Mode[(y - 13) / 2];
				SetColor(colorBlack);
			}
			break;
		}
		case 'S': case keyDown: {
			if (y < 17) {
				move(getSST());
				GotoXY(x, y);
				SetColor(colorBlack);
				cout << Mode[(y - 13) / 2];
				y += 2;
				GotoXY(x, y);
				SetColor(colorLightRed);
				cout << Mode[(y - 13) / 2];
				SetColor(colorBlack);
			}
			break;
		}
		case keySpace: case keyEnter: {
			choose(getSST());
			is_pause = false;
			if (y == 13) { //easy
				cg.setMode(1);
				Time = 500;
				char temp;
				string filename;
				cg.startGame(is_running);
				cg.drawGame(light);
				thread t1(LightChanging);
				thread t2(RunGame);
				thread t3(gameMusic);
				while (true) {
					if (cg.getPeople().isDead() == false) {
						temp = toupper(_getch());
						if (temp == 'O') {
							cg.pauseGame(is_pause);
						}
						else if (temp == 'R') {
							cg.resumeGame(is_pause);
						}
						else if (temp == 'L') {
							cg.pauseGame(is_pause);
							Frame frame;
							frame.createFrame(7, 42);
							frame.printFrame(125, 28);
							GotoXY(127, 30);
							cout << "Enter your filename: ";
							GotoXY(127, 31);
							getline(cin, filename);
							for (int i = 0; i < 7; i++) {
								for (int j = 0; j < 42; j++) {
									GotoXY(125 + j, 28 + i);
									cout << ' ';
								}
							}
							cg.saveGame(filename);

							cg.resumeGame(is_pause);

						}
						else if (temp == 'T') {
							is_running = false;
							Frame frame;
							frame.createFrame(7, 42);
							frame.printFrame(125, 28);
							GotoXY(127, 30);
							cout << "Enter your filename: ";
							GotoXY(127, 31);
							getline(cin, filename);
							for (int i = 0; i < 7; i++) {
								for (int j = 0; j < 42; j++) {
									GotoXY(125 + j, 28 + i);
									cout << ' ';
								}
							}
							cg.loadGame(filename);
							if (cg.getMode() == 1)
								Time = 500;
							else if (cg.getMode() == 2)
								Time = 300;
							else
								Time = 200;
							cg.resetGame(is_running);
							t1.detach();
							t2.detach();
							t3.detach();
							t1 = thread(LightChanging);
							t2 = thread(RunGame);
							t3 = thread(gameMusic);
						}
						else {
							if (is_pause == false) {
								moving = temp;
							}
						}
					}
					else {
						AmbulanceSound(getSST());
						cg.loseGame();
						loseSound(getSST());
						int x = 137, y = 31;
						GotoXY(x, y);
						int a = 0;
						while (a == 0) {
							char temp1 = toupper(_getch());
							switch (temp1) {
							case 'A': case keyLeft: {
								if (x == 149) {
									GotoXY(x, y);
									SetColor(colorBlack);
									cout << "No";
									x = 137;
									GotoXY(x, y);
									SetColor(colorLightRed);
									cout << "Yes";
									SetColor(colorBlack);
								}
								break;
							}
							case 'D': case keyRight: {
								if (x == 137) {
									//move(sSt);
									GotoXY(x, y);
									SetColor(colorBlack);
									cout << "Yes";
									x = 149;
									GotoXY(x, y);
									SetColor(colorLightRed);
									cout << "No";
									SetColor(colorBlack);
								}
								break;
							}
							case keySpace: case keyEnter: {
								if (x == 137) {
									a = 1;
									system("cls");
									cg.resetGame(is_running);
									t1.detach();
									t2.detach();
									t3.detach();
									is_pause = false;
									t1 = thread(LightChanging);
									t2 = thread(RunGame);
									t3 = thread(gameMusic);
									break;
								}
								else {
									a = 1;
									cg.exitGame(is_running);
									t1.detach();
									t2.detach();
									t3.detach();
									system("cls");
									SetGameTitle2();
									SetFrame2();
									printMenu();
									break;
								}
								break;
							}
							}
						}
					}
				}
			}

			else if (y == 15) { //medium
				cg.setMode(2);
				Time = 300;
				char temp;
				string filename;
				cg.startGame(is_running);
				cg.drawGame(light);
				thread t1(LightChanging);
				thread t2(RunGame);
				thread t3(gameMusic);

				while (true) {
					if (cg.getPeople().isDead() == false) {
						temp = toupper(_getch());
						if (temp == 'O') {
							cg.pauseGame(is_pause);
						}
						else if (temp == 'R') {
							cg.resumeGame(is_pause);
						}
						else if (temp == 'L') {
							cg.pauseGame(is_pause);
							Frame frame;
							frame.createFrame(7, 42);
							frame.printFrame(125, 28);
							GotoXY(127, 30);
							cout << "Enter your filename: ";
							GotoXY(127, 31);
							getline(cin, filename);
							for (int i = 0; i < 7; i++) {
								for (int j = 0; j < 42; j++) {
									GotoXY(125 + j, 28 + i);
									cout << ' ';
								}
							}
							cg.saveGame(filename);

							cg.resumeGame(is_pause);

						}
						else if (temp == 'T') {
							is_running = false;
							Frame frame;
							frame.createFrame(7, 42);
							frame.printFrame(125, 28);
							GotoXY(127, 30);
							cout << "Enter your filename: ";
							GotoXY(127, 31);
							getline(cin, filename);
							for (int i = 0; i < 7; i++) {
								for (int j = 0; j < 42; j++) {
									GotoXY(125 + j, 28 + i);
									cout << ' ';
								}
							}
							cg.loadGame(filename);
							if (cg.getMode() == 1)
								Time = 500;
							else if (cg.getMode() == 2)
								Time = 300;
							else
								Time = 200;
							cg.resetGame(is_running);
							t1.detach();
							t2.detach();
							t3.detach();
							t1 = thread(LightChanging);
							t2 = thread(RunGame);
							t3 = thread(gameMusic);
						}
						else {
							if (is_pause == false) {
								moving = temp;
							}
						}
					}
					else {
						AmbulanceSound(getSST());
						cg.loseGame();
						loseSound(getSST());
						int x = 137, y = 31;
						GotoXY(x, y);
						int a = 0;
						while (a == 0) {
							char temp1 = toupper(_getch());
							switch (temp1) {
							case 'A': case keyLeft: {
								if (x == 149) {
									//move(sSt);
									GotoXY(x, y);
									SetColor(colorBlack);
									cout << "No";
									x = 137;
									GotoXY(x, y);
									SetColor(colorLightRed);
									cout << "Yes";
									SetColor(colorBlack);
								}
								break;
							}
							case 'D': case keyRight: {
								if (x == 137) {
									GotoXY(x, y);
									SetColor(colorBlack);
									cout << "Yes";
									x = 149;
									GotoXY(x, y);
									SetColor(colorLightRed);
									cout << "No";
									SetColor(colorBlack);
								}
								break;
							}
							case keySpace: case keyEnter: {
								if (x == 137) {
									a = 1;
									system("cls");
									cg.resetGame(is_running);
									t1.detach();
									t2.detach();
									t3.detach();
									is_pause = false;
									t1 = thread(LightChanging);
									t2 = thread(RunGame);
									t3 = thread(gameMusic);
									break;
								}
								else {
									a = 1;
									cg.exitGame(is_running);
									t1.detach();
									t2.detach();
									t3.detach();
									system("cls");
									SetGameTitle2();
									SetFrame2();
									printMenu();
									break;
								}
								break;
							}
							}
						}
					}
				}
			}
			else { //hard
				cg.setMode(3);
				Time = 200;
				char temp;
				string filename;
				cg.startGame(is_running);
				cg.drawGame(light);
				thread t1(LightChanging);
				thread t2(RunGame);
				thread t3(gameMusic);

				while (true) {
					if (cg.getPeople().isDead() == false) {
						temp = toupper(_getch());
						if (temp == 'O') {
							cg.pauseGame(is_pause);
						}
						else if (temp == 'R') {
							cg.resumeGame(is_pause);
						}
						else if (temp == 'L') {
							cg.pauseGame(is_pause);
							Frame frame;
							frame.createFrame(7, 42);
							frame.printFrame(125, 28);
							GotoXY(127, 30);
							cout << "Enter your filename: ";
							GotoXY(127, 31);
							getline(cin, filename);
							for (int i = 0; i < 7; i++) {
								for (int j = 0; j < 42; j++) {
									GotoXY(125 + j, 28 + i);
									cout << ' ';
								}
							}
							cg.saveGame(filename);

							cg.resumeGame(is_pause);

						}
						else if (temp == 'T') {
							is_running = false;
							Frame frame;
							frame.createFrame(7, 42);
							frame.printFrame(125, 28);
							GotoXY(127, 30);
							cout << "Enter your filename: ";
							GotoXY(127, 31);
							getline(cin, filename);
							for (int i = 0; i < 7; i++) {
								for (int j = 0; j < 42; j++) {
									GotoXY(125 + j, 28 + i);
									cout << ' ';
								}
							}
							cg.loadGame(filename);
							if (cg.getMode() == 1)
								Time = 500;
							else if (cg.getMode() == 2)
								Time = 300;
							else
								Time = 200;
							cg.resetGame(is_running);
							t1.detach();
							t2.detach();
							t3.detach();
							t1 = thread(LightChanging);
							t2 = thread(RunGame);
							t3 = thread(gameMusic);
						}
						else {
							if (is_pause == false) {
								moving = temp;
							}
						}
					}
					else {
						AmbulanceSound(getSST());
						cg.loseGame();
						loseSound(getSST());
						int x = 137, y = 31;
						GotoXY(x, y);
						int a = 0;
						while (a == 0) {
							char temp1 = toupper(_getch());
							switch (temp1) {
							case 'A': case keyLeft: {
								if (x == 149) {
									GotoXY(x, y);
									SetColor(colorBlack);
									cout << "No";
									x = 137;
									GotoXY(x, y);
									SetColor(colorLightRed);
									cout << "Yes";
									SetColor(colorBlack);
								}
								break;
							}
							case 'D': case keyRight: {
								if (x == 137) {
									GotoXY(x, y);
									SetColor(colorBlack);
									cout << "Yes";
									x = 149;
									GotoXY(x, y);
									SetColor(colorLightRed);
									cout << "No";
									SetColor(colorBlack);
								}
								break;
							}
							case keySpace: case keyEnter: {
								if (x == 137) {
									a = 1;
									system("cls");
									cg.resetGame(is_running);
									t1.detach();
									t2.detach();
									t3.detach();
									is_pause = false;
									t1 = thread(LightChanging);
									t2 = thread(RunGame);
									t3 = thread(gameMusic);
									break;
								}
								else {
									a = 1;
									cg.exitGame(is_running);
									t1.detach();
									t2.detach();
									t3.detach();
									system("cls");
									SetGameTitle2();
									SetFrame2();
									printMenu();
									break;
								}
								break;
							}
							}
						}
					}
				}
			}
		}
		}
	} while (true);
}


int main() {
	system("color F7");
	srand (time(NULL));
	ResizeConsole(1300, 750);
	FixConsoleWindow();
	setFontnSize(7, 15);
	setCursor(0, 0);
	setTheme();
	printMenu();
	return 0;
}
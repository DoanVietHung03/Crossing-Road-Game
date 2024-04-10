#ifndef _CGAME_H_
#define _CGAME_H_
#include "CBird.h"
#include "CDog.h"
#include "CCar.h"
#include "CTruck.h"
#include "CPeople.h"
#include "Support.h"


class CGame {
	vector<CAnimal*> listAnimal;
	vector<CVehicle*> listVehicle;
	CPeople cn;
	int mode;
	int level;
public:
	CGame(); 
	CGame(int);
	void clearGame();
	void drawGame(bool); 
	~CGame(); 
	CPeople getPeople();
	vector<CVehicle*> getVehicle();
	vector<CAnimal*> getAnimal(); 
	CAnimal* getNewBird(int);
	CAnimal* getNewDog(int);
	CVehicle* getNewCar(int);
	CVehicle* getNewTruck(int);
	void resetGame(bool&); 
	void exitGame(bool&);
	void startGame(bool&); 
	void setMode(int);
	int getMode();
	int getLevel();
	void loseGame();
	void printLevel();
	void killPeople();
	void revivePeople();
	void setLevel(int);
	void levelUp();
	void loadGame(string); 
	void saveGame(string); 
	void pauseGame(bool &);
	void resumeGame(bool &); 
	void updatePosPeople(char); 
	void updatePosVehicle(int&, int&); 
	void updatePosAnimal(int&, int&);
	void printEnemy();
	void drawPeople();
};

#endif
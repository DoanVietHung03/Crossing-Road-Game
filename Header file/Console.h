#pragma once
#include "Libraries.h"

void FixConsoleWindow();
void ResizeConsole(int width, int height);
void setCursor(bool visible, DWORD size);
void GotoXY(int, int);
void SetColor(int);
void setFontnSize(float, float);
void SetGameTitle1();
void SetGameTitle2();
void SetFrame1();
void SetFrame2();
void setTheme();
void printMenu();
void selectCommand();
void selectAudio();
void printHowToPlay();
void win(bool);
bool getSST();
bool getMST();
void printPlay();
void printLoad();
void printSettingsScreen();
void printAboutScreen();
void drawBorder(int, int, int, int, int);
void themeM();
bool bgm1(bool);
void move(bool);
void choose(bool);
void gameMusic();
void crashSound(bool);
void loseSound(bool);
void AmbulanceSound(bool);

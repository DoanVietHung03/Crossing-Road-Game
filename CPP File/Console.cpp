#include "Console.h"

vector <string> command = { "New game", "Load game", "Settings", "About us", "  Exit" };
vector <string> level = { "Easy", "Medium", "Hard" };
vector <string> musicStatus = { "ON", "OFF", "ON", "OFF" };

bool mSt = true; //if music is on
bool sSt = true; //if sound is on


void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

//Co dinh kich thuoc console window
void ResizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//color
void SetColor(int fontColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fontColor);
}

void setFontnSize(float Fx, float Fy) {    //https://stackoverflow.com/questions/67268904/ive-found-this-code-to-change-the-font-but-it-doesnt-work
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = Fx;                   // Width of each character in the font
	cfi.dwFontSize.Y = Fy;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = 700;
	wcscpy_s(cfi.FaceName, L"Consolas");    // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

// an/hien con tro
void setCursor(bool visible, DWORD size) {
	// set bool visible = 0 - invisible, bool visible = 1 - visible;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (size == 0)
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 15;
	SetConsoleCursorInfo(console, &lpCursor);
}

void GotoXY(int x, int y) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout, coord);
}

//in ten game
void SetGameTitle1() {
	ifstream ifs("GameTitle1.txt");
	vector<string> lines;
	string line;
	int n = 241;
	int x = 42, y = 1;
	if (!ifs.is_open()) {
		cout << "Cannot open file" << endl;
		exit(0);
	}
	else {
		while (getline(ifs, line))
			lines.push_back(line);
	}
	for (int i = 0; i < lines.size(); i++) {
		SetColor(n);
		GotoXY(x, y);
		y++;
		cout << lines[i] << endl;
		Sleep(400);
		n++;
	}
	ifs.close();

	ifstream is("GameTitle2.txt");
	vector<string> vs;
	string s;
	int m = 246;
	if (!is.is_open()) {
		cout << " Cannot open file";
		exit(0);
	}
	else {
		while (getline(is, s))
			vs.push_back(s);
	}
	y = 1;
	x = 92;
	for (int i = 0; i < vs.size(); i++) {
		SetColor(m);
		GotoXY(x, y);
		y++;
		cout << vs[i] << endl;
		Sleep(400);
		m--;
	}
	cout << "\n\n\n";
	is.close();
}

void SetGameTitle2() {
	ifstream ifs("GameTitle1.txt");
	vector<string> lines;
	string line;
	int n = 241;
	int x = 42, y = 1;
	if (!ifs.is_open()) {
		cout << "Cannot open file" << endl;
		exit(0);
	}
	else {
		while (getline(ifs, line))
			lines.push_back(line);
	}
	for (int i = 0; i < lines.size(); i++) {
		SetColor(n);
		GotoXY(x, y);
		y++;
		cout << lines[i] << endl;
		n++;
	}
	ifs.close();

	ifstream is("GameTitle2.txt");
	vector<string> vs;
	string s;
	int m = 246;
	if (!is.is_open()) {
		cout << " Cannot open file";
		exit(0);
	}
	else {
		while (getline(is, s))
			vs.push_back(s);
	}
	y = 1;
	x = 92;
	for (int i = 0; i < vs.size(); i++) {
		SetColor(m);
		GotoXY(x, y);
		y++;
		cout << vs[i] << endl;
		m--;
	}
	cout << "\n\n\n";
	is.close();
}

//in khung menu
void SetFrame1() {
	ifstream frame("frame1.txt");
	vector<string> fra;
	string fr;
	if (!frame.is_open()) {
		cout << "Cannot open file";
		exit(0);
	}
	else {
		while (getline(frame, fr, ' '))
			fra.push_back(fr);
	}

	int x = 44;
	int y = 7;
	GotoXY(x, y);
	for (int i = 0; i < fra.size(); i++) {
		SetColor(colorLightAqua);
		//setFontnSize(9, 20);
		cout << fra[i];
		Sleep(50);
	}
	frame.close();

	x = 116;
	y = 8;
	ifstream fram("frame2.txt");
	vector<string> f;
	if (!fram.is_open()) {
		cout << "Cannot open file";
		exit(0);
	}
	else {
		while (getline(fram, fr))
			f.push_back(fr);
	}

	for (int i = 0; i < f.size(); i++) {
		GotoXY(x, y);
		SetColor(colorLightAqua);
		//setFontnSize(9, 20);
		cout << f[i];
		y++;
		Sleep(50);
	}

	x = 114;
	y = 26;
	ifstream ifs("frame3.txt");
	vector<string> vstr;
	string str;
	if (!ifs.is_open()) {
		cout << "Cannot open file";
		exit(0);
	}
	else {
		while (getline(ifs, str, ' '))
			vstr.push_back(str);
	}

	for (int i = vstr.size() - 1; i >= 0; i--) {
		GotoXY(x, y);
		SetColor(colorLightAqua);
		//setFontnSize(9, 20);
		cout << vstr[i];
		x -= 2;
		Sleep(50);
	}
	ifs.close();

	x = 44;
	y = 25;
	for (int i = 0; i < f.size(); i++) {
		GotoXY(x, y);
		SetColor(colorLightAqua);
		//setFontnSize(9, 20);
		cout << f[i];
		y--;
		Sleep(50);
	}
	fram.close();
}

void SetFrame2() {
	ifstream frame("frame1.txt");
	vector<string> fra;
	string fr;
	if (!frame.is_open()) {
		cout << "Cannot open file";
		exit(0);
	}
	else {
		while (getline(frame, fr, ' '))
			fra.push_back(fr);
	}

	int x = 44;
	int y = 7;
	GotoXY(x, y);
	for (int i = 0; i < fra.size(); i++) {
		SetColor(colorLightAqua);
		//setFontnSize(9, 20);
		cout << fra[i];
	}
	frame.close();

	x = 116;
	y = 8;
	ifstream fram("frame2.txt");
	vector<string> f;
	if (!fram.is_open()) {
		cout << "Cannot open file";
		exit(0);
	}
	else {
		while (getline(fram, fr))
			f.push_back(fr);
	}

	for (int i = 0; i < f.size(); i++) {
		GotoXY(x, y);
		SetColor(colorLightAqua);
		//setFontnSize(9, 20);
		cout << f[i];
		y++;
	}

	x = 114;
	y = 26;
	ifstream ifs("frame3.txt");
	vector<string> vstr;
	string str;
	if (!ifs.is_open()) {
		cout << "Cannot open file";
		exit(0);
	}
	else {
		while (getline(ifs, str, ' '))
			vstr.push_back(str);
	}

	for (int i = vstr.size() - 1; i >= 0; i--) {
		GotoXY(x, y);
		SetColor(colorLightAqua);
		//setFontnSize(9, 20);
		cout << vstr[i];
		x -= 2;
	}
	ifs.close();

	x = 44;
	y = 25;
	for (int i = 0; i < f.size(); i++) {
		GotoXY(x, y);
		SetColor(colorLightAqua);
		//setFontnSize(9, 20);
		cout << f[i];
		y--;
	}
	fram.close();
}

void setTheme() {
	themeM();
	SetGameTitle1();
	SetFrame1();
}



//chon cac yeu cau trong menu
void selectCommand() {
	int x = 76, y = 12;
	GotoXY(x, y);
	//	while (bgM(mSt) == true) {
	do {
		//if(is_pause == false){
		int k = toupper(_getch()); //key from keyboard
		switch (k) {
		case 'W': case keyUp: {
			if (y > 12) {
				GotoXY(x, y);
				SetColor(colorBlack);
				cout << command[(y - 12) / 2];
				y -= 2;
				GotoXY(x, y);
				SetColor(colorLightRed);
				move(sSt);
				cout << command[(y - 12) / 2];
			}
			break;
		}
		case 'S': case keyDown: {
			if (y < 20) {
				GotoXY(x, y);
				SetColor(colorBlack);
				cout << command[(y - 12) / 2];
				y += 2;
				GotoXY(x, y);
				SetColor(colorLightRed);
				move(sSt);
				cout << command[(y - 12) / 2];
			}
			break;
		}

		case keySpace: case keyEnter: {
			choose(sSt);
			if (y == 12) printPlay();
			if (y == 14) printLoad();
			if (y == 16) printSettingsScreen();
			if (y == 18) printAboutScreen();
			if (y == 20) {
				GotoXY(0, 40);
				exit(0);
			}
			break;
		}
		}
		//}
	} while (true);
	//}
}

//bat/tat am thanh
void selectAudio() {
	int x, y;
	x = 81, y = 11;
	GotoXY(x, y);
	do {
		int k = toupper(_getch()); //key from keyboard

		GotoXY(57, 22);
		SetColor(colorGrey);
		cout << "Press ESC to return to MENU...";
		if (k == keyEsc) {
			choose(sSt);
			system("cls");
			SetGameTitle2();
			SetFrame2();
			printMenu();
			break;
		}
		switch (k) {
		case 'W': case keyUp: {
			if (y > 11) {
				move(sSt);
				GotoXY(x, y);
				SetColor(colorBlack);
				cout << musicStatus[(y - 11) / 2];
				y -= 2;
				GotoXY(x, y);
				SetColor(colorLightRed);
				cout << musicStatus[(y - 11) / 2];
			}
			break;
		}
		case 'S': case keyDown: {
			if (y < 17) {
				move(sSt);
				GotoXY(x, y);
				SetColor(colorBlack);
				cout << musicStatus[(y - 11) / 2];
				y += 2;
				GotoXY(x, y);
				SetColor(colorLightRed);
				cout << musicStatus[(y - 11) / 2];
			}
			break;
		}
		case keySpace: case keyEnter: {
			choose(sSt);
			if (y == 11) mSt = true;
			if (y == 13) mSt = false;
			if (y == 15) sSt = true;
			if (y == 17) sSt = false;
			break;
		}
		}
	} while (true);
}

// in cac yeu cau trong menu
void printHowToPlay() {
	int x = 95; int y = 10;
	GotoXY(x, y);
	SetColor(colorBlue);
	cout << "HOW TO PLAY" << endl;
	y += 2;
	GotoXY(80, y);
	SetColor(colorLightBlue);
	cout << "* Use Arrow keys or A (left), D (right)," << endl;
	y += 2;
	GotoXY(80, y);
	cout << "      W (up), S (down) to move." << endl;
	y += 2;
	GotoXY(80, y);
	cout << "* If you hit the object, you will LOSE!" << endl;
	y += 2;
	GotoXY(80, y);
	cout << "* NOTE: The more difficult the level is," << endl;
	y += 2;
	GotoXY(80, y);
	cout << "        the faster the objects are!" << endl;
}

void printSettingsScreen() {
	int x = 81, y = 11;
	system("cls");
	drawBorder(40, 12, 52, 8, colorPurple);
	SetColor(colorYellow);
	GotoXY(62, 14);
	cout << "AUDIO";
	GotoXY(71, 12);
	cout << "MUSIC: ";
	GotoXY(71, 16);
	cout << "SOUND: ";
	SetColor(colorLightRed);
	GotoXY(x, y);
	cout << musicStatus[0];
	for (int i = 1; i < musicStatus.size(); i++) {
		y += 2;
		GotoXY(x, y);
		SetColor(colorBlack);
		cout << musicStatus[i];
	}

	selectAudio();
}

void printAboutScreen() {
	system("cls");
	drawBorder(100, 25, 25, 2, colorLightBlue);
	int y = 5;
	SetColor(colorYellow);
	//setFontnSize(9, 20);

	GotoXY(72, y);
	cout << "GROUP 7" << endl;
	y += 2;
	GotoXY(69, y);
	Sleep(300);
	cout << "CLASS 21CLC03" << endl;
	y += 2;
	GotoXY(57, y);
	cout << "HO CHI MINH CITY UNIVERSITY OF SCIENCE" << endl;
	y += 2;
	GotoXY(58, y);
	Sleep(300);
	cout << "OBJECT ORIENTED PROGRAMMING SUBJECT" << endl;
	y += 2;
	GotoXY(62, y);
	Sleep(300);
	cout << "PROJECT CROSSING ROAD GAME" << endl;
	y += 3;
	GotoXY(53, y);
	Sleep(300);
	cout << "MEMBERS" << endl;
	y += 2;
	GotoXY(41, y);
	Sleep(200);
	cout << "DOAN VIET HUNG      - 21127289" << endl;
	y += 2;
	GotoXY(41, y);
	Sleep(200);
	cout << "DINH BAO TRAN       - 21127454" << endl;
	y += 2;
	GotoXY(41, y);
	Sleep(200);
	cout << "DINH THI THUY DUONG - 21127572" << endl;
	y -= 6;
	GotoXY(90, y);
	cout << "INSTRUCTORS";
	y += 2;
	GotoXY(87, y);
	Sleep(200);
	cout << "TRUONG TOAN THINH" << endl;
	y += 2;
	GotoXY(90, y);
	Sleep(200);
	cout << "DO NGOC LE" << endl;
	y += 2;
	GotoXY(88, y);
	Sleep(200);
	cout << "NGUYEN HAI DANG" << endl;
	y += 7;

	GotoXY(59, y);
	SetColor(colorGrey);
	cout << "Press ESC to return to MENU...";
	while (true) {
		choose(sSt);
		int k = toupper(_getch());
		if (k == keyEsc) {
			system("cls");
			SetGameTitle2();
			SetFrame2();
			printMenu();
			break;
		}
	}


}

//in giao dien menu
void printMenu() {
	bgm1(mSt);
	int x = 76, y = 12;

	//setFontnSize(9, 20);
	GotoXY(x, y);
	SetColor(colorLightRed);
	cout << command[0];
	SetColor(colorBlack);
	//print list of commands
	for (int i = 1; i < 5; i++) {
		y += 2;
		GotoXY(x, y);
		cout << command[i];
	}
	selectCommand();
}

//ve khung
void drawBorder(int width, int height, int x, int y, int color) {
	SetColor(color);
	GotoXY(x, y);
	//chieu rong tren
	for (int i = 0; i < width; i++) {
		cout << char(220);
		x++;
	}
	//chieu dai phai
	cout << char(220);
	for (int i = 0; i < height; i++) {
		y++;
		GotoXY(x, y);
		cout << char(219);
	}
	//chieu dai trai
	y -= height;
	x -= width;
	for (int i = 0; i < height; i++) {
		y++;
		GotoXY(x, y);
		cout << char(219);
	}
	//chieu rong duoi
	GotoXY(x, y);
	for (int i = 0; i <= width; i++)
		cout << char(223);
}

//music when starting to print Title and framed 
void themeM() {
	PlaySound(TEXT("Frame.wav"), NULL, SND_ASYNC | SND_LOOP);
}

//background music
bool bgm1(bool mSt) {
	if (mSt == true)
		PlaySound(TEXT("background.wav"), NULL, SND_LOOP | SND_ASYNC);
	return mSt;
}

void gameMusic() {
	if (mSt == true)
		PlaySound(TEXT("whilePlaying.wav"), NULL, SND_LOOP | SND_ASYNC);
}

//move sound
void move(bool sSt) {
	if (sSt == true && mSt == true)
		PlaySound(TEXT("move.wav"), NULL, SND_ASYNC | SND_FILENAME);
}

//choose
void choose(bool sSt) {
	if (sSt == true)
		PlaySound(TEXT("enterKey.wav"), NULL, SND_ASYNC | SND_FILENAME);
}

//win sound
void win(bool sSt) {
	if(sSt == true)
		PlaySound(TEXT("win.wav"), NULL, SND_ASYNC | SND_FILENAME);
}

bool getSST() {
	return sSt;
}

bool getMST() {
	return mSt;
}

void crashSound(bool sSt) {
	if (sSt == true)
		PlaySound(TEXT("crash.wav"), NULL, SND_ASYNC | SND_FILENAME);
}

void loseSound(bool sSt) {
	if (sSt == true)
		PlaySound(TEXT("lose.wav"), NULL, SND_ASYNC | SND_FILENAME);
}

void AmbulanceSound(bool sSt) {
	if (sSt == true)
		PlaySound(TEXT("Ambulance.wav"), NULL, SND_ASYNC | SND_FILENAME);
}

//thread playsound(&playsound, this, <other params>);
//playsound.detach();
//thread othersound(&playsound, this, <other params>);
//othersound.detach();
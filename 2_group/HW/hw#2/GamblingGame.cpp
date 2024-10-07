#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

class Player {
	string name;
public:
	void setname(string name);
	string getname();

};
void Player::setname(string name) {
	this->name = name;
};
string Player::getname() {
	return name;
};

class GamblingGame {
	Player *p = new Player[2];
public:
	GamblingGame();
	void cinname();
	void gamestart();
};
GamblingGame::GamblingGame() {
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
};
void GamblingGame::cinname() {
	string name;
	cout << "첫번째 선수 이름>>";
	cin >> name;
	p[0].setname(name);
	cout << endl;
	cout << "두번째 선수 이름>>";
	cin >> name;
	p[1].setname(name);
	cout << endl;
};
void GamblingGame::gamestart() {
	srand((unsigned)time(0));
	int n = rand();
	int i = 1;
	while (i++) {
		cout << p[i % 2].getname() << " :<ENTER>";
		cin.ignore();
		if (cin.get() == '\n') {
			int a = rand() % 3, b = rand() % 3, c = rand() % 3;
			cout <<"\t\t" <<a << "\t" << b << "\t" << c;
			if (a == b && b == c) {
				cout << "\t" << p[i % 2].getname() << "님 승리!!" << endl;
				break;
			}
			else
				cout << "\t" << "아쉽군요!" << endl;
		};
	};
};

int main() {
	GamblingGame game;
	game.cinname();
	game.gamestart();

}

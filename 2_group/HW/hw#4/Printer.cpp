#include <iostream>
#include <string>
using namespace std;

class Printer {
    string model, manufacturer;
    int printedCount = 0, availableCount;

protected:
    Printer(string model, string manufacturer, int availableCount)
        : model(model), manufacturer(manufacturer), availableCount(availableCount) {}

    bool print(int pages) {
        printedCount = pages;
        if (availableCount >= printedCount) {
            availableCount -= printedCount;
            return true;
        }
        else {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
            return false;
        }
    }

    string getModel() { return model; }
    string getManu() { return manufacturer; }
    int getAvail() { return availableCount; }
};

class InkPrinter : public Printer {
    int availableInk;

public:
    InkPrinter(string model, string manufacturer, int availableCount, int availableInk)
        : Printer(model, manufacturer, availableCount), availableInk(availableInk) {}

    bool inkPrinter(int pages) {
        if (!print(pages))
            return false;
        if (availableInk < pages) {
            cout << "잉크가 부족하여 프린트 할 수 없습니다.\n";
            return false;
        }
        availableInk -= pages;
        return true;
    }

    void show() {
        cout << getModel() << "\t," << getManu() << "\t,남은 종이 " << getAvail() << "장\t,남은 잉크 " << availableInk << endl;
    }
};

class LaserPrinter : public Printer {
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
        : Printer(model, manufacturer, availableCount), availableToner(availableToner) {}

    bool laserPrint(int pages) {
        if (!print(pages))
            return false;
        if (availableToner < pages) {
            cout << "토너가 부족하여 프린트 할 수 없습니다.\n";
            return false;
        }
        availableToner -= pages;
        return true;
    }

    void show() {
        cout << getModel() << "\t," << getManu() << "\t,남은 종이 " << getAvail() << "장\t,남은 토너 " << availableToner << endl;
    }
};

int main() {
    int pnum, pages;
    char yon;
    InkPrinter* inkjet = new InkPrinter("Officejet V40", "Hp", 5, 10);
    LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

    cout << "현재 작동중인 2 대의 프린터는 아래와 같다\n";
    cout << "잉크젯 : ";
    inkjet->show();
    cout << "레이저 : ";
    laser->show();
    cout << endl;

    while (true) {
        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> pnum >> pages;

        if (pnum == 1) {
            if (inkjet->inkPrinter(pages))
                cout << "프린트 하였습니다.\n";
        }
        else if (pnum == 2) {
            if (laser->laserPrint(pages))
                cout << "프린트 하였습니다.\n";
        }
        else {
            cout << "프린터를 잘못 선택하셨습니다.\n";
        }

        inkjet->show();
        laser->show();

        while (true) {
            cout << "계속 프린트 하시겠습니까(y/n)>>";
            cin >> yon;
            cout << endl;
            if (yon == 'n') {
                delete inkjet;
                delete laser;
                return 0;
            }
            else if (yon == 'y') {
                break;
            }
            else {
                cout << "잘못 입력하셨습니다.\n";
            }
        }
    }
}

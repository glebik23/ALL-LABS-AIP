#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    void display() {
        cout << day << " - " << month << " - " << year << endl;
    }
};

class TMoney {
private:
    double Fif;
public:
    TMoney(double a) {
        Fif = a;
    }
    void display() {
        cout << "3.Summa: " << Fif << endl;
    }
};

class Account {
private:
    string name;
    Date kr;
    TMoney N;
public:
    Account(string n, Date date, TMoney b) : name(n), kr(date), N(b) {}
    void display() {
        cout << "1.Name: " << name << endl;
        cout << "2.Data: ";
        kr.display();
        N.display();
    }
};

int main() {
    setlocale(0, "Ru");
    Date date1(12, 9, 2020);
    TMoney b(1298);
    Account a("Фрося", date1, b);
    a.display();

    return 0;
}
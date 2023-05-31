#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    int getYear() const {
        return year;
    }

    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }
    string toString() {
        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }
};

class Goods {
private:
    string name;
    double price;
    int kol_wo;
    int DoklNumber;
    Date date;
public:

    Goods(string name, Date date, double price, int kol_wo, int DoklNumber) :date(date)
    {
        this->name = name;
        this->price = price;
        this->kol_wo = kol_wo;
        this->DoklNumber = DoklNumber;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void UwelichKol_wo(int amount) {
        this->kol_wo += amount;
    }

    void PonizKol_wo(int amount) {
        this->kol_wo -= amount;
    }

    double calculateCost() {
        return price * kol_wo;
    }

    string toString() {
        return "Наименование товара: " + name + "\nДата: " + date.toString() + "\nЦена: " + to_string(price) + "\nКоличество: " + to_string(kol_wo) + "\nНомер докладной " + to_string(DoklNumber);
    }

    string toStringO() {
        return "Цена(измененная): " + to_string(calculateCost());
    }
};

int main() {
    setlocale(0, "Ru");
    Goods goods("Apple", Date(2021, 10, 1), 1.5, 100, 12345);

    cout << goods.toString() << endl;
    cout << goods.toStringO() << endl;

    goods.setPrice(2.0);
    goods.UwelichKol_wo(50);

    cout << goods.toString() << endl;
    cout << goods.toStringO() << endl;

    goods.PonizKol_wo(75);

    cout << goods.toString() << endl;
    cout << goods.toStringO() << endl;

    return 0;
}

#include <iostream>

using namespace std;

class Double {
private:
    int first; // Целая часть
    int second; // Дробная часть
public:
    Double() { // инициализирует значения нулями
        first = 0;
        second = 0;
    }
    Double(int w, int f) { // передаем целую и дробную части
        first = w;
        second = f;
    }
    void read() { // ввод формата "целая часть и дробная часть"
        cin >> first >> second;
    }
    int display() { // вывод "целая часть . дробная часть"
        cout << first << "." << second;
        return 0;
    }
    Double operator + (const Double& d) { // сложения двух объектов класса
        int w_sum = first + d.first; // Сумма целых частей
        int f_sum = second + d.second; // Сумма дробных частей
        if (f_sum > 99) { // Если сумма дробных частей больше или равна 1, то переносим единицу в целую часть
            w_sum++;
            f_sum -= 100;
        }
        return Double(w_sum, f_sum);
    }
    Double operator - (const Double& d) { // вычитания двух объектов класса
        int w_diff = first - d.first; // Разность целых частей
        int f_diff = second - d.second; // Разность дробных частей
        if (f_diff < 0) { // Если разность дробных частей меньше нуля, то занимаем единицу из целой части
            w_diff--;
            f_diff += 100;
        }
        return Double(w_diff, f_diff);
    }
    Double power(int exp) { // Метод возведения в произвольную степень
        int w_pow = pow(first, exp); // Возводим целую часть в степень
        int f_pow = pow(second, exp); // Возводим дробную часть в степень
        if (f_pow > 99) { // Если дробная часть получилась больше или равна 1, то переносим единицу в целую часть
            w_pow += f_pow / 100;
            f_pow %= 100;
        }
        return Double(w_pow, f_pow);
    }
};

int main() {
    setlocale(0, "Ru");
    Double d1, d2;
    cout << "Введите первое число: ";
    d1.read();
    cout << "Введите второе число: ";
    d2.read();
    Double d_sum = d1 + d2; // Сумма двух чисел
    Double d_diff = d1 - d2; // Разность двух чисел
    cout << "Сумма: ";
    d_sum.display();
    cout << endl;
    cout << "Разность: ";
    d_diff.display();
    cout << endl;
    int pow_exp;
    cout << "Введите степень: ";
    cin >> pow_exp;
    Double d_pow = d1.power(pow_exp); // Возведение числа в степень
    cout << d1.display() << "^" << pow_exp << " = ";
    d_pow.display();

    return 0;
}
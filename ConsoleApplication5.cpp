#include <iostream>
#include <cmath>

using namespace std;

class Tetrahedron {
private:
    double a; // ребро правильного тетраэдра
    double plotnost; // плотность материала
public:
    Tetrahedron(double a, double plotnost) {
        this->a = a;
        this->plotnost = plotnost;
    }
    double getS_osn() {
        return sqrt(3) * pow(a, 2) / 4;
    }
    double getS_bok() {
        return 3 * (a * 2 * sqrt(3)) * 4;
    }
    double getS_poln() {
        return 2 * (sqrt(3) * pow(a, 2) / 4) + 3 * (a * 2 * sqrt(3)) * 4;
    }
    double getObjem() {
        return pow(a, 3) * sqrt(2) / 12;
    }
    double getWes() {
        return getObjem() * plotnost;
    }
};

int main() {
    setlocale(0, "Ru");
    double a = 5; // ребро правильного тетраэдра
    double ironPlotnost = 7.8; // плотность железа
    double copperPlotnost = 8.96; // плотность меди

    Tetrahedron ironTetrahedron(a, ironPlotnost);
    Tetrahedron copperTetrahedron(a, copperPlotnost);

    cout << "Железный тетраэдр :" << endl;
    cout << "площадь основания: " << ironTetrahedron.getS_osn() << endl;
    cout << "Площадь боковой поверхности: " << ironTetrahedron.getS_bok() << endl;
    cout << "Полная площадь: " << ironTetrahedron.getS_poln() << endl;
    cout << "Объем: " << ironTetrahedron.getObjem() << endl;
    cout << "Вес: " << ironTetrahedron.getWes() << endl;

    cout << endl;

    cout << "Медный тетраэдр:" << endl;
    cout << "площадь основания: " << copperTetrahedron.getS_osn() << endl;
    cout << "Площадь боковой поверхности: " << copperTetrahedron.getS_bok() << endl;
    cout << "Полная площадь: " << copperTetrahedron.getS_poln() << endl;
    cout << "Объем: " << copperTetrahedron.getObjem() << endl;
    cout << "Вес: " << copperTetrahedron.getWes() << endl;

    cout << endl;

    double ironWes = ironTetrahedron.getWes();
    double copperWes = copperTetrahedron.getWes();
    double Soot_wes = ironWes / copperWes;

    cout << "Соотношение веса: " << Soot_wes << endl;

    return 0;
}
//Realizar un funcion que dados 2 pares de coordenadas, correspondientes al inicio y fin de dos lineas.
//programa 1
#include <iostream>

using namespace std;

struct Punto {
    float x, y;
};

float productoCruzado(Punto a, Punto b) {
    return a.x * b.y - a.y * b.x;
}

bool sonParalelas(Punto a1, Punto a2, Punto b1, Punto b2) {
    return (a2.y - a1.y) * (b2.x - b1.x) == (b2.y - b1.y) * (a2.x - a1.x);
}

int interseccionLineas(Punto a1, Punto a2, Punto b1, Punto b2) {
    if (sonParalelas(a1, a2, b1, b2)) {
        return 0; 
    }

    Punto d1 = {a2.x - a1.x, a2.y - a1.y};
    Punto d2 = {b2.x - b1.x, b2.y - b1.y};
    Punto delta = {b1.x - a1.x, b1.y - a1.y};

    float cruz1 = productoCruzado(d1, d2);

    float s = productoCruzado(delta, d2) / cruz1;
    float t = productoCruzado(delta, d1) / cruz1;

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
        return 1; 
    }

    return -1; 
}

int main() {
    Punto a1, a2, b1, b2;
    cout << "Ingrese las coordenadas de la primera linea (x1 y1 x2 y2): ";
    cin >> a1.x >> a1.y >> a2.x >> a2.y;
    cout << "Ingrese las coordenadas de la segunda linea (x1 y1 x2 y2): ";
    cin >> b1.x >> b1.y >> b2.x >> b2.y;

    int resultado = interseccionLineas(a1, a2, b1, b2);
    cout << resultado << endl;

    cout << "1: Las lineas se cruzan." << endl;
    cout << "0: Las lineas son paralelas." << endl;
    cout << "-1: Las lineas no se cruzan ni son paralelas." << endl;

    return 0;
}

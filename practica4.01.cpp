//programa 2 sobrecarga

#include <iostream>
#include <cmath>

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

bool sonPerpendiculares(Punto a1, Punto a2, Punto b1, Punto b2) {
    Punto d1 = {a2.x - a1.x, a2.y - a1.y};
    Punto d2 = {b2.x - b1.x, b2.y - b1.y};
    float dotProduct = d1.x * d2.x + d1.y * d2.y;
    return dotProduct == 0;
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

int interseccionLineas(Punto a1, Punto a2, Punto b1, Punto b2, bool perpendiculares) {
    if (perpendiculares) {
        if (sonParalelas(a1, a2, b1, b2)) {
            return 0; 
        } else if (sonPerpendiculares(a1, a2, b1, b2)) {
            return 1; 
        } else {
            return -1; 
        }
    } else {
        return interseccionLineas(a1, a2, b1, b2);
    }
}

int main() {
    Punto a1, a2, b1, b2;
    bool perpendiculares;

    cout << "Ingrese las coordenadas de la primera linea (x1 y1 x2 y2): ";
    cin >> a1.x >> a1.y >> a2.x >> a2.y;
    cout << "Ingrese las coordenadas de la segunda linea (x1 y1 x2 y2): ";
    cin >> b1.x >> b1.y >> b2.x >> b2.y;
    cout << "Desea comprobar si son perpendiculares? (1 para si, 0 para no): ";
    cin >> perpendiculares;

    int resultado = interseccionLineas(a1, a2, b1, b2, perpendiculares);
    cout << resultado << endl;

    cout << "1: Son perpendiculares (si se comprobo) o se cruzan (si no se comprobo)." << endl;
    cout << "0: Son paralelas." << endl;
    cout << "-1: No son paralelas ni se cruzan (si no se comprobo) o no son paralelas ni perpendiculares (si se comprobo)." << endl;

    return 0;
}

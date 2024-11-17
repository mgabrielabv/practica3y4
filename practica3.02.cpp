#include <iostream>

using namespace std;

struct Punto {
    int x, y;
};

double calcularRaizCuadrada(double numero) {
    double raiz = numero / 2;
    double temp = 0;

    while (raiz != temp) {
        temp = raiz;
        raiz = (numero / temp + temp) / 2;
    }

    return raiz;
}

double calcularDistancia(const Punto& a, const Punto& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return calcularRaizCuadrada(dx * dx + dy * dy);
}

bool estaEnCuadrante(const Punto& p, int x_min, int x_max, int y_min, int y_max) {
    return p.x >= x_min && p.x <= x_max && p.y >= y_min && p.y <= y_max;
}

int main() {
    int x_min = 0, x_max = 10, y_min = 0, y_max = 10;
    Punto puntos[] = { {2, 3}, {5, 5}, {8, 2}, {3, 9}, {1, 1} };
    int num_puntos = sizeof(puntos) / sizeof(puntos[0]);
    double distanciaMax = 0;
    for (int i = 0; i < num_puntos; ++i) {
        for (int j = i + 1; j < num_puntos; ++j) {
            if (estaEnCuadrante(puntos[i], x_min, x_max, y_min, y_max) &&
                estaEnCuadrante(puntos[j], x_min, x_max, y_min, y_max)) {
                double distancia = calcularDistancia(puntos[i], puntos[j]);
                if (distancia > distanciaMax) {
                    distanciaMax = distancia;
                }
            }
        }
    }

    cout << "La distancia maxima entre dos puntos dentro del cuadrante es: " << distanciaMax << endl;

    int indicePunto = 0; 
    cout << "Distancias desde el punto (" << puntos[indicePunto].x << ", " << puntos[indicePunto].y << ") a cada punto del arreglo:" << endl;
    for (int i = 0; i < num_puntos; ++i) {
        double distancia = calcularDistancia(puntos[indicePunto], puntos[i]);
        cout << "A punto (" << puntos[i].x << ", " << puntos[i].y << "): " << distancia << endl;
    }

    return 0;
}

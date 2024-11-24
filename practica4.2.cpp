#include <iostream>
#include <cmath>

using namespace std;

struct Punto {
    float x, y;
};

float anguloEntreLineas(Punto a1, Punto a2, Punto b1, Punto b2) {
    float dx1 = a2.x - a1.x;
    float dy1 = a2.y - a1.y;
    float dx2 = b2.x - b1.x;
    float dy2 = b2.y - b1.y;

    float productoPunto = dx1 * dx2 + dy1 * dy2;
    float magnitud1 = sqrt(dx1 * dx1 + dy1 * dy1);
    float magnitud2 = sqrt(dx2 * dx2 + dy2 * dy2);

    float cosAngulo = productoPunto / (magnitud1 * magnitud2);
    return acos(cosAngulo); 
}

float convertirAGrados(float radianes) {
    return radianes * (180.0 / M_PI);
}

float anguloInterseccion(Punto a1, Punto a2, Punto b1, Punto b2, bool enGrados = false) {
    float angulo = anguloEntreLineas(a1, a2, b1, b2);
    if (enGrados) {
        return convertirAGrados(angulo);
    }
    return angulo;
}

int main() {
    Punto a1, a2, b1, b2;
    bool enGrados;

    cout << "Ingrese las coordenadas de la primera linea (x1 y1 x2 y2): ";
    cin >> a1.x >> a1.y >> a2.x >> a2.y;
    cout << "Ingrese las coordenadas de la segunda linea (x1 y1 x2 y2): ";
    cin >> b1.x >> b1.y >> b2.x >> b2.y;
    cout << "Desea el angulo en grados? (1 para si, 0 para no): ";
    cin >> enGrados;

    float angulo = anguloInterseccion(a1, a2, b1, b2, enGrados);
    if (enGrados) {
        cout << "El angulo en grados es: " << angulo << endl;
    } else {
        cout << "El angulo en radianes es: " << angulo << endl;
    }

    return 0;
}

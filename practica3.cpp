#include <iostream>
#include <iomanip>

using namespace std;

struct Coordenada {
    int x, y;
};

string determinarcuadrante(int x, int y) {
    if (x > 0 && y > 0) {
        return "Primer cuadrante";
    } else if (x < 0 && y > 0) {
        return "Segundo cuadrante";
    } else if (x < 0 && y < 0) {
        return "Tercer cuadrante";
    } else if (x > 0 && y < 0) {
        return "Cuarto cuadrante";
    } else if (x == 0 && y != 0) {
        return "Sobre el eje Y";
    } else if (y == 0 && x != 0) {
        return "Sobre el eje X";
    } else {
        return "En el origen";
    }
}

bool enmismaLinea(const Coordenada& a, const Coordenada& b, const Coordenada& c) {
    return (b.y - a.y) * (c.x - a.x) == (c.y - a.y) * (b.x - a.x);
}

string ecuaciondelalinea(const Coordenada& a, const Coordenada& b) {
    int m_num = b.y - a.y;
    int m_den = b.x - a.x;
    double m = static_cast<double>(m_num) / m_den;
    double b_intercept = a.y - m * a.x;
    ostringstream oss;
    oss << fixed << setprecision(2) << "y = " << m << "x + " << b_intercept;
    return oss.str();
}

int main() {
    Coordenada coordenadas[] = { {1, 2}, {2, 4}, {3, 6}, {5, -6}, {0, 4}, {4, 0}, {0, 0} };
    int num_coordenadas = sizeof(coordenadas) / sizeof(coordenadas[0]);

    for (int i = 0; i < num_coordenadas; ++i) {
        string cuadrante = determinarcuadrante(coordenadas[i].x, coordenadas[i].y);
        cout << "La coordenada (" << coordenadas[i].x << ", " << coordenadas[i].y << ") esta en el " << cuadrante << ".\n";
    }


    bool encontreLinea = false;
    for (int i = 0; i < num_coordenadas; ++i) {
        for (int j = i + 1; j < num_coordenadas; ++j) {
            for (int k = j + 1; k < num_coordenadas; ++k) {
                if (enmismaLinea(coordenadas[i], coordenadas[j], coordenadas[k])) {
                    cout << "Las coordenadas (" << coordenadas[i].x << ", " << coordenadas[i].y << "), ("
                         << coordenadas[j].x << ", " << coordenadas[j].y << ") y ("
                         << coordenadas[k].x << ", " << coordenadas[k].y << ") estan en la misma linea.\n";
                    cout << "Ecuacion de la linea: " << ecuaciondelalinea(coordenadas[i], coordenadas[j]) << "\n";
                    encontreLinea = true;
                }
            }
        }
    }

    if (!encontreLinea) {
        cout << "No se encontraron coordenadas en la misma linea.\n";
    }

    return 0;
}

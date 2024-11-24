//programa sobre la funcion 4
#include <iostream>
#include <string>

using namespace std;

int contador = 0;

void agregarPolloFrito() {
    contador++;
    cout << "Pollo frito agregado al pedido.\n";
}

void agregarOtracosa() {
    string cosa;
    cout << "Ingrese el nombre de lo que desea agregar: ";
    cin.ignore();
    getline(cin, cosa);
    contador++;
    cout <<cosa << " agregado al pedido.\n";
}

int obtenerCantidadcosas() {
    return contador;
}

int main() {
    char seguirPollo, seguirOtro;

    do {
        agregarPolloFrito();
        cout << "Desea agregar mas pollo frito? (s/n): ";
        cin >> seguirPollo;

        if (seguirPollo == 'n' || seguirPollo == 'N') {
            cout << "Desea agregar otra cosa al pedido? (s/n): ";
            cin >> seguirOtro;

            while (seguirOtro == 's' || seguirOtro == 'S') {
                agregarOtracosa();
                cout << "Desea agregar otra cosa al pedido? (s/n): ";
                cin >> seguirOtro;
            }
        }
    } while (seguirPollo == 's' || seguirPollo == 'S');

    int cantidadItems = obtenerCantidadcosas();
    cout << "Cantidad de cosas en el pedido: " << cantidadItems << endl;

    return 0;
}

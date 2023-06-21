#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    string nombre;
    cout << "Ingrese el nombre del archivo a buscar: ";
    cin >> nombre;
    nombre += ".txt";

    try {
        ifstream archivo(nombre);
        if (!archivo.is_open()) {
            throw runtime_error("Error: El archivo no existe.");
        }

        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

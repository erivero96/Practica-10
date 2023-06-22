#include <iostream>
using namespace std;

double dividir(double numerador, double denominador) {
    if (denominador == 0) {
        throw "Error: División por cero.";
    }
    return numerador / denominador;
}

int main() {
    double numerador, denominador;
    cout << "Ingrese el numerador: ";
    cin >> numerador;
    cout << "Ingrese el denominador: ";
    cin >> denominador;

    try {
        double resultado = dividir(numerador, denominador);
        cout << "El resultado de la división es: " << resultado << endl;
    } catch (const char* mensaje) {
        cout << "Excepción capturada: " << mensaje << endl;
    }

    return 0;
}

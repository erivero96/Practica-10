#include <iostream>
#include <stdexcept>

using namespace std;

int divide(int numerador, int denominador) {
    if (denominador == 0) {
        throw runtime_error("No se puede dividir por cero");
    }

    return numerador / denominador;
}

int main() {
    try {
        int resultado1 = divide(10, 2);
        cout<<"Resultado 1: "<<resultado1<<endl;

        int resultado2 = divide(5, 0); 
        cout<<"Resultado 2: " << resultado2<<endl; 
    } catch (const runtime_error& error) {
        cout<<"Error detectado: "<<error.what()<<endl;
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    string direccion;

    Persona() : nombre(" "), edad(0), direccion(" "){};

    Persona(const string& nombre, int edad, const string& direccion)
        : nombre(nombre), edad(edad), direccion(direccion) {}

    // Función para serializar Persona en un archivo binario
    void serializar(const string& archivo) const {
        ofstream ofs(archivo, ios::binary);
        if (ofs) {
            ofs.write(reinterpret_cast<const char*>(this), sizeof(Persona));
            ofs.close();
        }
    }

    // Función para deserializar Persona desde un archivo binario
    static Persona deserializar(const string& archivo) {
        Persona persona;
        ifstream ifs(archivo, ios::binary);
        if (ifs) {
            ifs.read(reinterpret_cast<char*>(&persona), sizeof(Persona));
            ifs.close();
        }
        return persona;
    }
};

int main() {
    Persona persona("Marcos Lopez", 22, "Calle 231");

    // Serializar 
    persona.serializar("persona.bin");

    // Deserializar 
    Persona personaDeserializada = Persona::deserializar("persona.bin");

    cout << "Nombre: " << personaDeserializada.nombre << endl;
    cout << "Edad: " << personaDeserializada.edad << endl;
    cout << "Dirección: " << personaDeserializada.direccion << endl;

    return 0;
}

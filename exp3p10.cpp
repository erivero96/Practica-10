#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Estructura para almacenar los datos de un producto(similar a una clase)
struct Producto {
	string nombre;
	string descripcion;
	double precio;
};

// Funcion para buscar un producto por su nombre en el archivo principal
void buscarProducto(const string& nombreProducto) {
	ifstream archivo("productos.csv"); // Abre el archivo en modo lectura
	if (archivo) {
		string linea;
		while (getline(archivo, linea)) {
			
			// Separa la línea en campos utilizando comas como separadores al ser un csv
			vector<string> campos;
			size_t pos = 0;
			while ((pos = linea.find(',')) != string::npos) {
				campos.push_back(linea.substr(0, pos));
				linea.erase(0, pos + 1);
			}
			campos.push_back(linea);
			
			// Verifica si el nombre del producto coincide
			if (campos[0] == nombreProducto) {
				// Muestra los datos del producto encontrado
				cout << "Producto encontrado!\n";
				cout << "Nombre: " << campos[0] << "\n";
				cout << "Descripcion: " << campos[1] << "\n";
				cout << "Precio: S/. " << campos[2] << "\n";
				archivo.close();
				return;
			}
		}
		cout << "PProducto no encontrado.\n";
	} else {
		cerr << "Error al abrir el archivo.\n";
	}
	archivo.close();
}

int main() {
	// Implementacion
	string nombreProducto;
	cout << "Ingrese el nombre del producto a buscar: ";
	getline(cin, nombreProducto);
	buscarProducto(nombreProducto);
	
	return 0;
}

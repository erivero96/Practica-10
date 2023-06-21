#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto() { }
    Producto(string nombre, double precio, int cantidad) {
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
    }

    void mostrarInformacion() {
        cout << "-------------------------------------------------\n";
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: S/." << precio << endl;
        cout << "Stock: " << cantidad << " unidades" << endl;
        cout << "-------------------------------------------------\n";
    }
    ~Producto () { }

    void actualizarInformacion() {
        cout << "-------------------------------------------------\n";
        cout << "Actualizar Informacion de " << nombre << endl;
        cout << "Nombre: "; cin >> nombre;
        cout << "Precio: "; cin >> precio;
        cout << "Stock: "; cin >> cantidad;
        cout << "-------------------------------------------------\n";
    }

    friend class Inventario;
    friend class Tienda;
};

class Inventario {
private:
    vector<Producto> productos;

public:
    Inventario() { }

    void cargarDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);

        if (!archivo) {
            cout << "No se pudo abrir el archivo" << endl;
            return;
        }

        productos.clear();

        string nombre;
        double precio;
        int cantidad;

        while (archivo >> nombre >> precio >> cantidad) {
            Producto p(nombre, precio, cantidad);
            productos.push_back(p);
        }

        archivo.close();
    }

    void guardarEnArchivo(const string& nombreArchivo) {
        ofstream archivo(nombreArchivo);

        if (!archivo) {
            cout << "No se pudo crear el archivo de inventario." << endl;
            return;
        }

        for (const auto& producto : productos) {
            archivo << producto.nombre << " " << producto.precio << " " << producto.cantidad << endl;
        }

        archivo.close();
    }

    Inventario& agregarProducto(Producto& x) {
        productos.push_back(x);
        return *this;
    }

    void informeProductos() {
        cout << "--------------------Productos--------------------\n";
        for (int i = 0; i < productos.size(); i++) {
            productos[i].mostrarInformacion();
        }
    }

    Producto* buscarProducto(const string& nombre) {
        for (auto& producto : productos) {
            if (producto.nombre == nombre) {
                return &producto;
            }
        }
        return nullptr;
    }
};

class Tienda {
private:
    Inventario& inventario;

public:
    Tienda(Inventario& inventario_) : inventario(inventario_) {}

    void venta() {
        string nombre;
        int cantidad;
        cout << "Ingrese el nombre del producto que desea comprar: ";
        cin >> nombre;
        Producto* producto = inventario.buscarProducto(nombre);

        if (producto != nullptr) {
            cout << "Ingrese la cantidad que desea comprar: ";
            cin >> cantidad;

            if (cantidad <= producto->cantidad) {
                producto->cantidad -= cantidad;
                cout << "Su compra exitosa" << endl;
            } 
            else {
                cout << "No hay suficiente stock del producto" << endl;
                }
            } 
            else 
        {
        cout << "No se encontró el producto" << endl;
        }   
    }
};

int main() {
Inventario inventario;
Producto p1("Jabon", 4.5, 100);
Producto p2("Shampoo", 10.5, 200);
Tienda tienda(inventario);
inventario.cargarDesdeArchivo("inventario.txt");

p1.actualizarInformacion();
inventario.agregarProducto(p1).agregarProducto(p2);
inventario.guardarEnArchivo("inventario.txt");

inventario.informeProductos();
tienda.venta();

return 0;
}

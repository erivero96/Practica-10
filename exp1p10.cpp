#include <iostream>
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
            this-> precio = precio;
            this->cantidad = cantidad;
        }

        void mostrarInformacion() {
                cout << "-------------------------------------------------\n";
                cout << "Nombre: " << nombre << endl;
                cout << "Precio: S/." << precio << endl;
                cout << "Stock: " << cantidad <<" unidades" << endl;
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
        vector <Producto> productos;

    public:
        Inventario() { }
        Inventario& agregarProducto(Producto& x) {
            productos.push_back(x);
            return *this;
        }

        void informeProductos() {
            cout << "--------------------Productos--------------------\n";
            for(int i = 0; i < productos.size(); i++)
            {
                productos[i].mostrarInformacion();
            }
        }
        friend class Tienda;
};

class Tienda{
    private:
        Inventario& inventario;
    
    public:
        Tienda(Inventario &inventario_) : inventario(inventario_) {}

        void venta() {
            string nombre;
            int cantidad;
            cout << "Ingrese el nombre del producto que desea comprar: ";
            cin >> nombre;
            for(int i=0; i <inventario.productos.size(); i++) {
                if (inventario.productos[i].nombre == nombre) {
                    cout << "Ingrese la cantidad que desea comprar: " ;
                    cin >> cantidad;
                    if(cantidad <= inventario.productos[i].cantidad) {
                        inventario.productos[i].cantidad -= cantidad;
                        cout << "Su compra a sido exitosa" << endl;
                        return;
                    }

                    else {
                        cout << "No hay suficiente stock del producto" << endl;
                        return;
                    }
                }
            }
            cout << "No se encontro el producto" << endl;
        }



};

int main() {
    Inventario inventario;
    Producto p1("Jabon", 4.5, 100);
    Producto p2("Shampoo", 10.5, 200);
    Tienda tienda(inventario);

    p1.actualizarInformacion();
    inventario.agregarProducto(p1).agregarProducto(p2);
    inventario.informeProductos();
    tienda.venta();
    
    return 69;
}
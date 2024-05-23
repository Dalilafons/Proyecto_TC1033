#ifndef TIENDA_H_ //Bibliotecas
#define TIENDA_H_ //Bibliotecas

#include <iostream>
#include <string>
#include "producto.h"

class Inventario
{
    private:
        Producto* producto[10];// Cree un arreglo de 100 punteros del tipo Producto.
        int numProductos;
    public:
        Inventario();
        void agregarProducto(Producto* p);
        void eliminarProducto(int id);
        void eliminarProducto(std::string nombre);
        Producto* buscarProducto(int id);
        void mostrarInventario();
        Producto** getProductos();//------------------------------------------------------------------------------------------------------
        int getNumProductos();//----------------------------------------------------------------------------------------------------------
};
//Metodos inventario:
Inventario::Inventario(): numProductos(0){} //Inicializa numProductos en 0.
void Inventario::agregarProducto(Producto* p) //Recibe un puntero a un objeto de tipo Producto.
    {
        if (numProductos < 10)
            {
                producto[numProductos++] = p; //Agrega a productos el puntero p.
            }
        else
            {
                std::cout << "Inventario lleno" << std::endl;
            }
    }
void Inventario::eliminarProducto(int id)
    {
        for (int i = 0; i < numProductos; i++) //Recorre el arreglo de productos.
           {
                if (producto[i]->getId()== id)// Verifica si el identificador actual es aigual al id del producto, lo encuentra.
                {
                    for(int a = i; a < numProductos -1; ++a)
                    {
                        producto[a] = producto[a+1];
                    }
                    --numProductos;
                    return;// Sale de la funcion.
                }
           }
        std::cout << "Producto no encontrado" << std::endl;
    }
// Sobrecarga de eliminarProducto para eliminar por nombre:
void Inventario::eliminarProducto(std::string nombre) 
    {
        for (int i = 0; i < numProductos; i++) 
            {
                if (producto[i]->getNombre() == nombre) 
                {
                    for (int j = i; j < numProductos - 1; ++j) 
                    {
                        producto[j] = producto[j + 1];
                    }
                --numProductos;
                return;
            }
    }
    std::cout << "Producto no encontrado" << std::endl;
    }
Producto* Inventario::buscarProducto(int id)
        {
            for (int i = 0; i < numProductos; i++)
            {
                if (producto[i]->getId()==id)
                {
                    std::cout << "El producto encontrado es: " << producto[i]->getNombre() << std::endl;
                    return producto[i];
                }
            }    
            std::cout << "Producto con id:" << id << "no encontrado."<<std::endl;    
            return nullptr;
        }
void Inventario::mostrarInventario()
        {
            std::cout<<"Informacion del inventario:"<<std::endl;
            for(int i = 0; i < numProductos;i++ )
            {
                producto[i]->infoProducto();
            }
        }
Producto** Inventario::getProductos()
        {
            return producto;
        }
int Inventario::getNumProductos()
        {
            return numProductos;
        }

class Venta
{
    private:
        Producto* productosVendidos[100];// Cree un arreglo de 100 punteros del tipo Producto.
        double total;
        int numVentas;
    public:
        Venta();
        void agregarProductoVenta(Producto* p_vendido);
        double calcularTotal();
        double calcularTotal(double descuento);
        void mostrarDetallesVenta();
};
//Metodos venta:
Venta::Venta(): numVentas(0), total(0.0){}//Inicializa ventas en 0 y total.
void Venta::agregarProductoVenta(Producto* p_vendido)
        {
            if (numVentas < 10)
            {
                productosVendidos[numVentas++] = p_vendido; //Agrega a productos el puntero p.
            }
            else
            {
                std::cout << "Ventas completadas." << std::endl;
            }
        }
double Venta::calcularTotal()
        {
            total = 0.0;
            for (int i = 0; i < numVentas;i++)
            {
                total += productosVendidos[i] ->calcularPrecio() * productosVendidos[i]->getCantidad();
            }
            return total;
        }
//Sobrecarga de calcularTotal para aplicar un descuento adicional:
double Venta::calcularTotal(double descuento) 
        {
            total = 0.0;
            for (int i = 0; i < numVentas; i++) 
            {
                total += productosVendidos[i]->calcularPrecio() * productosVendidos[i]->getCantidad();
            }
            return total * (1 - descuento / 100);
        }
void Venta::mostrarDetallesVenta()
        {
            std::cout<<"Informacion de las ventas:"<<std::endl;
            for(int i = 0; i < numVentas;i++ )
            {
                productosVendidos[i]->infoProducto();
            }
            std::cout << "El total de la venta es: " << calcularTotal() <<std::endl;
        }

class Tienda
{
private:
    Inventario inventario;
    Venta ventaActual;
public:
    Tienda();
    void crearInventario();
    void crearVenta();
    void mostrarInformacionInventario();
    void mostrarInformacionVenta();
};
//Metodos Tienda:
Tienda::Tienda(){}
void Tienda::crearInventario()
    {
        char respuesta;
        std::cout << "Quieres crear un inventario? (s/n): ";
        std::cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S')
        {
            int numProductos;
            std::cout << "Cuantos productos quieres agregar?: ";
            std::cin >> numProductos;

            for (int i = 0; i < numProductos; ++i)
            {
                int id, cantidad, tipoProducto;
                double precio, tasaImpuesto;
                std::string nombre;
                std::cout << "Agregar producto " << i + 1 << ":" << std::endl;
                std::cout << "ID: ";
                std::cin >> id;
                std::cout << "Nombre: ";
                std::cin.ignore(); // Ignorar el salto de línea anterior
                std::getline(std::cin, nombre);
                std::cout << "Precio: ";
                std::cin >> precio;
                std::cout << "Cantidad: ";
                std::cin >> cantidad;
                std::cout << "Tipo de producto (1 - Alimento, 2 - Articulo): ";
                std::cin >> tipoProducto;

                if (tipoProducto == 1)
                {
                    inventario.agregarProducto(new Alimento(id, nombre, precio, cantidad));
                }
                else if (tipoProducto == 2)
                {
                    std::cout << "Tasa de Impuesto (%): ";
                    std::cin >> tasaImpuesto;
                    inventario.agregarProducto(new Articulo(id, nombre, precio, cantidad, tasaImpuesto));
                }
                else
                {
                    std::cout << "Tipo de producto no valido." << std::endl;
                }
            }
            std::cout << "Inventario creado." << std::endl;
        }
        else
        {
            std::cout << "No se creo el inventario." << std::endl;
        }

    }
void Tienda::crearVenta()
    {
        ventaActual = Venta(); // Resetea la venta actual
        int numProductos;
        std::cout << "Cuantos productos quieres agregar a la venta?: ";
        std::cin >> numProductos;

        for (int i = 0; i < numProductos; ++i)
        {
            int id, cantidad;
            std::cout << "Agregar producto " << i + 1 << " a la venta:" << std::endl;
            std::cout << "ID: ";
            std::cin >> id;
            std::cout << "Cantidad: ";
            std::cin >> cantidad;
            Producto* producto = inventario.buscarProducto(id);
            if (producto != nullptr)
            {
                ventaActual.agregarProductoVenta(producto);
                std::cout << "Producto agregado a la venta." << std::endl;
            }
            else
            {
                std::cout << "Producto no encontrado en el inventario." << std::endl;
            }
        }
        std::cout << "Venta creada." << std::endl;
    }
void Tienda::mostrarInformacionInventario()
    {
        inventario.mostrarInventario();
    }
void Tienda::mostrarInformacionVenta() 
    {
        ventaActual.mostrarDetallesVenta();
    }
#endif
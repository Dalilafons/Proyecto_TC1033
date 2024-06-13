/*
 *
 * Proyecto Tienda clase Tienda 1
 * Dalila Fonseca Maya
 * A01711722
 * 06/06/2024
 * 
 * Esta clase define un objeto de tipo Tienda que gestiona el inventario 
 * y las ventas.Permite crear y agregar productos al inventario, 
 * realizar ventas de productos y mostrar la información tanto del 
 * inventario como de las ventas realizadas.
 * Utiliza polimorfismo para manejar productos de diferentes tipos.
 * Esta clase es parte del proyecto Tienda.
 */

#ifndef TIENDA_H_ 
#define TIENDA_H_ 

#include <iostream>

#include <string>

// Bibliotecas con mis objetos a usa:
#include "producto.h"
#include "inventario.h"
#include "venta.h"

// Declaración de la clase Tienda
class Tienda
{
    // Variables de instancia de Tienda
    private:
        Inventario inventario;
        Venta ventaActual;
    
    // Métodos de Tienda
    public:
        Tienda();
        void crearInventario();
        void crearVenta();
        void mostrarInformacionInventario();
        void mostrarInformacionVenta();
};

/**
 * Constructor por defecto de Tienda.
 * 
 * @param
 * @return
 */
Tienda::Tienda(){}

/**
 * crearInventario crea un inventario de productos.
 *
 * Solicita al usuario la cantidad de productos y 
 * los detalles de cada producto, y los agrega al inventario.
 * 
 * @param
 * @return
 */
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
                inventario.agregarProducto(new Alimento(id, nombre, 
                precio, cantidad));
                }
                else if (tipoProducto == 2)
                {
                    std::cout << "Tasa de Impuesto (%): ";
                    std::cin >> tasaImpuesto;
                    inventario.agregarProducto(new Articulo(id, nombre, 
                    precio, cantidad, tasaImpuesto));
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

/**
 * crearVenta crea una nueva venta.
 *
 * Solicita al usuario la cantidad de productos a agregar a la venta 
 * y los detalles de cada producto. Luego, agrega los productos a la 
 * venta si se encuentran en el inventario.
 * 
 * @param
 * @return
 */
void Tienda::crearVenta()
    {
        char respuesta;
        std::cout << "Quieres realizar una venta? (s/n): ";
        std::cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S')
        {
            ventaActual = Venta(); // Resetea la venta actual
            int numProductos;
            std::cout << "Cuantos productos quieres agregar a la venta?: ";
            std::cin >> numProductos;

            for (int i = 0; i < numProductos; ++i)
            {
                int id, cantidad;
                std::cout << "Agregar producto " << i + 1 
                 << " a la venta:" << std::endl;
                std::cout << "ID: ";
                std::cin >> id;
                Producto* producto = inventario.buscarProducto(id);
                if (producto != nullptr)
                {
                    ventaActual.agregarProductoVenta(producto);
                    std::cout << "Producto agregado a la venta." 
                    << std::endl;
                }
                else
                {
                    std::cout << "Producto no encontrado en el inventario." 
                    << std::endl;
                }
            }
            std::cout << "Venta creada." << std::endl;
        }
        else
        {
            std::cout << "No se creo el inventario." << std::endl;
        }
    }

/**
 * mostrarInformacionInventario muestra la información del inventario.
 *
 * Llama al método mostrarInventario del objeto Inventario para 
 * imprimir la información de todos los productos en el inventario.
 * 
 * @param
 * @return
 */
void Tienda::mostrarInformacionInventario()
    {
        inventario.mostrarInventario();
    }

/**
 * mostrarInformacionVenta muestra la información de la venta.
 *
 * Llama al método mostrarDetallesVenta del objeto Venta para 
 * imprimir la información de todos los productos vendidos 
 * y el total de la venta.
 * 
 * @param 
 * @return
 */
void Tienda::mostrarInformacionVenta() 
    {
        ventaActual.mostrarDetallesVenta();
    }

#endif //TIENDA_H

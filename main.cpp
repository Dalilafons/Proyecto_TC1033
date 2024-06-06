/*
 * Proyecto Tienda main
 * Dalila Fonseca Maya
 * A01711722
 * 06/06/2024
 *
 * Este es un proyecto para la clase TC1030 Programación Orientado a
 * Objetos. Es un programa que captura diferentes tipos de productos (Alimentos y Artículos),
 * los gestiona en un inventario y permite realizar ventas calculando los precios
 * con polimorfismo.
 */

#include <iostream>  

#include <string> 

#include "producto.h" // bibliotecas con objetos de mi proyecto.

#include "inventario.h"

#include "venta.h"

#include "tienda.h"


int main(void)
{
    // Crear productos:
    Producto* producto1 = new Alimento(1, "Pan", 1.0, 10);
    Producto* producto2 = new Articulo(2, "Laptop", 1000.0, 5, 15.0);

    // Mostrar precio:
    std::cout << "Precio del " << producto1->getNombre() << " : " << producto1->calcularPrecio() << std::endl;
    std::cout << "Precio de la " << producto2->getNombre() << " : " << producto2->calcularPrecio() << std::endl;

    // Crear inventario y agregar productos:
    Inventario inventario;
    inventario.agregarProducto(producto1);
    inventario.agregarProducto(producto2);

    // Mostrar inventario:
    std::cout << "Mostrando inventario:" << std::endl;
    inventario.mostrarInventario();

    // Buscar un producto por ID:
    std::cout << "Buscando producto con ID 1:" << std::endl;
    if (Producto* productoEncontrado = inventario.buscarProducto(1)) {
        std::cout << "Producto encontrado: " << productoEncontrado->getNombre() 
                  << ", Precio calculado: " << productoEncontrado->calcularPrecio() << std::endl;
    }

    // Crear una venta y agregar productos vendidos:
    Venta venta;
    venta.agregarProductoVenta(producto1);
    venta.agregarProductoVenta(producto2);

    // Mostrar detalles de la venta:
    std::cout << "Mostrando detalles de la venta:" << std::endl;
    venta.mostrarDetallesVenta();

    // Calcular total de la venta con y sin descuento usando polimorfismo
    std::cout << "Total de la venta: " << venta.calcularTotal() << std::endl;
    std::cout << "Total de la venta con 10% de descuento: " << venta.calcularTotal(10.0) << std::endl;

    //Crear Tienda:
    Tienda tienda;
    tienda.crearInventario();
    tienda.mostrarInformacionInventario();
    tienda.crearVenta();
    tienda.mostrarInformacionVenta();

    // Limpiar memoria
    delete producto1;
    delete producto2;
    
    return 0;
}

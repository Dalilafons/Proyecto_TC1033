#include <iostream>  
#include <string> 
#include "producto.h" // bibliotecas con objetos de mi proyecto.
#include "tienda.h"

int main(void)
{
    Tienda tienda1;

    // Crear un inventario:
    tienda1.crearInventario();
    tienda1.mostrarInformacionInventario();

    // Crear una venta:
    tienda1.crearVenta();
    tienda1.mostrarInformacionVenta();

    // Demostrar el uso de la sobreescritura y sobrecarga:
    // Sobreescritura de calcularPrecio:
    Producto* articulo = new Articulo(1, "Lapiz", 1.50, 100, 10.0);
    Producto* alimento = new Alimento(2, "Manzana", 0.80, 50);

    std::cout << "Precio calculado para articulo: " << articulo->calcularPrecio() << std::endl;
    std::cout << "Precio calculado para alimento: " << alimento->calcularPrecio() << std::endl;

    // Sobrecarga de setPrecio:
    articulo->setPrecio(1.40);
    std::cout << "Nuevo precio para articulo sin descuento: " << articulo->getPrecio() << std::endl;

    articulo->setPrecio(1.40, 10.0); // 10% de descuento
    std::cout << "Nuevo precio para articulo con descuento: " << articulo->getPrecio() << std::endl;

    // Liberar memoria
    delete articulo;
    delete alimento;

    return 0;
}
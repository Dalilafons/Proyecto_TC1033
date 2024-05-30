#include <iostream>  
#include <string> 
#include "producto.h" // bibliotecas con objetos de mi proyecto.
#include "tienda.h" 

int main(void)
{
    Producto* producto1 = new Alimento(1, "Pan", 1.0, 10);
    Producto* producto2 = new Articulo(2, "Laptop", 1000.0, 5, 15.0);

    // Polimorfismo llamando a calcularPrecio():
    std::cout << "Precio del " << producto1->getNombre() <<" : " << producto1->calcularPrecio() << std::endl;
    std::cout << "Precio de la " << producto2->getNombre() <<" : " << producto2->calcularPrecio() << std::endl;

    // Crear un inventario y agregar productos:
    Inventario inventario;
    inventario.agregarProducto(producto1);
    inventario.agregarProducto(producto2);
    inventario.mostrarInventario();

    // Buscar un producto por ID y demostrando polimorfismo:
    if (Producto* productoEncontrado = inventario.buscarProducto(1)) {
        std::cout << "Producto encontrado: " << productoEncontrado->getNombre() 
                  << ", Precio calculado: " << productoEncontrado->calcularPrecio() << std::endl;
    }

    // Crear una venta y agregar productos vendidos:
    Venta venta;
    venta.agregarProductoVenta(producto1);
    venta.agregarProductoVenta(producto2);
    venta.mostrarDetallesVenta();

    // Calcular total de la venta con y sin descuento usando polimorfismo:
    std::cout << "Total de la venta: " << venta.calcularTotal() << std::endl;
    std::cout << "Total de la venta con 10% de descuento: " << venta.calcularTotal(10.0) << std::endl;

    // Limpiar memoria
    delete producto1;
    delete producto2;
    return 0;
}

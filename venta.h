/*
 *
 * Proyecto Tienda clase Venta
 * Dalila Fonseca Maya
 * A01711722
 * 06/06/2024
 * 
 * Esta clase define un objeto de tipo Venta que contiene las operaciones
 * necesarias para gestionar las ventas de productos. Permite agregar productos
 * a la venta, calcular el total de la venta, aplicar descuentos, y mostrar
 * detalles de la venta. Los productos pueden ser de diferentes tipos (por ejemplo,
 * Articulo o Alimento) gracias al uso de polimorfismo. Esta clase es utilizada
 * por la función principal del programa y es parte del proyecto Tienda.
 */

#ifndef VENTA_H_ 
#define VENTA_H_ 

#include <iostream>

#include <string>

#include "producto.h"//biblioteca con mis objetos a usar.



// Declaración de la clase Venta
class Venta
{
    // Variables de instancia de Venta
    private:
        Producto* productosVendidos[20];//Se define como apuntador para usar polimorfismo
        double total;
        int numVentas;

    // Métodos de Venta
    public:
        Venta();
        void agregarProductoVenta(Producto* p_vendido);
        double calcularTotal();
        double calcularTotal(double descuento);
        void mostrarDetallesVenta();
};

/**
 * Constructor por defecto de Venta.
 *
 * Inicializa el número de ventas a 0 y el total a 0.0.
 * 
 * @param
 * @return
 */
Venta::Venta(): numVentas(0), total(0.0){}

/**
 * agregarProductoVenta agrega un producto a la venta.
 *
 * Recibe un puntero a un objeto de tipo Producto y lo agrega a la venta.
 *
 * @param p_vendido Puntero a un objeto Producto.
 * @return
 */
void Venta::agregarProductoVenta(Producto* p_vendido)
        {
            if (numVentas < 20)// LImitar a 20 ventas.
            {
                productosVendidos[numVentas++] = p_vendido;
            }
            else
            {
                std::cout << "Ventas completadas." << std::endl;
            }
        }

/**
 * calcularTotal calcula el total de la venta.
 *
 * Calcula el total de la venta sumando los precios de todos los productos 
 * vendidos.
 *
 * @param
 * @return Total de la venta.
 */
double Venta::calcularTotal()
        {
            total = 0.0;
            for (int i = 0; i < numVentas;i++)
            {
                total += productosVendidos[i] ->calcularPrecio() * productosVendidos[i]->getCantidad();
            }
            return total;
        }

/**
 * calcularTotal calcula el total de la venta aplicando un descuento.
 *
 * Calcula el total de la venta sumando los precios de todos los productos 
 * vendidos y aplicando un descuento.
 *
 * @param descuento Porcentaje de descuento aplicado.
 * @return Total de la venta con descuento.
 */
double Venta::calcularTotal(double descuento) 
        {
            total = 0.0;
            for (int i = 0; i < numVentas; i++) 
            {
                total += productosVendidos[i]->calcularPrecio() * productosVendidos[i]->getCantidad();
            }
            return total * (1 - descuento / 100);
        }

/**
 * mostrarDetallesVenta muestra la información de la venta.
 *
 * Imprime la información de todos los productos vendidos y el total de la venta,
 * muestra un mensaje si no se realizo una venta "Sin informacion".
 * 
 * @param
 * @return
 */
void Venta::mostrarDetallesVenta()
        {
            if(numVentas == 0)
            {
                std::cout << "Sin informacion de la venta." << std::endl;
            }
            else
            {
                std::cout<<"Informacion de las ventas:"<<std::endl;
                for(int i = 0; i < numVentas;i++ )
                {
                    productosVendidos[i]->infoProducto();
                }
                std::cout << "El total de la venta es: " << calcularTotal() <<std::endl;
            }
        }

#endif // VENTA_H

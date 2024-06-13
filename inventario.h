/*
 *
 * Proyecto Tienda clase Inventario 1
 * Dalila Fonseca Maya
 * A01711722
 * 06/06/2024
 * 
 * Esta clase define un objeto de tipo Inventario que contiene las operaciones
 * para agregar, eliminar y buscar productos en el inventario. 
 * Además, gestiona la muestra de la información de los productos.
 * Esta clase es utilizada por la función principal del programa 
 * y es parte del proyecto Tienda.
 */

#ifndef INVENTARIO_H_ 
#define INVENTARIO_H_ 

#include <iostream>

#include <string>

#include "producto.h"//biblioteca con mis objetos a usar.

// Declaración de la clase Inventario
class Inventario
{
    // Variables de instancia de Inventario
    private:
        Producto* producto[20];//Apuntador para usar polimorfismo.
        int numProductos;

    // Métodos de Inventario
    public:
        Inventario();
        void agregarProducto(Producto* p);
        void eliminarProducto(int id);
        void eliminarProducto(std::string nombre);
        Producto* buscarProducto(int id);
        void mostrarInventario();
        Producto** getProductos();
        int getNumProductos();
};

/**
 * Constructor por defecto de Inventario.
 *
 * Inicializa el número de productos a 0.
 * 
 * @param
 * @return
 */
Inventario::Inventario(): numProductos(0){} 

/**
 * agregarProducto agrega un producto al inventario.
 *
 * Recibe un puntero a un objeto de tipo Producto y lo agrega al inventario.
 *
 * @param p Puntero a un objeto Producto.
 * @return
 */
void Inventario::agregarProducto(Producto* p) 
    {
        if (numProductos < 20)// Limitar a 20 productos
            {
                producto[numProductos++] = p; 
            }
        else
            {
                std::cout << "Inventario lleno" << std::endl;
            }
    }

/**
 * eliminarProducto elimina un producto del inventario por ID.
 *
 * Busca un producto por su ID y lo elimina del inventario.
 *
 * @param id ID del producto a eliminar.
 * @return
 */
void Inventario::eliminarProducto(int id)
    {
        for (int i = 0; i < numProductos; i++) 
           {
                if (producto[i]->getId()== id)
                {
                    for(int a = i; a < numProductos -1; ++a)
                    {
                        producto[a] = producto[a+1];
                    }
                    --numProductos;
                    return;
                }
           }
        std::cout << "Producto no encontrado" << std::endl;
    }

/**
 * eliminarProducto elimina un producto del inventario por nombre.
 *
 * Busca un producto por su nombre y lo elimina del inventario.
 *
 * @param nombre Nombre del producto a eliminar.
 * @return
 */
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

/**
 * buscarProducto busca un producto en el inventario por ID.
 *
 * Busca un producto por su ID y devuelve un puntero al producto si se 
 * encuentra.
 *
 * @param id ID del producto a buscar.
 * @return Puntero al producto encontrado, o nullptr si no se encuentra.
 */
Producto* Inventario::buscarProducto(int id)
        {
            for (int i = 0; i < numProductos; i++)
            {
                if (producto[i]->getId()==id)
                {
                    std::cout << "El producto encontrado es: " <<
                     producto[i]->getNombre() << std::endl;
                    return producto[i];
                }
            }    
            std::cout<< "Producto con id:" << id << "no encontrado."<<std::endl;    
            return nullptr;
        }

/**
 * mostrarInventario muestra la información del inventario.
 *
 * Imprime la información de todos los productos en el inventario,
 * en caso de no tener ningún prouducto muestra el mensaje 
 * "Sin informacion del inventario"
 * 
 * @param
 * @return
 */
void Inventario::mostrarInventario()
        {
            if (numProductos == 0) 
            {
                std::cout << "Sin informacion del inventario." << std::endl;
            } 
            else 
            {
                std::cout<<"Informacion del inventario:"<<std::endl;
                for(int i = 0; i < numProductos;i++ )
                {
                    producto[i]->infoProducto();
                }
            }
        }
/**
 * getProductos obtiene el arreglo de productos.
 *
 * Devuelve un puntero al arreglo de productos.
 *
 * @param
 * @return Puntero al arreglo de productos.
 */
Producto** Inventario::getProductos()
        {
            return producto;
        }

/**
 * getNumProductos obtiene el número de productos en el inventario.
 *
 * Devuelve el número de productos actualmente en el inventario.
 *
 * @param
 * @return Número de productos en el inventario.
 */
int Inventario::getNumProductos()
        {
            return numProductos;
        }

#endif // INVENTARIO_H

/*
 *
 * Proyecto Tienda clase Producto
 * Dalila Fonseca Maya
 * A01711722
 * 06/06/2024
 * 
 * Esta clase define un objeto de tipo Producto, que es una clase base abstracta
 * utilizada para manejar productos. Proporciona métodos para obtener y establecer
 * el ID, nombre, precio y cantidad del producto. 
 * Contiene las clases heredadas Articulo y Alimento.
 */

#ifndef PRODUCTO_H 
#define PRODUCTO_H 

#include <iostream>

#include <string>

//Dclaración de clase empleado que es abstracta
class Producto
{
    //Declaro variables de instancia
    protected: 
        int id;
        std::string nombre;
        double precio;
        int cantidad;
    
    // Métodos de Producto
    public:
        Producto(int id1, std::string nombre1, double precio1,int cantidad1);
        virtual double calcularPrecio() = 0; //método abstracto será sobrescrito.
        std::string getNombre();
        double getPrecio();
        int getCantidad();
        int getId();
        void setPrecio(int nuevoPrecio);
        void setPrecio(int nuevoPrecio, double descuento);
        void setCantidad(int nuevaCantidad);
        void infoProducto();
};

/**
 * Constructor parametrizado de Producto.
 *
 * Inicializa un objeto Producto con los valores dados.
 *
 * @param id1 Identificador del producto.
 * @param nombre1 Nombre del producto.
 * @param precio1 Precio del producto.
 * @param cantidad1 Cantidad del producto.
 */
Producto::Producto(int id1, std::string nombre1, double precio1,int cantidad1)
        : id(id1), nombre(nombre1), precio(precio1), cantidad(cantidad1) {}

/**
 * getNombre bbtiene el nombre del producto.
 *
 * Devuelve el nombre del producto.
 *
 * @param
 * @return Nombre del producto.
 */
std::string Producto::getNombre() {
    return nombre;
}

/**
 * getPrecio obtiene el precio del producto.
 *
 * Devuelve el precio del producto.
 *
 * @param
 * @return Precio del producto
 */
double Producto::getPrecio()
        {
            return precio;
        }

/**
 * getCantidad obtiene la cantidad del producto.
 *
 * Devuelve la cantidad del producto.
 *
 * @param
 * @return Cantidad del producto.
 */
int Producto::getCantidad()
        {
            return cantidad;
        }

/**
 * getId obtiene el ID del producto.
 *
 * Devuelve el ID del producto.
 *
 * @param
 * @return ID del producto.
 */
int Producto::getId()
        {
            return id;
        }

/**
 * setPrecio establece un nuevo precio para el producto.
 *
 * Asigna un nuevo precio al producto.
 *
 * @param nuevoPrecio Nuevo precio del producto.
 * @return
 */
void Producto::setPrecio(int nuevoPrecio)
        {
            precio = nuevoPrecio;
        }

/**
 * setPrecio establece un nuevo precio para el producto con un descuento.
 *
 * Asigna un nuevo precio al producto aplicando un descuento.
 *
 * @param nuevoPrecio Nuevo precio del producto.
 * @param descuento Porcentaje de descuento aplicado.
 */
void Producto::setPrecio(int nuevoPrecio, double descuento)
        {
            precio = nuevoPrecio * (1 - descuento / 100);
        }

/**
 * setCantidad establece una nueva cantidad para el producto.
 *
 * Asigna una nueva cantidad al producto.
 *
 * @param nuevaCantidad Nueva cantidad del producto.
 * @return
 */
void Producto::setCantidad(int nuevaCantidad)
        {
            cantidad = nuevaCantidad;
        }

/**
 * infoProducto muestra la información del producto.
 *
 * Imprime el ID, nombre, precio y cantidad del producto.
 * 
 * @param
 * @return
 */
void Producto::infoProducto()
        {
            std::cout << "ID: " << id << ", Nombre: " << nombre<< ", Precio: " << precio << ", Cantidad: " << cantidad << std::endl;
        }


// Declaración de la clase Articulo que hereda de Producto
class Articulo : public Producto
{
    // Variables de instancia de Articulo
    private:
        double tasaImpuesto;

    // Métodos de Articulo
    public:
        Articulo(int id1, std::string nombre1, double precio1,int cantidad1, double tasaImpuesto1);
        double calcularPrecio(); 
        double getTasaImpuesto();
};

/**
 * Constructor parametrizado de Articulo.
 *
 * Inicializa un objeto Articulo con los valores dados.
 *
 * @param id1 Identificador del artículo.
 * @param nombre1 Nombre del artículo.
 * @param precio1 Precio del artículo.
 * @param cantidad1 Cantidad del artículo.
 * @param tasaImpuesto1 Tasa de impuesto aplicada al artículo.
 */
Articulo::Articulo(int id1, std::string nombre1, double precio1,int cantidad1, double tasaImpuesto1)
        : tasaImpuesto(tasaImpuesto1), Producto(id1,nombre1,precio1,cantidad1){}
        
/**
 * calcularPrecio calcula el precio del artículo con el impuesto aplicado.
 *
 * Calcula el precio total del artículo incluyendo la tasa de impuesto.
 *
 * @param
 * @return Precio total del artículo incluyendo el impuesto.
 */
double Articulo::calcularPrecio()
    {
        double total;
        total = precio + (precio * tasaImpuesto / 100);
        return total;
    } 

/**
 * getTasaImpuesto obtiene la tasa de impuesto del artículo.
 *
 * Devuelve la tasa de impuesto aplicada al artículo.
 *
 * @param
 * @return Tasa de impuesto del artículo.
 */
double Articulo::getTasaImpuesto()
        {
            return tasaImpuesto;
        }


// Declaración de la clase Alimento que hereda de Producto
class Alimento: public Producto
{
    // Métodos de Alimento
    public:
        Alimento(int id1, std::string nombre1, double precio1,int cantidad1);
        double calcularPrecio();

};

/**
 * Constructor parametrizado de Alimento.
 *
 * Inicializa un objeto Alimento con los valores dados.
 *
 * @param id1 Identificador del alimento.
 * @param nombre1 Nombre del alimento.
 * @param precio1 Precio del alimento.
 * @param cantidad1 Cantidad del alimento.
 */
Alimento::Alimento(int id1, std::string nombre1, double precio1,int cantidad1)
        : Producto(id1,nombre1,precio1,cantidad1){}

/**
 * calcularPrecio calcula el precio del alimento con un incremento del 5%.
 *
 * Calcula el precio total del alimento aplicando un incremento del 5% al precio.
 *
 * @param
 * @return Precio total del alimento incluyendo el incremento.
 */
double Alimento::calcularPrecio() 
        {
            double total;
            total = precio + ((5*precio)/100);
            return total;
        }

#endif //PRODUCTO_H

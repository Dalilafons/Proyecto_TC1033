#ifndef PRODUCTO_H //Bibliotecas.
#define PRODUCTO_H //Bibliotecas.

#include <iostream>
#include <string>

//Clase base Producto:
class Producto
{
    protected: //Atributos:
        int id;
        std::string nombre;
        double precio;
        int cantidad;
    public://Esqueleto:
        Producto(int id1, std::string nombre1, double precio1,int cantidad1);
        virtual double calcularPrecio();
        std::string getNombre();
        double getPrecio();
        int getCantidad();
        int getId();//-----------------------------------------------------------------------
        void setPrecio(int nuevoPrecio);
        void setPrecio(int nuevoPrecio, double descuento);//---------------------------------
        void setCantidad(int nuevaCantidad);
        void infoProducto();//---------------------------------------------------------------
};
//Metodos Producto:
Producto::Producto(int id1, std::string nombre1, double precio1,int cantidad1)
        : id(id1), nombre(nombre1), precio(precio1), cantidad(cantidad1) {}
double Producto::calcularPrecio()
        {
            return precio;
        }
std::string Producto::getNombre()
        {
            return nombre;
        }
double Producto::getPrecio()
        {
            return precio;
        }
int Producto::getCantidad()
        {
            return cantidad;
        }
int Producto::getId()
        {
            return id;
        }
void Producto::setPrecio(int nuevoPrecio)
        {
            precio = nuevoPrecio;
        }
 // Sobrecarga de setPrecio para aceptar un descuento en porcentaje:
void Producto::setPrecio(int nuevoPrecio, double descuento)
        {
            precio = nuevoPrecio * (1 - descuento / 100);
        }
void Producto::setCantidad(int nuevaCantidad)
        {
            cantidad = nuevaCantidad;
        }
void Producto::infoProducto()
        {
            std::cout << "ID: " << id << ", Nombre: " << nombre<< ", Precio: " << precio << ", Cantidad: " << cantidad << std::endl;
        }

// Clase derivada Articulo, hereda de Producto:
class Articulo : public Producto
{
    private:
        double tasaImpuesto;
    public:
        Articulo(int id1, std::string nombre1, double precio1,int cantidad1, double tasaImpuesto1);
        double calcularPrecio() override; 
        double getTasaImpuesto();
};
//Metodos Articulo:
Articulo::Articulo(int id1, std::string nombre1, double precio1,int cantidad1, double tasaImpuesto1)
        : tasaImpuesto(tasaImpuesto1), Producto(id1,nombre1,precio1,cantidad1){}
//Sobrescribe el metodo calcularPrecio(), de producto:
double Articulo::calcularPrecio()
    {
        double total;
        total = precio + (precio * tasaImpuesto / 100);
        return total;
    } 
double Articulo::getTasaImpuesto()
        {
            return tasaImpuesto;
        }

// Clase derivada Alimento, hereda de Producto
class Alimento: public Producto //Clase que hereda de producto.
{
    public:
        Alimento(int id1, std::string nombre1, double precio1,int cantidad1);
        double calcularPrecio() override;

};
//Metodos Alimento:
Alimento::Alimento(int id1, std::string nombre1, double precio1,int cantidad1)
        : Producto(id1,nombre1,precio1,cantidad1){}
//Sobrescribe el metodo calcularPrecio(), de producto:
double Alimento::calcularPrecio() 
        {
            double total;
            // Al precio de un alimento se le suma el 5% del precio total, a su precio final.
            total = precio + ((5*precio)/100);
            return total;
        }

#endif

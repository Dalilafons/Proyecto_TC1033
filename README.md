# TC1030 Proyecto Tienda
Este proyecto está diseñado para simular la gestión eficaz de una tienda que ofrece una amplia variedad de productos, incluyendo artículos generales y alimentos. Los artículos generales, además, están sujetos a una tasa de impuesto que se calcula en su precio. El sistema permite una organización meticulosa del inventario y facilita la realización de ventas, integrando funciones para mostrar informes detallados sobre el estado del inventario y el desempeño de las ventas. Además, permite realizar y seguir transacciones con facilidad.

## Casos de Fallo que harían que el Proyecto deje de funcionar
**1.Entradas de usuario inválida:**
Ingresar datos no válidos o incorrectos cuando se solicite información, como IDs de productos no numéricos, nombres vacíos, o cantidades negativas.
Selección de un tipo de producto no válido (cualquier cosa diferente a 1 o 2 en el menú).

**2.Límite de Inventario y Ventas:**
Intentar agregar más de 20 productos al inventario o a una venta podría causar que el programa deje de funcionar correctamente ya que los arrays están limitados a 20 elementos.

**3.Acceso a Productos no existentes:**
Aunque el programa tiene avisos para cuando un producto no existe, intentar realizar operaciones (como eliminar o vender) repetidamente sobre productos inexistentes puede causar comportamientos inesperados si no se maneja adecuadamente.

**4.Fugas de memoria:**
No eliminar correctamente los objetos creados dinámicamente con new. Si el programa se cierra inesperadamente sin llamar a delete, esto puede causar fugas de memoria.

**5.Dependencias de Compilación:**
No tener un compilador C++ compatible con C++11 o superior instalado puede causar errores de compilación.
Errores en la inclusión de archivos de cabecera (por ejemplo, falta de #include "producto.h" en los archivos que lo necesitan).



/** @file Inventario.hh
    @brief Especificación de la clase Inventario
*/
#ifndef INVENTARIO_HH
#define INVENTARIO_HH

#include <string> //hace falta???
#include <map>
#include <iostream>

using namespace std;

/*
 * Clase Inventario
 */

/** @class Inventario 
    @brief Representa el conjunto de productos, sus respectivas cantidades y
    las operaciones del Inventario.

    Sus operaciones son las modificadoras y consultoras de producto, cantidad y señalización, y la de escritura de todos los productos y sus cantidades. 
*/
class Inventario {
    
private:
    
    /* El Sistema guarda el identificador del producto con su respectiva cantidad.
       Sistema.begin() <= it <= Sistema.end() 
    */

    /** @brief Datos del producto y su cantidad */
    map<string, int> Sistema;
    /** @brief Identificador que señaliza la posicion del producto a tratar */
    map<string, int>::iterator it;

public:

    //Constructoras

    /** @brief Creadora por defecto
        @pre cierto
        @post El resultado es un Inventario vacio
        @coste Constante
    */
    Inventario();


    //Modificadoras

    /** @brief Modificadora que determina la existenica de un producto
        @pre cierto
        @post El resultado indica si el producto existe o no. Si existe, el parámetro implícito
        pasa a señalizar la posicion del producto <em>p</em>  
        @coste 
    */
    bool existe_producto(string p);

    
    /** @brief Modificadora de la existencia y la cantidad de un producto
        \pre cierto
        \post Se le suma <em>q</em> a la cantidad del producto <em>p</em> del parámetro implícito.
        Si el producto no existia, se añade el nuevo producto con la cantidad <em>q</em>.
        \coste 
    */
    void poner_prod(string p, int q);


    /** @brief Modificadora que gestiona la existencia de un producto
        \pre El parámetro implícito esta señalizando el producto a modificar
        \post El parámetro implícito deja de contener el producto señalizado. 
        \coste 
    */
    void quitar_prod();
    
    
    /** @brief Modificadora que gestiona la cantidad de un producto
        \pre El parámetro implícito esta señalizando el producto a modificar
        \post Se le suma <em>q</em> a la cantidad del producto señalizado en el parámetro implícito
        \coste 
    */
    void sumar_prod(int q);


    /** @brief Modificadora del producto señalizado
        \pre cierto
        \post El Inventario pasa a señalizar al primer elemento
        \coste 
    */
    void inicial();


    /** @brief Modificadora del producto señalizado
        \pre cierto
        \post El Inventario pasa a señalizar al siguiente elemento
        \coste 
    */
    void avanzar_it();



    //Consultoras

    /** @brief Consultora que indica la cantidad de un producto
        @pre El parámetro implícito esta señalizando el producto a consultar
        @post Retorna la cantidad del producto consultado 
        @coste 
    */
    int consultar_prod() const;


    /** @brief Consultora de producto y cantidad
        @pre El parámetro implícito esta señalizando el producto a consultar
        @post Retorna el producto consultado con su cantidad 
        @coste 
    */
    pair<string, int> composicion() const;
   

    /** @brief Consultora que indica si ya hemos reccorido el inventario
        @pre cierto
        @post El resultado indica si el Inventario señaliza a la última posición 
        @coste 
    */
    bool finalizado() const;


    //escritura

    /** @brief Operación de escritura
        @pre cierto
        @post Se han escrito por el canal de escritura estándard
        todos los identificadores de producto con su respectiva cantidad 
        @coste 
    */
    void inventario() const;
};
#endif

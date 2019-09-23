/** @file Almacen.hh
    @brief Especificación de la clase Almacen
*/

#ifndef ALMACEN_HH
#define ALMACEN_HH


#include "Sala.hh"
#include "BinTree.hh"

/*
 * Clase Almacen
 */

/** @class Almacen 
    @brief Representa la informacion y las operaciones del Almacen.

    Ofrece la operación de ...
*/

class Almacen {

private:
    /* Cada nodo del arbol tiene 2 o 0 hijos. La sala con identificador 
    n se encuentra en v_sala[n-1]. 0 <= v_sala.size() <= número de salas. */
    
    /** @brief Estructura y distribución de las salas en el Almacen */
    BinTree<int> arb;

    /** @brief Vector de salas del almacen.
    
     *  Ordenado crecientemente por el identificador de cada sala. */ 
    vector<Sala> v_sala;

    /** @brief Modificadora del almacen
        \pre a contiene la distribución de las salas del almacen
        \post se ponen un máximo de <em>q</em> productos <em>p</em>p a la sala tratada. Las unidades
        que no han cabido se distribuyen equitativamente a las salas posteriores izquierda y derecha.
        Si el resto era impar el elemento sobrante se distribuye a la sala izquierda.
        Se devuelve un entero de las unidades que no han podido ser distribuidas a las salas
        posteriores de la sala actual
        \coste 
    */    
    int i_distribuir(const BinTree<int> &a, string p, int q);


    /** @brief Operación de lectura
        \pre a es vacio; el canal estandard d'entrada contiene el recorrido en preorden
        de un arbol binario A d'enteros
        \post a = A
        \coste 
    */    
    void static read_bintree_int(BinTree<int> &a, int marca);

public:

    //Constructora
    /** @brief Creadora por defecto
        @pre cierto
        @post El resultado es un Almacen vacio
        @coste Constante
    */
    Almacen();


    //Consultoras
    
    /** @brief Consultora de la referencia a sala
        \pre <em>n</em> es un identificador valido de sala
        \post Devuelve la referencia a la sala con identificador n 
        \coste 
    */
    Sala& consultar_sala(int n);

    
    /** @brief Consultora constante de la referencia a sala
        \pre <em>n</em> es un identificador valido de sala
        \post Devuelve la referencia constante a la sala con identificador n 
        \coste 
    */
    const Sala& consultar_sala2(int n);

   
    //Modificadoras
    
    /** @brief Modificadora del almacen
        \pre cierto
        \post Se distribuyen un máximo de <em>q</em> unidades del producto <em>p</em> por el almacen.
        Empezando por la sala inicial, ponemos todos los productos que quepa en la sala en que estemos.
        Las unidades sobrantes UD se distribuyen UD+1/2 a la sala izquierda y UD/2 a la sala derecha.
        Retorna la unidades que no han cabido en el almacen.
        \coste 
    */
    int distribuir(string p, int q);

    

    //Entrada
    /** @brief Operación de lectura
        \pre el canal estándard de entrada contiene un entero N > 0 seguido de los datos de la distribucion de la salas y de el tamaño de cada sala
        \post El parámetro implícito contiene su estructura, organización y el tamaño de cada sala.
        \coste 
    */
    void leer_almacen();

};

#endif

/** @file Sala.hh
    @brief Especificación de la clase Sala
*/

#ifndef SALA_HH
#define SALA_HH

#include <iostream>
#include <vector>
#include <string> //hace falta??
#include <map>
#include "Inventario.hh"

using namespace std;

/*
 * Clase Sala
 */

/** @class Sala 
    @brief Representa el conjunto de características y
    operaciones de las células.

    Ofrece la operación de lucha entre células y las operaciones de
    lectura y escritura.
*/

class Sala {
    
private:
    
    /* 0<f y 0<c. 0<=items<=f*c     0<est.size()<=f*c   f*c = est.size()
    0 <= inv.size() <= items  */

    /** @brief Número de filas de la sala */
    int f;

    /** @brief Número de columnas de la sala */
    int c;

    /** @brief Vector de los huecos de la sala */
    vector <string> est;

    /** @brief Número de items de la sala */
    int items;

    /** @brief Indica si la sala está compactada (true) o si no se puede determinar que lo este (false) */
    bool compac; //false si es posible que no este compactado, true si estamos seguro que esta compactado.

    /** @brief Conjunto de productos y sus cantidades correspondientes */
    Inventario inv;

public:

    //Constructores

    /** @brief Creadora por defecto
        \pre cierto
        \post El resultado es una Sala vacia de f filas y c columnas, compactado y con número de items = 0
        \coste Constante
    */
    Sala(int f, int c);


    //Modificadoras

    /** @brief Modificadora de la sala
        \pre 0 <= q
        \post Se añaden un número <= q de productos p. 
        Retorna el número de items que no han cabido
        \coste  */
    int poner_items(string p, int q);

    
    
    /** @brief Modificadora de la sala
        \pre 0 <= q
        \post Se quita un número <= q de productos p.
        Retorna el número de items que no se han podido quitar.
        \coste  */
    int quitar_items(string p, int q);

    
    
    /** @brief Modificadora del tamaño de la sala
        \pre f*c >= número de items de la sala
        \post La sala pasa a tener f filas y c columnas. Queda compactada.
        \coste  */
    void redimensionar(int f, int c);

    
    
    /** @brief Modificadora de la sala
        \pre cierto
        \post La sala pasa a estar compactada.
        \coste  */
    void compactar();

    
    
    /** @brief Modificadora del orden de los items
        \pre cierto
        \post La sala pasa a estar reorganizada  */
    void reorganizar();


    //Consultoras
    
    /** @brief Consultora del número de items
        \pre cierto
        \post Retorna el número de items de la sala
        \coste  
    */
    int num_items() const;


    /** @brief Consultora de una posición
        \pre nf y nc es la posición de la fila y la columnas a consultar.
        La posición existe.
        \post Retorna el producto que se encuentra en la posición 
        \coste  
    */
    string consultar_pos(int nf, int nc) const;

    
    //escritura

    /** @brief Operación de escritura
        \pre cierto
        \post Se ha escrito por el canal de escritura estándard
        la sala con la cantidad de items y por orden alfabético
        todos los productos con sus cantidades.
        \coste  
    */
    void escribir() const;
           
};

#endif

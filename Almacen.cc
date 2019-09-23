/** @file Almacen.cc
    @brief Código de la clase Almacen
*/

#include "Almacen.hh"


Almacen::Almacen(){
}

Sala& Almacen::consultar_sala(int n){
    return v_sala[n-1];
}

const Sala& Almacen::consultar_sala2(int n){
    return v_sala[n-1];
}

int Almacen::i_distribuir(const BinTree<int> &a, string p, int q){ //algo raro, se podria depurar pero creo que funciona NICE!
    if (not a.empty()){
        int n = a.value();
        int x = v_sala[n-1].poner_items(p, q);
        if (x > 0){
            BinTree<int> l = a.left();
            int z = i_distribuir(l, p, (x+1)/2);
            if (x > 1){
                BinTree<int> r = a.right();
                z += i_distribuir(r, p, x/2);
            }
            return z;
        }
        else return x; 
    }
    else return q;
}

int Almacen::distribuir(string p, int q){
    int x = i_distribuir(arb, p, q);
    return x;
}

void Almacen::leer_almacen() {
    int n;
    cin >> n;
    //num_salas = n;
    //v_sala.resize(n);
    read_bintree_int(arb,0);
    int f, c;
    for (int i = 0; i < n; ++i){
        cin >> f >> c;
        Sala s(f,c);
        v_sala.push_back(s);
        //v_sala[i] = s; //asi o creando un vector de n elementos????
    }
}

void Almacen::read_bintree_int(BinTree<int> &a, int marca)
{
    int x;
    cin >> x;
    if (x != marca)
    {
        BinTree<int> l;
        read_bintree_int(l, marca);
        BinTree<int> r;
        read_bintree_int(r, marca);
        a = BinTree<int>(x, l, r);
    }
}

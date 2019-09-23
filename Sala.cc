/** @file Sala.cc
    @brief Código de la clase Sala 
*/

#include "Sala.hh"

Sala::Sala(int f, int c){
    this->f = f;
    this->c = c;
    est = vector<string> (f*c, "NULL");
    items = 0;
    compac = true;
}


int Sala::poner_items(string p, int q){
    int x = q;
    if (items < f*c){
        for (int i = 0; i<f*c and x!=0; ++i){
            if (est[i] == "NULL") {
                est[i] = p;
                --x;
                ++items;
            }

        }
        if (x != 0) compac = true;
        if (x != q){
            inv.poner_prod(p, q-x);
        }
    }
    return x;
}
    


int Sala::quitar_items(string p, int q){
    int x = q;
    if (inv.existe_producto(p)){
        for (int i = 0; i<f*c and x!=0; ++i){
            if (est[i] == p){
                est[i] = "NULL";
                --x;
                --items;
            }
        }
        compac = false; //hay que esperar le peor caso, puede que sea true.
        inv.sumar_prod(-(q-x));
        if (inv.consultar_prod() == 0) inv.quitar_prod();
    }
    return x;
}


void Sala::compactar(){
    if (not compac){
        int it = 0; //iterador que busca items; usar int o iterator??
        int hu = 0; //iterador que referencia hueco;
        while (hu != items){
            if (est[it] != "NULL"){
                if (it != hu){
                    est[hu] = est[it];
                    est[it] = "NULL";
                }
                ++hu;
            }
            ++it;
        }
        compac = true;
    }
}


void Sala::redimensionar(int f, int c){
    if (not compac) compactar();
    est.resize(f*c, "NULL");
    this->f = f;
    this->c = c;
}


void Sala::reorganizar(){
    int i = 0;
    pair<string, int> a;
    inv.inicial();
    while (not inv.finalizado()){
        a = inv.composicion();
        string p = a.first;
        int q = a.second;
        while (q != 0){
            cerr << i << endl;
            est[i] = p;
            --q;
            ++i;
        }
        inv.avanzar_it();
    }
    while (i<f*c) { //cambio, daba error.
        est[i] = "NULL";
        ++i;
    }
    compac = true;
}


int Sala::num_items() const {
    return items;
}


void Sala::escribir() const {
    cout << "  ";
    for (int i = c*f-c; i != c-1; ++i){
        cout << est[i];
        if ((i+1)%c == 0) {
            cout << endl << "  ";
            i -= 2*c;
        }
        else cout << ' ';
    }
    cout << est[c-1] << endl;
    cout << "  " << items << endl;
    if (items > 0) {
        inv.inventario();
    }
}


string Sala::consultar_pos(int nf, int nc) const{
    return est[(f-nf)*c+nc-1];
}

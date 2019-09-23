/** @file Inventario.cc
    @brief Código de la clase Inventario
*/


#include "Inventario.hh"


Inventario::Inventario(){
}

bool Inventario::existe_producto(string p){
    it = Sistema.find(p);
    return it != Sistema.end();
}

void Inventario::inventario() const{
    map<string,int>::const_iterator c = Sistema.begin();
    while (c != Sistema.end()){
        cout << "  " << c->first << ' ' << c->second << endl;
        ++c;
    }
}

int Inventario::consultar_prod() const{
    return it->second;
}

void Inventario::poner_prod(string p, int q){
    Sistema[p] += q;
}

void Inventario::quitar_prod(){
    Sistema.erase(it);
}

void Inventario::sumar_prod(int q){
    it->second += q;
}

pair<string, int> Inventario::composicion() const{ //cambio
    return *it;
}

bool Inventario::finalizado() const{
    return it == Sistema.end();
}

void Inventario::inicial(){
    it = Sistema.begin();
}

void Inventario::avanzar_it(){
    ++it;
}


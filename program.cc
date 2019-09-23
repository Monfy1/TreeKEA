/** @mainpage

    Práctica TreeKEA de la asignatura de PRO2, con documentación <b> completa</b>
    (incluyendo elementos privados y código).

    El programa principal se encuentra en el módulo program.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un
    módulo para representar el Almacen en el que se desarrollarán las
    operaciones, otro para la Sala y otro para el tipo 
    Inventario.

    Comentarios:

    - He querido desarrollar la práctica de forma completamente modular, mirando
    de conservar la eficiencia en todo momento. Para eso he conservado lo máximo
    posible la independéncia de las clases para otorgar una fácil modificación
    y libertad a la hora de usar las clases.

*/

/** @file program.cc

    @brief Programa principal

    Estamos suponiendo que los identificadores de sala serán siempre válidos, las
    cantidades de producto siempre serán positivas, los valores de las filas y las
    columnas siempre serán mayores que cero y cuando se apliquen a una posición de
    una estantería, dicha posición existirá en ese momento.
*/

#include "Almacen.hh"
#include "Inventario.hh"
#ifndef NO_DIAGRAM
#endif

int main() {
    Almacen alm;
    alm.leer_almacen();
    Inventario inv;

    const string ERROR = "  error";

    string op;          //Código de operación
    string p;           //Producto
    int f, c, q, n;     //Fila, Columna, Cantidad y nº sala
    cin >> op;
    while(op != "fin"){

        if (op == "poner_prod"){
            cin >> p;
            cout << "poner_prod " << p << endl;
            if (not inv.existe_producto(p)) inv.poner_prod(p,0);
            else cout << ERROR << endl;
        }

        else if (op == "quitar_prod"){
            cin >> p;
            cout << "quitar_prod " << p << endl;
            if (inv.existe_producto(p) and inv.consultar_prod() == 0) inv.quitar_prod();
            else cout << ERROR << endl;
        }

        else if (op == "poner_items"){
            cin >> n >> p >> q;
            cout << "poner_items " << n << ' ' << p << ' ' << q << endl;
            if (inv.existe_producto(p)) {
                Sala &s = alm.consultar_sala(n);
                int x = s.poner_items(p, q);
                cout << "  " << x << endl;
                inv.sumar_prod(q-x);
            }
            else cout << ERROR << endl;
        }

        else if (op == "quitar_items"){
            cin >> n >> p >> q;
            cout << "quitar_items " << n << ' ' << p << ' ' << q << endl;
            if (inv.existe_producto(p)) {
                Sala &s = alm.consultar_sala(n);
                int x = s.quitar_items(p, q);
                cout << "  " << x << endl;
                inv.sumar_prod(-(q-x));
            }
            else cout << ERROR << endl;
        }

        else if (op == "distribuir"){
            cin >> p >> q;
            cout << "distribuir " << p << ' ' << q << endl;
            if (inv.existe_producto(p)) {
                int x = alm.distribuir(p, q);
                cout << "  " << x << endl;
                inv.sumar_prod(q-x);
            }
            else cout << ERROR << endl;
        }

        else if (op == "compactar"){
            cin >> n;
            cout << "compactar " << n << endl;
            Sala &s = alm.consultar_sala(n);
            s.compactar();
        }

        else if (op == "reorganizar"){
            cin >> n;
            cout << "reorganizar " << n << endl;
            Sala &s = alm.consultar_sala(n);
            s.reorganizar();
        }

        else if (op == "redimensionar"){
            cin >> n >> f >> c;
            cout << "redimensionar " << n << ' ' << f << ' ' << c << endl;
            Sala &s = alm.consultar_sala(n);
            if (f*c >= s.num_items()) {
                s.redimensionar(f, c);
            }
            else cout << ERROR << endl;
        }

        else if (op == "inventario"){
            cout << "inventario" << endl;
            inv.inventario();
        }

        else if (op == "escribir"){
            cin >> n;
            cout << "escribir " << n << endl;
            const Sala &s = alm.consultar_sala2(n);
            s.escribir();
        }

        else if (op == "consultar_pos"){
            cin >> n >> f >> c;
            cout << "consultar_pos " << n << ' ' << f << ' ' << c << endl;
            const Sala &s = alm.consultar_sala2(n);
            cout << "  " << s.consultar_pos(f, c) << endl;
        }

        else if (op == "consultar_prod"){
            cin >> p;
            cout << "consultar_prod " << p << endl;
            if (inv.existe_producto(p)) {
                cout << "  " << inv.consultar_prod() << endl;
            }
            else cout << ERROR << endl;
        }
        cin >> op;
    }
    cout << "fin" << endl;
}

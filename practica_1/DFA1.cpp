#include <iostream>
#include <cstdlib>
using namespace std;
string entrada;
const int ERR=-1;

const int matran[4][2] = {
            //a     b
    /*q0*/{0, 1},
    /*q1*/{0, 2},
    /*q2*/{0, 3},
    /*q3*/{3, 3}
};

int colCar( char c) {
    if( c == 'a') return 0;
    if( c == 'b') return 1;

    cout << "Simbolo " << c << " no pertenece al Alfabeto" << endl;
    return ERR;
}

void automata() {
    int estado=0, idx = 0;

    while( idx < entrada.size() && estado != ERR) {
        char x = entrada[idx++];
        int col = colCar( x );
        if( col >= 0 && col <= 1) {
            estado = matran[estado][col];
        }
        else estado == ERR;
    }
    if( estado == 0 || estado == 1 || estado == 2) {
        cout << entrada << " pertenece al lenguaje del Automata" << endl;
    }
    else {
        cout << entrada << " NO ES valida en el Lenguaje" << endl;
    }
}

int main() {
    cout << "Cadena [.]=salir: ";
    cin >> entrada;
    while( entrada != ".") {
            automata();
        cout << "Cadena [.]=salir: ";
        cin >> entrada;
    }

    return EXIT_SUCCESS;
}
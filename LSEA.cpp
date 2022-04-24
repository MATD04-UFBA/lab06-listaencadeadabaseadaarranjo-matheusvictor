// Lista Encadeada Baseada em Arranjos

#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 30

#include "cLSEA.h"

// ***********************************************
// ***********************************************
// ***********************************************

int main(int argc, char** argv) {


int nL = MAX;

    if (argc > 1) {
        nL = atoi(argv[1]);
        if (nL < 1) 
            nL = MAX; 
        }

    cLSEA L(nL);

    srand( time(NULL) );

    std::cout << "########### LISTA INICIAL" << std::endl;
    L.imprimirLSEA();
    L.imprimirLSEACompleta();
    
    int i = 0;
    while ( L.inserirElem(i * 10) )
        i++;

    std::cout << "########### LISTA APOS INSERCOES" << std::endl;
    L.imprimirLSEA();
    L.imprimirLSEACompleta();

    i = 0;
    while ( i < nL ) {
        L.removerElem(i * 20);
        i++;
        }

    std::cout << "########### LISTA APOS REMOCOES" << std::endl;
    L.imprimirLSEA();
    L.imprimirLSEACompleta();
}

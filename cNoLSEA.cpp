#include <stdio.h>
#include <stdlib.h>

#include "cNoLSEA.h"

// ***********************************************
// ***                                         ***
// ***********************************************
cNoLSEA::cNoLSEA() {	
		
	dado 	= 0.0;
    prox 	= -1;
}

// ***********************************************
// ***                                         ***
// ***********************************************
cNoLSEA::cNoLSEA(float num) {	
		
	dado 	= num;
    prox 	=-1;
}

// ***********************************************
// ***                                         ***
// ***********************************************
cNoLSEA::~cNoLSEA() {
	
	prox = -1;

}

// ***********************************************
// ***                                         ***
// ***********************************************
float cNoLSEA::getDado() {
	
	return dado;
}

// ***********************************************
// ***                                         ***
// ***********************************************
void cNoLSEA::setDado(float n) {
	
	dado = n;
}

// ***********************************************
// ***                                         ***
// ***********************************************
int cNoLSEA::getProx() {
	
	return prox;
}

// ***********************************************
// ***                                         ***
// ***********************************************
void cNoLSEA::setProx(int i) {
	
	prox = i;
}

// ***********************************************
// ***                                         ***
// ***********************************************
void cNoLSEA::imprimeNo() {

	std::cout << " ( " << dado << " , " << prox << " ) " << std::endl;

}

// ***********************************************
// ***                                         ***
// ***********************************************
void cNoLSEA::imprimeDado() {

	std::cout << dado;

}

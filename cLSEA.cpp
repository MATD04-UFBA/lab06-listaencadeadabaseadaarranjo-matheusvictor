#include <stdio.h>
#include <stdlib.h>

#include "cLSEA.h"
#include "cNoLSEA.h"

// ***********************************************
// ***                                         ***
// ***********************************************
cLSEA::cLSEA() {	
		
	inicio 		= NULO;
    numElems 	= 0;
    tamMax 		= 0;
    
    V 			= NULL;    
}

// ***********************************************
// ***                                         ***
// ***********************************************
cLSEA::cLSEA(int num) {	
		
	inicio 		= NULO;
    numElems 	= 0;
    tamMax 		= 0;
    
    V = new cNoLSEA [num];

    if (V != NULL) {
		tamMax = num;
		this->limparLista();
		}

}

// ***********************************************
// ***                                         ***
// ***********************************************
cLSEA::~cLSEA() {
	
	delete[] V;

}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEA::inserirElem(float k) {

int novoNo = 0,
	noCor;

	if ( numElems == tamMax)					// Verifica se o vetor já esta cheio
		return false;
    
	while(V[novoNo].getProx() != novoNo) 		// Procura um elemento vazio, cujo prox aponta para ele mesmo
 		novoNo++;								// É garantido sua existencia pois o vetor não esta cheio

	V[novoNo].setDado(k);						// Coloca o novo dado no nó vazio
	V[novoNo].setProx(NULO);					// Sinaliza que ele será o ultimo, apontando para NULO

	if(inicio == NULO) 							// Verifica se a lista esta vazia
		inicio = novoNo;						// e nesse caso é necessário atualizar o inicio da lista

	else {										// A lista tem pelo menos um elemento

		noCor = inicio;							// Inicia a busca do ultimo elemento da lista pelo primeiro

		while (V[noCor].getProx() != NULO) 		// Busca o ultimo elemento, cujo campo prox do nó aponta para NULO
			noCor = V[noCor].getProx();			// Avança na lista pelo encadeamento, ou seja, o campo prox do nó

		V[noCor].setProx(novoNo);				// Encontrado o ultimo elemento faz com que ele aponte para o novo nó
		}
		
	numElems++;									// Atualiza o numero de elementos armazenados na lista

	return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEA::removerElem(float k) {

int noCor,
	noAnt;

	if ( numElems == 0 )						// Verifica se a lista é vazia (poderia verificar pelo inicio == NULO)
		return false;

	if (!buscarElem(k, noCor, noAnt))			// Busca a posição da chave na lista e seu nó anterior
		return false;							// Busca sem sucesso

	if (noAnt == NULO)  						// O elemento a ser removido é o primeiro
		inicio = V[noCor].getProx();			// Atualiza o inicio pois não há nó anterior ao primmeiro 
	else 										// O elemento a ser removido não é o primeiro
		V[noAnt].setProx(V[noCor].getProx());	// Atualiza o encadeamento do nó anterior para apontar para o proximo do nó a ser removido
	
	V[noCor].setProx(noCor);					// Marca o nó corrente como livre.
		
	numElems--;									// Reduz o numero de elementos da lista

	return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEA::buscarElem(float k, int &pos) {
		
	pos = NULO;

	if ( numElems == 0 )						// Verifica se a lista é vazia (poderia verificar pelo inicio == NULO)
		return false;

	pos = inicio;								// Ajusta o apontador do nó corrente da busca para o primeiro da lista

	while 	( 	(pos != NULO) &&				// Final da lista encontrado 
				(V[pos].getDado() != k) 		// Chave de busca encontrada
			) {
		pos = V[pos].getProx();					// Nó corrente avança para o proximo nó da lista
		}

	if(pos == NULO) 							// Verifica se a busca terminou pelo final da lista
		return false;							// Busca sem sucesso

	return true;
}


// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEA::buscarElem(float k, int &noCor, int &noAnt) {

	noCor = 
	noAnt =	NULO;	

	if ( numElems == 0 )						// Verifica se a lista é vazia (poderia verificar pelo inicio == NULO)
		return false;

	noCor = inicio;								// Ajusta o apontador do nó corrente da busca para o primeiro da lista
	noAnt = NULO;								// Ajusta o apontador do nó anterior ao corrente para NULO (não há nó antes do primeiro)

	while 	( 	(noCor != NULO) &&				// Final da lista encontrado 
				(V[noCor].getDado() != k) 		// Chave de busca encontrada
			) {
		noAnt = noCor;							// Nó corrente na proxima repetição vira o nó anterior
		noCor = V[noCor].getProx();				// Nó corrente avança para o proximo nó da lista
		}

	if(noCor == NULO) 							// Verifica se a busca terminou pelo final da lista
		return false;							// Busca sem sucesso

	return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEA::buscarElem(float k) {
		
int noCor = NULO;

	if ( numElems == 0 )						// Verifica se a lista é vazia (poderia verificar pelo inicio == NULO)
		return false;

	noCor = inicio;								// Ajusta o apontador do nó corrente da busca para o primeiro da lista

	while 	( 	(noCor != NULO) &&				// Final da lista encontrado 
				(V[noCor].getDado() != k) 		// Chave de busca encontrada
			) {
		noCor = V[noCor].getProx();				// Nó corrente avança para o proximo nó da lista
		}

	if(noCor == NULO) 							// Verifica se a busca terminou pelo final da lista
		return false;							// Busca sem sucesso

	return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
void cLSEA::limparLista() {

	for (int i = 0 ; i < tamMax ; i++) {
		V[i].setDado(0.0);
		V[i].setProx(i);
	    }
}

// ***********************************************
// ***                                         ***
// ***********************************************
void cLSEA::imprimirLSEA() {

	std::cout << "------------ LISTA ------------" << std::endl;

	if (inicio == NULO) {
		std::cout << "*********** LISTA VAZIA ***********" << std::endl;
		return;
		}

	int noCor = inicio;

	std::cout << "[ ";

	while (noCor != NULO) {
		V[noCor].imprimeDado();
		std::cout << " , ";
		noCor = V[noCor].getProx();
		}

	std::cout << " ]" << std::endl;

	std::cout << "-------------------------------" << std::endl;	

}

// ***********************************************
// ***                                         ***
// ***********************************************
void cLSEA::imprimirLSEACompleta() {

	std::cout << "=============== LISTA COMPLETA ===============" << std::endl;
	std::cout << "++++++++++++  inicio = " << inicio << "  ++++++++++++++" << std::endl; 
	std::cout << "=============================================" << std::endl;	

	for (int i = 0 ; i < tamMax ; i++) {
		std::cout << "V[ " << i << "] = ";
		V[i].imprimeNo();
		}

	std::cout << "=============================================" << std::endl;	

}

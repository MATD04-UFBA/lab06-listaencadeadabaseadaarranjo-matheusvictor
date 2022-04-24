/* Classe No de uma Lista Simplesmente Encadeada */ 

#pragma once

#include<iostream>

#include "cNoLSEA.h"

#define NULO -1

class cLSEA {           // Lista Simplesmente Encadeada baseada em Arranjos

private:
    cNoLSEA *V;			// vetor que armazena os elementos da lista
    int     inicio;     // Indice do primeiro elemento da lista dentro do vetor
    int     numElems;	// numero de elementos na lista em um determinado momento
    int     tamMax;		// tamanho maximo da lista. 

    void limparLista();
    bool buscarElem(float k, int &noCor, int &noAnt);

public:
    cLSEA();
    cLSEA(int n);
    ~cLSEA();

    bool inserirElem(float k);

    bool removerElem(float k);

    bool buscarElem(float k, int &pos);

    bool buscarElem(float k);

    void imprimirLSEA();

    void imprimirLSEACompleta();

};
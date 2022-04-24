#pragma once

#include<iostream>

class cNoLSEA {     // Nó de Lista Simplesmente Encadeada baseada em Arranjos

private:
	float 	dado;
 	int 	prox;

public:
    cNoLSEA();
    cNoLSEA(float n);
    ~cNoLSEA();

    float   getDado();
    void    setDado(float n);

    int     getProx();
    void    setProx(int n);

    void    imprimeNo();
    void    imprimeDado();
};


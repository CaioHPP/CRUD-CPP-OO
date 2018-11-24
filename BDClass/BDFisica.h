/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#ifndef BDFisica_H
#define BDFisica_H


#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "..\\Classes\\Fisica.h"
#include "SeparaString.h"
#include "BDPessoa.h"

using namespace std;


class BDFisica {
public:
	bool guardar(Fisica fisica);
	bool buscar(string cpf, Fisica * fisica);
	bool buscar(int id, Fisica * fisica);
	Fisica * buscar(string cpf);
	Fisica * buscar(int id);
	Fisica ** buscarN(string nome, int *retornoQuantidade);
	bool apagar(Fisica * fisica);
	bool alterar(Fisica * FisicaNovo, Fisica FisicaAntiga);
};

#endif
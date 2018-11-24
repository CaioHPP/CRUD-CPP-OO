/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#ifndef BDPessoa_H
#define BDPessoa_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "..\\Classes\\Pessoa.h"
#include "SeparaString.h"

using namespace std;


class BDPessoa {
public:
	bool guardar(Pessoa pessoa);

	bool buscar(int id, Pessoa * pessoa);
	Pessoa * buscar(int id);
	bool apagar(Pessoa * pessoa);
	bool alterar(Pessoa * PessoaNova, Pessoa PessoaAntiga);
	Pessoa ** buscarN(string nome, int *retornoRegistroEncontrados);

};

#endif
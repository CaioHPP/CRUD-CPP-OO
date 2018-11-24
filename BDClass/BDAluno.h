/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#ifndef BDAluno_H
#define BDAluno_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "..\\Classes\\Aluno.h"
#include "SeparaString.h"
#include "BDFisica.h"

class BDAluno {
public:
	bool guardar(Aluno aluno);
	bool buscar(int id, Aluno * aluno);
	Aluno * buscar(string cpf);
	Aluno * buscar(int id);
	Aluno ** buscarN(string nome, int *retornoQuantidade);
	bool apagar(Aluno * aluno);
	bool alterar(Aluno * AlunoNovo, Aluno AlunoAntigo);
};


#endif
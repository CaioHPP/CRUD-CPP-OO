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
	bool apagar(Aluno * aluno);
	bool alterar(Aluno * AlunoNovo, Aluno AlunoAntigo);
};


#endif
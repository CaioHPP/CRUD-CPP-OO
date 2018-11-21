#ifndef BDAluno_H
#define BDAluno_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "..\\Classes\\Aluno.h"
#include "SeparaString.h"


class BDAluno {
public:
	bool guardar(Aluno aluno);
	bool mostrar();
	bool apagarLinha(string linha);
};


#endif
#ifndef BDJuridica_H
#define BDJuridica_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "..\\Classes\\Juridica.h"
#include "SeparaString.h"
#include "BDPessoa.h"

class BDJuridica {
public:
	bool guardar(Juridica Juridica);
	bool buscar(string cpf, Juridica * Juridica);
	bool buscar(int id, Juridica * Juridica);
	Juridica * buscar(string cnpj);
	Juridica * buscar(int id);
	bool apagar(Juridica * Juridica);
	bool alterar(Juridica * JuridicaNova, Juridica JuridicaAntiga);
};

#endif
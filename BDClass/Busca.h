#ifndef BD_H
#define BD_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "SeparaString.h"

using namespace std;

class Busca{
	
	int verificaTipo(string tipo);
	void ImprimeDados(string line, int xCaminho);
	void mostraResultados(int i);
	bool buscaGeral(string caminho, string valorAtributo, string tipo);
public:
	int verificaCaminho(string caminho);

	string buscaLinha(string caminho, string valorAtributo, string tipo);

	bool buscaFisica(string valorAtributo);
	bool buscaAluno(string valorAtributo);
	bool buscaJuridica(string valorAtributo);

	void buscaNomeF(string valorAtributo);
	void buscaNomeA(string valorAtributo);
	void buscaNomeJ(string valorAtributo);
};


#endif
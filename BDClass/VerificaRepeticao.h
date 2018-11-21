#ifndef BVer_H
#define BVer_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Busca.h"


using namespace std;


class VerificacaoRepeticao{
	int buscaPeloElemento(string caminho, string valorAtributo, int pos);
public:
	bool VerificaRepeticao(string caminho, string valorAtributo, int pos);
};
#endif
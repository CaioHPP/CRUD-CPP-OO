#ifndef BD_H
#define BD_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Classes.h"

using namespace std;


class Busca{
	
	int verificaTipo(string tipo);
	void ImprimeDados(string line, int xCaminho);
	void mostraResultados(int i);
	void buscaGeral(string caminho, string valorAtributo, string tipo);
public:
	int verificaCaminho(string caminho);

	void buscaFisica(string valorAtributo);
	void buscaAluno(string valorAtributo);
	void buscaJuridica(string valorAtributo);

	void buscaNomeF(string valorAtributo);
	void buscaNomeA(string valorAtributo);
	void buscaNomeJ(string valorAtributo);
};

class VerificacaoRepeticao{
	int buscaPeloElemento(string caminho, string valorAtributo, int pos);
public:
	bool VerificaRepeticao(string caminho, string valorAtributo, int pos);
};


class SeparaString{

public:
	void splitter(string linha, string linhasplitada[]);

	void aluno(string line);
	void fisica(string line);
	void juridica(string line);
};

class BDPessoa {
public:
	bool guardar(Pessoa pessoa);
	bool mostrar();
};

class BDFisica {
public:
	bool guardar(Fisica fisica);
	
	bool mostrar();
};

class BDJuridica {
public:
	bool guardar(Juridica juridica);
	bool mostrar();
};

class BDAluno {
public:
	bool guardar(Aluno aluno);
	bool mostrar();
};

#endif
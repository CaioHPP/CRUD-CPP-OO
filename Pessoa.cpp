/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#include"Classes\\Pessoa.h"


using namespace std;




Pessoa::Pessoa(){};

Pessoa::proximoId(){
	idcount++;
	return idcount;
}
Pessoa::Pessoa(int id){ 
	this->id = id;
}

void Pessoa::setId(int id){
	this->id = id;
}

int Pessoa::getId(){ 
	return id;
}

string Pessoa::getNome(){ 
	return nome;
}
void Pessoa::setNome(string nome){ 
	this->nome = nome;
}

int Pessoa::idcount = 0;

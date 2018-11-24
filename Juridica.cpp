/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#include "Classes\\Juridica.h"



Juridica::Juridica(){};




Juridica::Juridica(int i):Pessoa(i){}

string Juridica::getCnpj(){return this->cnpj;}
void Juridica::setCnpj(string c){ this->cnpj = c; }


string Juridica::toString(){
	stringstream ss;
	ss.str("");
	ss << getId() << ";" << getCnpj();
	return ss.str(); 
}



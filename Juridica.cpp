#include "Classes\\Juridica.h"



Juridica::Juridica(){};




Juridica::Juridica(int i):Pessoa(i){}

string Juridica::getCnpj(){return this->cnpj;}
void Juridica::setCnpj(string c){ this->cnpj = c; }


string Juridica::toString(){
	stringstream ss;
	ss.str("");
	ss << getId() << ";" << getNome() << ";" << getCnpj();
	return ss.str(); 
}



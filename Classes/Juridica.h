#ifndef Juridica_h
#define Juridica_h


#include"Pessoa.h"



class Juridica: public Pessoa {
	string cnpj;

public:
	Juridica(int i);
	Juridica();
	string getCnpj();
	void setCnpj(string c);


	string toString();
};

#endif
#ifndef Fisica_h
#define Fisica_h


#include"Pessoa.h"


class Fisica: public Pessoa {
	string cpf;
	int idade;

public:

	Fisica(int i);
	Fisica();
	string getCpf();
	void setCpf(string cpf);

	int getIdade();
	void setIdade(int idade);


	string toString();


};

#endif
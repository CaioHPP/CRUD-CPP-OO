#include"Classes\\Pessoa.h"


using namespace std;




Pessoa::Pessoa(){};


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

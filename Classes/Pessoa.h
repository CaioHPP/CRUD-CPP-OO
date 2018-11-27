#ifndef Pessoa_h
#define Pessoa_h

#include <fstream>
#include <string>
#include <sstream>
using namespace std;


class Pessoa{
protected:
	static int idcount;
	int id;
	string nome;

public:
	proximoId();
	Pessoa(int id);
	Pessoa();
	int getId();
	void setId(int id);

	string getNome();
	void setNome(string nome);
};

#endif
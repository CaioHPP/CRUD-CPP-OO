#ifndef Classes_h
#define Classes_h

#include <fstream>
#include <string>
#include <sstream>



using namespace std;

class Pessoa{
protected:
  int id;
  string nome;

public:
  Pessoa(int id);
  Pessoa();
  int getId();

  string getNome();
  void setNome(string nome);
};


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

class Aluno: public Fisica{

 string curso;
 string faculdade;

public:
  Aluno(int i);
  Aluno();
  string getCurso();
  void setCurso(string curso);

  string getFaculdade();
  void setFaculdade(string faculdade);


  string toString();
};


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
#include <fstream>
#include <string>
#include <sstream>
#include"Classes.h"
#include "BD.h"

using namespace std;

stringstream ss;

Pessoa::Pessoa(){};
Juridica::Juridica(){};
Fisica::Fisica(){};
Aluno::Aluno(){};


Pessoa::Pessoa(int id){ this->id = id;}

void Pessoa::setId(int id){this->id = id;}

int Pessoa::getId(){ return id;}

string Pessoa::getNome(){ return nome;}
void Pessoa::setNome(string nome){ this->nome = nome;}


Fisica::Fisica(int i):Pessoa(i){}

string Fisica::getCpf(){return this->cpf;}
void Fisica::setCpf(string cpf){ this->cpf = cpf;}

int Fisica::getIdade(){ return this->idade; }
void Fisica::setIdade(int idade){
 if(idade > 120) this->idade = 120; else this->idade = idade;
}


string Fisica::toString(){
  ss.str("");
  ss << getId() << ";" << getNome() << ";" << getCpf() << ";" << getIdade();
      //string toString = ss.str() + ";" + nome + ";" + cpf + ";" + ss.str();
  return ss.str(); 
}





Aluno::Aluno(int i):Fisica(i){}

string Aluno::getCurso(){ return curso; }
void Aluno::setCurso(string curso){ this->curso = curso;}

string Aluno::getFaculdade(){ return faculdade;}
void Aluno::setFaculdade(string faculdade){ this->faculdade = faculdade;}


string Aluno::toString(){
  ss.str("");
  ss << getId() << ";" << getNome() << ";" << getCpf() << ";" << getIdade() << ";" << getFaculdade() << ";" << getCurso();
     // string toString = to_string(id) + ";" + nome + ";" + getCpf() + ";" + to_string(getIdade()) + ";" + curso + ";" + faculdade;
  return ss.str();
}



Juridica::Juridica(int i):Pessoa(i){}

string Juridica::getCnpj(){return this->cnpj;}
void Juridica::setCnpj(string c){ this->cnpj = c; }


string Juridica::toString(){
  ss.str("");
  ss << getId() << ";" << getNome() << ";" << getCnpj();
  return ss.str(); 
}



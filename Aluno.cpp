#include "Classes\\Aluno.h"




Aluno::Aluno(){};


Aluno::Aluno(int i):Fisica(i){}

string Aluno::getCurso(){ return curso; }
void Aluno::setCurso(string curso){ this->curso = curso;}

string Aluno::getFaculdade(){ return faculdade;}
void Aluno::setFaculdade(string faculdade){ this->faculdade = faculdade;}


string Aluno::toString(){
	stringstream ss;
	ss.str("");
	ss << getId() << ";" << getCurso() << ";" << getFaculdade();
     // string toString = to_string(id) + ";" + nome + ";" + getCpf() + ";" + to_string(getIdade()) + ";" + curso + ";" + faculdade;
	return ss.str();
}
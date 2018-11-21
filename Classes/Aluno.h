#ifndef Aluno_h
#define Aluno_h


#include"Fisica.h"


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

#endif
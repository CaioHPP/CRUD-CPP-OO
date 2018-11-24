/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#include "BDClass\\SeparaString.h" 


void SeparaString::splitter(string linha, string linhasplitada[]){
 int i = 0, x = 0;
 string buff = "";
 for (i; i < strlen(linha.c_str()); i++)
 {
  if(linha[i] != ';'){
   buff+= linha[i];
 }
 else if(linha[i] == ';'){
   linhasplitada[x] = buff;
   buff = "";
   x++;
 }
}
linhasplitada[x] = buff;
}

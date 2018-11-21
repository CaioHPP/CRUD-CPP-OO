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

void SeparaString::aluno(string line){
  string linhasplitada [6];
  splitter(line, linhasplitada);
  cout << "\nID: " << linhasplitada[0] << "\nNome: " << linhasplitada[1] << "\nCpf: " << linhasplitada[2] << "\nIdade: " << linhasplitada[3] << "\nCurso: " << linhasplitada[4] << "\nFaculdade: " << linhasplitada[5] <<'\n';

}
void SeparaString::fisica(string line){
  string linhasplitada [4];
  splitter(line, linhasplitada);
  cout << "\nID: " << linhasplitada[0] << "\nNome: " << linhasplitada[1] << "\nCpf: " << linhasplitada[2] << "\nIdade: " << linhasplitada[3] << '\n';


}
void SeparaString::juridica(string line){
  string linhasplitada [3];
  splitter(line, linhasplitada);
  cout << "\nID: " << linhasplitada[0] << "\nNome: " << linhasplitada[1] << "\nCNPJ: " << linhasplitada[2] << '\n';


}

#include "BDClass\\BDAluno.h"

#define caminhoF "Banco de Dados\\aluno.txt" //caminho Aluno.txt
#define caminhoT "Banco de Dados\\temp.txt" //caminho Temp.txt


bool BDAluno::guardar(Aluno aluno){
 ofstream arquivo;
 arquivo.open(caminhoF, ios::app);
 arquivo<<aluno.toString()<<endl;
 return true;
}
bool BDAluno::mostrar(){
 string line;
 ifstream arquivo (caminhoF);
 if (arquivo.is_open()){
  SeparaString linha;
  cout << "Aluno: \n" << "................................\n";
  while ( getline (arquivo,line) ){
    cout << "----------------";
    linha.aluno(line);
    cout << "----------------\n";
  }
  cout << "................................\n";
  arquivo.close();
}
else cout << "Unable to open file\n"; 
return true;
}

bool BDAluno::apagarLinha(string linha){
  string line;
  ofstream temporario;
  temporario.open(caminhoT, ios::app);
  ifstream arquivo(caminhoF);
  if(arquivo.is_open()){
    while(getline(arquivo,line)){
      if(line != linha){
        temporario<<line<<endl;
      }
    }
    arquivo.close();
  }
  temporario.close();
  
  remove(caminhoF);

  if(rename(caminhoT, caminhoF)!= 0){
    perror("Erro ao apagar ficheiro");
  }
 
  return true;
}



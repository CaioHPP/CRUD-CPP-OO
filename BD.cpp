

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>


#include "BD.h"

using namespace std;


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

int VerificacaoRepeticao::buscaPeloElemento(string caminho, string valorAtributo, int pos){
  string line;
  int i = 0;
  Busca busca;
  ifstream arquivo (caminho.c_str());
  int xCaminho = busca.verificaCaminho(caminho);
  int tipoBusca = pos;
  if (arquivo.is_open()){
    SeparaString linha;
    string linhasplitada[xCaminho];
    while ( getline (arquivo,line) ){
      linha.splitter(line, linhasplitada);
      if(linhasplitada[tipoBusca] == valorAtributo){
        i++;
      }          
    }
    arquivo.close();
  }
  else cout << ""; 
  return i;
}

bool VerificacaoRepeticao::VerificaRepeticao(string caminho, string valorAtributo, int pos){
  int existe = buscaPeloElemento(caminho, valorAtributo, pos);
  if (existe>0){
    return false;
  }
  else{
    return true;
  }


}

void Busca::mostraResultados(int i){

  if(i){
    cout << "Total de Resultados encontrados: " << i << "\n";
  }else{
    cout << "Nenhum Resultados encontrado \n";
  }

}

int Busca::verificaCaminho(string caminho){
  if(caminho == "Banco de Dados\\fisica.txt"){
    return 4;    
  }
  else if(caminho == "Banco de Dados\\juridica.txt"){
    return 3;
  }
  else {
    return 6;
  }
}

int Busca::verificaTipo(string tipo){
  if(tipo == "unico"){
    return 2;    
  }
  else if(tipo == "nome"){
    return 1;
  }
}

void Busca::ImprimeDados(string line, int xCaminho){
  SeparaString linha;
  if (xCaminho == 4){
    linha.fisica(line);
  }
  if (xCaminho == 3){
    linha.juridica(line);
  }
  if (xCaminho == 6){
    linha.aluno(line);
  }
}

bool Busca::buscaGeral(string caminho, string valorAtributo, string tipo){
  string line;
  ifstream arquivo (caminho.c_str());
  int xCaminho = verificaCaminho(caminho);
  int tipoBusca = verificaTipo(tipo);
  if (arquivo.is_open()){
    int i = 0;
    SeparaString linha;
    string linhasplitada[xCaminho];
    while ( getline (arquivo,line) ){
      linha.splitter(line, linhasplitada);
      if(linhasplitada[tipoBusca] == valorAtributo){
        ImprimeDados(line, xCaminho);
        i++;
      }          
    }
    mostraResultados(i);
    arquivo.close();
    if(i>0){
      return true;
    }else{
      return false;
    }
  }
  else {
    cout << ""; 
    return false;
  }

}

string Busca::buscaLinha(string caminho, string valorAtributo, string tipo){
 string line ="";
 ifstream arquivo (caminho.c_str());
 int xCaminho = verificaCaminho(caminho);
 int tipoBusca = verificaTipo(tipo);
 if (arquivo.is_open()){
  int i = 0;
  SeparaString linha;
  string linhasplitada[xCaminho];
  while ( getline (arquivo,line) ){
    linha.splitter(line, linhasplitada);
    if(linhasplitada[tipoBusca] == valorAtributo){
      return line;

    }  
  }

  arquivo.close();
}
else cout << ""; 

return "";
}



bool Busca::buscaFisica(string valorAtributo){
  bool x = buscaGeral("Banco de Dados\\fisica.txt", valorAtributo, "unico");
  return x;
}

bool Busca::buscaAluno(string valorAtributo){
  bool x = buscaGeral("Banco de Dados\\aluno.txt", valorAtributo, "unico");
  return x;
}

bool Busca::buscaJuridica(string valorAtributo){
  bool x = buscaGeral("Banco de Dados\\juridica.txt", valorAtributo, "unico");
  return x;
}

void Busca::buscaNomeF(string valorAtributo){
  buscaGeral("Banco de Dados\\fisica.txt", valorAtributo, "nome");
}

void Busca::buscaNomeA(string valorAtributo){
  buscaGeral("Banco de Dados\\aluno.txt", valorAtributo, "nome");
}

void Busca::buscaNomeJ(string valorAtributo){
  buscaGeral("Banco de Dados\\juridica.txt", valorAtributo, "nome");

}








bool BDPessoa::guardar(Pessoa pessoa){
 ofstream arquivo;
 arquivo.open("Banco de Dados\\pessoaaa.txt", ios::app);
 arquivo<<pessoa.getId()<<";"<<pessoa.getNome()<<endl;
 return true;
}
bool BDPessoa::mostrar(){
 string line;
 ifstream arquivo ("Banco de Dados\\pessoaaaa.txt");
 if (arquivo.is_open()){
  cout << "................................";
  while ( getline (arquivo,line) ){
   cout <<line << '\n';
 }
 cout << "................................";
 arquivo.close();
}
else cout << "Unable to open file\n"; 
return true;
}




bool BDFisica::guardar(Fisica fisica){
 ofstream arquivo;
 arquivo.open("Banco de Dados\\fisica.txt", ios::app);
 arquivo<<fisica.toString()<<endl;
 return true;
}
bool BDFisica::mostrar(){
 string line;
 ifstream arquivo ("Banco de Dados\\fisica.txt");
 if (arquivo.is_open()){
  SeparaString linha;
  cout << "Fisica: \n" << "................................\n";
  while ( getline (arquivo,line) ){
    cout << "----------------";
    linha.fisica(line);
    cout << "----------------\n";
  }
  cout << "................................\n";
  arquivo.close();
}
else cout << "Unable to open file\n"; 
return true;
}
bool BDFisica::apagarLinha(string linha){
  string line;
  ofstream temporario;
  temporario.open("Banco de Dados\\temp.txt", ios::app);
  ifstream arquivo("Banco de Dados\\fisica.txt");
  if(arquivo.is_open()){
    while(getline(arquivo,line)){
      if(line != linha){
        temporario<<line<<endl;
      }
    }
    arquivo.close();
  }
  temporario.close();
  remove("Banco de Dados\\fisica.txt");

  if(rename("Banco de Dados\\temp.txt", "Banco de Dados\\fisica.txt") != 0){
    perror("Erro ao apagar ficheiro");
  }
  else{
    cout << "Ficheiro Apagado com sucesso\n";
  }
  return true;
}




bool BDJuridica::guardar(Juridica juridica){
 ofstream arquivo;
 arquivo.open("Banco de Dados\\juridica.txt", ios::app);
 arquivo<<juridica.toString()<<endl;
 return true;
}
bool BDJuridica::mostrar(){
 string line;
 ifstream arquivo ("Banco de Dados\\juridica.txt");
 if (arquivo.is_open()){
  SeparaString linha;
  cout << "Juridica: \n" << "................................\n";
  while ( getline (arquivo,line) ){
    cout << "----------------";
    linha.juridica(line);
    cout << "----------------\n";
  }
  cout << "................................\n";
  arquivo.close();
}
else cout << "Unable to open file\n"; 
return true;
}

bool BDJuridica::apagarLinha(string linha){
  string line;
  ofstream temporario;
  temporario.open("Banco de Dados\\temp.txt", ios::app);
  ifstream arquivo("Banco de Dados\\juridica.txt");
  if(arquivo.is_open()){
    while(getline(arquivo,line)){
      if(line != linha){
        temporario<<line<<endl;
      }
    }
    arquivo.close();
  }
  temporario.close();
  ; 
  remove("Banco de Dados\\juridica.txt");

  if(rename("Banco de Dados\\temp.txt", "Banco de Dados\\juridica.txt")!= 0){
    perror("Erro ao apagar ficheiro");
  }
  else{
    cout << "Ficheiro Apagado com sucesso\n";
  }
  return true;
}




bool BDAluno::guardar(Aluno aluno){
 ofstream arquivo;
 arquivo.open("Banco de Dados\\aluno.txt", ios::app);
 arquivo<<aluno.toString()<<endl;
 return true;
}
bool BDAluno::mostrar(){
 string line;
 ifstream arquivo ("Banco de Dados\\aluno.txt");
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
  temporario.open("Banco de Dados\\temp.txt", ios::app);
  ifstream arquivo("Banco de Dados\\aluno.txt");
  if(arquivo.is_open()){
    while(getline(arquivo,line)){
      if(line != linha){
        temporario<<line<<endl;
      }
    }
    arquivo.close();
  }
  temporario.close();
  
  remove("Banco de Dados\\aluno.txt");

  if(rename("Banco de Dados\\temp.txt", "Banco de Dados\\aluno.txt")!= 0){
    perror("Erro ao apagar ficheiro");
  }
  else{
    cout << "Ficheiro Apagado com sucesso\n";
  }
  return true;
}





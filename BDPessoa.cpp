/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#include "BDClass\\BDPessoa.h"

#define caminhoid "Banco de Dados\\IDCount.txt" //caminho Fisica.txt
#define caminhoF "Banco de Dados\\pessoa.txt" //caminho Fisica.txt
#define caminhoT "Banco de Dados\\temp.txt" //caminho Temp.txt

using namespace std;

int BDPessoa::obtemId(){
  int id =0;
  string line;
  ifstream arquivo (caminhoid);
  if (arquivo.is_open()){
    while ( getline (arquivo,line)){
      id = stoi(line)+1;
    }
    arquivo.close();
    remove(caminhoid);
    ofstream arquivo;
    arquivo.open(caminhoid, ios::app);
    arquivo<<id<<endl;
    return id;
  }
  else {
    ofstream arquivo;
    arquivo.open(caminhoid, ios::app);
    arquivo<<1<<endl;
    return 1;
  }

}




bool BDPessoa::guardar(Pessoa pessoa){
 ofstream arquivo;
 arquivo.open(caminhoF, ios::app);
 arquivo<<pessoa.getId()<<";"<<pessoa.getNome()<<endl;
 return true;
}

bool BDPessoa::buscar(int id, Pessoa * p){
  string line;
  ifstream arquivo (caminhoF);
  if (arquivo.is_open()){

    SeparaString linha;
    string linhasplitada[2];
    while ( getline (arquivo,line) ){
      linha.splitter(line, linhasplitada);
      if(stoi(linhasplitada[0]) == id){
        p->setId(stoi(linhasplitada[0]));
        p->setNome(linhasplitada[1]);
        return true;
      }          
    }
    arquivo.close();
  }
  else {
    cout << "";
  }
  return false;
}


Pessoa ** BDPessoa::buscarN(string nome, int  *retornoRegistroEncontrados){
  Pessoa ** pessoas = new Pessoa*[1];
  string line;
  ifstream arquivo(caminhoF);
  if (arquivo.is_open()){
    SeparaString linha;
    string linhasplitada[2];
    while (getline(arquivo,line)){
      linha.splitter(line, linhasplitada);
      if(linhasplitada[1] == nome){
        pessoas[*retornoRegistroEncontrados] = new Pessoa();
        Pessoa * p = new Pessoa();
        p->setId(stoi(linhasplitada[0]));
        p->setNome(nome);
        pessoas[*retornoRegistroEncontrados] = p;
        *retornoRegistroEncontrados += 1;     

      }       
    }
    arquivo.close();
    if(*retornoRegistroEncontrados>0){
      return pessoas;
    }else{
      return NULL;
    }
  }
  else {
    cout << "";
  }
  return NULL;
}

Pessoa * BDPessoa::buscar(int id){
  Pessoa *p = new Pessoa();
  if(buscar(id, p)){
    return p;
  }else{
    return NULL;
  }

}


bool BDPessoa::apagar(Pessoa *p){
  SeparaString split;
  string line;
  ofstream temporario;
  temporario.open(caminhoT, ios::app);
  ifstream arquivo(caminhoF);
  if(arquivo.is_open()){
    while(getline(arquivo,line)){
      string linhasplitada[2];
      split.splitter(line, linhasplitada);
      if(stoi(linhasplitada[0]) != p->getId()){
        temporario<<line<<endl;
      }
    }
    arquivo.close();
  }
  temporario.close();
  remove(caminhoF);

  if(rename(caminhoT, caminhoF) != 0){
    perror("Erro ao apagar ficheiro");
    return false;
  }
  return true;
}

bool BDPessoa::alterar(Pessoa * PessoaNova, Pessoa PessoaAntiga){
  if(apagar(&PessoaAntiga) && guardar(*PessoaNova)){
    return true;
  }else{
    return false;
  }
}

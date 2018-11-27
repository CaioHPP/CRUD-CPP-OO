/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#include "BDClass\\BDAluno.h"

#define caminhoF "Banco de Dados\\aluno.txt" //caminho Aluno.txt
#define caminhoT "Banco de Dados\\temp.txt" //caminho Temp.txt


bool BDAluno::guardar(Aluno aluno){
  BDFisica bdf;
  Fisica * f1;
  if(aluno.getId() == 0){
    BDPessoa dbp;
    aluno.setId(dbp.obtemId());
  }
  f1->setId(aluno.getId());
  f1->setNome(aluno.getNome());
  f1->setCpf(aluno.getCpf());
  f1->setIdade(aluno.getIdade());
  bdf.guardar(* f1);
  ofstream arquivo;
  arquivo.open(caminhoF, ios::app);

  arquivo<<aluno.toString()<<endl;
  return true;
}


bool BDAluno::buscar(int id, Aluno * a){
  string line;
  ifstream arquivo (caminhoF);
  if (arquivo.is_open()){
    SeparaString linha;
    string linhasplitada[3];
    while ( getline (arquivo,line) ){
      linha.splitter(line, linhasplitada);
      if(stoi(linhasplitada[0]) == id){
        a->setCurso(linhasplitada[1]);
        a->setFaculdade(linhasplitada[2]);
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

Aluno * BDAluno::buscar(string cpf){
  Aluno *a = new Aluno();
  Fisica *f = new Fisica();
  BDFisica dbf;
  f = dbf.buscar(cpf);  
  if(f!=NULL){
    if(buscar(f->getId(), a)){
      a->setId(f->getId());
      a->setNome(f->getNome());
      a->setCpf(f->getCpf());
      a->setIdade(f->getIdade());
      return a;
    }else{
      return NULL;
    }
  }
  return NULL;

}

Aluno ** BDAluno::buscarN(string nome, int * qtde){
  BDFisica bdf;

  int achouA = 0;
  Fisica ** f = new Fisica*[1];
  f = bdf.buscarN(nome, qtde);
  Aluno ** alunos = new Aluno*[*qtde];
  if(f != NULL){
    for(int i = 0; i < *qtde;i++){
      alunos[i]=new Aluno();
      if(f[i]!=NULL){
        if(buscar(f[i]->getId(), alunos[i])){
          alunos[i]->setId(f[i]->getId());
          alunos[i]->setNome(f[i]->getNome());
          alunos[i]->setCpf(f[i]->getCpf());
          alunos[i]->setIdade(f[i]->getIdade());
          achouA++; 
        }else{
          alunos[i]=NULL;
        }
      }else{
        alunos[i]=NULL;
      }

    }
    if(achouA>0){
      return alunos;

    }
    return NULL;
  }else{
    return NULL;
    
  }
}

Aluno * BDAluno::buscar(int id){
  BDFisica bdf;
  Fisica *f = new Fisica();
  Aluno * a = new Aluno();
  f = bdf.buscar(id);
  if(f!=NULL){
    if(buscar(f->getId(), a)){
      a->setId(f->getId());
      a->setNome(f->getNome());
      a->setCpf(f->getCpf());
      a->setIdade(f->getIdade());

      return a;
    }

    else{
      return NULL;
    }
  }
  return NULL;
}


bool BDAluno::apagar(Aluno * a){
  BDFisica dbf;
  Fisica *f = new Fisica();
  f->setId(a->getId());
  dbf.apagar(f);
  SeparaString split;
  string line;
  ofstream temporario;
  temporario.open(caminhoT, ios::app);
  ifstream arquivo(caminhoF);
  if(arquivo.is_open()){
    while(getline(arquivo,line)){
      string linhasplitada[3]; 
      split.splitter(line, linhasplitada);
      if(stoi(linhasplitada[0]) != a->getId()){
        temporario<<line<<endl;
      }
    }
    arquivo.close();
  }
  temporario.close();
  remove(caminhoF);

  if(rename(caminhoT, caminhoF) != 0){
    perror("Erro ao apagar ficheiro");
  }

  return true;
}



bool BDAluno::alterar(Aluno * AlunoNovo, Aluno AlunoAntigo){
  if(apagar(&AlunoAntigo) && guardar(*AlunoNovo)){
    return true;
  }else{
    return false;
  }



};

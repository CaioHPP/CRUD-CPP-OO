#include"BDClass\\Busca.h" 

#define caminhoF "Banco de Dados\\fisica.txt" 
#define caminhoJ "Banco de Dados\\juridica.txt" 
#define caminhoA "Banco de Dados\\alunos.txt" 

void Busca::mostraResultados(int i){

  if(i){
    cout << "Total de Resultados encontrados: " << i << "\n";
  }else{
    cout << "Nenhum Resultados encontrado \n";
  }

}

int Busca::verificaCaminho(string caminho){
  if(caminho == caminhoF){
    return 4;    
  }
  else if(caminho == caminhoJ){
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
  bool x = buscaGeral(caminhoF, valorAtributo, "unico");
  return x;
}

bool Busca::buscaAluno(string valorAtributo){
  bool x = buscaGeral(caminhoA, valorAtributo, "unico");
  return x;
}

bool Busca::buscaJuridica(string valorAtributo){
  bool x = buscaGeral(caminhoJ, valorAtributo, "unico");
  return x;
}

void Busca::buscaNomeF(string valorAtributo){
  buscaGeral(caminhoF, valorAtributo, "nome");
}

void Busca::buscaNomeA(string valorAtributo){
  buscaGeral(caminhoA, valorAtributo, "nome");
}

void Busca::buscaNomeJ(string valorAtributo){
  buscaGeral(caminhoJ, valorAtributo, "nome");

}




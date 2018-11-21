
#include "BDClass\\VerificaRepeticao.h"


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



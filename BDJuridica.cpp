/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#include"BDClass\\BDjuridica.h"

#define caminhoF "Banco de Dados\\juridica.txt" //caminho Juridica.txt
#define caminhoT "Banco de Dados\\temp.txt" //caminho Temp.txt


bool BDJuridica::guardar(Juridica juridica){
	BDPessoa dbp;
	Pessoa * p;
	if(juridica.getId() == 0){
		juridica.setId(dbp.obtemId());
	}
	p->setId(juridica.getId());
	p->setNome(juridica.getNome());
	dbp.guardar(*p);
	ofstream arquivo;
	arquivo.open(caminhoF, ios::app);
	arquivo<<juridica.toString()<<endl;
	return true;
}

bool BDJuridica::buscar(string cnpj, Juridica * j){
	string line;
	ifstream arquivo (caminhoF);
	if (arquivo.is_open()){
		SeparaString linha;
		string linhasplitada[2];
		while ( getline (arquivo,line) ){
			linha.splitter(line, linhasplitada);
			if(linhasplitada[1] == cnpj){
				j->setId(stoi(linhasplitada[0]));
				j->setCnpj(linhasplitada[1]);
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

bool BDJuridica::buscar(int id, Juridica * j){
	string line;
	ifstream arquivo (caminhoF);
	if (arquivo.is_open()){
		SeparaString linha;
		string linhasplitada[2];
		while ( getline (arquivo,line) ){
			linha.splitter(line, linhasplitada);
			if(stoi(linhasplitada[0]) == id){
				j->setCnpj(linhasplitada[1]);
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

Juridica ** BDJuridica::buscarN(string nome, int *qtde){
	BDPessoa bdp;
	int achouJ = 0;
	Pessoa ** p = bdp.buscarN(nome, qtde);
	Juridica **j = new Juridica*[*qtde];
	if(p != NULL){
		for(int i = 0; i < *qtde;i++){
			Juridica * juridica = new Juridica();
			juridica = buscar(p[i]->getId());
			j[i]=new Juridica();
			j[i] = juridica;
			if(j[i]!= NULL){
				achouJ++;
			}
		}
		if(achouJ>0){
			return j;
		}
		return NULL;
	}else{
		return NULL;
	}
}


Juridica * BDJuridica::buscar(string cnpj){
	Juridica *j = new Juridica();
	if(buscar(cnpj, j)){
		Pessoa *p = new Pessoa();
		BDPessoa dbp;
		p=dbp.buscar(j->getId());
		j->setNome(p->getNome());
		return j;
	}else{
		return NULL;
	}

}

Juridica * BDJuridica::buscar(int id){
	Juridica *j = new Juridica();
	Pessoa *p = new Pessoa();
	BDPessoa dbp;
	p=dbp.buscar(j->getId());
	if(buscar(p->getId(), j)){
		j->setId(p->getId());
		j->setNome(p->getNome());
		return j;
	}else{
		return NULL;
	}

}

bool BDJuridica::apagar(Juridica *j){
	BDPessoa dbp;
	Pessoa *p = new Pessoa();
	p->setId(j->getId());
	dbp.apagar(p);
	SeparaString split;
	string line;
	ofstream temporario;
	temporario.open(caminhoT, ios::app);
	ifstream arquivo(caminhoF);
	if(arquivo.is_open()){
		while(getline(arquivo,line)){
			string linhasplitada[2];
			split.splitter(line, linhasplitada);
			if(stoi(linhasplitada[0]) != j->getId()){
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




bool BDJuridica::alterar(Juridica * JuridicaNova, Juridica JuridicaAntiga){
	if(apagar(&JuridicaAntiga) && guardar(*JuridicaNova)){
		return true;
	}else{
		return false;
	}
	
	

};


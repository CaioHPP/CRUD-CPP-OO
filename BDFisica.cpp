/*
APS DE PROG
ALUNO: CAIO HENRIQUE PEDROSO PEDRO
RA:1602950
ENGENHARIA ELETRÔNICA
PROF: LUCIO VALENTIN 
*/
#include "BDClass\\BDFisica.h"


#define caminhoF "Banco de Dados\\fisica.txt" //caminho Fisica.txt
#define caminhoT "Banco de Dados\\temp.txt" //caminho Temp.txt


bool BDFisica::guardar(Fisica fisica){
	BDPessoa dbp;
	Pessoa * p;
	p->setId(fisica.getId());
	p->setNome(fisica.getNome());
	dbp.guardar(*p);
	ofstream arquivo;
	arquivo.open(caminhoF, ios::app);
	arquivo<<fisica.toString()<<endl;
	return true;
}
bool BDFisica::buscar(string cpf, Fisica * f){
	string line;
	ifstream arquivo (caminhoF);
	if (arquivo.is_open()){
		
		SeparaString linha;
		string linhasplitada[3];
		while ( getline (arquivo,line) ){
			linha.splitter(line, linhasplitada);
			if(linhasplitada[1] == cpf){
				f->setId(stoi(linhasplitada[0]));
				f->setCpf(linhasplitada[1]);
				f->setIdade(stoi(linhasplitada[2]));
				
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

bool BDFisica::buscar(int id, Fisica * f){
	string line;
	ifstream arquivo (caminhoF);
	if (arquivo.is_open()){	
		SeparaString linha;
		string linhasplitada[3];
		while ( getline (arquivo,line) ){
			linha.splitter(line, linhasplitada);
			if(stoi(linhasplitada[0]) == id){
				f->setCpf(linhasplitada[1]);
				f->setIdade(stoi(linhasplitada[2]));
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


Fisica * BDFisica::buscar(string cpf){
	Fisica *f = new Fisica();
	if(buscar(cpf, f)){
		Pessoa *p = new Pessoa();
		BDPessoa dbp;
		p=dbp.buscar(f->getId());
		f->setNome(p->getNome());
		return f;
	}else{
		return NULL;
	}
}

Fisica ** BDFisica::buscarN(string nome, int *qtde){
	BDPessoa bdp;
	int achouF = 0;
	Pessoa ** p = bdp.buscarN(nome, qtde);
	Fisica ** fisicas = new Fisica*[*qtde];

	if(p != NULL){
		
		for(int i = 0; i < *qtde;i++){
			Fisica *f = new Fisica();
			f = buscar(p[i]->getId());
			fisicas[i] = new Fisica();
			fisicas[i]=f;
			if(fisicas[i] != NULL){
				achouF++;
			}
		}
		if(achouF>0){
			return fisicas;
		}
		
		return NULL;
	}else{
		return NULL;
	}
}

Fisica * BDFisica::buscar(int id){
	Fisica *f = new Fisica();
	Pessoa *p = new Pessoa();
	BDPessoa dbp;
	p = dbp.buscar(id);
	if(buscar(p->getId(), f)){
		f->setId(p->getId());
		f->setNome(p->getNome());
		return f;
	}else{
		return NULL;
	}

}
bool BDFisica::apagar(Fisica *f){
	BDPessoa dbp;
	Pessoa *p = new Pessoa();
	p->setId(f->getId());
	dbp.apagar(p);
	SeparaString split;
	string line;
	ofstream temporario;
	temporario.open(caminhoT, ios::app);
	ifstream arquivo(caminhoF);
	if(arquivo.is_open()){
		while(getline(arquivo,line)){
			string linhasplitada[3];
			split.splitter(line, linhasplitada);
			if(stoi(linhasplitada[0]) != f->getId()){
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

bool BDFisica::alterar(Fisica * FisicaNovo, Fisica FisicaAntiga){
	if(apagar(&FisicaAntiga) && guardar(*FisicaNovo)){
		return true;
	}else{
		return false;
	}
	
	

};


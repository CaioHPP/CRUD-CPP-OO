#include "BDClass\\BDFisica.h"

#define caminhoF "Banco de Dados\\fisica.txt" //caminho Fisica.txt
#define caminhoT "Banco de Dados\\temp.txt" //caminho Temp.txt


bool BDFisica::guardar(Fisica fisica){
	ofstream arquivo;
	arquivo.open(caminhoF, ios::app);
	arquivo<<fisica.toString()<<endl;
	return true;
}
bool BDFisica::mostrar(){
	string line;
	ifstream arquivo (caminhoF);
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

	if(rename(caminhoT, caminhoF) != 0){
		perror("Erro ao apagar ficheiro");
	}

	return true;
}


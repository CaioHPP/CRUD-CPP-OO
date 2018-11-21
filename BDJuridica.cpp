#include"BDClass\\BDjuridica.h"

#define caminhoJ "Banco de Dados\\juridica.txt" //caminho Juridica.txt
#define caminhoT "Banco de Dados\\temp.txt" //caminho Temp.txt


bool BDJuridica::guardar(Juridica juridica){
	ofstream arquivo;
	arquivo.open(caminhoJ, ios::app);
	arquivo<<juridica.toString()<<endl;
	return true;
}
bool BDJuridica::mostrar(){
	string line;
	ifstream arquivo (caminhoJ);
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
	temporario.open(caminhoT, ios::app);
	ifstream arquivo(caminhoJ);
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
	remove(caminhoJ);

	if(rename(caminhoT, caminhoJ)!= 0){
		perror("Erro ao apagar ficheiro");
	}
	
	return true;
}



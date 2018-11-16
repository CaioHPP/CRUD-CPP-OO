
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>


using namespace std;



bool guardar(string b){
	ofstream arquivo;
	arquivo.open("teste.txt", ios::app);
	arquivo<<b<<endl;
	return true;
}


bool mostrar(){
	string line;
	ifstream arquivo ("teste.txt");
	if (arquivo.is_open()){

		while ( getline (arquivo,line) ){
			cout<<line<<endl;

		}
		arquivo.close();
	}
	else cout << "Unable to open file\n"; 
	return true;
}

bool apagar(string x){
	string line;
	ofstream temporario;
	temporario.open("temp.txt", ios::app);
	ifstream arquivo("teste.txt");

	if(arquivo.is_open()){
		while(getline(arquivo,line)){
			if(line != x){
				temporario<<line<<endl;
			}
		}
		arquivo.close();
	}
	temporario.close();

	if( remove("teste.txt") != 0 ){
		perror( "Error deleting file" );
	}
	else{
		puts( "File successfully deleted" );
	}

	ofstream temp2;
	temp2.open("teste.txt", ios::app);
	ifstream arq("temp.txt");

	if(arq.is_open()){
		while(getline(arq,line)){
			temp2<<line<<endl;
		}
		arq.close();
	}

	temp2.close();
	
	if( remove("temp.txt") != 0 ){
		perror( "Error deleting file" );
	}
	else{
		puts( "File successfully deleted" );
	}
	
	return true;
}


int main(){
	char p;

	while(1){
		cin >> p;
		switch(p){
			case 'a':{
				string b;
				cout << "oq escrever";
				cin >> b;
				guardar(b);
				break;
			}
			case 'b':{

				mostrar();
				break;
			}
			case 'c':{
				string x;
				cout << "oq deletar";
				cin >> x;
				apagar(x);
				break;
			}

		}


	}
}
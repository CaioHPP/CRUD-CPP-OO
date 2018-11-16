

#include "GUI.h"



using namespace std;
GUI::GUI(){};


void GUI::mostraNomeAtributoParaColetar(string nomeAtributo){
	cout << "==================================" << endl;
	cout << "|" << nomeAtributo << ": " << "|";
}
string GUI::obtemValorAtributoString(string nomeAtributo){
	mostraNomeAtributoParaColetar(nomeAtributo);
	string aux;
	cin >> aux;
	return aux;
}
int GUI::obtemValorAtributoInt(string nomeAtributo){
	mostraNomeAtributoParaColetar(nomeAtributo);
	int aux;
	cin >> aux;
	return aux;
}


void GUI::menu(){
	cout << "\n================================================================\n\n";
	cout << "Para cadastrar Pessoa:" << "\n    Fisica - f \n    Juridica - j \n    Aluno - a\n";
	cout << "Para bucar os cadastros pressione - v\n";
	cout << "Para sair pressione - x \n"; 
	cout << "\n================================================================\n\n";
}

char GUI::obtemEscolha(){
	char escolha;
	cin >> escolha;
	return escolha;

}

void GUI::cadF(){
	Fisica f1;


	f1.setNome(obtemValorAtributoString("Nome completo"));
	f1.setIdade(obtemValorAtributoInt("Idade"));
	f1.setCpf(obtemValorAtributoString("Cpf"));
	BDFisica obj;
	obj.guardar(f1);

}
void GUI::cadJ(){
	Juridica j1;


	j1.setNome(obtemValorAtributoString("Nome"));
	j1.setCnpj(obtemValorAtributoString("Cnpj"));


	BDJuridica obj;
	obj.guardar(j1);



}
void GUI::cadA(){
	Aluno a1;


	a1.setNome(obtemValorAtributoString("Nome completo"));
	a1.setIdade(obtemValorAtributoInt("Idade"));
	a1.setCpf(obtemValorAtributoString("Cpf"));
	a1.setFaculdade(obtemValorAtributoString("Faculdade"));
	a1.setCurso(obtemValorAtributoString("Curso"));

	BDAluno obj;
	obj.guardar(a1);
}

void GUI::showAll(){
	BDAluno a;
	BDFisica f;
	BDJuridica j;

	f.mostrar();
	j.mostrar();
	a.mostrar();


}

void GUI::buscaF(){
	Busca busca;
	cout << "Deseja buscar atraves do nome(n) ou cpf(c)? \n";
	switch(obtemEscolha()){
		case 'c':{
			busca.buscaFisica(obtemValorAtributoString("CPF"));
			break;
		}
		case 'n':{
			busca.buscaNomeF(obtemValorAtributoString("Nome"));
			break;
		}
		default:{
			cout << "Erro";
			break;
		}
	}

}

void GUI::buscaJ(){
	Busca busca;
	cout << "Deseja buscar atraves do nome(n) ou CNPJ(c)? \n";
	switch(obtemEscolha()){
		case 'c':{
			busca.buscaJuridica(obtemValorAtributoString("CNPJ"));
			break;
		}
		case 'n':{
			busca.buscaNomeJ(obtemValorAtributoString("Nome"));
			break;
		}
		default:{
			cout << "Erro";
			break;
		}
	}
}

void GUI::buscaA(){
	Busca busca;
	cout << "Deseja buscar atraves do nome(n) ou cpf(c)? \n";
	switch(obtemEscolha()){
		case 'c':{
			busca.buscaAluno(obtemValorAtributoString("CPF"));
			break;
		}
		case 'n':{
			busca.buscaNomeA(obtemValorAtributoString("Nome"));
			break;
		}
		default:{
			cout << "Erro";
			break;
		}
	}
	
}

void GUI::showBuscas(){
	cout << "|||||||||||||||||||||||||||||||||";
	cout << "\nPara buscar: \n\tFisica(CPF) - f\n\tAluno(CPF) - a\n\tJuridica(CNPJ) - j\n\tMostrar Todos - t\n";
	cout << "|||||||||||||||||||||||||||||||||\n";
	switch(obtemEscolha()){
		case 'f':
		{
			buscaF();
			break;
		}
		case 'j':
		{
			buscaJ();
			break;
		}
		case 'a':
		{
			buscaF();
			break;
		}
		case 't':
		{
			showAll(); 
			break;
		}


	}

}


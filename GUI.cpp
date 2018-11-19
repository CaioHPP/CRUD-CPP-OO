

#include "GUI.h"



using namespace std;


GUI::GUI(){};


void GUI::mostraNomeAtributoParaColetar(string nomeAtributo){
	cout << "\n==================================" << endl;
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

string GUI::VerificaDado(int pos ,string valorAtributo, string pessoa){
	VerificacaoRepeticao ver;
	string caminho;
	bool x;
	if(pessoa == "fisica"){
		caminho = "Banco de Dados\\fisica.txt";
	}
	else if(pessoa == "juridica"){
		caminho = "Banco de Dados\\juridica.txt";
	}
	else{
		caminho = "Banco de Dados\\aluno.txt";
	}
	x = ver.VerificaRepeticao(caminho, valorAtributo, pos);
	if(x == true){
		return valorAtributo;
	}else{

		return VerificaDado(pos, obtemValorAtributoString("Dado existente, insira outro"), pessoa);
	}
}

int GUI::MenorId(string pessoa, int j){
	int i = j;
	VerificacaoRepeticao ver;
	string caminho;
	bool x;
	if(pessoa == "fisica"){
		caminho = "Banco de Dados\\fisica.txt";
	}
	else if(pessoa == "juridica"){
		caminho = "Banco de Dados\\juridica.txt";
	}
	else{
		caminho = "Banco de Dados\\aluno.txt";
	}
	x = ver.VerificaRepeticao(caminho, to_string(i), 0);
	if(x == true){
		return i;
	}else{

		return MenorId(pessoa, i+1);
	}


}

void GUI::cadF(){
	Fisica f1;

	f1.setId(MenorId("fisica", 0));
	f1.setNome(obtemValorAtributoString("Nome completo"));
	f1.setIdade(obtemValorAtributoInt("Idade"));
	f1.setCpf(VerificaDado(2, obtemValorAtributoString("Cpf"), "fisica"));
	BDFisica obj;
	obj.guardar(f1);

}
void GUI::cadJ(){
	Juridica j1;

	j1.setId(MenorId("juridica", 0));
	j1.setNome(obtemValorAtributoString("Nome"));
	j1.setCnpj(VerificaDado(2, obtemValorAtributoString("Cnpj"), "juridica"));


	BDJuridica obj;
	obj.guardar(j1);



}
void GUI::cadA(){
	Aluno a1;

	a1.setId(MenorId("aluno", 0));
	a1.setNome(obtemValorAtributoString("Nome completo"));
	a1.setIdade(obtemValorAtributoInt("Idade"));
	a1.setCpf(VerificaDado(2, obtemValorAtributoString("Cpf"), "aluno"));
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

void GUI::menuAlterarF(string linha){
	SeparaString split;
	cout<<"\nQual Informacao deseja alterar? \n\t1.Nome\n\t2.CPF\n\t3.Idade\n\t";
	string linhasplitada[4];
	split.splitter(linha, linhasplitada);
	Fisica f1;
	BDFisica obj;
	switch(obtemValorAtributoInt("Escolha a opcao")){
		case 1:{
			f1.setId(stoi(linhasplitada[0]));
			f1.setNome(obtemValorAtributoString("Novo Nome"));
			f1.setIdade(stoi(linhasplitada[3]));
			f1.setCpf(linhasplitada[2]);
			obj.apagarLinha(linha);
			obj.guardar(f1);
			break;
		}
		case 2:{
			f1.setId(stoi(linhasplitada[0]));
			f1.setNome(linhasplitada[1]);
			f1.setIdade(stoi(linhasplitada[3]));
			f1.setCpf(VerificaDado(2, obtemValorAtributoString("Novo Cpf"), "fisica"));
			obj.apagarLinha(linha);
			obj.guardar(f1);
			break;
		}
		case 3:{
			f1.setId(stoi(linhasplitada[0]));
			f1.setNome(linhasplitada[1]);
			f1.setIdade(obtemValorAtributoInt("Nova Idade"));
			f1.setCpf(linhasplitada[2]);
			obj.apagarLinha(linha);
			obj.guardar(f1);
			break;
		}
	}

}

void GUI::menuAlterarJ(string linha){
	SeparaString split;
	cout<<"\nQual Informacao deseja alterar? \n\t1.Nome\n\t2.CNPJ\n\t";
	string linhasplitada[3];
	split.splitter(linha, linhasplitada);
	Juridica j1;
	BDJuridica obj;
	switch(obtemValorAtributoInt("Escolha a opcao")){
		case 1:{
			j1.setId(stoi(linhasplitada[0]));
			j1.setNome(obtemValorAtributoString("Novo Nome"));
			j1.setCnpj(linhasplitada[2]);
			obj.apagarLinha(linha);
			obj.guardar(j1);
			break;
		}
		case 2:{
			j1.setId(stoi(linhasplitada[0]));
			j1.setNome(linhasplitada[1]);
			j1.setCnpj(VerificaDado(2, obtemValorAtributoString("Novo CNPJ"), "juridica"));
			obj.apagarLinha(linha);
			obj.guardar(j1);
			break;
		}
		
	}

}

void GUI::menuAlterarA(string linha){
	SeparaString split;
	cout<<"\nQual Informacao deseja alterar? \n\t1.Nome\n\t2.CPF\n\t3.Idade\n\t4.Curso\n\t5.Faculdade";
	string linhasplitada[6];
	split.splitter(linha, linhasplitada);
	Aluno a1;
	BDAluno obj;
	switch(obtemValorAtributoInt("Escolha a opcao")){
		case 1:{
			a1.setId(stoi(linhasplitada[0]));
			a1.setNome(obtemValorAtributoString("Novo Nome"));
			a1.setIdade(stoi(linhasplitada[3]));
			a1.setCpf(linhasplitada[2]);
			a1.setFaculdade(linhasplitada[5]);
			a1.setCurso(linhasplitada[4]);
			obj.apagarLinha(linha);
			obj.guardar(a1);
			break;
		}
		case 2:{
			a1.setId(stoi(linhasplitada[0]));
			a1.setNome(linhasplitada[1]);
			a1.setIdade(stoi(linhasplitada[3]));
			a1.setCpf(VerificaDado(2, obtemValorAtributoString("Novo Cpf"), "aluno"));
			a1.setFaculdade(linhasplitada[5]);
			a1.setCurso(linhasplitada[4]);
			obj.apagarLinha(linha);
			obj.guardar(a1);
			break;
		}
		case 3:{
			a1.setId(stoi(linhasplitada[0]));
			a1.setNome(linhasplitada[1]);
			a1.setIdade(obtemValorAtributoInt("Nova Idade"));
			a1.setCpf(linhasplitada[2]);
			a1.setFaculdade(linhasplitada[5]);
			a1.setCurso(linhasplitada[4]);
			obj.apagarLinha(linha);
			obj.guardar(a1);
			break;
		}
		case 4:{
			a1.setId(stoi(linhasplitada[0]));
			a1.setNome(linhasplitada[1]);
			a1.setIdade(stoi(linhasplitada[3]));
			a1.setCpf(linhasplitada[2]);
			a1.setCurso(obtemValorAtributoString("Nova Curso"));
			
			a1.setFaculdade(linhasplitada[5]);
			obj.apagarLinha(linha);
			obj.guardar(a1);
			break;
		}
		case 5:{
			a1.setId(stoi(linhasplitada[0]));
			a1.setNome(linhasplitada[1]);
			a1.setIdade(stoi(linhasplitada[3]));
			a1.setCpf(linhasplitada[2]);
			a1.setCurso(linhasplitada[4]);
			a1.setFaculdade(obtemValorAtributoString("Nova Faculdade"));
			obj.apagarLinha(linha);
			obj.guardar(a1);	
			break;
		}

	}

}



void GUI::menuRemocaoF(string valorAtributo){
	BDFisica bd;
	cout << "\n==========================\n";
	cout << "Para: \n\t remover cadastro - r \n\t alterar cadastro - u \n\t voltar ao menu - x";
	cout << "\n==========================\n";
	string linha = menuAchaLinha(valorAtributo, "fisica");

	switch(obtemEscolha()){
		case 'r':{
			bd.apagarLinha(linha);
			cout << "\n*Ficheiro apagado Com Sucesso!*\n";
			break;
		}
		case 'u':{
			menuAlterarF(linha);
			break;
		}
		case 'x':{
			break;
			
		}
	}
}

void GUI::menuRemocaoJ(string valorAtributo){
	BDJuridica bd;
	cout << "\n==========================\n";
	cout << "Para: \n\t remover cadastro - r \n\t alterar cadastro - u \n\t voltar ao menu - x";
	cout << "\n==========================\n";
	string linha = menuAchaLinha(valorAtributo,"juridica");

	switch(obtemEscolha()){
		case 'r':{
			bd.apagarLinha(linha);
			cout << "\n*Ficheiro apagado Com Sucesso!*\n";
			break;
		}
		case 'u':{
			menuAlterarJ(linha);
			break;
		}
		case 'x':{
			break;
			
		}
	}
}

void GUI::menuRemocaoA(string valorAtributo){
	BDAluno bd;
	cout << "\n==========================\n";
	cout << "Para: \n\t remover cadastro - r \n\t alterar cadastro - u \n\t voltar ao menu - x";
	cout << "\n==========================\n";
	string linha = menuAchaLinha(valorAtributo, "aluno");

	switch(obtemEscolha()){
		case 'r':{
			bd.apagarLinha(linha);
			cout << "\n*Ficheiro apagado Com Sucesso!*\n";
			break;
		}
		case 'u':{
			menuAlterarA(linha);
			break;
		}
		case 'x':{
			break;
			
		}
	}
}



string GUI::menuAchaLinha(string valorAtributo, string tipo){
	Busca busca;
	string caminho;
	if(tipo == "fisica"){
		caminho = "Banco de Dados\\fisica.txt";
	}
	else if(tipo == "juridica"){
		caminho = "Banco de Dados\\juridica.txt";
	}
	else{
		caminho = "Banco de Dados\\aluno.txt";
	}

	string linha = busca.buscaLinha(caminho, valorAtributo, "unico");

	return linha;
}

void GUI::buscaF(){
	Busca busca;
	cout << "Deseja buscar atraves do nome(n) ou cpf(c)? \n";
	switch(obtemEscolha()){
		case 'c':{
			string valorAtributo = obtemValorAtributoString("CPF");
			bool x = busca.buscaFisica(valorAtributo);//deletar - alterar - voltar ao menu
			if (x==true){
				menuRemocaoF(valorAtributo);
			}
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
			string valorAtributo = obtemValorAtributoString("CNPJ");
			bool x = busca.buscaJuridica(valorAtributo);
			if (x==true){
				menuRemocaoJ(valorAtributo);
			}
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
			string valorAtributo = obtemValorAtributoString("CPF");
			bool x = busca.buscaAluno(valorAtributo);//deletar - alterar - voltar ao menu
			if (x==true){
				menuRemocaoA(valorAtributo);
			} 
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
			buscaA();
			break;
		}
		case 't':
		{
			showAll(); 
			break;
		}


	}

}


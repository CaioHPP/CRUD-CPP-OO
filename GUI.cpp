#include "GUI\\GUI.h"

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

string GUI::ExisteCpf(string cpf){
	BDFisica bdf;
	Fisica * f;
	f = bdf.buscar(cpf);	
	if(f==NULL){
		return cpf;
	}else{
		return ExisteCpf(obtemValorAtributoString("Insira outro CPF"));
	}
}


string GUI::ExisteCnpj(string cnpj){
	BDJuridica bdj;
	Juridica * j;
	j = bdj.buscar(cnpj);	
	if(j==NULL){
		return cnpj;
	}else{
		return ExisteCnpj(obtemValorAtributoString("Insira outro CNPJ"));
	}
}



int GUI::ExisteId(int id){
	BDPessoa bdp;
	Pessoa * p;
	p = bdp.buscar(id);	
	if(p==NULL){
		return id;
	}else{
		return ExisteId(obtemValorAtributoInt("Insira outro ID"));
	}
	}




void GUI::cadF(){
	Fisica f1;

	f1.setId(ExisteId(obtemValorAtributoInt("ID")));
	f1.setNome(obtemValorAtributoString("Nome completo"));
	f1.setIdade(obtemValorAtributoInt("Idade"));
	f1.setCpf(ExisteCpf(obtemValorAtributoString("Cpf")));
	BDFisica obj;
	obj.guardar(f1);

}
void GUI::cadJ(){
	Juridica j1;

	j1.setId(ExisteId(obtemValorAtributoInt("ID")));
	j1.setNome(obtemValorAtributoString("Nome"));
	j1.setCnpj(ExisteCpf(obtemValorAtributoString("CNPJ")));


	BDJuridica obj;
	obj.guardar(j1);



}
void GUI::cadA(){
	Aluno a1;

	a1.setId(ExisteId(obtemValorAtributoInt("ID")));
	a1.setNome(obtemValorAtributoString("Nome completo"));
	a1.setIdade(obtemValorAtributoInt("Idade"));
	a1.setCpf(ExisteCpf(obtemValorAtributoString("Cpf")));
	a1.setFaculdade(obtemValorAtributoString("Faculdade"));
	a1.setCurso(obtemValorAtributoString("Curso"));

	BDAluno obj;
	obj.guardar(a1);
}

void GUI::menuAlterarF(Fisica fAntiga){
	cout<<"\nQual Informacao deseja alterar? \n\t1.Nome\n\t2.CPF\n\t3.Idade\n\t";
	Fisica * f1 = new Fisica();
	BDFisica obj;
	f1 = obj.buscar(fAntiga.getCpf());
	switch(obtemValorAtributoInt("Escolha a opcao")){
		case 1:{
			f1->setId(fAntiga.getId());
			f1->setNome(obtemValorAtributoString("Novo Nome"));
			f1->setIdade(fAntiga.getIdade());
			f1->setCpf(fAntiga.getCpf());
			obj.alterar(f1, fAntiga);
			break;
		}
		case 2:{
			f1->setId(fAntiga.getId());
			f1->setNome(fAntiga.getNome());
			f1->setIdade(fAntiga.getIdade());
			f1->setCpf(ExisteCpf(obtemValorAtributoString("CPF")));
			obj.alterar(f1, fAntiga);
			break;
		}
		case 3:{
			f1->setId(fAntiga.getId());
			f1->setNome(fAntiga.getNome());
			f1->setIdade(obtemValorAtributoInt("Nova Idade"));
			f1->setCpf(fAntiga.getCpf());
			obj.alterar(f1, fAntiga);
			break;
		}
	}

}

void GUI::menuAlterarJ(Juridica jAntiga){
	cout<<"\nQual Informacao deseja alterar? \n\t1.Nome\n\t2.CNPJ\n\t";
	Juridica * j1;
	BDJuridica obj;
	j1 = obj.buscar(jAntiga.getCnpj());
	switch(obtemValorAtributoInt("Escolha a opcao")){
		case 1:{
			j1->setId(jAntiga.getId());
			j1->setNome(obtemValorAtributoString("Novo Nome"));
			j1->setCnpj(jAntiga.getCnpj());
			obj.alterar(j1, jAntiga);
			break;
		}
		case 2:{
			j1->setId(jAntiga.getId());
			j1->setNome(jAntiga.getNome());
			j1->setCnpj(ExisteCnpj(obtemValorAtributoString("CNPJ")));
			obj.alterar(j1, jAntiga);
			break;
		}
		
	}

}

void GUI::menuAlterarA(Aluno aAntiga){
	cout<<"\nQual Informacao deseja alterar? \n\t1.Nome\n\t2.CPF\n\t3.Idade\n\t4.Curso\n\t5.Faculdade";
	Aluno * a1;
	BDAluno obj;
	a1 = obj.buscar(aAntiga.getCpf());
	switch(obtemValorAtributoInt("Escolha a opcao")){
		case 1:{
			a1->setId(aAntiga.getId());
			a1->setNome(obtemValorAtributoString("Novo Nome"));
			a1->setIdade(aAntiga.getIdade());
			a1->setCpf(aAntiga.getCpf());
			a1->setFaculdade(aAntiga.getFaculdade());
			a1->setCurso(aAntiga.getCurso());
			obj.alterar(a1, aAntiga);
			break;
		}
		case 2:{
			a1->setId(aAntiga.getId());
			a1->setNome(aAntiga.getNome());
			a1->setIdade(aAntiga.getIdade());
			a1->setCpf(ExisteCpf(obtemValorAtributoString("CPF")));
			a1->setFaculdade(aAntiga.getFaculdade());
			a1->setCurso(aAntiga.getCurso());
			obj.alterar(a1, aAntiga);
			break;
		}
		case 3:{
			a1->setId(aAntiga.getId());
			a1->setNome(aAntiga.getNome());
			a1->setIdade(obtemValorAtributoInt("Nova Idade"));
			a1->setCpf(aAntiga.getCpf());
			a1->setFaculdade(aAntiga.getFaculdade());
			a1->setCurso(aAntiga.getCurso());
			obj.alterar(a1, aAntiga);
			break;
		}
		case 4:{
			a1->setId(aAntiga.getId());
			a1->setNome(aAntiga.getNome());
			a1->setIdade(aAntiga.getIdade());
			a1->setCpf(aAntiga.getCpf());
			a1->setCurso(obtemValorAtributoString("Nova Curso"));
			a1->setFaculdade(aAntiga.getFaculdade());
			obj.alterar(a1, aAntiga);
			break;
		}
		case 5:{
			a1->setId(aAntiga.getId());
			a1->setNome(aAntiga.getNome());
			a1->setIdade(aAntiga.getIdade());
			a1->setCpf(aAntiga.getCpf());
			a1->setCurso(aAntiga.getCurso());
			a1->setFaculdade(obtemValorAtributoString("Nova Faculdade"));
			obj.alterar(a1, aAntiga);
			break;
		}

	}

}



void GUI::menuRemocaoF(Fisica f){
	BDFisica bd;
	cout << "\n==========================\n";
	cout << "Para: \n\t remover cadastro - r \n\t alterar cadastro - u \n\t voltar ao menu - x";
	cout << "\n==========================\n";

	switch(obtemEscolha()){
		case 'r':{
			bd.apagar(&f);
			cout << "\n*Ficheiro apagado Com Sucesso!*\n";
			break;
		}
		case 'u':{

			menuAlterarF(f);
			break;
		}
		case 'x':{
			break;
			
		}
	}
}

void GUI::menuRemocaoJ(Juridica j){
	BDJuridica bd;
	cout << "\n==========================\n";
	cout << "Para: \n\t remover cadastro - r \n\t alterar cadastro - u \n\t voltar ao menu - x";
	cout << "\n==========================\n";
	

	switch(obtemEscolha()){
		case 'r':{
			bd.apagar(&j);
			cout << "\n*Ficheiro apagado Com Sucesso!*\n";
			break;
		}
		case 'u':{
			menuAlterarJ(j);
			break;
		}
		case 'x':{
			break;
			
		}
	}
}

void GUI::menuRemocaoA(Aluno a){
	BDAluno bd;
	cout << "\n==========================\n";
	cout << "Para: \n\t remover cadastro - r \n\t alterar cadastro - u \n\t voltar ao menu - x";
	cout << "\n==========================\n";


	switch(obtemEscolha()){
		case 'r':{
			bd.apagar(&a);
			cout << "\n*Ficheiro apagado Com Sucesso!*\n";
			break;
		}
		case 'u':{
			menuAlterarA(a);
			break;
		}
		case 'x':{
			break;
			
		}
	}
}

void GUI::buscarF(){
	Busca busca;
	BDFisica dbf;

	cout << "Deseja buscar atraves do nome(n) ou cpf(c)? \n";
	switch(obtemEscolha()){
		case 'c':{
			string cpf = obtemValorAtributoString("CPF");
			Fisica * f = dbf.buscar(cpf);
			if (f!=NULL){	
				cout << "\nID: " << f->getId() << endl;
				cout << "Nome: " << f->getNome() << endl;
				cout << "Cpf: " << f->getCpf() << endl;
				cout << "Idade: " << f->getIdade() << endl;
				menuRemocaoF(*f);
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

void GUI::buscarJ(){
	Busca busca;
	BDJuridica dbj;
	cout << "Deseja buscar atraves do nome(n) ou CNPJ(c)? \n";
	switch(obtemEscolha()){
		case 'c':{
			string cnpj = obtemValorAtributoString("CPF");
			Juridica * j = dbj.buscar(cnpj);
			if (j!=NULL){
				cout << "\nID: " << j->getId() << endl;
				cout << "Nome: " << j->getNome() << endl;
				cout << "Cnpj: " << j->getCnpj() << endl;
				menuRemocaoJ(*j);
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

void GUI::buscarA(){
	Busca busca;
	BDAluno dba;
	cout << "Deseja buscar atraves do nome(n) ou cpf(c)? \n";
	switch(obtemEscolha()){
		case 'c':{
			string cpf = obtemValorAtributoString("CPF");
			Aluno * a = dba.buscar(cpf);
			if (a!=NULL){
				cout << "\nID: " << a->getId() << endl;
				cout << "Nome: " << a->getNome() << endl;
				cout << "Cpf: " << a->getCpf() << endl;
				cout << "Idade: " << a->getIdade() << endl;
				cout << "Faculdade: " << a->getFaculdade() << endl;
				cout << "Curso: " << a->getCurso() << endl;
				menuRemocaoA(*a);
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
	cout << "\nPara buscar: \n\tFisica(CPF) - f\n\tAluno(CPF) - a\n\tJuridica(CNPJ) - j\n";
	cout << "|||||||||||||||||||||||||||||||||\n";
	switch(obtemEscolha()){
		case 'f':
		{
			buscarF();
			break;
		}
		case 'j':
		{
			buscarJ();
			break;
		}
		case 'a':
		{
			buscarA();
			break;
		}

	}

}


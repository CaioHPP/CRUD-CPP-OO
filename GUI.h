#ifndef GUI_h
#define GUI_h

#include <string>
#include <stdio.h>

#include "BD.h"
#include "Classes.h"



using namespace std;
class GUI{
private:
	void mostraNomeAtributoParaColetar(string nomeAtributo);
	string obtemValorAtributoString(string nomeAtributo);
	int obtemValorAtributoInt(string nomeAtributo);
	string VerificaDado(int pos ,string valorAtributo, string pessoa);
	void buscaF();
	void buscaJ();
	void buscaA();
	int MenorId(string pessoa, int j);

	void menuRemocaoF(string valorAtributo);
	void menuRemocaoJ(string valorAtributo);
	void menuRemocaoA(string valorAtributo);

	void menuAlterarF(string linha);
	void menuAlterarJ(string linha);
	void menuAlterarA(string linha);

	string menuAchaLinha(string valorAtributo, string tipo);
public: 
	GUI();
	void menu();

	char obtemEscolha();

	void cadF();
	void cadJ();
	void cadA();

	void showAll();

	void showBuscas();




};



#endif


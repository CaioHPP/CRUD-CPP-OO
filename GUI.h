#ifndef GUI_h
#define GUI_h

#include <string>

#include "BD.h"
#include "Classes.h"



using namespace std;
class GUI{
private:
	void mostraNomeAtributoParaColetar(string nomeAtributo);
	string obtemValorAtributoString(string nomeAtributo);
	int obtemValorAtributoInt(string nomeAtributo);
	void buscaF();
	void buscaJ();
	void buscaA();

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


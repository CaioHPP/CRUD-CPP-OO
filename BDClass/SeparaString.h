#ifndef BDSplitter_H
#define BDSplitter_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;


class SeparaString{

public:
	void splitter(string linha, string linhasplitada[]);

	void aluno(string line);
	void fisica(string line);
	void juridica(string line);
};


#endif
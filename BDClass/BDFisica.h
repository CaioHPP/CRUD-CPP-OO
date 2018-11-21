#ifndef BDFisica_H
#define BDFisica_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "..\\Classes\\Fisica.h"
#include "SeparaString.h"

using namespace std;


class BDFisica {
public:
	bool guardar(Fisica fisica);
	bool mostrar();
	bool apagarLinha(string linha);
};

#endif
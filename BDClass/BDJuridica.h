#ifndef BDJuridica_H
#define BDJuridica_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include "..\\Classes\\Juridica.h"
#include "SeparaString.h"


class BDJuridica {
public:
	bool guardar(Juridica juridica);
	bool mostrar();
	bool apagarLinha(string linha);
};

#endif
#pragma once
#include "pch.h"
#include <string>
using namespace std;
class Persona
{
private:
	string nombre;
public:
	Persona(string nombre);
	string getNombre();
	string getPais();
	void virtual mostrar();
};


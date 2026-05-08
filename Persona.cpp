#include "pch.h"
#include "Persona.h"
Persona::Persona(string nombre) {
	this->nombre = nombre;
}
string Persona::getNombre() {
	return this->nombre;
}

#include "pch.h"
#include "Genero.h"
#include <iostream>
#include <string>
using namespace std;
Genero::Genero() {
	nombre = "";
}
Genero::Genero(string nombre, int id) {
	this->nombre = nombre;
	this->id = id;
}
Genero::~Genero() {
}

int Genero::getID() {
	return id;
}
string Genero::getNombre() {
	return nombre;
}
void Genero::setNombre(string v) {
	nombre = v;
}
void Genero::mostrar() {
	cout << "Genero: " << nombre << endl;
}
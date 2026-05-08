#include "pch.h"
#include "Usuario.h"
#include <iostream>
using namespace std;
Usuario::Usuario(string nombre, string nombreUsuario, string email, int contrasena, int id) : Persona(nombre)
{
	this->nombreUsuario = nombreUsuario;
	this->email = email;
	this->id = id;
	this->contrasena = contrasena;
	this->playlists = new Lista<Playlists*>();
}
Lista<Playlists*>* Usuario::getPlaylists() { return this->playlists; }
int Usuario::getID() { return this->id; }
void Usuario::setPlaylists(Lista<Playlists*>* playlists) { this->playlists = playlists; }

void Usuario::setFavoritos(ListaFavoritos* favoritos) { 
	if (favoritos != nullptr && favoritos != this->favoritos) delete this->favoritos;//
	this->favoritos = favoritos;
}

ListaFavoritos* Usuario::getFavoritos() { return this->favoritos; }

string Usuario::getNombreUsuario() { return this->nombreUsuario; }
string Usuario::getEmail() { return this->email; }
int Usuario::getContrasena() { return this->contrasena; }
void Usuario::mostrar() {
	cout << "Nombre: " << nombreUsuario << endl;
	cout << "Email: " << email << endl;
	cout << "Playlists: " << playlists->tam() << endl;
}
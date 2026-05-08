#include "pch.h"
#include "Artista.h"

Artista::Artista(string nombre, string generoPrincipal, int oyentesMensuales, string nombreArtistico, int id) : Persona(nombre) {
	this->nombreArtistico = nombreArtistico;
	this->generoPrincipal = generoPrincipal;
	this->oyentesMensuales = oyentesMensuales;
	this->id = id;
	this->albums = new Lista<Album*>();
}

Artista::~Artista() {}

int Artista::getID() {
	return id;
}

string Artista::getNombreArtistico() {
	return this->nombreArtistico;
}

string Artista::getGeneroPrincipal() {
	return this->generoPrincipal;
}
int Artista::getOyentesMensuales() {
	return this->oyentesMensuales;
}
Lista<Album*>* Artista::getAlbums() {
	return this->albums;
}
void Artista::setAlbums(Lista<Album*>* albums) {
	this->albums = albums;
}

void Artista::agregarAlbum(Album* a) {
	if (a == nullptr) return;
	this->albums->insertarInicio(a);
}

void Artista::mostrar() {
	cout << "Nombre: " << getNombre() << endl;
	cout << "Nombre Artistico: " << getNombreArtistico() << endl;
	cout << "Albunes: " << albums->tam() << endl;
}
#pragma once
#include "Persona.h"
#include <string>
#include <iostream>
#include "Lista.hpp"
#include "Album.h"
class Artista :
    public Persona
{
private:
	int id;
	string nombreArtistico;
	string generoPrincipal;
	int oyentesMensuales;
	Lista<Album*>* albums;
public:
	Artista();
	Artista(string nombre, string generoPrincipal, int oyentesMensuales, string nombreArtistico, int id);
	~Artista();	

	int getID();
	string getNombreArtistico();
	string getGeneroPrincipal();
	int getOyentesMensuales();
	Lista<Album*>* getAlbums();
	void setAlbums(Lista<Album*>* albums);

	void agregarAlbum(Album* a);

	void mostrar() override;
};


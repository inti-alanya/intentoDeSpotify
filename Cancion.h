#pragma once
#include <iostream>
#include <string>
#include "Artista.h"
#include "Album.h"
#include "Genero.h"
using namespace std;
class Cancion
{
private:
	Genero* genero;
	Artista* compositor;

	
	int id;
	string titulo;
	int duracion;
	int anioLanzamiento;

public:		
	Cancion();
	Cancion(string titulo, int duracion, Genero* genero, Artista* compositor, int anioLanzamiento);
	~Cancion();

	int getID();

	string getTitulo();
	void setTitulo(string titulo);

	int getDuracion();
	void setDuracion(int duracion);

	Genero* getGenero();

	void setGenero(Genero* genero);

	Artista* getCompositor();

	int getAnioLanzamiento();

	string duracionFormato();

	void   mostrarTodo(int indice);
};


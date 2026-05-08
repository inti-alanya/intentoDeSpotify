#pragma once
#include "Cancion.h"
#include "ListaDobleCircular.hpp"
#include "Usuario.h"
class Playlists
{
private:
	int id;
	string nombre;
	ListaDobleCircular<Cancion*>* canciones;
	Usuario* creador;
	bool modoRepeticion;
	bool visibilidad;
public:
	Playlists();
	Playlists(string nombre, Usuario* creador, int id, bool modoRepeticion, bool visibilidad);
	
	int getID();
	string getNombre();
	void setNombre(string nombre);
	ListaDobleCircular<Cancion*>* getCanciones();
	void setCanciones(ListaDobleCircular<Cancion*>* canciones);
	string getFechaCreacion();
	Usuario* getCreador();
	bool getModoRepeticion();
	void setModoRepeticion(bool modoRepeticion);
	bool getVisibilidad();
	void setVisibilidad(bool visibilidad);
	void mostrar();
	void listarCanciones();

};


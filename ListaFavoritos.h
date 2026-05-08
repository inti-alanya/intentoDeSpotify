#pragma once

#include "Cancion.h"
#include "Usuario.h"
#include "Lista.hpp"
class ListaFavoritos
{
private:
	int id;
	Usuario* usuario;
	Lista<Cancion*>* canciones;
public:
	ListaFavoritos();
	ListaFavoritos(int id, Usuario* propietario);
	~ListaFavoritos();

	int getID();
	Usuario* getUsuario();
	Lista<Cancion*>* getCanciones();
	void marcarFavorita(Cancion* cancion);
	bool desmarcarFavorita(int posicion);
	bool contiene(Cancion* cancion);
	void mostrar();

};


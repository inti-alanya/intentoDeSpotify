#pragma once
#include "ListaCircular.hpp"
#include "Cancion.h"
#include "Playlists.h"

class ReproductorActivo
{
private:
	ListaCircular<Cancion*>* listaCircular;
	bool repeticionActiva;
public:
	ReproductorActivo();
	~ReproductorActivo();
	void cargarPlaylist(Playlists* playlist);

	Cancion* actual() const;
	Cancion* avanzar();
	int getTamanio() const { return listaCircular->tam(); }
	bool vacio() const { return listaCircular->estaVacia(); }
	void limpiar() { listaCircular->limpiar(); }

	void activarRepeticion() { repeticionActiva = true; }
	void desactivarRepeticion() { repeticionActiva = false; }
	bool getRepeticionActiva() const { return repeticionActiva; }

	void mostrar() const;

};


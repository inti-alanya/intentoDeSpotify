#include "pch.h"
#include "ListaFavoritos.h"

ListaFavoritos::ListaFavoritos() {}
ListaFavoritos::ListaFavoritos(int id, Usuario* propietario) {
	this->id = id;
	this->usuario = propietario;
	this->canciones = new Lista<Cancion*>();
}
ListaFavoritos::~ListaFavoritos() {}

int ListaFavoritos::getID() { return id; }

Usuario* ListaFavoritos::getUsuario() { return usuario; }
Lista<Cancion*>* ListaFavoritos::getCanciones() { return canciones; }

void ListaFavoritos::marcarFavorita(Cancion* cancion) {
	if (cancion == nullptr) return;
	if (contiene(cancion)) return;
	canciones->insertarFinal(cancion);
}

bool ListaFavoritos::desmarcarFavorita(int posicion) { 
	if (posicion < 0 || posicion >= canciones->tam()) return false;
	canciones->eliminar(posicion);
	return true;
}

bool ListaFavoritos::contiene(Cancion* cancion) { 
		if (cancion == nullptr) return false;
		return canciones->contarSi([&](Cancion* c) { return c == cancion; }) > 0;// esto 
}
void ListaFavoritos::mostrar() {
	cout << "[Favoritos #" << id << "] ";
	if (usuario != nullptr) cout << "de " << usuario->getNombre();
	cout << "  " << canciones->tam() << " canciones\n";
}
#include "pch.h"
#include "Playlists.h"
Playlists::Playlists() : nombre(""),  creador(nullptr), modoRepeticion(false), visibilidad(false){
	canciones = new ListaDobleCircular<Cancion*>();
}
Playlists::Playlists(string nombre, Usuario* creador, int id, bool modoRepeticion, bool visibilidad) {
	this->nombre = nombre;
	this->creador = creador;
    this->id = id;
	this->modoRepeticion = modoRepeticion;
	this->visibilidad = visibilidad;
	this->canciones = new ListaDobleCircular<Cancion*>();
}

int Playlists::getID() {
    return id;
}
string Playlists::getNombre() {
    return nombre;
}
void Playlists::setNombre(string nombre) {
    this->nombre = nombre;
}
ListaDobleCircular<Cancion*>* Playlists::getCanciones() {
    return canciones;
}
void Playlists::setCanciones(ListaDobleCircular<Cancion*>* canciones) {
    this->canciones = canciones;
}
Usuario* Playlists::getCreador() {
    return creador;
}
bool Playlists::getModoRepeticion() {
    return modoRepeticion;
}
void Playlists::setModoRepeticion(bool modoRepeticion) {
    this->modoRepeticion = modoRepeticion;
}
bool Playlists::getVisibilidad() {
    return visibilidad;
}
void Playlists::setVisibilidad(bool visibilidad) {
    this->visibilidad = visibilidad;
}
void Playlists::mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Creador: " << creador->getNombre() << endl;
    cout << "Modo Repeticion: " << (modoRepeticion ? "Activado" : "Desactivado") << endl;
    cout << "Visibilidad: " << (visibilidad ? "Publica" : "Privada") << endl;
}
void Playlists::listarCanciones() {
    if (canciones == nullptr)
    {
        cout << "no hay musicas en la playlist" << endl; 
        return;
    }
	cout << "Canciones en la playlist: " << endl;
    canciones->recorrer([](Cancion* c) {
        if (c) cout << "- " << c->getTitulo() << endl;
		});
    
}
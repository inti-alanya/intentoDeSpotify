#include "pch.h"
#include "Album.h"

Album::Album() : id(0), nombre(""), anio(0), portada(""), artista(nullptr) {}

Album::Album(int id, string nombre, int anio,
    Artista* artista, string portada = "") {
    this->id = id;
	this->nombre = nombre;
    this->anio = anio;
    this->artista = artista;
	this->portada = portada;
}
Album::~Album(){}

int Album::getId(){return id;}
string Album::getNombre() {return nombre;}
int Album::getAnio() { return anio; }
const string Album::getPortada() { return portada; }
Artista* Album::getArtista() { return artista; }
Lista<Cancion*>*& Album::getCanciones() { return canciones; }

void Album::setId(int v) { this->id = id; }
void Album::setNombre(string v) { this->nombre = nombre; }
void Album::setAnio(int v) { this->anio = anio; }
void Album::setPortada(string v) { this->portada = portada; }
void Album::setArtista(Artista* a) { this->artista = artista; }

void Album::agregarCancion(Cancion* c){
    if (c == nullptr) return;
    canciones->insertarInicio(c);
}

void Album::mostrar() {
    std::cout << "[Album #" << id << "] " << nombre
        << " (" << anio << ")  "
        << canciones->tam() << " canciones";
    if (artista != nullptr)
        cout << "  -- " << artista->getNombreArtistico();
     cout << "\n";
}
#include "pch.h"
#include "ReproductorActivo.h"
#include "Playlists.h"
#include <iostream>

ReproductorActivo::ReproductorActivo()
    : repeticionActiva(false) {

}
void ReproductorActivo::cargarPlaylist(Playlists* playlist) {
    listaCircular->limpiar();
    if (playlist == nullptr) return;
    ListaDobleCircular<Cancion*>* canciones = playlist->getCanciones();
    
    canciones->recorrer([this](Cancion* c) {
        if (c) listaCircular->insertarFinal(c);   
    });
    
    listaCircular->reiniciarCursor();
    repeticionActiva = playlist->getModoRepeticion();
}

Cancion* ReproductorActivo::actual() const {
    if (listaCircular->estaVacia()) return nullptr;
    return listaCircular->primero()->elem;
}

Cancion* ReproductorActivo::avanzar() {
    if (listaCircular->estaVacia()) return nullptr;
    return listaCircular->siguiente();
}

void ReproductorActivo::mostrar() const {
    std::cout << "[Reproductor]  canciones=" << listaCircular->tam()
        << "  repeticion=" << (repeticionActiva ? "SI" : "NO") << "\n";
    if (!listaCircular->estaVacia()) {
        std::cout << "  Actual: " << listaCircular->primero()->elem->getTitulo()<< "\n";
    }
}
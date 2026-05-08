#include "pch.h"
#include "Catalogo.h"
#include <iostream>
#include "Ordenamiento.h"
Catalogo::Catalogo() = default;

Catalogo::~Catalogo() {
    canciones->recorrer([](Cancion* c) { delete c; });
    albumes->recorrer([](Album* a) { delete a; });
    artistas->recorrer([](Artista* a) { delete a; });
    generos->recorrer([](Genero* g) { delete g; });
}

void Catalogo::agregarCancion(Cancion* c) { if (c) canciones->insertarInicio(c); }
void Catalogo::agregarAlbum(Album* a) { if (a) albumes->insertarInicio(a); }
void Catalogo::agregarArtista(Artista* a) { if (a) artistas->insertarInicio(a); }
void Catalogo::agregarGenero(Genero* g) { if (g) generos->insertarInicio(g); }

Cancion* Catalogo::buscarCancionPorID(int id) const{
    Cancion* can = canciones->buscarPrimero(
        [id](Cancion* c) { return c && c->getID() == id; });
    return can;
}
Album* Catalogo::buscarAlbumPorID(int id) const{
    return albumes->buscarPrimero(
        [id](Album* a) { return a && a->getId() == id; });
}
Artista* Catalogo::buscarArtistaPorID(int id) const {
    return artistas->buscarPrimero(
        [id](Artista* a) { return a && a->getID() == id; });
}
Genero* Catalogo::buscarGeneroPorID(int id) const {
    return generos->buscarPrimero(
        [id](Genero* g) { return g && g->getID() == id; });
}

void Catalogo::listarCanciones() const {
    cout << "--- Canciones (" << canciones->tam() << ") ---\n";
    canciones->recorrer([](Cancion* c) { if (c) cout << c->getTitulo() << endl; });
}

void Catalogo::listarAlbumes() const {
    cout << "--- Albumes (" << albumes->tam() << ") ---\n";
    albumes->recorrer([](Album* a) { if (a) a->mostrar(); });
}

void Catalogo::listarArtistas() const {
    cout << "--- Artistas (" << artistas->tam() << ") ---\n";
    artistas->recorrer([](Artista* a) { if (a) a->mostrar(); });
}

void Catalogo::listarGeneros() const {
    cout << "--- Generos (" << generos->tam() << ") ---\n";
    generos->recorrer([](Genero* g) { if (g) g->mostrar(); });
}

Lista<Cancion*>* Catalogo::buscarCancionesPorGenero(Genero* genero) {
    Lista<Cancion*>* resultado = new Lista<Cancion*>();
    canciones->recorrer([&](Cancion* c) {
        if (c && c->getGenero() == genero)
            resultado->insertarFinal(c);
    });
    return resultado;
}

void Catalogo::ordenarCancionesPorDuracion() {
    auto compararPorDuracion = [](Cancion* a, Cancion* b) {
        if (a == nullptr) return false;
        if (b == nullptr) return true;
        return a->getDuracion() < b->getDuracion();
        };
    Ordenamiento<Cancion*>::insertion(canciones, compararPorDuracion);
}

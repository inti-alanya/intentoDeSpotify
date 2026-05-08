#pragma once
#include "Lista.hpp"
#include "Cancion.h"
#include "Album.h"
#include "Artista.h"
#include "Genero.h"

class Catalogo
{
private:
    Lista<Cancion*>*  canciones;
    Lista<Album*>*    albumes;
    Lista<Artista*>*  artistas;
    Lista<Genero*>*   generos;
public:
    Catalogo();
    ~Catalogo();


    //====== nuevos registros ======
    void agregarCancion(Cancion* cancion);
    void agregarAlbum(Album* album);
    void agregarArtista(Artista* artista);
    void agregarGenero(Genero* genero);


    //====== Accesos ======
    const Lista<Cancion*>*& getCanciones() {return canciones;}
    const Lista<Album*>*& getAlbumes() {return albumes;}
    const Lista<Artista*>*& getArtistas() {return artistas;}
    const Lista<Genero*>*& getGeneros() {return generos;}

	Cancion* buscarCancionPorID(int id) const;
	Album* buscarAlbumPorID(int id) const;
	Artista* buscarArtistaPorID(int id) const;
    Genero* buscarGeneroPorID(int id) const;

	// ====== Listados del menu ======
	void listarCanciones() const;
	void listarAlbumes() const;
	void listarArtistas() const;
	void listarGeneros() const;

	Lista<Cancion*>* buscarCancionesPorGenero(Genero* genero);

    void ordenarCancionesPorDuracion();


};


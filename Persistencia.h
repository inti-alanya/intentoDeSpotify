#pragma once
#include <string>
#include "Util.h"
#include "Spotify.h"

class Persistencia
{
private:
	string ruta;
public:
    Persistencia(string carpetaData = "data/");
	~Persistencia() = default;
    bool guardarTodo(const Spotify& s) const;

    bool cargarTodo(Spotify& s) const;
private:
	//===== guardar cada tipo de dato en un archivo de texto separado =====
    bool guardarGeneros(const Spotify& s)        const;
    bool guardarArtistas(const Spotify& s)       const;
    bool guardarAlbumes(const Spotify& s)        const;
    bool guardarCanciones(const Spotify& s)      const;
    bool guardarUsuarios(const Spotify& s)       const;
    bool guardarFavoritos(const Spotify& s)      const;
    bool guardarPlaylists(const Spotify& s)      const;

	//===== cargar cada tipo de dato desde un archivo de texto separado =====
    bool cargarGeneros(Spotify& s)        const;
    bool cargarArtistas(Spotify& s)       const;
    bool cargarAlbumes(Spotify& s)        const;
    bool cargarCanciones(Spotify& s)      const;
    bool cargarUsuarios(Spotify& s)       const;
    bool cargarSuscripciones(Spotify& s)  const;
    bool cargarFavoritos(Spotify& s)      const;
	bool cargarPlaylists(Spotify& s)      const;

};


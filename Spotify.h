#pragma once
#include "Lista.hpp"
#include "Catalogo.h"
#include "Usuario.h"
#include "Playlists.h"
#include "Artista.h"
#include "ColaReproduccion.h"
class Spotify
{
private:
	Catalogo* catalogo;
	ColaReproduccion* colaReproduccion;
	Lista<Usuario>* usuarios;
	Lista<Playlists>* playlists;

	int siguienteIDusuario;
	int siguienteIDplaylist;

public:
	Spotify();
	~Spotify();

	Catalogo* getCatalogo() const { return catalogo; }
	Lista<Usuario>* getUsuarios() const { return usuarios; }
	Lista<Playlists>* getPlaylists() const { return playlists; }

	int getSiguienteIDusuario() const { return siguienteIDusuario; }
	int getSiguienteIDplaylist() const { return siguienteIDplaylist; }

	Usuario* buscarUsuarioPorID(int id) const;
	Playlists* buscarPlaylistPorID(int id) const;

	// ======= Casos de Menú =======
	Usuario* registrarUsuario(string nombre, string nombreUsuario, string email, int contrasena);
	Playlists* crearPlaylist(string nombre, Usuario* creador, bool modoRepeticion = false, bool visibilidad = true);
	void agregarCancionAPlaylist(Playlists* playlist, Cancion* cancion);

	void iniciarReproduccion(Usuario* usuario, Playlists* playlist);
	Cancion* avanzarReproduccion();
	void cambiarModoRepeticion(Playlists* playlist, bool valor);

	void listarUsuarios() const;
	void listarPlaylists() const;
	void listarPlaylistsDeUsuario(Usuario* usuario) const;

	int nuevoIdReproduccion() { return ++siguienteIDplaylist; }
};


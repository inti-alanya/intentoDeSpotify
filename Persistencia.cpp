#include "pch.h"
#include "Spotify.h"
#include "Persistencia.h"
#include "Genero.h"
#include "Util.h"
#include "Usuario.h"
Persistencia::Persistencia(string carpetaData) : ruta(carpetaData) {}


// ===== guardar =====
bool Persistencia::guardarGeneros(const Spotify& s) const {
	guardarArchivo(s.getCatalogo()->getGeneros(), "Generos.txt",
		[](Genero* g) { return to_string(g->getID()) + "," + g->getNombre(); });
	return true;
}
bool Persistencia::guardarArtistas(const Spotify& s) const {
	guardarArchivo(s.getCatalogo()->getArtistas(), "Artistas.txt",
		[](Artista* a) {
			return to_string(a->getID()) + "," + a->getNombre() + "," + a->getNombreArtistico() + "," +
				a->getGeneroPrincipal() + "," + to_string(a->getOyentesMensuales());
		});
	return true;
}
bool Persistencia::guardarAlbumes(const Spotify& s) const {
	guardarArchivo(s.getCatalogo()->getAlbumes(), "Albumes.txt",
		[](Album* a) {
			return to_string(a->getId()) + "," +
				a->getNombre() + "," +
				to_string(a->getAnio()) + "," +
				to_string(a->getArtista()->getID()) + "," +
				a->getPortada();
		});
	return true;

}
bool Persistencia::guardarCanciones(const Spotify& s) const {
	guardarArchivo(
		s.getCatalogo()->getCanciones(),
		"Canciones.txt",
		[](Cancion* c) {
			return to_string(c->getID()) + "," +
	            c->getTitulo() + "," +
				to_string(c->getDuracion()) + "," +
				to_string(c->getGenero()->getID()) + "," +
				to_string(c->getCompositor()->getID()) + "," +
				to_string(c->getAnioLanzamiento());
		}
	);
	return true;
}
bool Persistencia::guardarUsuarios(const Spotify& s) const {
	guardarArchivo(s.getUsuarios(), "Usuarios.txt",
		[](Usuario* u) {
			return to_string(u->getID()) + "," +
				u->getNombreUsuario() + "," +
				u->getEmail()+ "," + 
				to_string(u->getContrasena());
		});
	return true;
}
bool Persistencia::guardarFavoritos(const Spotify& s) const {
	ofstream archivo(ruta + "Favoritos.txt");
	if (!archivo.is_open()) {
		cout << "No se pudo abrir el archivo." << endl;
		return false;
	}
	for (int i = 0; i < s.getUsuarios()->tam(); i++) {
		Usuario u = s.getUsuarios()->obtener(i);
		Lista<Cancion*>* favs = u.getFavoritos()->getCanciones();
		for (int j = 0; j < favs->tam(); j++) {
			Cancion* c = favs->obtener(j);
			archivo << u.getID() << "," << c->getID() << endl;
		}
	}
	archivo.close();
	return true;
}

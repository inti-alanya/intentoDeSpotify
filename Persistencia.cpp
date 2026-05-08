#include "pch.h"
#include "Persistencia.h"

Persistencia::Persistencia(string carpetaData) : ruta(carpetaData) {}


// ===== guardar =====
bool Persistencia::guardarGeneros(const Spotify& s) const {
	return guardarArchivo(s.getCatalogo()->getGeneros(), "Generos.txt",
		[](Genero* g) { return to_string(g->getID()) + "," + g->getNombre(); });
}


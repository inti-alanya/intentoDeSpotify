#include "pch.h"
#include "ColaReproduccion.h"
#include <iostream>  
void ColaReproduccion::mostrar() const {
    cola->mostrarCon([](Cancion* c) -> string {
        if (c == nullptr) return "(nulo)";
        return c->getTitulo();
        });
}
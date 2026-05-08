#pragma once
#include "Cola.hpp"
#include "Cancion.h"
using namespace std;
class ColaReproduccion
{
private:
	Cola<Cancion*>* cola;
public:
	ColaReproduccion();
	~ColaReproduccion();

    void encolar(Cancion* c) { if (c) cola->encolar(c); }
    Cancion* desencolar() {
        if (cola->estaVacia()) return nullptr;
        Cancion* c = cola->frente();
        cola->desencolar();          
        return c;                    
    }
    Cancion* verFrente() const { return cola->estaVacia() ? nullptr : cola->frente(); }
    bool estaVacia() const { return cola->estaVacia(); }
    int getTamano() const { return cola->tam(); }
    void vaciar() { while (!cola->estaVacia()) cola->desencolar(); }

    // Wrapper que muestra la cola usando una lambda formateadora.
    void mostrar() const;
	
};


#pragma once
#include "Lista.hpp"
#include "Cancion.h"
#include "Artista.h"
#include <string>

using namespace System;
using namespace std;

class Album {
private:
    int id;
    string nombre;
    int anio;
    string portada;
    Artista* artista;          // no propietario
    Lista<Cancion*>* canciones;        

public:
    Album();
    Album(int id, string nombre, int anio,
        Artista* artista, string portada = "");
    ~Album();

    int getId();
    string getNombre();
    int getAnio();
    const string getPortada();
    Artista* getArtista();
    Lista<Cancion*>*& getCanciones();

    void setId(int v);
    void setNombre(string v);
    void setAnio(int v);
    void setPortada(string v);
    void setArtista(Artista* a);

    void agregarCancion(Cancion* c);

    void mostrar();
};


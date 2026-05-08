#pragma once
#include "Persona.h"
#include "Lista.hpp"
#include "Playlists.h"
#include "ListaFavoritos.h"
class Usuario :
    public Persona
{
private:
	int id;
	Lista<Playlists*>* playlists;
	ListaFavoritos* favoritos;

	string nombreUsuario;
	string email;
	int contrasena;
public:
	Usuario(string nombre, string nombreUsuario, string email, int contrasena, int id);
	Lista<Playlists*>* getPlaylists();
	void setPlaylists(Lista<Playlists*>* playlists);
	ListaFavoritos* getFavoritos();
	void setFavoritos(ListaFavoritos* favoritos);
	string getNombreUsuario();
	string getEmail();
	int getID();
	int getContrasena();
	void mostrar() override;

};


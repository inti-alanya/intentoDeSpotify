#pragma once
#include <string>
using namespace std;
class Genero {
private:
    int id;
    string nombre;
public:
    Genero();
    Genero(string nombre, int id);
    ~Genero();

    int getID();
    string getNombre();

    void setNombre(string v);
    
    void mostrar();
};



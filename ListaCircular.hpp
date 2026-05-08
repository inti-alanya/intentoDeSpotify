#pragma once

typedef unsigned int uint;


template <typename T>
class ListaCircular {
public:
    struct Nodo {
        T     elem;
        Nodo* sig;
        Nodo(T elem) : elem(elem), sig(nullptr) {}
    };

private:
    Nodo* ult;
    uint  lon;

public:
    ListaCircular() : ult(nullptr), lon(0) {}
    ~ListaCircular() {
        if (ult == nullptr) return;
        Nodo* ini = ult->sig;
        ult->sig = nullptr;
        Nodo* aux;
        while (ini != nullptr) {
            aux = ini;
            ini = ini->sig;
            delete aux;
        }
        lon = 0;
    }

    uint  tam()       const { return lon; }
    bool  estaVacia() const { return lon == 0; }
    Nodo* primero()   const { return ult ? ult->sig : nullptr; }
    Nodo* ultimo()    const { return ult; }

    void insertarInicio(T elem) {
        Nodo* nuevo = new Nodo(elem);
        if (ult == nullptr) {
            nuevo->sig = nuevo;
            ult = nuevo;
        }
        else {
            nuevo->sig = ult->sig;
            ult->sig = nuevo;
        }
        lon++;
    }

    // Avanza el cursor una posicion y retorna el nuevo elemento.
    T siguiente() {
        if (ult == nullptr) return T();
        ult = ult->sig;
        return ult->elem;
    }

    void insertarFinal(T elem) {
        insertarInicio(elem);
        ult = ult->sig;
    }

    void limpiar() { 
        if (ult == nullptr) return;
        Nodo* ini = ult->sig;
        ult->sig = nullptr;
        Nodo* aux;
        while (ini != nullptr) {
            aux = ini;
            ini = ini->sig;
            delete aux;
        }
        ult = nullptr;
        lon = 0;
    }

    void eliminarInicio() {
        if (lon == 0) return;
        Nodo* borrar = ult->sig;
        if (lon == 1) ult = nullptr;
        else ult->sig = borrar->sig;
        delete borrar;
        lon--;
    }
    void reiniciarCursor() {
        if (ult != nullptr) {
            cursor = ult->sig;
        } else {
            cursor = nullptr;
        }
    }

    T obtener(uint pos) {
        Nodo* aux = ult->sig;
        for (uint i = 0; i < pos; i++) aux = aux->sig;
        return aux->elem;
    }

    Nodo* buscar(T elem) {
        if (ult == nullptr) return nullptr;
        Nodo* aux = ult->sig;
        for (uint i = 0; i < lon; i++) {
            if (aux->elem == elem) return aux;
            aux = aux->sig;
        }
        return nullptr;
    }
};

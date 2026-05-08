#pragma once

typedef unsigned int uint;


template <typename T>
class ListaDobleCircular {
public:
    struct Nodo {
        T     elem;
        Nodo* sig;
        Nodo* ant;
        Nodo(T elem) : elem(elem), sig(nullptr), ant(nullptr) {}
    };

private:
    Nodo* ult;
    uint  lon;

public:
    ListaDobleCircular() : ult(nullptr), lon(0) {}
    ~ListaDobleCircular() {
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
            nuevo->ant = nuevo;
            ult = nuevo;
        }
        else {
            nuevo->sig = ult->sig;
            ult->ant = nuevo;
			nuevo->ant = ult;
            ult->sig = nuevo;
        }
        lon++;
    }

    void insertarFinal(T elem) {
        insertarInicio(elem);
        ult = ult->sig;
    }

    void eliminarInicio() {
        if (lon == 0) return;
        Nodo* borrar = ult->sig;
        if (lon == 1) ult = nullptr;
        else {
            ult->sig = borrar->sig;
            borrar->sig->ant = ult;
        }
        delete borrar;
        lon--;
    }
    template <typename Fun >
    void recorrer(Fun f) const {
        if (ult == nullptr) return;
        Nodo* a = ult->sig;
        for (uint i = 0; i < lon; i++) {
            f(a->elem);
            a = a->sig;
        }
    }
    void eliminarFinal() {
        if (lon <= 1) {
            eliminarInicio();
            return;
        }
        Nodo* borrar = ult;
        ult = ult->ant;             
        ult->sig = borrar->sig;     
        borrar->sig->ant = ult;     
        delete borrar;
        lon--;
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

#include <iostream>
#include <iterator>
#include <vector>
#include "Node.cpp"

template <typename T>
class List {
protected:
    Node<T> *head;

public:
    List(List *copy){
        // Constructor copia
        List::head = copy->head;
    }

    List(T* array, int n){
        //Constructor  parametro,
        //llena una lista a partir de un array
        Node<T>* it = Node<T>(array[0]);
        List::head = it;
        for(int i = 0; i < n-1; i++){
            it->setNext(Node<T>(array[i]));
            it = it->getNext();
        }
        it->setNext(nullptr);
    }

    List(Node<T>* nodo){
        //Constructor por parametro,
        //retorna una lista con un nodo
        List::head = nodo;
    }

    List(int n){
        //Constructor por parametro,
        //retorna un lista de randoms de tamaño n
    }

    List(void){
        //Constructor por defecto
    }

    ~List(void){
    }

    // Retorna una referencia al primer elemento
    T front(void) = 0;

    // Retorna una referencia al ultimo elemento
    T back(void) = 0;

    // Inserta un elemento al final
    void push_back(const T& element) = 0;

    // Inserta un elemento al inicio
    void push_front(const T& element) = 0;

    // Quita el ultimo elemento y retorna una referencia
    T& pop_back(void) = 0;

    // Quita el primer elemento y retorna una referencia
    T& pop_front(void) = 0;

    // Acceso aleatorio
    T& operator[] (const int&) = 0;

    // la lista esta vacia?
    bool empty(void) = 0;

    // retorna el tamaño de la lista
    unsigned int size(void) = 0;

    // Elimina toda la lista
    void clear(void) = 0;

    // Elimina un elemento en base a un puntero
    void erase(Node<T>*) = 0;

    // Inserta un elemento  en base a un puntero
    void insert(Node<T>*, const T&) = 0;

    // Elimina todos los elementos por similitud
    void remove(const T&) = 0;

    // ordena la lista
    List& sort(void) = 0;

    // invierte la lista
    List& reverse(void) = 0;

    // Imprime la lista con cout
    template<typename __T>
    inline friend std::ostream& operator<<
            (std::ostream& , const List<__T>& );
}

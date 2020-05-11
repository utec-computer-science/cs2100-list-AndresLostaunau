#include <iostream>
#include <iterator>
#include <vector>
#include <random>
#include <ctime>
#include "Node.cpp"

template <typename T>
class List {
protected:
    Node<T> *head;

public:
    List(List *copy){
        // Constructor copia
        unsigned int n = copy->size();
        if(n != 0){
            setHead(new Node<T>(copy->getHead()->getValue()));
            Node<T>* it_copy = copy->getHead();
            Node<T>* it_new = getHead();
            for(int i = 1; i < n; i++){
                push_back(it_copy[i]);
            }
        }else{
            setHead(nullptr);
        }

    }

    List(T* array, int n){
        //Constructor  parametro,
        //llena una lista a partir de un array
        auto it = new Node<T>(array[0]);
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
        setHead(nodo);
    }

    List(int n){
        //Constructor por parametro,
        //retorna un lista de randoms de tamaño n

    }

    List()= default;

    ~List()= default;

    Node<T> *getHead() const {
        return head;
    }

    void setHead(Node<T> *head) {
        List::head = head;
    }

    // Retorna una referencia al primer elemento
    T front(){ return this->getHead()->getValue();}

    // Retorna una referencia al ultimo elemento
    T back(){
        auto it = getHead();
        while(it->getNext() != nullptr){
            it = it->getNext();
        }
        return it->getValue();
    }

    // Inserta un elemento al final
    void push_back(const T& element){
        auto it = getHead();
        while(it->getNext() != nullptr){
            it = it->getNext();
        }
        it->setNext(new Node<T>(element));
    }

    // Inserta un elemento al inicio
    void push_front(const T& element){
        auto aux = getHead();
        setHead(new Node<T>(element));
        getHead()->setNext(aux);
    }

    // Quita el ultimo elemento y retorna una referencia
    T& pop_back(){
        auto it = getHead();
        while(it->getNext()->getNext() != nullptr){
            it = it->getNext();
        }
        auto popped = it->getNext();
        it->setNext(nullptr);
        return popped->getValue();
    }

    // Quita el primer elemento y retorna una referencia
    T& pop_front(){
        auto popped = getHead();
        this->setHead(popped->getNext());
        return popped->getValue();
    }

    // Acceso aleatorio
    T& operator[] (const int& n){
        auto it = getHead();
        for(int i = 0; i < n; i++){
            it = it->getNext();
        }
        return it->getValue();
    }

    // la lista esta vacia?
    bool empty(){
        return this->getHead() == nullptr;
    }

    // retorna el tamaño de la lista
    unsigned int size(){
        int counter = 1;
        auto it = getHead();
        if(it != nullptr){
            while(it->getNext()!= nullptr){
                counter++;
            }
            return counter;
        }else{
            return 0;
        }
    }

    // Elimina toda la lista
    void clear(){
        int n = size();
        Node<T>* it;
        for (int i = 0; i < n ; i++) {
            it = getHead();
            while(it->getNext()!= nullptr){
                it->getNext();
            }
            delete it;
        }
    }

    // Elimina un elemento en base a un puntero
    void erase(Node<T>* ptr){
        ptr->setValue(NULL);
    };

    // Inserta un elemento  en base a un puntero
    void insert(Node<T>* ptr, const T& element){
        ptr->setValue(element);
    }

    // Elimina todos los elementos por similitud
    void remove(const T& element){
        auto it = getHead();
        while(it->getNext()!= nullptr){
            if(it->getValue()==element){
                it->setValue(NULL);
            }
        }
    }

    // ordena la lista
    List& sort(){
        std::cout<<"Can't sort this type of list\n";
    };

    // invierte la lista
    List& reverse(){
        Node<T>* newHead = nullptr;
        int n = size();
        Node<T>* it, newIt;
        for (int i = 0; i < n ; i++) {
            it = getHead();
            while(it->getNext()!= nullptr){
                it->getNext();
            }
            if(i == 0){
                newHead = it;
                newIt = newHead;
            }else{
                newIt->setNext(it);
                newIt = it;
            }
        }
        this->setHead(newHead);
    }
    /*
    // Imprime la lista con cout
    template<typename __T>
    inline friend std::ostream& operator<<
            (std::ostream& cd, const List<__T>& list){
        int n = list.size();
        for(int i = 0; i < n; i++ ){
            cd<<list[i]<<" ";
        }
        cd<<"\n";
        return 0;
    };*/
};


template <>
class List<int>{
public:
    List(int n){
        srand(time(NULL));
        Node<int>* aux = nullptr;
        for(int i = 0; i < n; ++i){
            aux = new Node<int>(rand());
            if(i == 0){

            }else{

            }
        }
    }

    //List& sort()= 0;
};
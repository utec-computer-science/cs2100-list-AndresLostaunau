#include <iostream>
#include <iterator>
#include <vector>
#include <random>
#include <ctime>
#include "Node.cpp"



template <bool circular, typename NodeType, typename T>
class List {
protected:
    NodeType *head;

public:
    List(const List&):head(nullptr){};

    List(T*):head(nullptr){}

    List(NodeType*):head(nullptr){}

    List(int):head(nullptr){}

    List():head(nullptr){}

    ~List(){}

    // Retorna una referencia al primer elemento
    T front() = 0;

    // Retorna una referencia al ultimo elemento
    T back() = 0;

    // Inserta un elemento al final
    void push_back(const T& element) = 0;

    // Inserta un elemento al inicio
    void push_front(const T& element) = 0;

    // Quita el ultimo elemento y retorna una referencia
    T& pop_back() = 0;

    // Quita el primer elemento y retorna una referencia
    T& pop_front() = 0;

    // Acceso aleatorio
    T& operator[] (const int&) = 0;

    // la lista esta vacia?
    bool empty() = 0;

    // retorna el tamaño de la lista
    unsigned int size() = 0;

    // Elimina toda la lista
    void clear() = 0;

    // Elimina un elemento en base a un puntero
    void erase(Node<T>*) = 0;

    // Inserta un elemento  en base a un puntero
    void insert(Node<T>*, const T&) = 0;

    // Elimina todos los elementos por similitud
    void remove(const T&) = 0;

    // ordena la lista
    List& sort() = 0;

    // invierte la lista
    List& reverse() = 0;

    // Imprime la lista con cout
    /*template<typename __T>
    inline friend std::ostream& operator<<
            (std::ostream& , const List<__T>& );*/
};

typedef SingleNode<int> SingleNodeType;
typedef List<false, SingleNodeType, int> SingleList;
typedef List<true, SingleNodeType, int> CircularList;
typedef DoubleNode<int> DoubleNodeType;
typedef List<false, DoubleNodeType, int> DoubleList;
typedef List<true, DoubleNodeType, int> CircularDoubleList;

// Linear Forward List
template<>
class List<false, SingleNodeType, int>{
protected:
    SingleNodeType *head;

public:
    List(SingleList *copy){
        // Constructor copia
        unsigned int n = copy->size();
        if(n != 0){
            setHead(new SingleNodeType(copy->getHead()->getValue()));
            SingleNodeType* it_copy = copy->getHead()->getNext();
            for(int i = 1; i < n; i++){
                push_back(it_copy->getValue());
                it_copy = it_copy->getNext();
            }
        }else{
            setHead(nullptr);
        }

    }

    List(int* array, int n){
        //Constructor  parametro,
        //llena una lista a partir de un array
        auto it = new SingleNodeType(array[0]);
        setHead(it);
        for(int i = 1; i < n; i++){
            it->setNext(new SingleNodeType(array[i]));
            it = it->getNext();
        }
    }

    List(SingleNodeType* nodo){
        //Constructor por parametro,
        //retorna una lista con un nodo
        setHead(nodo);
    }

    List(int n){
        srand(time(NULL));
        SingleNodeType* aux = nullptr;
        SingleNodeType* it = nullptr;
        for(int i = 0; i < n; ++i){
            aux = new SingleNodeType(rand()%100);
            if(i == 0){
                setHead(aux);
                it = getHead();
            }else{
                it->setNext(aux);
                it = it->getNext();
            }
        }
    }

    List()= default;

    ~List()= default;

    SingleNodeType *getHead() const {
        return head;
    }

    void setHead(SingleNodeType *head) {
        List::head = head;
    }

    // Retorna una referencia al primer elemento
    int front(){ return this->getHead()->getValue();}

    // Retorna una referencia al ultimo elemento
    int back(){
        auto it = getHead();
        while(it->getNext() != nullptr){
            it = it->getNext();
        }
        return it->getValue();
    }

    // Inserta un elemento al final
    void push_back(const SingleNodeType& element){
        auto it = getHead();
        while(it->getNext() != nullptr){
            it = it->getNext();
        }
        it->setNext(new SingleNodeType(element));
    }

    // Inserta un elemento al inicio
    void push_front(const SingleNodeType& element){
        auto new_node = new SingleNodeType(element);
        new_node->setNext(new SingleNodeType(getHead()));
        setHead(new_node);
    }

    // Quita el ultimo elemento y retorna una referencia
    SingleNodeType pop_back(){
        auto it = getHead();
        if(it->getNext()!= nullptr){
            while(it->getNext()->getNext()!= nullptr){
                it = it->getNext();
            }
            auto popped = it->getNext();
            it->setNext(nullptr);
            return popped->getValue();
        }else{
            auto popped = it;
            setHead(nullptr);
            return popped->getValue();
        }
    }

    // Quita el primer elemento y retorna una referencia
    SingleNodeType pop_front(){
        auto popped = getHead();
        this->setHead(popped->getNext());
        return popped->getValue();
    }

    // Acceso aleatorio
    int operator[] (const int& n){
        auto it = getHead();
        for(int i = 0; i < n; i++){
            it = it->getNext();
        }
        return it->getValue();
    }

    // la lista esta vacia?
    bool empty(){
        return (this->getHead() == nullptr);
    }

    // retorna el tamaño de la lista
    unsigned int size(){
        int counter = 1;
        auto it = getHead();
        if(it != nullptr){
            while(it->getNext()!= nullptr){
                counter++;
                it = it->getNext();
            }
            return counter;
        }else{
            return 0;
        }
    }

    // Elimina toda la lista
    void clear(){
        int n = size();
        for(int i = 0; i < n; i++){pop_back();}
    }

    /*
    // Elimina un elemento en base a un puntero
    void erase(SingleNodeType* ptr){
        ptr->setValue(NULL);
    };

    // Inserta un elemento  en base a un puntero
    void insert(SingleNodeType* ptr, const int& element){
        ptr->setValue(element);
    }

    // Elimina todos los elementos por similitud
    void remove(const int& element){
        auto it = getHead();
        while(it->getNext()!= nullptr){
            if(it->getValue()==element){
                it->setValue(NULL);
            }
        }
    }*/

    // ordena la lista
    void sort(){
        int n = size();
        int aux_array[n];
        int aux;
        auto it = getHead();
        for(int i = 0; i < n; i++){
            aux_array[i] = it->getValue();
            it = it->getNext();
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(aux_array[i]>aux_array[j]){
                    aux = aux_array[i];
                    aux_array[i] = aux_array[j];
                    aux_array[j] = aux;
                }
            }
        }
        auto newList = new List(aux_array,n);
        setHead(newList->getHead());
    };

    // invierte la lista
    List& reverse(){
        auto NewList = new SingleList(new SingleNodeType(this->pop_back()));
        int n = size();
        SingleNodeType* newIt;
        newIt = NewList->getHead();
        for (int i = 0; i < n ; i++) {
            newIt->setNext(new SingleNodeType(this->pop_back()));
            newIt = newIt->getNext();
        }
        this->setHead(NewList->getHead());
        return *NewList;
    }

    // Imprime la lista con cout
    inline friend std::ostream& operator<<(std::ostream& cd, SingleList& list){
        unsigned int n = list.size();
        for(int i = 0; i < n; i++){
            cd<<list[i];
            if(i!=n-1){
                cd<<"->";
            }
        }
        cd<<"\n";
        return cd;
    };
};

// Linear Double List
template<>
class List<false, DoubleNodeType, int>{
protected:
    DoubleNodeType *head;

public:
    List(DoubleList *copy){
        // Constructor copia
        unsigned int n = copy->size();
        if(n != 0){
            setHead(new DoubleNodeType(copy->getHead()->getValue()));
            DoubleNodeType* it_copy = copy->getHead()->getNext();
            for(int i = 1; i < n; i++){
                push_back(it_copy->getValue());
                it_copy = it_copy->getNext();
            }
        }else{
            setHead(nullptr);
        }

    }

    List(int* array, int n){
        //Constructor  parametro,
        //llena una lista a partir de un array
        auto it = new DoubleNodeType(array[0]);
        setHead(it);
        for(int i = 1; i < n; i++){
            it->setNext(new DoubleNodeType(array[i]));
            it = it->getNext();
        }
    }

    List(DoubleNodeType* nodo){
        //Constructor por parametro,
        //retorna una lista con un nodo
        setHead(nodo);
    }

    List(int n){
        srand(time(NULL));
        DoubleNodeType* aux = nullptr;
        DoubleNodeType* it = nullptr;
        for(int i = 0; i < n; ++i){
            aux = new DoubleNodeType(rand()%100);
            if(i == 0){
                setHead(aux);
                it = getHead();
            }else{
                it->setNext(aux);
                it = it->getNext();
            }
        }
    }

    List()= default;

    ~List()= default;

    DoubleNodeType *getHead() const {
        return head;
    }

    void setHead(DoubleNodeType *head) {
        List::head = head;
    }

    // Retorna una referencia al primer elemento
    int front(){ return this->getHead()->getValue();}

    // Retorna una referencia al ultimo elemento
    int back(){
        auto it = getHead();
        while(it->getNext() != nullptr){
            it = it->getNext();
        }
        return it->getValue();
    }

    // Inserta un elemento al final
    void push_back(const DoubleNodeType& element){
        auto it = getHead();
        while(it->getNext() != nullptr){
            it = it->getNext();
        }
        it->setNext(new DoubleNodeType(element));
    }

    // Inserta un elemento al inicio
    void push_front(const DoubleNodeType& element){
        auto new_node = new DoubleNodeType(element);
        new_node->setNext(new DoubleNodeType(getHead()));
        setHead(new_node);
    }

    // Quita el ultimo elemento y retorna una referencia
    DoubleNodeType pop_back(){
        auto it = getHead();
        if(it->getNext()!= nullptr){
            while(it->getNext()->getNext()!= nullptr){
                it = it->getNext();
            }
            auto popped = it->getNext();
            it->setNext(nullptr);
            return popped->getValue();
        }else{
            auto popped = it;
            setHead(nullptr);
            return popped->getValue();
        }
    }

    // Quita el primer elemento y retorna una referencia
    DoubleNodeType pop_front(){
        auto popped = getHead();
        this->setHead(popped->getNext());
        return popped->getValue();
    }

    // Acceso aleatorio
    int operator[] (const int& n){
        auto it = getHead();
        for(int i = 0; i < n; i++){
            it = it->getNext();
        }
        return it->getValue();
    }

    // la lista esta vacia?
    bool empty(){
        return (this->getHead() == nullptr);
    }

    // retorna el tamaño de la lista
    unsigned int size(){
        int counter = 1;
        auto it = getHead();
        if(it != nullptr){
            while(it->getNext()!= nullptr){
                counter++;
                it = it->getNext();
            }
            return counter;
        }else{
            return 0;
        }
    }

    // Elimina toda la lista
    void clear(){
        int n = size();
        for(int i = 0; i < n; i++){pop_back();}
    }

/*
    // Elimina un elemento en base a un puntero
    void erase(DoubleNodeType* ptr){
        ptr->setValue(NULL);
    };

    // Inserta un elemento  en base a un puntero
    void insert(DoubleNodeType* ptr, const int& element){
        ptr->setValue(element);
    }

    // Elimina todos los elementos por similitud
    void remove(const int& element){
        auto it = getHead();
        while(it->getNext()!= nullptr){
            if(it->getValue()==element){
                it->setValue(NULL);
            }
        }
    }*/

    // ordena la lista
    void sort(){
        int n = size();
        int aux_array[n];
        int aux;
        auto it = getHead();
        for(int i = 0; i < n; i++){
            aux_array[i] = it->getValue();
            it = it->getNext();
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(aux_array[i]>aux_array[j]){
                    aux = aux_array[i];
                    aux_array[i] = aux_array[j];
                    aux_array[j] = aux;
                }
            }
        }
        auto newList = new List(aux_array,n);
        setHead(newList->getHead());
    };

    // invierte la lista
    List& reverse(){
        auto NewList = new DoubleList(new DoubleNodeType(this->pop_back()));
        int n = size();
        DoubleNodeType* newIt;
        newIt = NewList->getHead();
        for (int i = 0; i < n ; i++) {
            newIt->setNext(new DoubleNodeType(this->pop_back()));
            newIt = newIt->getNext();
        }
        this->setHead(NewList->getHead());
        return *NewList;
    }

    // Imprime la lista con cout
    inline friend std::ostream& operator<<(std::ostream& cd, DoubleList& list){
        unsigned int n = list.size();
        for(int i = 0; i < n; i++){
            cd<<list[i];
            if(i!=n-1){
                cd<<"->";
            }
        }
        cd<<"\n";
        return cd;
    };
};

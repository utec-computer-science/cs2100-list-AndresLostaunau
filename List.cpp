#include <iostream>
#include <iterator>
#include <vector>
#include <random>
#include <ctime>
#include "Node.cpp"



template <typename T>
class List {
protected:
    SingleNode<T> *head;

public:
    List(List *copy){
        // Constructor copia
        unsigned int n = copy->size();
        if(n != 0){
            setHead(new SingleNode<T>(copy->getHead()->getValue()));
            SingleNode<T>* it_copy = copy->getHead()->getNext();
            for(int i = 1; i < n; i++){
                push_back(it_copy->getValue());
                it_copy = it_copy->getNext();
            }
        }else{
            setHead(nullptr);
        }

    }

    List(T* array, int n){
        //Constructor  parametro,
        //llena una lista a partir de un array
        auto it = new SingleNode<T>(array[0]);
        setHead(it);
        for(int i = 1; i < n; i++){
            it->setNext(new SingleNode<T>(array[i]));
            it = it->getNext();
        }
    }

    List(SingleNode<T>* nodo){
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

    SingleNode<T> *getHead() const {
        return head;
    }

    void setHead(SingleNode<T> *head) {
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
        it->setNext(new SingleNode<T>(element));
    }

    // Inserta un elemento al inicio
    void push_front(const T& element){
        auto new_node = new SingleNode<T>(element);
        new_node->setNext(new SingleNode<T>(getHead()));
        setHead(new_node);
    }

    // Quita el ultimo elemento y retorna una referencia
    T pop_back(){
        auto it = getHead();
        while(it->getNext()->getNext() != nullptr){
            it = it->getNext();
        }
        auto popped = it->getNext();
        it->setNext(nullptr);
        return popped->getValue();
    }

    // Quita el primer elemento y retorna una referencia
    T pop_front(){
        auto popped = getHead();
        this->setHead(popped->getNext());
        return popped->getValue();
    }

    // Acceso aleatorio
    T operator[] (int n){
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
        SingleNode<T>* it;
        for (int i = 0; i < n ; i++) {
            it = getHead();
            while(it->getNext()!= nullptr){
                it->getNext();
            }
            delete it;
        }
    }

    // Elimina un elemento en base a un puntero
    void erase(SingleNode<T>* ptr){
        ptr->setValue(NULL);
    };

    // Inserta un elemento  en base a un puntero
    void insert(SingleNode<T>* ptr, const T& element){
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
    void sort(){
        //No todo tipo de clases pueden ser sorteadas, asi que en la lista general será void, pero en los traits retornará una lista.
        std::cout<<"Can't sort this type of list\n";
    };

    // invierte la lista
    List& reverse(){
        SingleNode<T>* newHead = nullptr;
        int n = size();
        SingleNode<T>* it, newIt;
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

    // Imprime la lista con cout
    inline friend std::ostream& operator<<(std::ostream& cd, List<T>& list){
        unsigned int n = list.size();
        for(int i = 0; i < n; i++){
            cd<<list[i]<<" ";
        }
        cd<<"\n";
        return cd;
    };
};

/*
template <>
class List<int>{
protected:
    SingleNode<int> *head;

public:
    List(int n){
        srand(time(NULL));
        SingleNode<int>* aux = nullptr;
        SingleNode<int>* it = nullptr;
        for(int i = 0; i < n; ++i){
            aux = new SingleNode<int>(rand()%100);
            if(i == 0){
                setHead(aux);
                it = getHead();
            }else{
                it->setNext(aux);
                it = it->getNext();
            }
        }
    }
    List(List *copy){
        // Constructor copia
        unsigned int n = copy->size();
        if(n != 0){
            setHead(new SingleNode<int>(copy->getHead()->getValue()));
            SingleNode<int>* it_copy = copy->getHead()->getNext();
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
        auto it = new SingleNode<int>(array[0]);
        setHead(it);
        for(int i = 1; i < n; i++){
            it->setNext(new SingleNode<int>(array[i]));
            it = it->getNext();
        }
    }

    List(SingleNode<int>* nodo){
        //Constructor por parametro,
        //retorna una lista con un nodo
        setHead(nodo);
    }

    List()= default;

    ~List()= default;

    SingleNode<int> *getHead() const {
        return head;
    }

    void setHead(SingleNode<int> *head) {
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
    void push_back(const int& element){
        auto it = getHead();
        while(it->getNext() != nullptr){
            it = it->getNext();
        }
        it->setNext(new SingleNode<int>(element));
    }

    // Inserta un elemento al inicio
    void push_front(const int& element){
        auto new_node = new SingleNode<int>(element);
        new_node->setNext(new SingleNode<int>(getHead()));
        setHead(new_node);
    }

    // Quita el ultimo elemento y retorna una referencia
    int pop_back(){
        auto it = getHead();
        while(it->getNext()->getNext() != nullptr){
            it = it->getNext();
        }
        auto popped = it->getNext();
        it->setNext(nullptr);
        return popped->getValue();
    }

    // Quita el primer elemento y retorna una referencia
    int pop_front(){
        auto popped = getHead();
        this->setHead(popped->getNext());
        return popped->getValue();
    }

    // Acceso aleatorio
    int operator[] (int n){
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
        SingleNode<int>* it;
        for (int i = 0; i < n ; i++) {
            it = getHead();
            while(it->getNext()!= nullptr){
                it->getNext();
            }
            delete it;
        }
    }

    // Inserta un elemento  en base a un puntero
    void insert(SingleNode<int>* ptr, const int& element){
        ptr->setValue(element);
    }


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


    // Imprime la lista con cout
    inline friend std::ostream& operator<<(std::ostream& cd, List<int>& list){
        unsigned int n = list.size();
        for(int i = 0; i < n; i++){
            cd<<list[i]<<" ";
        }
        cd<<"\n";
        return cd;
    };
};
*/
typedef List<SingleNode<int>> SimpleList;
typedef List<SingleNode<int>> CircularList;
typedef List<DoubleNode<int>> DoubleList;
typedef List<DoubleNode<int>> CircularDoubleList;
#include "CircleList.cpp"

template <typename T>
class DoubleList{
protected:
    DoubleNode<T> *head;

public:
    DoubleList(DoubleList *copy){
        // Constructor copia
        unsigned int n = copy->size();
        if(n != 0){
            setHead(new DoubleNode<T>(copy->getHead()->getValue()));
            DoubleNode<T>* it_copy = copy->getHead();
            for(int i = 1; i < n; i++){
                push_back(it_copy->getValue());
                it_copy = it_copy->getNext();
            }
        }else{
            setHead(nullptr);
        }

    }

    DoubleList(List<T> *copy){
        auto list_aux = new List<T>(copy);
        this = DoubleLink(list_aux);
    }



    DoubleList(T* array, int n){
        //Constructor  parametro,
        //llena una lista a partir de un array
        auto list_aux = new List<T>(array, n);
        this = DoubleLink(list_aux);
    }

    DoubleList(SingleNode<T>* nodo){
        //Constructor por parametro,
        //retorna una lista con un nodo
        setHead(nodo);
    }

    DoubleList(int n){
        //Constructor por parametro,
        //retorna un lista de randoms de tamaño n

    }

    DoubleList()= default;

    ~DoubleList()= default;

    DoubleList* DoubleLink(List<T>* list){
        auto doubled = new DoubleList();
        SingleNode<T>* list_it = list->getHead();
        DoubleNode<T>* d_it = nullptr;
        int n = list->size();
        if(n!=0){
            doubled->setHead(new DoubleNode<T>(list_it->getValue()));
            list_it = list_it->getNext();
            d_it = doubled->getHead();
            for(int i = 1; i < n; i++){
                d_it->setNext(new DoubleNode<T>(list_it->getValue()));
                d_it->getNext()->setPrev(d_it);
                d_it = d_it->getNext();
                if(i!=n-1){
                    list_it = list_it->getNext();
                }
            }
        }
        return doubled;
    }

    DoubleNode<T> *getHead() const {
        return head;
    }

    void setHead(DoubleNode<T> *head) {
        DoubleList::head = head;
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
        auto aux = getHead();
        setHead(new SingleNode<T>(element));
        getHead()->setNext(aux);
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
    T& operator[] (int& n){
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
        DoubleNode<T>* it;
        for (int i = 0; i < n ; i++) {
            it = getHead();
            while(it->getNext()!= nullptr){
                it->getNext();
            }
            delete it;
        }
    }

    // Elimina un elemento en base a un puntero
    void erase(DoubleNode<T>* ptr){
        ptr->setValue(NULL);
    };

    // Inserta un elemento  en base a un puntero
    void insert(DoubleNode<T>* ptr, const T& element){
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
    DoubleList& reverse(){
        DoubleNode<T>* newHead = nullptr;
        int n = size();
        DoubleNode<T>* it, newIt;
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
    template<typename __T>
    inline friend std::ostream& operator<<(std::ostream& cd, const List<__T>& list){
        unsigned int n = list.size();
        for(int i = 0; i < n; i++){
            cd<<list[i]<<" ";
        }
        cd<<"\n";
        return cd;
    };
};
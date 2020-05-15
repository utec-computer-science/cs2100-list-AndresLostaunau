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



#include "List.cpp"

template<typename T>
class CircleList: public List<T>{
public:
    CircleList* CircleLink(List<T>* list){
        unsigned int n = list->size();
        auto list_it = list->getHead();
        for(int i = 1; i < n; i++){
            list_it++;
        }
        list_it->setNext(list->getHead());
    }
};


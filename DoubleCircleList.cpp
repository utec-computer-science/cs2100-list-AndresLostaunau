#include "DoubleList.cpp"

template <typename T>
class DoubleCircleList: public DoubleList<T>{
public:
    DoubleCircleList* DoubleCircleLink(DoubleList<T>* list){
        unsigned int n = list->size();
        auto list_it = list->getHead();
        for(int i = 1; i < n; i++){
            list_it++;
        }
        list_it->setNext(list->getHead());
        list->getHead()->setPrev(list_it);
    }
};
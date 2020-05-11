#include <iostream>
#include "DoubleCircleList.cpp"

char t1Array[6] = {'p','r','u','e','b','a'};
typedef char T1type;
typedef int T3type;

int main (int, char*[]){
    //Test 1 (Construcción con array y sort generico)
    auto t1 = new List<T1type>(t1Array,6);
    std::cout<<"Size T1: "<<t1->size()<<"\n";
    std::cout<<*t1;
    t1->sort();
    //Test 2 (Copia de lista, push y pop)
    auto t2 = new List<T1type>(t1);
    std::cout<<"Size T2: "<<t2->size()<<"\n";
    t2->push_front('A');
    t2->push_back('s');
    std::cout<<*t2;
    t2->pop_back();
    t2->pop_back();
    t2->pop_front();
    std::cout<<*t2;
    return 1;
    //Test 3 
}
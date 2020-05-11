#include <iostream>
#include "DoubleList.cpp"

char t1Array[6] = {'p','r','u','e','b','a'};
typedef char T1type;

int main (int, char*[]){
    //Test 1 (Construcción con array y sort generico)
    auto t1 = new List<T1type>(t1Array,6);
    std::cout<<"Size T1: "<<t1->size()<<"\n";
    t1->sort();
    //Test 2 (Copia de lista)
    auto t2 = new List<T1type>(t1);
    std::cout<<"Size T2: "<<t2->size()<<"\n";
    t2->push_front('A');
    //std::cout<<(t2->getHead()->getValue()==t2[2]);
    //std::cout<<*t2;
    return 1;
}
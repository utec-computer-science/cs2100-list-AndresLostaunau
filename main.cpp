#include <iostream>
#include "List.cpp"

char t1Array[6] = {'p','r','u','e','b','a'};
typedef char T1type;

int main (int, char*[]){
    auto t1 = new List<T1type>(t1Array,6);
    std::cout<<"Size T1:"<<t1->size()<<"\n";
    t1->sort();
    return 1;
}
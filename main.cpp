#include <iostream>
#include "List.cpp"
using namespace std;

int tArray[6] = {4, 20, 6, 9, 0, 18};


int main (int, char*[]){
    cout<<"Test 1: Construccion con array y funcion size\n";
    auto t1 = new DoubleList(tArray,6);
    cout<<"Size T1: "<<t1->size()<<"\n";
    cout<<*t1;

    cout<<"\nTest 2: Sort\n";
    t1->sort();
    cout<<*t1;

    cout<<"\nTest 3: Copia de lista t1 a t2\n";
    auto t2 = new DoubleList(t1);
    cout<<*t2;

    cout<<"\nTest 4: Push front(21), Push back (5)\n";
    t2->push_front(21);
    t2->push_back(5);
    cout<<*t2;

    cout<<"\nTest 5: Dos pop back y un pop front\n";
    t2->pop_back();
    t2->pop_back();
    t2->pop_front();
    cout<<*t2;

    cout<<"\nTest 6: Random List de 8 elementos\n";
    auto t3 = new DoubleList(8);
    cout<<*t3;

    cout<<"\nTest 7: Front y back\n";
    cout<<"Front: "<<t3->front()<<endl;
    cout<<"Back: "<<t3->back()<<endl;

    cout<<"\nTest 8: Empty y clear\n";
    for(int i = 0; i < 2; i++){
        if(t3->empty()){
            cout<<"Esta vacio.\n";
        }else{
            cout<<"No esta vacio. Vaciando\n";
            t3->clear();
        }
    }

    cout<<"\nTest 9: Reverse de t2\n";
    t2->reverse();
    cout<<*t2;

    cout<<"\nTESTS DE LISTAS DOBLES LINEARES\n";
    return 1;
}
#include <iostream>
#include "List.cpp"
using namespace std;

int tArray[6] = {4, 20, 6, 9, 0, 18};


int main (int, char*[]){
    cout<<"TEST DE LISTAS SINGULARES LINEARES\nTest 1: Construccion con array y funcion size\n";
    auto tls1 = new SingleList(tArray,6);
    cout<<"Size T1: "<<tls1->size()<<"\n";
    cout<<*tls1;

    cout<<"\nTest 2: Sort\n";
    tls1->sort();
    cout<<*tls1;

    cout<<"\nTest 3: Copia de lista t1 a t2\n";
    auto tls2 = new SingleList(tls1);
    cout<<*tls2;

    cout<<"\nTest 4: Push front(21), Push back (5)\n";
    tls2->push_front(21);
    tls2->push_back(5);
    cout<<*tls2;

    cout<<"\nTest 5: Dos pop back y un pop front\n";
    tls2->pop_back();
    tls2->pop_back();
    tls2->pop_front();
    cout<<*tls2;

    cout<<"\nTest 6: Random List de 8 elementos\n";
    auto tls3 = new SingleList(8);
    cout<<*tls3;

    cout<<"\nTest 7: Front y back\n";
    cout<<"Front: "<<tls3->front()<<endl;
    cout<<"Back: "<<tls3->back()<<endl;

    cout<<"\nTest 8: Empty y clear\n";
    for(int i = 0; i < 2; i++){
        if(tls3->empty()){
            cout<<"Esta vacio.\n";
        }else{
            cout<<"No esta vacio. Vaciando\n";
            tls3->clear();
        }
    }

    cout<<"\nTest 9: Reverse de t2\n";
    tls2->reverse();
    cout<<*tls2;

    cout<<"\nTESTS DE LISTAS DOBLES LINEARES\n";
    auto tld1 = new DoubleList(tArray,6);
    cout<<"Size T1: "<<tld1->size()<<"\n";
    cout<<*tld1;

    cout<<"\nTest 2: Sort\n";
    tld1->sort();
    cout<<*tld1;

    cout<<"\nTest 3: Copia de lista t1 a t2\n";
    auto tld2 = new DoubleList(tld1);
    cout<<*tld2;

    cout<<"\nTest 4: Push front(21), Push back (5)\n";
    tld2->push_front(21);
    tld2->push_back(5);
    cout<<*tld2;

    cout<<"\nTest 5: Dos pop back y un pop front\n";
    tld2->pop_back();
    tld2->pop_back();
    tld2->pop_front();
    cout<<*tld2;

    cout<<"\nTest 6: Random List de 8 elementos\n";
    auto tld3 = new DoubleList(8);
    cout<<*tld3;

    cout<<"\nTest 7: Front y back\n";
    cout<<"Front: "<<tld3->front()<<endl;
    cout<<"Back: "<<tld3->back()<<endl;

    cout<<"\nTest 8: Empty y clear\n";
    for(int i = 0; i < 2; i++){
        if(tld3->empty()){
            cout<<"Esta vacio.\n";
        }else{
            cout<<"No esta vacio. Vaciando\n";
            tld3->clear();
        }
    }

    cout<<"\nTest 9: Reverse de t2\n";
    tld2->reverse();
    cout<<*tld2;

    cout<<"\nTESTS DE LISTAS CIRCULARES\n";
    auto tcs1 = new CircularList(tArray,6);
    cout<<"Size T1: "<<tcs1->size()<<"\n";
    cout<<*tcs1;

    cout<<"\nTest 2: Sort\n";
    tcs1->sort();
    cout<<*tcs1;

    cout<<"\nTest 3: Copia de lista t1 a t2\n";
    auto tcs2 = new CircularList(tcs1);
    cout<<*tcs2;

    cout<<"\nTest 4: Push front(21), Push back (5)\n";
    tcs2->push_front(21);
    tcs2->push_back(5);
    cout<<*tcs2;

    cout<<"\nTest 5: Dos pop back y un pop front\n";
    tcs2->pop_back();
    tcs2->pop_back();
    tcs2->pop_front();
    cout<<*tcs2;

    cout<<"\nTest 6: Random List de 8 elementos\n";
    auto tcs3 = new CircularList(8);
    cout<<*tcs3;

    cout<<"\nTest 7: Front y back\n";
    cout<<"Front: "<<tcs3->front()<<endl;
    cout<<"Back: "<<tcs3->back()<<endl;

    cout<<"\nTest 8: Empty y clear\n";
    for(int i = 0; i < 2; i++){
        if(tcs3->empty()){
            cout<<"Esta vacio.\n";
        }else{
            cout<<"No esta vacio. Vaciando\n";
            tcs3->clear();
        }
    }

    cout<<"\nTest 9: Reverse de t2\n";
    tcs2->reverse();
    cout<<*tcs2;
    return 1;
}
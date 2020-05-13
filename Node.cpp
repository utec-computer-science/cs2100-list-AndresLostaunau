template <typename T>
class Node {
protected:
    T value;

public:
    Node()= default;
    Node(T _value){Node::value=_value;}

    T getValue() const {
        return Node::value;
    }

    void setValue(T value) {
        Node::value = value;
    }
/*
    Node* getNext()= default;
    Node* setNext(Node* n)= default;
    Node* getPrev()= default;
    Node* setPrev(Node* n)= default;*/

};

template <typename T>
class SingleNode: public Node<T>{
private:
    SingleNode<T> * next;

public:
    SingleNode(){SingleNode::next = nullptr;};

    SingleNode(T value){
        SingleNode::value = value;
        SingleNode::next = nullptr;
    };

    SingleNode(SingleNode* copy){
        SingleNode::value = copy->getValue();
        SingleNode::next = copy->getNext();
    }


    SingleNode<T> *getNext() const {
        return next;
    }

    void setNext(SingleNode<T> *next) {
        SingleNode::next = next;
    }

    ~SingleNode(){
    }
    /*
    template<typename _T>
    Node<_T>& operator ++(Node<_T>& nodo){
        nodo = nodo->getNext();
        return nodo;
    }*/
};

template <typename T>
class DoubleNode: public SingleNode<T>{
protected:
    SingleNode<T>* prev;

public:
    DoubleNode(){
        DoubleNode::next = nullptr;
        DoubleNode::prev = nullptr;
    }

    DoubleNode(T value){
        DoubleNode::value = value;
        DoubleNode::next = nullptr;
        DoubleNode::prev = nullptr;
    }

    SingleNode<T> *getPrev() const {
        return prev;
    }

    void setPrev(SingleNode<T> *prev) {
        DoubleNode::prev = prev;
    }

    template<typename _T>
    void operator --(SingleNode<_T>& nodo){
        nodo = nodo->getPrev();
    }
};


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

    template<typename _T>
    void operator --(Node<_T>& nodo){
        nodo = nodo->getPrev();
    }

    template<typename _T>
    void operator ++(Node<_T>& nodo){
        nodo = nodo->getNext();
    }
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

};

template <typename T>
class DoubleNode: public Node<T>{
protected:
    DoubleNode<T>* next;
    DoubleNode<T>* prev;

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

    DoubleNode(DoubleNode* copy){
        DoubleNode::value = copy->getValue();
        DoubleNode::next = copy->getNext();
    }

    DoubleNode *getPrev() const {
        return prev;
    }

    void setPrev(DoubleNode<T> *prev) {
        DoubleNode::prev = prev;
    }

    DoubleNode *getNext() const {
        return next;
    }

    void setNext(DoubleNode<T> *next) {
        DoubleNode::next = next;
    }


};


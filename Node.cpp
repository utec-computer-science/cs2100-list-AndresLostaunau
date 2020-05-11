template <typename T>
class Node {
protected:
    T value;
    Node<T> * next;

public:
    Node(){Node::next = nullptr;};

    Node(T value){
        Node::value = value;
        Node::next = nullptr;
    };

    T getValue() const {
        return Node::value;
    }

    void setValue(T value) {
        Node::value = value;
    }

    Node<T> *getNext() const {
        return next;
    }

    void setNext(Node<T> *next) {
        Node::next = next;
    }

    ~Node(){
    }

    template<typename _T>
    friend Node<_T>* operator ++(Node<_T>* nodo){
        nodo = nodo->getNext();
        return nodo;
    }
};

template <typename T>
class DoubleNode: public Node<T>{
protected:
    Node<T>* prev;

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

    Node<T> *getPrev() const {
        return prev;
    }

    void setPrev(Node<T> *prev) {
        DoubleNode::prev = prev;
    }

    template<typename _T>
    friend Node<_T>* operator --(Node<_T>* nodo){
        nodo = nodo->getPrev();
        return nodo;
    }
};


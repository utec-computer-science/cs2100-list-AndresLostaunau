template <typename T>
class Node {
protected:
    T value;
    Node<T> * next;

public:
    Node()= default;

    Node(T value){Node::value = value;};

    T getValue() const {

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
};
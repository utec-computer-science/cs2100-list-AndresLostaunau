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
};
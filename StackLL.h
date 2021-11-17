// template <typename C>
// class Stack;

template <typename T>
class Node {
 public:
  T data;
  Node* next;
  Node(T data) { this->data = data; }
};

template <typename T>
class Stack {
  Node<T>* head;

 public:
  void push(T data) {
    Node<T>* x = new Node<T>(data);
    x->next = head;
    head = x;
  }
  void pop() {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
  }
  bool isEmpty() {
    if (head == NULL)
      return true;
    else
      return false;
  }
  T top() { return head->data; }
};
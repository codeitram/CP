class Queue {
  int *arr;
  int front, rear;
  int size;

 public:
  Queue(int size = 5) {
    arr = new int[size];
    front = rear = 0;
    this->size = size;
  }
  void push(int data) {
    int x;
    x = (rear + 1) % size;
    if (x != front) {
      rear = x;
      arr[rear] = data;
    }
  }
  void pop() {
    if (rear != front) {
      front = (front + 1) % size;
    }
  }
  bool empty() {
    if (rear == front)
      return true;
    else
      return false;
  }
  int top() {
    if (!empty()) return arr[(front + 1) % size];  // this line fixed the error
    return -1;
  }
  ~Queue() { delete[] arr; }
};
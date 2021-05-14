class MyCircularQueue {
public:
  deque<int> q;
  int curSize = 0;
  int size = 0;
  MyCircularQueue(int k) { size = k; }

  bool enQueue(int value) {
    if (curSize >= size)
      return false;
    curSize++;
    q.push_back(value);
    return true;
  }

  bool deQueue() {
    if (curSize <= 0)
      return false;
    curSize--;
    q.pop_front();
    return true;
  }

  int Front() {
    if (curSize <= 0)
      return -1;
    return q.front();
  }

  int Rear() {
    if (curSize <= 0)
      return -1;
    return q.back();
  }

  bool isEmpty() {
    if (curSize <= 0)
      return true;
    return false;
  }

  bool isFull() {
    if (curSize >= size)
      return true;
    return false;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
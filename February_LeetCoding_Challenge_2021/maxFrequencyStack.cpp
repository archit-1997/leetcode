class FreqStack {
public:
  map<int, int> hash;
  map<int, stack<int>> setmap;
  int max;
  FreqStack() { max = 0; }

  void push(int x) {
    // increment the frequency of this element
    hash[x]++;
    if (hash[x] > max)
      max = hash[x];
    setmap[hash[x]].push(x);
  }

  int pop() {
    int top = setmap[max].top();
    setmap[max].pop();

    hash[top]--;

    // if the size of setmap[max]==0,decrement max
    if (setmap[max].size() == 0)
      max--;
    return top;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
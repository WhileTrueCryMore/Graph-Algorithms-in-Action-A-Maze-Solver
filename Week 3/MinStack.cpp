class MinStack {
  vector<int> vec;
  vector<int> mn;

 public:
  MinStack() {
  }

  void push(int value) {
    vec.push_back(value);
    if (vec.size() == 1) {
      mn.push_back(value);
    } else {
      mn.push_back(min(mn.back(), value));
    }
  }

  void pop() {
    vec.pop_back();
    mn.pop_back();
  }

  int top() {
    return vec.back();
  }

  int getMin() {
    return mn.back();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
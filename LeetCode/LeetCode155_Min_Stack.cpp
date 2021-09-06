// Time complexity: O(N)
// Space complexity: O(N)
// N: number of value had been pushed
class MinStack {
  stack<int> stack, min;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int val) {
    stack.push(val);
    if (min.empty() || val <= min.top()) {
      min.push(val);
    }
  }

  void pop() {
    int x = stack.top();
    stack.pop();
    if (min.top() == x) {
      min.pop();
    }
  }

  int top() { return stack.top(); }

  int getMin() { return min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
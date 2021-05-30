// Time complexity:
//  push(): O(N)
//  pop() : O(1)
// Space complexity: O(N)
class MyStack {
  queue<int> queIn;
  queue<int> queOut;

 public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) {
    while (!queIn.empty()) {
      queOut.push(queIn.front());
      queIn.pop();
    }
    while (!queOut.empty()) {
      queIn.push(queOut.front());
      queOut.pop();
    }
    queOut.push(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int num = 0;
    if (!queOut.empty()) {
      num = queOut.front();
      queOut.pop();
    } else if (!queIn.empty()) {
      num = queIn.front();
      queIn.pop();
    }

    return num;
  }

  /** Get the top element. */
  int top() {
    int num = 0;
    if (!queOut.empty()) {
      num = queOut.front();
    } else if (!queIn.empty()) {
      num = queIn.front();
    }

    return num;
  }

  /** Returns whether the stack is empty. */
  bool empty() { return queIn.empty() && queOut.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
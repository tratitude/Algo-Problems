// Time complexity: O(N)
// Space complexity: O(N)
class MyQueue {
  stack<int> stackIn;
  stack<int> stackOut;

 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { stackIn.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int num = peek();
    stackOut.pop();

    return num;
  }

  /** Get the front element. */
  int peek() {
    if (stackOut.empty()) {
      while (!stackIn.empty()) {
        stackOut.push(stackIn.top());
        stackIn.pop();
      }
    }
    int num = stackOut.top();

    return num;
  }

  /** Returns whether the queue is empty. */
  bool empty() { return stackIn.empty() && stackOut.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
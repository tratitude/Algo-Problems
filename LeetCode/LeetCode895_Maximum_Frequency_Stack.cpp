// Time complexity:
// push: O(1)
// pop: O(1)
// Space complexity: O(n)
class FreqStack {
  // val -> feq
  unordered_map<int, int> feqTable;
  // feq -> val stack
  unordered_map<int, stack<int>> feqStack;
  int maxFeq;

 public:
  FreqStack() { maxFeq = 0; }

  void push(int val) {
    int feq = feqTable[val] + 1;

    // add to feqTable
    feqTable[val] = feq;

    // add to feqStack
    feqStack[feq].push(val);

    // update maxFeq
    maxFeq = max(feq, maxFeq);
  }

  int pop() {
    auto& s = feqStack[maxFeq];
    int val = s.top();
    s.pop();

    // update feqTable
    if (--feqTable[val] == 0) {
      auto it = feqTable.find(val);
      feqTable.erase(it);
    }

    // update maxFeq
    if (s.empty()) --maxFeq;

    return val;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
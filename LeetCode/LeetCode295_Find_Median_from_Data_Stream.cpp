#include <queue>
#include <iostream>
using namespace std;
// Time complexity:
// addNum: O(log(n))
// findMedian: O(1)
// Space complexity: O(n)
class MedianFinder {
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int size = 0;

 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    ++size;
    if (minHeap.size() == 0) {
      minHeap.push(num);
      return;
    }
    if (maxHeap.size() == 0) {
      // heapfiy
      if (num > minHeap.top()) {
        int node = minHeap.top();
        minHeap.pop();

        maxHeap.push(node);
        minHeap.push(num);
      } else {
        maxHeap.push(num);
      }
      return;
    }

    // push to minHeap
    if (minHeap.size() <= maxHeap.size()) {
      if (num <= maxHeap.top()) {
        int node = maxHeap.top();
        maxHeap.pop();

        minHeap.push(node);
        maxHeap.push(num);
      } else {
        minHeap.push(num);
      }
    }
    // push to maxHeap
    else {
      if (num >= minHeap.top()) {
        int node = minHeap.top();
        minHeap.pop();

        maxHeap.push(node);
        minHeap.push(num);
      } else {
        maxHeap.push(num);
      }
    }
  }

  double findMedian() {
    double mean;

    if (size % 2)
      mean = minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
    else
      mean = double(minHeap.top() + maxHeap.top()) / 2.0;

    return mean;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
  MedianFinder mf;
  mf.addNum(-1);
  cout << mf.findMedian() << "\n";
  mf.addNum(-2);
  cout << mf.findMedian() << "\n";
  mf.addNum(-3);
  cout << mf.findMedian() << "\n";
  mf.addNum(-4);
  cout << mf.findMedian() << "\n";
  mf.addNum(-5);
  cout << mf.findMedian() << "\n";
  mf.addNum(-6);
  cout << mf.findMedian() << "\n";
}
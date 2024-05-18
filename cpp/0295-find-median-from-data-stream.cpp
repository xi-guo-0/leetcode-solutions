#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
  MedianFinder() : len(0) {}

  void addNum(int num) {
    ++len;
    min_heap.push(num);
    max_heap.push(min_heap.top());
    min_heap.pop();
    if (max_heap.size() > min_heap.size()) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
  }

  double findMedian() {
    if (len % 2 == 0)
      return (min_heap.top() + max_heap.top()) / 2.0;
    return min_heap.top();
  }

private:
  int len;
  std::priority_queue<int> max_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

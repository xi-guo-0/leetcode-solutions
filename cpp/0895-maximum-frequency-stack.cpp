#include <stack>
#include <unordered_map>

using namespace std;

class FreqStack {
private:
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> freqStacks;
  int maxFreq;

public:
  FreqStack() { maxFreq = 0; }

  void push(int val) {
    int curFreq = ++freq[val];
    maxFreq = max(maxFreq, curFreq);
    freqStacks[curFreq].push(val);
  }

  int pop() {
    int val = freqStacks[maxFreq].top();
    freqStacks[maxFreq].pop();
    if (freqStacks[maxFreq].empty()) {
      maxFreq--;
    }
    freq[val]--;
    if (freq[val] == 0) {
      freq.erase(val);
    }
    return val;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

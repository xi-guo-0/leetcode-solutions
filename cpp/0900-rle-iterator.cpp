#include <vector>

using namespace std;

class RLEIterator {
private:
  vector<int> encoding;
  int index;
  int count;

public:
  RLEIterator(vector<int> &encoding) {
    this->encoding = encoding;
    index = 0;
    count = 0;
  }

  int next(int n) {
    while (index < encoding.size()) {
      if (count + n <= encoding[index]) {
        count += n;
        return encoding[index + 1];
      } else {
        n -= (encoding[index] - count);
        count = 0;
        index += 2;
      }
    }
    return -1;
  }
};
/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

int main() { return 0; }

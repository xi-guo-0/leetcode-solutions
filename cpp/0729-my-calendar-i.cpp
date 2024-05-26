#include <iostream>
#include <map>

using namespace std;

class MyCalendar {

public:
  MyCalendar() {}

  bool book(int start, int end) {
    auto next = calendar.lower_bound(start);
    if (next != calendar.end() && next->first < end) {

      return false;
    }
    if (next != calendar.begin() && (--next)->second > start) {
      return false;
    }

    calendar[start] = end;
    return true;
  }

private:
  std::map<int, int> calendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() { return 0; }

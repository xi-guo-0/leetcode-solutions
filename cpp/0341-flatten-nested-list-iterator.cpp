/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
  vector<NestedInteger>::const_iterator first, last;
  NestedIterator *it;

public:
  NestedIterator(const vector<NestedInteger> &nestedList) {
    this->first = nestedList.begin();
    this->last = nestedList.end();
    it = nullptr;
  }

  ~NestedIterator() {
    if (it)
      delete it;
  }

  int next() {
    if (first->isInteger())
      return first++->getInteger();
    else
      return it->next();
  }

  bool hasNext() {
    while (first != last) {
      if (first->isInteger())
        return true;
      else {
        if (!it)
          it = new NestedIterator(first->getList());
        if (it->hasNext()) {
          return true;
        } else {
          delete it;
          it = nullptr;
        }
      }
      first++;
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

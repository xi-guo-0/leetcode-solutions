class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    bool ans = !s.count(val);
    s.insert(val);
    return ans;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    bool ans = s.count(val);
    s.erase(val);
    return ans;
  }

  /** Get a random element from the set. */
  int getRandom() { return *next(s.begin(), rand() % s.size()); }

private:
  set<int> s;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

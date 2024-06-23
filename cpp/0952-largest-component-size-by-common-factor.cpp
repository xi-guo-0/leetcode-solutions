#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class UnionFind {
  vector<int> parent;
  vector<int> size;

public:
  UnionFind(int n) {
    parent.resize(n);
    size.resize(n, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      if (size[rootX] < size[rootY]) {
        swap(rootX, rootY);
      }
      parent[rootY] = rootX;
      size[rootX] += size[rootY];
    }
  }

  int getSize(int x) { return size[find(x)]; }
};

class Solution {
public:
  int largestComponentSize(vector<int> &nums) {
    int n = nums.size();
    UnionFind uf(n);

    unordered_map<int, int> primeToIndex;

    for (int i = 0; i < n; ++i) {
      vector<int> primes = getPrimeFactors(nums[i]);
      int firstPrimeIndex = -1;
      for (int prime : primes) {
        if (primeToIndex.count(prime)) {
          int prevIndex = primeToIndex[prime];
          uf.unite(prevIndex, i);
        } else {
          primeToIndex[prime] = i;
        }
      }
    }

    unordered_map<int, int> componentSize;
    int maxSize = 0;

    for (int i = 0; i < n; ++i) {
      int root = uf.find(i);
      componentSize[root]++;
      maxSize = max(maxSize, componentSize[root]);
    }

    return maxSize;
  }

private:
  vector<int> getPrimeFactors(int num) {
    vector<int> factors;
    for (int i = 2; i * i <= num; ++i) {
      if (num % i == 0) {
        while (num % i == 0) {
          num /= i;
        }
        factors.push_back(i);
      }
    }
    if (num > 1) {
      factors.push_back(num);
    }
    return factors;
  }
};

int main() { return 0; }

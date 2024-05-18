#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    int len = nums.size();
    int mid = getMid(nums, 0, len - 1, len / 2);
    int i = 0;
    int j = 0;
    int n = len - 1;
    while (j <= n) {
      int index = getIndex(j, len);
      if (nums[index] > mid) {
        swap(nums, getIndex(j++, len), getIndex(i++, len));
      } else if (nums[index] < mid) {
        swap(nums, index, getIndex(n--, len));
      } else {
        j++;
      }
    }
  }

private:
  void swap(std::vector<int> &nums, int l, int r) {
    int temp = nums[l];
    nums[l] = nums[r];
    nums[r] = temp;
  }

  int getIndex(int i, int len) { return (2 * i + 1) % (len | 1); }

  int getMid(std::vector<int> &nums, int l, int r, int rank) {
    int now = nums[l];
    int left = l;
    int right = r;
    while (left < right) {
      while (left < right && nums[right] >= now) {
        right--;
      }
      nums[left] = nums[right];
      while (left < right && nums[left] <= now) {
        left++;
      }
      nums[right] = nums[left];
    }
    nums[left] = now;
    if (left - l == rank) {
      return now;
    } else if (left - l < rank) {
      return getMid(nums, left + 1, r, rank - left + l - 1);
    } else {
      return getMid(nums, l, right - 1, rank);
    }
  }
};

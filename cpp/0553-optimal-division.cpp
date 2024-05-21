class Solution {
public:
  string optimalDivision(const vector<int> &nums) {
    if (nums.size() == 0) {
      return "";
    } else if (nums.size() == 1) {
      return to_string(nums[0]);
    } else if (nums.size() == 2) {
      return to_string(nums[0]) + "/" + to_string(nums[1]);
    }
    ostringstream os;
    os << to_string(nums[0]) << "/(" << to_string(nums[1]);
    for (int i = 2; i < nums.size(); i++)
      os << "/" << to_string(nums[i]);
    os << ")";
    return os.str();
  }
};

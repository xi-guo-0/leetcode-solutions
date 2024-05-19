class Solution {
public:
  string toHex(int num) {
    ostringstream os;
    os << std::hex << num;
    return os.str();
  }
};

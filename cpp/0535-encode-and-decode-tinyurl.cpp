class Solution {
public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    dict[index] = longUrl;
    return prefix + to_string(index);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return dict[stoi(shortUrl.replace(0, prefix.size(), ""))];
  }

private:
  map<int, string> dict;
  int index = 0;
  string prefix = string("http://tinyurl.com/");
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

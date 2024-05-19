class Twitter {
public:
  /** Initialize your data structure here. */
  Twitter() {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    valid(userId);
    arr.push_back(make_pair(userId, tweetId));
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> result;
    if (!dict.count(userId)) {
      return result;
    }
    valid(userId);
    const auto &friends = dict[userId];
    for (auto it = arr.crbegin(); it != arr.crend() && result.size() < 10; it++)
      if (friends.count(it->first))
        result.push_back(it->second);
    return result;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    valid(followerId);
    dict[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    valid(followerId);
    if (dict.count(followerId))
      dict[followerId].erase(followeeId);
    else
      dict[followerId] = set<int>();
  }

private:
  vector<pair<int, int>> arr;
  map<int, set<int>> dict;

  void valid(int userId) {
    if (!dict.count(userId))
      dict[userId] = set<int>();
    dict[userId].insert(userId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

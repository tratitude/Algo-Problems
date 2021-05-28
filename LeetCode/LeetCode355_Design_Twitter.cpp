// Time complexity:
// postTweet(): O(1)
// getNewsFeed(): O(P)
//   P: number of all posts
// follow(): O(1)
// unfollow(): O(1)
class Twitter {
  using PII = pair<int, int>;
  // posts stack, {id, tweetId}
  vector<PII> posts;

  struct MyHash {
    size_t operator()(const pair<int, int>& v) const {
      // wrong: {v.first, v.second} == {v.second, v.first}. But AC
      //return v.first ^ v.second;

      // maximum userId is 500, that will be not interchangable. But slower 
      return (v.first+501) ^ v.second;
    }
  };
  // {followerID, followeeID}
  unordered_set<PII, MyHash> followed;

 public:
  /** Initialize your data structure here. */
  Twitter() {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    posts.push_back({userId, tweetId});
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    int count = 10;
    vector<int> tweets;

    for (auto it = posts.rbegin(); it != posts.rend(); ++it) {
      if (it->first == userId || followed.count({userId, it->first}) > 0) {
        tweets.push_back(it->second);
        if (--count == 0) break;
      }
    }
    return tweets;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    followed.insert({followerId, followeeId});
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    auto it = followed.find({followerId, followeeId});

    if (it != followed.end()) followed.erase(it);
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
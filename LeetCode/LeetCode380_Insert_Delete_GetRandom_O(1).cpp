// Time complexity: O(1) for all function in average
// Space complexity: O(N)
class RandomizedSet {
  // v[i] -> i
  unordered_map<int, int> mp;
  vector<int> v;

 public:
  /** Initialize your data structure here. */
  RandomizedSet() { srand(time(nullptr)); }

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (mp.count(val)) return false;

    mp[val] = v.size();
    v.push_back(val);

    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (!mp.count(val)) return false;

    int end = v.back();
    // update v
    v[mp[val]] = end;
    v.pop_back();
    // update mp
    mp[end] = mp[val];
    // erase mp
    mp.erase(val);

    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    int num = rand() % v.size();
    return v[num];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
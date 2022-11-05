// Time complexity:
//   set: O(1)
//   get: O(logN)
// Space complexity: O(N)
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> record;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        record[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (record.count(key) == 0 || timestamp < record[key].front().first)
            return "";

        int left = 0, right = record[key].size();
        while (left < right) {
            int mid = left + (right - left)/2;
            int midTimeStamp = record[key][mid].first;
            if (midTimeStamp == timestamp) {
                left = mid + 1;
            } else if (midTimeStamp < timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left == 0) return "";
        
        return record[key][left-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
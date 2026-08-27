
//for binary search, find a interval l and right then appluy binary search
class TimeMap {
private:
    map<string, vector<pair<string,int>>> m;
    //ceate a map for instace search and insertion 0(1)
public:
    //find the index of the value that equal or closest to timestamp(earlier)
    //because set was call strictly increasing order
    //we can use binary search
   int binarySearch(const std::vector<std::pair<std::string,int>>& vec, int target) {
        int l = 0, r = (int)vec.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid].second <= target) {
                ans = mid;        // candidate (timestamp <= target)
                l = mid + 1;      // try to find a later one
            } else {
                r = mid - 1;
            }
        }
        return ans; // -1 means all timestamps are > target
    }
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        this->m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        auto it = m.find(key);
        if(it == m.end()) return "";


        int n = m[key].size();
        int res = binarySearch(m[key],timestamp);
        return res == -1 ? "" : m[key][res].first;


        
    }
};

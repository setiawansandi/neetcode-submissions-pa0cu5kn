class TimeMap {
public:
unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int l = 0;
        int r = mp[key].size() - 1;
        int res = -1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            // [10, 20, 30, 40, 50] 35
            if(mp[key][mid].first > timestamp) r = mid - 1;
            else if (mp[key][mid].first <= timestamp) {
                res = mid;
                l = mid + 1;
            }
        }
        if(res != -1) return mp[key][res].second;
        return "";
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(const int& num : nums) {
            if(seen.contains(num)) return num;
            seen.insert(num);
        }
        return 0;
    }
};

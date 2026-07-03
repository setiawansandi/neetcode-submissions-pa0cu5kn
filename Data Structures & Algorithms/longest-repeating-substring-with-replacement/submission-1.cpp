class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int res = 0;
        int maxf = 0;
        unordered_map<char, int> count;

        while(r < s.length()) {
            count[s[r]]++;
            
            for(auto& [key, value]: count) {
                maxf = max(maxf, value);
            }

            while(r-l+1 - maxf > k) {
                count[s[l]]--;
                ++l;
            }

            res = max(res, r-l+1);
            ++r;
            cout << res << " ";
        }
        return res;
    }
};

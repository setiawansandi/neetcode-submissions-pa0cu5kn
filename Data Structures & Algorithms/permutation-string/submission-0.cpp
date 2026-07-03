class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        
        unordered_map<char, int> countS1, countS2;
        int matches = 0;

        for(int i = 0; i < s1.length(); ++i) {
            countS1[s1[i]]++;
            countS2[s2[i]]++;
        }

        for(int i = 0; i < 26; ++i) {
            if(countS1['a' + i] == countS2['a' + i]) ++matches;
        }
        
        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++, l++) {
            if(matches == 26) return true;

            countS2[s2[r]]++;
            if(countS2[s2[r]] == countS1[s2[r]]) ++matches;
            else if(countS2[s2[r]] == countS1[s2[r]] + 1) --matches;

            countS2[s2[l]]--;
            if(countS2[s2[l]] == countS1[s2[l]]) ++matches;
            else if(countS2[s2[l]] == countS1[s2[l]] - 1) --matches;
        }
        return matches == 26;
    }
};

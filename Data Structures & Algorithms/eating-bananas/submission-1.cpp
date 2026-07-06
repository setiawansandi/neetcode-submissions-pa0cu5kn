class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 0;
        long long result = LONG_MAX;
        while(result > h) {
            result = 0;
            k++;
            for(int i = 0; i < piles.size(); ++i) {
                result += ceil((double)piles[i]/k);
            }
        }
        return k;
    }
};

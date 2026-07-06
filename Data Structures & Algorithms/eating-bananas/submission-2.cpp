class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // upper bound of k = largest pile
        // h   0 - largest pile -> mid -> sum all(k = largest pile/mid) == h or iterate all

        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        int res = r;

        while (l <= r) {
            int mid = l + (r-l)/2;

            long long totalTime = 0;
            for(int i = 0; i < piles.size(); ++i) {
                totalTime += ceil((double)piles[i]/mid);
            }
            if (totalTime > h) l = mid+1;
            else {
                res = mid;
                r = mid-1;
            }
        }
        return res;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carPair;
        for(int i = 0; i < position.size(); ++i) {
            carPair.push_back({position[i], speed[i]});
        }
        sort(carPair.rbegin(), carPair.rend()); // reverse
        vector<double> stk;
        for (auto& p : carPair) {
            stk.push_back((double) (target-p.first)/p.second);
            if(stk.size() >= 2 && stk.back() <= stk[stk.size()-2]) {
                stk.pop_back();
            }
        }
        return stk.size();
    }
};

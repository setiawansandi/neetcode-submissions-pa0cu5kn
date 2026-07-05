class Solution {
public:
// store index, pop smaller
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> buffer;
        vector<int> ans(temperatures.size(), 0);
        
        for(int i = 0; i < temperatures.size(); ++i) {
            while(!buffer.empty() && temperatures[i] > temperatures[buffer.top()]) {
                int val = buffer.top();
                buffer.pop();
                ans[val] = i - val;
            }
            buffer.push(i);
        }

        return ans;
    }
};

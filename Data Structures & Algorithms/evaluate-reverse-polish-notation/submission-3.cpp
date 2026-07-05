class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> buffer;

        for(int i = 0; i < tokens.size(); ++i) {
            if(tokens[i] != "*"
                && tokens[i] != "+"
                && tokens[i] != "-"
                && tokens[i] != "/") {
                
                buffer.push(stoi(tokens[i]));
                continue;
            }

            int b = buffer.top();
            buffer.pop();
            int a = buffer.top();
            buffer.pop();
            int res = 0;

            if(tokens[i] == "*") res = a * b;
            else if(tokens[i] == "-") res = a - b;
            else if(tokens[i] == "+") res = a + b;
            else if(tokens[i] == "/") res = a /b;

            buffer.push(res);
        }
        return buffer.top();
    }
};

class MinStack {
public:
stack<int> storage;
stack<int> minVal;

    MinStack() {
        
    }
    
    void push(int val) {
        storage.push(val);
        if(minVal.empty()) {
            minVal.push(val);
        } else {
            val < minVal.top() ? minVal.push(val) : minVal.push(minVal.top());
        }
    }
    
    void pop() {
        storage.pop();
        minVal.pop();
    }
    
    int top() {
        return storage.top();
    }
    
    int getMin() {
        return minVal.top();
    }
};

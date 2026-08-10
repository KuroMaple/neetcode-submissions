class MinStack {
std::stack<std::pair<int,int>> stateStack;
public:
    MinStack() {}
    
    void push(int val) {
        int currentMin = val;
        if(!stateStack.empty()) {
            currentMin = std::min(currentMin, this->getMin());
        }
        stateStack.push({val, currentMin});
    }
    
    void pop() {
        stateStack.pop();
    }
    
    int top() {
        return stateStack.top().first;
    }
    
    int getMin() {
        return stateStack.top().second;
    }
};

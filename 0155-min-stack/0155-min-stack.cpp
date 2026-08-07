class MinStack {
    stack<int> mainstack;
    stack<int> minstack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        mainstack.push(value);
        if(minstack.empty() || value<=minstack.top()){
            minstack.push(value);
        }
    }
    
    void pop() {
        int temp=mainstack.top();
        mainstack.pop();
        if(temp==minstack.top()){
            minstack.pop();
        }

    }
    
    int top() {
        return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
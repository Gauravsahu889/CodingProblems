class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}
    
    // Push always goes to the non-empty queue, or q1 if both are empty
    void push(int x) {
        if (!q2.empty()) {
            q2.push(x);
        } else {
            q1.push(x);
        }
    }
    
    // Pop moves n-1 elements to the empty queue, pops the last one, and swaps
    int pop() {
        if (q1.empty()) {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int val = q2.front();
            q2.pop();
            return val;
        } else {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int val = q1.front();
            q1.pop();
            return val;
        }
    }
    
    // Top returns the last element pushed
    int top() {
        if (q1.empty()) {
            return q2.back();
        } else {
            return q1.back();
        }
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

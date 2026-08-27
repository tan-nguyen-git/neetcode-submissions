class MinStack {
private:
    stack<int> s, prefix;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty() || val<prefix.top()){
            prefix.push(val);
        }
        else{
            prefix.push(prefix.top());
        }
        s.push(val);

       
        
    }
    
    void pop() {
        if(s.empty()) return;
        s.pop();
        prefix.pop();
        
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return prefix.top();

    }
};

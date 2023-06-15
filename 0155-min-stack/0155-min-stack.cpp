class MinStack {
public:
    stack<pair<int,int>> a1;
    MinStack() {
        
    }
    
    void push(int val) {
        if(a1.empty()==true){
            a1.push(make_pair(val,val));
        }
        else
            a1.push(make_pair(val,min(a1.top().second,val)));
    }
    
    void pop() {
        a1.pop();
    }
    
    int top() {
       return a1.top().first;
    }
    
    int getMin() {
        return a1.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
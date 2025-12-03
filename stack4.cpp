// 232. implement queue using stacks

class MyQueue {
private:
stack<int> s1;
stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        int s = s1.size();
        for(int i = 0 ;i<s;i++ ){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        int S = s2.size();
        for(int i = 0 ;i<S;i++ ){
            s1.push(s2.top());
            s2.pop();
        }

    }
    
    int pop() {
        int n = s1.top();
        s1.pop();
        return n;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

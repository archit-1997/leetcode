/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : minStack.cpp
 * @created     : Wednesday Aug 18, 2021 07:28:35 IST
 */

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<long long> st;
    long long  curMin;
    MinStack() {
    }
    
    void push(long long val) {
        if(st.empty()){
            st.push(val);
            curMin=val;
            return;
        }

        //the stack is not empty
        if(val>=curMin)
            st.push(val);
        else{
            //inserting num instead of val
            st.push(2*val-curMin);
            //updating the current min to value
            curMin=val;
        }
    }
    
    void pop() {
        if(st.top()>=curMin)
            st.pop();
        else{
            //we now have a min element
            curMin=2*curMin-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>curMin)
            return st.top();
        else
            return curMin;
    }
    
    int getMin() {
        return curMin;
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

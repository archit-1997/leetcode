/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : implementQueueUsingTwoStacks_rec.cpp
 * @created     : Saturday Jul 31, 2021 19:23:53 IST
 */

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> st;

    stack<int> insertAtBottom(stack<int> st,int x){
        if(st.empty()){
            //insert the element now
            st.push(x);
            return st;
        }

        int t=st.top();
        st.pop();
        st=insertAtBottom(st,x);
        st.push(t);
        return st;
    }

    stack<int> reverse(stack<int> st){
        if(st.empty())
            return st;

        int t=st.top();
        st.pop();
        st=reverse(st);
        //insert t at the bottom of the stack
        st=insertAtBottom(st,t);
        return st;

    }

    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
                st.push(x);
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //reverse the stack
        st=reverse(st);
        int t=st.top();
        st.pop();
        //again reverse the stack
        st=reverse(st);
        return t;

    }
    
    /** Get the front element. */
    int peek() {
        //reverse the stack
        st=reverse(st);
        int t=st.top();
        //again reverse the stack
        st=reverse(st);
        return t;

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
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

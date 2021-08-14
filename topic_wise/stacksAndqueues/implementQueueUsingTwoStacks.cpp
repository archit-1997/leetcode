/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : implementQueueUsingTwoStacks.cpp
 * @created     : Saturday Jul 31, 2021 07:07:45 IST
 */


#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> pushStack,popStack;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        //check if there is anything inside the pop stack
        //insert all elements into the push stack
        int t;
        while(!popStack.empty()){
            t=popStack.top();
            popStack.pop();
            pushStack.push(t);
        }
        //now we need to push x back to pushStack
        pushStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //take all elements in the popStack
        int t;
        while(!pushStack.empty()){
            t=pushStack.top();
            pushStack.pop();
            popStack.push(t);
        }
        t=popStack.top();
        popStack.pop();
        return t;
        
    }
    
    /** Get the front element. */
    int peek() {
        //take all elements in the popStack
        int t;
        while(!pushStack.empty()){
            t=pushStack.top();
            pushStack.pop();
            popStack.push(t);
        }
        t=popStack.top();
        return t;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (popStack.empty() && pushStack.empty());
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

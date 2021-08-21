/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : basicCalculatorII.cpp
 * @created     : Saturday Aug 21, 2021 09:06:09 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long int evaluate(long long int a,long long int b,char op){
        if(op=='*')
            return a*b;
        else
            return a/b;
    }

    int calculate(string s) {
        //we need to parse the string so that there are no empty spaces
        stack<long long > num;
        string number="";
        int n=s.size(),i=0;
        //find the first number
        while(i<n && (s[i]==' ' || ( s[i]>='0' && s[i]<='9' ))){
            if(s[i]==' '){
                i++;
                continue;
            }
            number=number+s[i];
            i++;
        }
        
        long long first=stoll(number);
        if(i==n)
            return first;

        num.push(first);
        while(i<n){
            if(s[i]==' '){
                i++;
                continue;
            }
            char ch=s[i];
            i++;
            string tmp="";
            while(i<n && (s[i]==' ' || ( s[i]>='0' && s[i]<='9' ))){
                if(s[i]==' '){
                    i++;
                    continue;
                }
                tmp=tmp+s[i];
                i++;
            }
            //this is the next number
            long long int b=stoll(tmp);
            if(ch=='*' || ch=='/'){
                //we can do evaluation and just push the result back to the num stack
                long long int a=num.top();
                num.pop();
                long long int res=evaluate(a,b,ch);
                num.push(res);
            }
            else if(ch=='-')
                num.push(-b);
            else
                num.push(b);
        }

        long long int ans=0;
        while(!num.empty()){
            ans=ans+num.top();
            num.pop();
        }
        return ans;
    }
};

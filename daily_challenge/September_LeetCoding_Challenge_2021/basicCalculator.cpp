/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : basicCalculator.cpp
 * @created     : Saturday Sep 18, 2021 09:58:01 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

class Solution {
public:
    int calculate(string s) {
        int pos=0;
        return evaluate(s,pos);
    }
    
    int evaluate(string& s, int& i) {
        int res = 0;
        bool negFlag=false;
        while(i<s.size()&&s[i]!=')') {
            if(s[i]=='+'||s[i]==' ') 
                i++;
            else if(s[i]=='-') {
                i++;
                negFlag=true;
            }
            else if(s[i]=='(') {
                i++;
                res+=negFlag?-evaluate(s,i):evaluate(s,i);
                negFlag=false;
            }
            else {// numeric chars
                int num=0;
                while(i<s.size()&&isdigit(s[i]))
                    num = num*10 + (s[i++]-'0');
                
                res+=negFlag?-num:num;
                negFlag=false;
            }
        }
        i++; // skip the current ')'
        return res;
    }
};

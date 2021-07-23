/** @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : sumGame.cpp
 * @created     : Friday Jul 23, 2021 10:02:41 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();

        int sum=0,count=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?')
                count+=(i<(n/2))?1:-1;
            else{
                int val=num[i]-'0';
                sum+=(i<(n/2))?val:-val;
            }
        }
        
        int val=abs(count);
        if(val%2==1)
            return true;
        else{
            int rounds=count/2;
            if(( sum+( 9*rounds ) )==0)
                return false;
            return true;
        }

    }
};


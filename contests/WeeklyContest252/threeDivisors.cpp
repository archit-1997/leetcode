/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : threeDivisors.cpp
 * @created     : Sunday Aug 01, 2021 08:01:04 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isThree(int n) {
        int sq=sqrt(n);
        set<int> st;
        st.insert(1);
        st.insert(n);
        for(int i=2;i<=sq;i++){
            if(n%i==0){
                st.insert(i);
                if(n/i!=i)
                    st.insert(n/i);
            }
            
        }
        return (st.size()==3);
    }
};


/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : wonderfulSubstrings.cpp
 * @created     : Wednesday Jul 28, 2021 20:59:55 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isOdd(int n){
        return (n%2==1);
    }

    long long compute(int n){
        long long int ans=(n*(n+1))/2;
        return ans;
    }

    long long wonderfulSubstrings(string word) {
        long long ans=0;
        //for hashing
        vector<int> hash(10,0);
        //store the odd count
        long long oc=1;
        //increment the value of hash of the first character
        hash[word[0]-'a']++;
        int prev=0;
        for(int i=1;i<word.size();i++){
            int val=word[i]-'a';
            hash[val]++;
            
            //if the count of this is odd
            if(isOdd(hash[val]))
                oc++;

           //we need to check only if oc>1
           if(oc>1){
                //we can have substrings from length i-prev
                int len=i-prev;
                ans+=compute(len);
                //we will have to increment prev till oc>1
                while(oc>1){
                    //if now the hash is even, that means that earlier it was odd
                    if(isOdd(hash[word[prev]-'a']))
                        oc--;
                    hash[word[prev]-'a']--;
                    prev++;
                }
           }
        }

        int len=word.size()-prev;
        ans+=compute(len);
                oc=0;
        //check for the whole string
        unordered_map<char,int> map;
        for(int i=0;i<word.size();i++)
            map[word[i]]++;

        for(auto it=map.begin();it!=map.end();it++){
            if(isOdd(it->second))
                oc++;
        }
        if(oc<=1)
            ans++;

        return ans;
    }
};


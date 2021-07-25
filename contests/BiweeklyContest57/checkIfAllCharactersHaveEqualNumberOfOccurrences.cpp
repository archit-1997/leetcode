/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : checkIfAllCharactersHaveEqualNumberOfOccurrences.cpp
 * @created     : Saturday Jul 24, 2021 20:00:56 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> count;
        int n=s.size();

        for(int i=0;i<n;i++)
            count[s[i]]++;

        auto it=count.begin();
        int ans=it->second;
        it++;
        while(it!=count.end()){
            int num=it->second;
            if(ans!=num)
                return false;
            it++;
        }
        return true;
    }
};

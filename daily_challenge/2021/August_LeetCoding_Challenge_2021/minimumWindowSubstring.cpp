/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : minimumWindowSubstring.cpp
 * @created     : Monday Aug 16, 2021 05:28:02 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //first we will count all the characters of the smaller string
        unordered_map<char,int> small,big;
        for(int i=0;i<t.size();i++)
            small[t[i]]++;

        int count=0,start=0,end=0;

        //now we will keep on incrementing until we find all the characters of the small string in the big string
        for(int i=0;i<s.size();i++){
            if(small[s[i]]>big[s[i]])
                count++;
            big[s[i]]++;

            //if count is equal to the size of the small string , this means all the characters have been found
            if(count==t.size()){
                end=i;
                break;
            }
            
        }
        //if the string hasn't been found yet
        if(count<t.size())
            return "";
        
        //we will trim the string from the front
        while(big[s[start]]>small[s[start]]){
            big[s[start]]--;
            start++;
        }
        //this is the current min requried window
        int len=end-start+1;
        string ans=s.substr(start,len);
        /* cout<<ans<<"\n"; */


        while(end<s.size()){
            big[s[start]]--;
            char prev=s[start];
            start++;
            end++;

            while(end<s.size() && s[end]!=prev){
                big[s[end]]++;
                end++;
            }
            //in case we reach the end, we will just return the ans
            if(end==s.size())
                return ans;
            
            //end has reached the correct index
            big[s[end]]++;

            //we have found this character, now we will move the back pionter
            while(big[s[start]]>small[s[start]]){
                big[s[start]]--;
                start++;
            }

            int curLen=end-start+1;
            if(curLen<len){
                ans=s.substr(start,curLen);
                len=curLen;
            }

        }

        return ans;
    }
};


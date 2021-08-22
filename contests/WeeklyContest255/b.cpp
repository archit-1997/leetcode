/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : b.cpp
 * @created     : Sunday Aug 22, 2021 08:03:56 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long long binaryToDecimal(string s){
        reverse(s.begin(),s.end());
        long long ans=0;
        long long n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1')
                ans+=pow(2,i);
        }
        return ans;
    }

    string decimalToBinary(long long n){
        string ans="";
        while(n!=0){
            int rem=n%2;
            ans=ans+to_string(rem);
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<long long ,long long >map;
        int n=nums.size();

        for(int i=0;i<n;i++){
            string s=nums[i];

            //find the decimal representation of this number
            long long num=binaryToDecimal(s);
            map[num]++;
        }

        int s=nums[0].size();

        long long int limit=pow(2,s)-1;

        string bin="";
        for(long long i=1;i<=limit;i++){
            if(map.find(i)==map.end()){
                //we need to find the binary rep of this number
                bin=decimalToBinary(i);
                break;
            }
        }

        //we need to append zeroes accordingly
        while(bin.size()<s){
            bin='0'+bin;
        }

        return bin;
    }
};

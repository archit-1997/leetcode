/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : letterCombinationOfAPhoneNumber.cpp
 * @created     : Wednesday Jul 28, 2021 08:39:04 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_map<int,string> prepare(){
            unordered_map<int,string>dict;
            dict[0]="";
            dict[1]="";
            dict[2]="abc";
            dict[3]="def";
            dict[4]="ghi";
            dict[5]="jkl";
            dict[6]="mno";
            dict[7]="pqrs";
            dict[8]="tuv";
            dict[9]="wxyz";
            
            return dict;

    }

    void findCombinations(vector<string> &ans,string tmp,unordered_map<int,string> &dict, string &digits,int index){
        //traversed the whole string
        if(index==digits.size()){
            ans.push_back(tmp);
            return;
        }

        char ch=digits[index];
        int pos=ch-'0';
        string numbers=dict[pos];
        for(int i=0;i<numbers.size();i++){
           //insert first character and recur for the rest of the string
           findCombinations(ans,tmp+numbers[i],dict,digits,index+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            vector<string> ans;
            return ans;
        }
        //prepare a map to store the mappings of numbers
        unordered_map<int,string> dict = prepare();

        vector<string> ans;
        
        //start from the 0th digit
        string tmp="";
        findCombinations(ans,tmp,dict,digits,0);
        
        return ans;

    }
};


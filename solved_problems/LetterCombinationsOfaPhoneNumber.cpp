/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, vector<string>> dir {
               {'2', {"a","b","c"}},  
               {'3', {"d","e","f"}},  
               {'4', {"g","h","i"}},  
               {'5', {"j","k","l"}},  
               {'6', {"m","n","o"}},  
               {'7', {"p","r","q","s"}},  
               {'8', {"t","u","v"}},  
               {'9', {"w","x","y","z"}}
       };
        
        vector<string> ans;
        
        if(digits.size()==0)
            return ans;
        else if(digits.size()==1)
            return dir[digits[0]];
        else
        {
            vector<string> comb=letterCombinations(digits.substr(1));
            
            for(string s1:dir[digits[0]])
                for(string s2: comb)
                    ans.push_back(s1+s2);
        }
        
        return ans;
        
    }
};

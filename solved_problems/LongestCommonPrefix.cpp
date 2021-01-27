/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        return "";
        string ans="";
        int max=INT_MAX;
        for(auto& s:strs)
        {
            max=(max>s.length())?s.length():max;
        }
        for(int i=0;i<max;i++)
        {
            bool flag=true;
            char x=strs[0][i];
            for(auto& s:strs)
            {
                if(s[i]!=x)
                {
                    flag=false;
                    break;
                }
            }
            if(flag==false)
            return ans;
            ans+=x;
        }
        return ans;
    }
};

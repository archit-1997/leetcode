/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb" */


class Solution {
public:
    string longestPalindrome(string s) {
        
        int ans=0,len=1,li=0,ri=0;
        
        //First we are calculating for pallindromes
        
        for(int i=0;i<s.size();i++)
        {
            int l=i-1;
            int r=i+1;
            
            while(1)
            {
                if(l<0 || r>=s.size() || (s[l]!=s[r]))
                    break;
                len+=2;
                l--;r++;
            }
            if(len>ans)
            {
                ans=len;
                li=l+1;
                ri=r-1;
            }
            len=1;
        }
        
        //Now we are checking for even strings
        len=0;
        
        for(int i=0;i<s.size();i++)
        {
            int l=i-1;
            int r=i;
            
            while(1)
            {
                if(l<0 || r>=s.size() || (s[l]!=s[r]))
                    break;
                len+=2;
                l--;r++;
            }
            if(len>ans)
            {
                ans=len;
                li=l+1;
                ri=r-1;
            }
            len=0;
        }
        
        string str=s.substr(li,(ri-li+1));
        return str;
    }
};

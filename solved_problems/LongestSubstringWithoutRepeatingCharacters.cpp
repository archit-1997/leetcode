/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/
    
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()==0)
            return 0;
        
        unordered_map<char,int> pos;
        
        int i,st=0,curlen=0,start,maxlen=0;
        
        pos[s[0]]=0;
        
        for(i=1;i<s.size();i++)
        {
            if(pos.find(s[i])==pos.end())
                pos[s[i]]=i;
            else
            {
                if(pos[s[i]]>=st)
                {
                    curlen=i-st;
                    if(maxlen<curlen)
                    {
                        maxlen=curlen;
                        start=st;
                    }
                    
                    st=pos[s[i]]+1;
                }
             
                 pos[s[i]]=i;
            }
        }
        //Now you have to compare the length of the last substring with the 
        //maxlen
        
        if(maxlen<(i-st))
        {
            maxlen=i-st;
            start=st;
        }
        
        return maxlen;
        
    }
};

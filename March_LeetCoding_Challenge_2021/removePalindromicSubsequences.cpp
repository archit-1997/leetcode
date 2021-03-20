class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        
        //now check whether the string is palindrome or not
        string rev=s;
        reverse(rev.begin(),rev.end());
        
        if(s==rev)
            return 1;
        else
            return 2;
        
    }
};
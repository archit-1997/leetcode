class Solution {
    
public:
    bool isAnagram(string s, string t) {
        map<char,int> h1,h2;
        
        int n1=s.size(),n2=t.size();
        
        if(n1!=n2)
            return false;
        
        for(int i=0;i<n1;i++){
            h1[s[i]]++;
            h2[t[i]]++;
        }
        auto it=h1.begin();
        for(auto it=h1.begin();it!=h1.end();it++){
            char c=it->first;
            int val=it->second;
            
            if(h2[c]!=val)
                return false;
        }
        
        return true;
        
    }
};

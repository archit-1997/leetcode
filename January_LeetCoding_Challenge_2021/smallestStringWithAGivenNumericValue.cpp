Stclass Solution {
public:
    vector<char> a = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                      'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string getSmallestString(int n, int k) {
        string s="";
        for(int i=0;i<n;i++)
            s+='a';
        k-=n;
        int ind = n-1;
        while(k!=0)
        {
            if(k>=25)
            {
                s[ind] = a[25]; 
                k-=25;
                ind--;
            }
            else
            {
                s[ind] = a[k];
                break;              
            }
        }
        return s;
    }
};
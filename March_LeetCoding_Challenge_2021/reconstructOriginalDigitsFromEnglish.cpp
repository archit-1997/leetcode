class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,int> count;

        int n=s.size();

        for(int i=0;i<n;i++){
            count[s[i]]++;
        }

        vector<int> ans(10,0);

        //we know the count of zero
        ans[0]=count['z'];
        ans[2]=count['w'];
        ans[4]=count['u'];
        ans[6]=count['x'];
        ans[8]=count['g'];
        //one is peresent in zero, one, two and four
        ans[1]=count['o']-ans[0]-ans[2]-ans[4];
        ans[3]=count['h']-ans[8];
        ans[5]=count['f']-ans[4];
        ans[7]=count['s']-ans[6];
        ans[9]=count['i']-ans[5]-ans[6]-ans[8];

        string res="";
        for(int i=0;i<10;i++){
            for(int j=0;j<ans[i];j++)
                res=res+to_string(i);
        }

        return res;

    }
};
#include <bits/stdc++.h>
using namespace std;

unordered_map<char,int> prio;
bool compare(const char &a,const char &b){
    return prio[a]<prio[b];
}

class Solution {
public:
   
    string customSortString(string order, string str) {
         prio.clear();
       //find the priority of each characer
       int count=1;
       for(int i=0;i<order.size();i++){
            if(prio[order[i]]==0){
                prio[order[i]]=count;
                count++;
            }
       }
       string first="",last="";
       //filter out the strings which are present in order 
       for(int i=0;i<str.size();i++){
            if(prio[str[i]]>0)
                first=first+str[i];
            else
                last=last+str[i];
       }
        //cout<<first<<" "<<last<<"\n";
       //sort first based on priority
       sort(first.begin(),first.end(),compare);
       string ans=first+last;
       return ans;
    }
};


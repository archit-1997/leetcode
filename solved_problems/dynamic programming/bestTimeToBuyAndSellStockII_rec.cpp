#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findProfit(vector<int> &prices,int index){
        if(index==prices.size())
            return 0;

        
        int curProfit=prices[index]-prices[index-1];
        if(curProfit>0)
            return curProfit+findProfit(prices,index+1);
        else
            return findProfit(prices,index+1);
            
    }

    int maxProfit(vector<int>& prices) {
        return findProfit(prices,1);
    }
};

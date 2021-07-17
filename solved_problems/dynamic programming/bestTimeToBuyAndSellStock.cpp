#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1)
            return 0;
        int maxProfit=0;
        int curPrice=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>curPrice)
                maxProfit=max(maxProfit,prices[i]-curPrice);
            else
                curPrice=prices[i];
        }
        return maxProfit;

    }
};

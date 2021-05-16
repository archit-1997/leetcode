#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fenwickTree;
    int size;

    //returns the number of elements which are <=index
    int sum(int index) {
        int ans = 0;
        for (int i = index; i > 0; i -= (i & -i))
            ans += fenwickTree[i];
        return ans;
    }

    void update(int index) {
        for (int i = index; i <size; i += (i & -i))
            fenwickTree[i] += 1;
    }

    int createSortedArray(vector<int> &v) {
        int n = v.size();
        size = 1e5 + 2;
        int mod=1e9+7;
        //fenwick tree
        fenwickTree.resize(size, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            //find the number of elements which are smaller
            int small = sum(v[i]-1);
            int large = i-sum(v[i]);
            ans += min(small, large);
            ans=ans%mod;
            //update the fenwick tree
            update(v[i]);
        }

        return ans;
    }
};
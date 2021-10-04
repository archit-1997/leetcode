/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : leftMostColumnWithAtleastOne.cpp
 * @created     : Monday Oct 04, 2021 22:58:00 IST
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P pair<int,int>

void init(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

  class BinaryMatrix {
    public:
      int get(int row, int col);
      vector<int> dimensions();
  };

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim=binaryMatrix.dimensions();

        int r=dim[0],c=dim[1];

        int l=0,h=c-1;
        int ans=INT_MAX;
        while(l<=h){
            //find the column through binary search
            int mid=l+(h-l)/2;
            
            //we find if ther is a 1 in the whole column
            bool flag=false;
            for(int i=0;i<r;i++){
                if(binaryMatrix.get(i,mid)){
                    //if we find a 1 in this part
                    ans=min(ans,mid);
                    flag=true;
                    break;
                }
            }
            if(flag)
                h=mid-1;
            else
                l=mid+1;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};

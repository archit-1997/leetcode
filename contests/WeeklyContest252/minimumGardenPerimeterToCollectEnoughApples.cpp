/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : minimumGardenPerimeterToCollectEnoughApples.cpp
 * @created     : Monday Aug 02, 2021 21:45:14 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long total=0;
        long long ans=0;
        while(total<neededApples){
            ans++;
            total+=12*ans*ans;
        }
        return 8*ans;
    }
};

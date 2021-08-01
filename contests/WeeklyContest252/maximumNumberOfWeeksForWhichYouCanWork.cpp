/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : maximumNumberOfWeeksForWhichYouCanWork.cpp
 * @created     : Sunday Aug 01, 2021 08:56:53 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum=accumulate(milestones.begin(),milestones.end(),0LL);
        int big=*max_element(milestones.begin(),milestones.end());

        if (2 * big > sum) {
            sum = (sum-big) * 2 + 1;
        }

        return sum;
    }
};

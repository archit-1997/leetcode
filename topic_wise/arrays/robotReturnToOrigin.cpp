/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : robotReturnToOrigin.cpp
 * @created     : Friday Aug 06, 2021 20:36:19 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U')
                y++;
            else if(moves[i]=='D')
                y--;
            else if(moves[i]=='L')
                x--;
            else
                x++;
        }
        return (x==0 && y==0);
    }
};

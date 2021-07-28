/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : validSudoku.cpp
 * @created     : Wednesday Jul 28, 2021 18:26:53 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool verify(vector<vector<char>> &board,int x,int y){
        char ch=board[x][y];
        //check for row
        for(int j=0;j<9;j++){
            if(j!=y && board[x][j]!='.' && board[x][j]==ch)
                return false;
        }
        //check for col
        for(int i=0;i<9;i++){
            if(i!=x && board[i][y]!='.' && board[i][y]==ch)
                return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        //9 x 9 board
        //first verify for every row and column
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    bool res=verify(board,i,j);
                    if(!res)
                        return false;
                }
            }
        }

        //now we have to verify for every 3x3 submatrix
        for(int i=0;i<9;i+=3){
            //now there are three column sets in every row
            for(int j=0;j<9;j+=3){
                unordered_map<int,int> hash;
                for(int a=i;a<i+3;a++){
                    for(int b=j;b<j+3;b++){
                        char ch=board[a][b];
                        if(ch!='.'){
                            int num=ch-'0';
                            hash[num]++;
                            if(hash[num]>1)
                                return false;
                        }
                    }
                }
            }
        }


        //everything seems to be fine, this is a valid sudoku
        return true;
    }
};

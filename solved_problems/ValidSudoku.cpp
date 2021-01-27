/*Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.


A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
    The given board contain only digits 1-9 and the character '.'.
    The given board size is always 9x9.
    */
    
    class Solution {
public:
    
    bool isValid(int r,int c,vector<vector<char>> &board)
    {
        //row checking
        for(int i=0;i<9;i++)
        {
            if(i!=c && board[r][i]!='.' && board[r][i]==board[r][c])
                return false;
        }
        
        //column checking
        for(int i=0;i<9;i++)
        {
            if(i!=r && board[i][c]!='.' && board[i][c]==board[r][c])
                return false;
        }
        
        int row=(r/3)*3;
        int col=(c/3)*3;
        
        int rm=row+3;
        int cm=col+3;
        
        int hash[9]={0};
        
        for(int i=row;i<rm;i++)
        {
            for(int j=col;j<cm;j++)
            {
                if(board[i][j]!='.')
                {
                    char ch=board[i][j];
                    int num=ch-'0';
                    if(hash[num-1]==1)
                        return false;
                    hash[num-1]=1;
                }
            }
        }
        
        return true;
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int r=board.size();
        int c=board[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!(isValid(i,j,board)))
                        return false;
                        
                }
            }
        }
        
        return true;
        
    }
};


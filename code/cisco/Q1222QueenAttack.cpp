#include <map>
#include <string>	
#include <vector>		
using namespace std;

class Solution {
public:
    vector<vector<int> > queensAttacktheKing(vector<vector<int> >& queens, vector<int>& king) {
        
    }
};



/**
 * 
 * method1:
 * start from king, find:
 * left, right, upper, lower
 * upperLeft, upperRight, lowerLeft, lowerRight
 * each step search for a position in queen, if find out/no find out/end/ break.
 * Append result to a returning vector.
 * 
 * 
 * method2: 
 * 1. start from each queen, find:
 * if column/row equal: put in a bracket.
 * if not, calculate how can king get to its position: whether out of bound or not match
 * put all in a bracket.
 * 
 * 2. check all queen's validity:
 * pick one, calculate upper left, upper right ... left / right.
 * same column with king: find other queen, if same column and same side, pick the one 
 * with smallest difference with king. 
 * 
 * 
 */


// Come from a Super Giant!
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
    {
        /* 
         * Plan:
         * 1. Create a board and mark the places where there are queens.
         * 2. For each direction a queen can go to:
         *      From the position of the king go into the current direction:
         *          If a queen is reached, add it to the result and continue with the next direction.
         *          If the end of the board is reached, continue with the next direction.
         * 3. Return the result.
         */
        
        array<bool,64> board{false}; // Array to hold the board.
        for(int i = 0; i < queens.size(); i++) // Fill the queens in the board.
            board[queens[i][0]+queens[i][1]*8] = true;
        vector<vector<int>> queensThatCanAttack; // Vector to hold answer.
        for(pair<int,int> modifier: initializer_list<pair<int,int>>{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}) // Iterate over the directions a queen can go to.
        {
            for(int i = king[0], j = king[1]; i >= 0 && i < 8 && j >= 0 && j < 8; i += modifier.first, j += modifier.second) // Go from the King towards the current direction until the end of the board is reached.
            {
                if(board[i+j*8]) // If a queen is found add it to the result and break.
                {
                    queensThatCanAttack.push_back({i,j}); 
                    break;
                }
            }
        }
        return queensThatCanAttack; // Return the result.
    }
};
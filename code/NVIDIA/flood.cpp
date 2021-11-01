// Q733 Flood fill

// two solutions: bfs & dfs

/*
 *  given a matrix, given a coordinate [1, 1], (the middle coordinate), given a new color 2
 *  0  1  0
 *  1  1  0
 *  1  0  0 
 * 
 *  change the color of given coordinate, 
 *  then change all its neighbour's color who has the same color with it.
 *  iterate this process, until all its neighbours and neighbours of its neighbour
 *  who has same old color have changed color.
 * 
 */

#include <algorithm>
#include <vector>
using namespace std;

// use dfs, saves space and time needed to put data into container, compared to bfs
class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        // start dfs
        dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
    
    void dfs(vector<vector<int> >& image, int row, int col, int oldColor, int newColor) {
        // need to check whether oldColor equals to newColor. Otherwise, get into infinite loop
        if (oldColor == newColor) return;
        if (image[row][col]==oldColor) {
            image[row][col]=newColor;
            if (row-1>=0) dfs(image, row-1, col, oldColor, newColor);
            if (row+1<image.size()) dfs(image, row+1, col, oldColor, newColor);
            if (col-1>=0) dfs(image, row, col-1, oldColor, newColor);
            if (col+1<image[0].size()) dfs(image, row, col+1, oldColor, newColor);
        }
    }
};


// What about using bfs??
class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        vector<pair<int, int> > toChange;  // vector to save points that need to be changed
        toChange.push_back(make_pair(sr, sc)); // push value
        
        // start bfs
        bfs(image, toChange, oldColor, newColor);
        return image;
    }
    
    void bfs(vector<vector<int> >& image, vector<pair<int, int> >& toChange, int oldColor, int newColor) {        
        // need to check whether oldColor equals to newColor. Otherwise, get into infinite loop
        while (!toChange.empty()) {
            if (oldColor == newColor) return;    
            pair<int, int> toCheck = toChange[toChange.size()-1];
            int i = toCheck.first;
            int j = toCheck.second;
            toChange.pop_back();
            if (image[i][j]==oldColor) {
                image[i][j] = newColor;
                if (i-1>=0) toChange.push_back(make_pair(i-1, j));
                if (i+1<image.size()) toChange.push_back(make_pair(i+1, j));
                if (j-1>=0) toChange.push_back(make_pair(i, j-1));
                if (j+1<image[0].size()) toChange.push_back(make_pair(i, j+1));
            }
        }
    }
};
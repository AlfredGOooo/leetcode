#include <map>
#include <string>	
#include <vector>		
using namespace std;
class Solution {
public:

    void rotate(vector<vector<int> >& matrix) {
        const int size = matrix.size();
        int arr[size];
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++){
                arr[j*size+size-1-i] = matrix[i][j];
            }
        }
        for (int k=0; k<size; k++) {
            for (int l=0; l<size; l++){
                matrix[k][l] = arr[k*size+l];
            }
        }
    }
};


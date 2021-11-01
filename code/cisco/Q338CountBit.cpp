#include <map>
#include <string>	
#include <vector>
#include <bitset>
#include <cmath>	
using namespace std;	
	
// Best answer!!
// Use a container called bitset
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> vec;
        vec.push_back(0);
        if (num>0){
            for (int i=1; i<=num; i++) {
            bitset<17> b(i);            // input: [0~10^5, =2^16+]
            int cnt = b.count();
            vec.push_back(cnt);
            }
        }
        return vec;
    }
};


// use bit operation
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> vec;
        int cnt = 0;
        int j;
        for (int i=0; i<=num; i++){
            j = i;
            while (j){
                if (j&0x1)  cnt++;
                j = j>>1;
            }
            vec.push_back(cnt);
            cnt = 0;
        }
        return vec;
    }
};


// Use DP to do the work: current solution can be derived from
// sub-solutions which solves the previous sub problems

vector<int> countBits(int num) {
        
        vector<int> dp(num+1,0);
        dp[0]=0;
        if(num==0)
            return {0};
        
        dp[1]=1;
        int flag=0;
        for(int i=2;i<=num;i++){
            
            double k=log2(i);
            if(floor(k)==ceil(k)){
                dp[i]=1;
                flag=i;
            }
            else{
                dp[i]=dp[flag]+dp[i-flag];
            }
            //cout<<k<<" ";
        }
        
        return dp;
}


/**
 *      Python DP solution:     
 * 
 *     def countBits(self, n: int) -> List[int]:
        if n==0:
            return[0]
        new=[0]*(n+1)
        new[0]=0
        new[1]=1
        if n==1:
            return new
        for i in range(2,n+1):
            if i%2==0:
                new[i]=new[i//2]
            else:
                new[i]=new[i//2]+1
        return new
*/


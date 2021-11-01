// solution 1

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*  corner case: abnormal input */
        /* input size == 0. */
        if (nums.size() == 0) return 0;
        
        int len = nums.size();
        int effecLen = len;
        int startPos=0, endPos=len-1;
        // remove value from nums
        for (int k=0; k<len; k++) {
            if (nums[k]==val) {
                nums[k] = -1;
                effecLen--;
            }
        }
        /* corner case: abnormal output */
        /* output size == 0 */
        if (effecLen==0) return 0;

        // move all elements to first k position
        /* carefully think of the right termination condition */
        while (startPos<endPos) {
            /* think of all conditions conditions to finish the move */
            if (nums[startPos]!=-1)  {
                startPos++;
                continue;
            }
            else {
                while(nums[startPos]==-1) {
                    if(nums[endPos]!=-1){
                        nums[startPos]=nums[endPos];
                    }
                    endPos--;
                }
                startPos++;
            }
        }
        return effecLen;
    }
};


// solution2
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        /* an index calculating the # of remaining elements */
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=val){
                /* when i = j, no effect, when i < j, cover i with j */ 
                nums[i]=nums[j];
                /* when a valid element found, i+1 */
                i+=1;
            }
        }
    return i;
    }  
};
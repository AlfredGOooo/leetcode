// solution 1 , a time-consuming & memory-consuming version

class Solution {
public:
    // the difficult part: how to determine this is a duplicate 
    // the difficult part: after removing duplicated element,
    // the relative order of this whole array should keep the same.
    int removeDuplicates(vector<int>& nums) {
        int dup=0, retSize, marker, size;
        // corner case: what if the size is zero or 1
        if ((nums.size()==0)||(nums.size()==1)) return nums.size();
        
        marker = nums[0];
        retSize = 1;
        size = nums.size();
        for (int i=1; i<size; i++) {
            if (nums[i]!=marker) {
                marker = nums[i];
                retSize++;
            }else {
                nums[i] = 101;
                dup = 1;
            }
        }
        
        if (retSize == 1) return retSize;
        
        // replace duplicates with numbers in place
        if (dup==1) {
            for (int j=1; j<size-1; j++) {
                if (nums[j]==101){  // it is a hole
                    int k = j+1;
                    while ((k<size)&&(nums[k]==101)) {
                        k++;
                    }
                    if (k==size) break;
                    nums[j] = nums[k];
                    nums[k] = 101;
                }
            }
        }
        return retSize;
    }
};


// solution 2, two pointers!
// there is a slow runner and a fast runner
// fast runner iterates and detect any target value
// slow runner only to increase and change the array
// such that the array is wanted.

class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        int ret = 0, size = nums.size();
        // corner case: if the size is zero.
        if ((size==0)||(size==1)) return size;

        // set up the slow and fast pointer
        for (int j=1; j<size; j++) {
            if (nums[ret]!=nums[j]) {
                if ()
                ret++;
            }
        }

    }
};

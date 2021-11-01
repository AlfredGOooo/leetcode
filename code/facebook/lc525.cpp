//     int findMaxLength(vector<int>& nums) {
//         int longest=0; // keep track of long subArray
//         int left=0;  // left bound of sub array
//         int right=0; // right bound of sub arr
        
//         for (int i=0; i<nums.size(); i++) {
//             if (nums[i]==0) nums[i]=-1;
//             printf("%d ", nums[i]);
//         }
        
        
//         for (left=0; left<nums.size(); left++){
//             int arrLen = 0;
//             int partialSum = 0;
//             for (right = left; right<nums.size(); right++) {
//                 partialSum += nums[right];
//                 if (partialSum==0) {
//                     arrLen = right - left + 1;
//                     if (arrLen>longest) longest = arrLen;
//                 }
//             }
            
//         }
//         return longest;
//     }
// };

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        int maxLen = 0;
        vector<int> countIndex (2*nums.size()+1, -2);
        countIndex[nums.size()] = -1;
        
        // iterate the nums vector
        for (int i=0; i<nums.size(); i++) {
            count = count + (nums[i]==0? -1:1);
            if (countIndex[count+nums.size()] >= -1) {
                maxLen = max(maxLen, i- countIndex[count+nums.size()]);
            }
            else{
                countIndex[count+nums.size()] = i;
            }
        }
        return maxLen;
    }
};
/*  This is an add_two_number_question  */

/* This is the first version */
#include <vector>
#include <map>
//#include <hash_map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1, index2, difference;
        vector<int> result;
        for (index1=0; index1<nums.size()-1; index1++) {
            difference = target - nums[index1];
            for (index2 = index1+1; index2<nums.size(); index2++) {
                if (nums[index2] == difference) {
                    result.push_back(index1); result.push_back(index2);
                    return result;
                }
            }
            
        }
        return result;
    }
};


/*  The brutal force approach */
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target)   {
        vector<int> result;
        for (int i=0; i<nums.size()-1; i++)   {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] == target - nums[j])   {
                    result.push_back(i); result.push_back(j);
                    return result;
                }
            }
        }
    return result;
    }
};



/* The Two-way hash table */
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target)   {
        vector<int> result;
        unordered_map<int,int> container;
        
        for (int i=0; i<nums.size(); i++)   {
            container.insert(pair<int, int>(nums[i],i));
            //container.insert({nums[i],i});   
        }

        for (int j=0; j<nums.size(); j++)   {
            int difference = target - nums[j];
            if ((container.find(difference) != container.end()) && (container.find(difference)->second != j))   {
                result.push_back(j); result.push_back(container.find(difference)->second);
                return result;
            }
        }
    return result;
    }
};


/* The One-way hash table */
class Solution4 {
public:
    vector<int> twoSum(vector<int>& nums, int target)   {
        vector<int> result;
        unordered_map<int,int> container;
    
        for (int j=0; j<nums.size(); j++)   {
            container.insert(pair<int, int>(nums[j],j));
            int difference = target - nums[j];
            if ((container.find(difference) != container.end()) && (container.find(difference)->second != j))   {
                result.push_back(j); result.push_back(container.find(difference)->second);
                return result;
            }
        }
    return result;
    }
};
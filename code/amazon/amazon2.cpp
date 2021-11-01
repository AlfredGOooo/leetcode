#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'evenSubarray' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY numbers
 *  2. INTEGER k
 */

// int evenSubarray(vector<int> numbers, int k) {
//     for (int k=0;k<numbers.size();k++) {
//     printf("%d ", numbers[k]);
//     }
//     set<vector<int>> exist;
//     int sum = 0;
//     for (int i=0; i<numbers.size(); i++) {
//         int local_cnt = 0;
//         int odd = 0;
//         vector<int> good;
//         for (int j=i; j<numbers.size();j++){
//             if (numbers[j]%2==0) {
//                 good.push_back(numbers[j]);
//                 if (exist.find(good) == exist.cend()) {
//                     local_cnt++;
//                     exist.insert(good);
//                 }
//             }
//             else {
//                 odd++;
//                 if (odd>k) break;
//                 good.push_back(numbers[j]);
//                 if (exist.find(good) == exist.cend()){
//                     local_cnt++;
//                     exist.insert(good);
//                 }
//             }
//         }
//         sum+=local_cnt;
//     }
//     return sum;
// }

class Trie {
public:
    Trie(int val) {
        this->val = val;
    }
    void addNext(int num, Trie* nextTrie) {
        nextNums[num] = nextTrie;
    }
    
    Trie* getNumTrie(int num) {
        if (nextNums.count(num) == 0) return NULL;
        return nextNums[num];
    }
    
private:
    int val;
    unordered_map<int, Trie*> nextNums;
};

int evenSubarray(vector<int> numbers, int k) {
    int left = 0;
    int right, countOdd;
    int n = numbers.size();
    
    Trie* sentinel = new Trie(-1);
    vector<vector<int>> res;
    
    while (left < n) {
        right = left;
        countOdd = 0;
        vector<int> curNumList;
        Trie* prevTrie = sentinel;
        while (countOdd <= k && right < n) {
            int curNum = numbers[right];
            if (curNum % 2 == 1) countOdd++;
            if (countOdd > k) break;
            curNumList.push_back(curNum);
            if (prevTrie->getNumTrie(curNum) == NULL) {
                Trie* newTrie = new Trie(curNum);
                prevTrie->addNext(curNum, newTrie);
                res.push_back(curNumList);
            }
            prevTrie = prevTrie->getNumTrie(curNum);
            right++;
        }
        left++;
    }
    return res.size();
}

int main()
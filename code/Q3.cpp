/*

Find the Longest Substring w/o repeating characters
find out the length, only.
分析：因为是not repeating，所以应该用Set，而不是map
*/


// string 和 char 怎么转换？ https://www.cnblogs.com/wuruofeng/p/10412559.html
// string 的成员函数有哪些？
// string 询问长度的方法是 .length() member function
// c_string  询问长度的方法是 strlen(string)
// map 放物品进去的函数是 strBox.insert(pair<string,int>(s.substr(j,1),j));

/*
s.substr()
Parameters
pos	-	position of the first character to include
count	-	length of the substring
Return value
String containing the substring [pos, pos+count).
*/


#include <map>
#include <string>			/* This is my first attempt */
using namespace std;		/* This solution exceeded time limit */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<string,int> strBox;
        int longestLen=0, subLen=0;
        if (s.length()==0) return 0;
        if (s.length()==1) return 1;
        for (int i=0; i<s.length()-1; i++)  {
            if (longestLen>=s.length()-i)   return longestLen;
            for (int j=i; j<s.length(); j++)    {
                if (strBox.find(s.substr(j,1))==strBox.end()) {
                    strBox.insert(pair<string,int>(s.substr(j,1),j));
                    subLen+=1;
                    longestLen = (longestLen>subLen) ? longestLen : subLen;
                }else {
                    subLen=0;
                    strBox.clear();
                    break;
                }      
            }
        }
        return longestLen;
    }
};


/* 答案 */
// 方法一: 暴力搜索
/* Intuition: Check all the substring one by one to see if it has no duplicate character.
Java: String 转 char Character ch = s.charAt(i);

// 方法二: 滑动窗口
A sliding window is an abstract concept commonly used in array/string problems.
A window is a range of elements in the array/string 
which usually defined by the start and end indices, i.e. [i, j)[i,j) (left-closed, right-open).








*/







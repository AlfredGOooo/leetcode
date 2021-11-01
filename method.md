# LeetCode Habits

- 按照Tag刷，同时用不同颜色标记做过和没有做过的题目
  - 红蓝绿：表示有做过，难度已被标记
  - 无色：还没有做过
- 做题速度
  - 一般做的出来不限制时间
  - 做不出来，限制10-15min后看答案
  - 看懂至少一个有效答案，记忆思路方法，然后不要看答案，按照自己的记忆和思路重新写一遍
  - 如果不止brutal force 解法，了解多个Ans来补充知识面
  - 总结code
    - 不同解法的代码 + 代码注释放在code.c, 当时为什么要这样做，答案为什么这样写
    - 解题思路放在md上（？）

```c++
%% 注释样例
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int dist = INT_MAX;
        int pos1 = -1;
        int pos2 = -1;
        
        bool same = word1 == word2;
        
        //basic idea is identical with problem 243
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                pos1 = i;
                if (pos2 >= 0) dist = min(dist, pos1 - pos2);
                //a bit change is at here: if word1 and word2
                //are same words, every time we met word it will
                //only go into this loop, so after we calculate
                //distance, we put the value of pos1 to pos2, 
                //pos2 always represent the position of word1/word2
                //we met last time
                if (same) {
                    swap(pos1, pos2);
                }
            }
            else if (words[i] == word2) {
                pos2 = i;
                if (pos1 >= 0) dist = min(dist, pos2 - pos1);
            }
        }
        
        return dist;
    }
};
```
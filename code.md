# LeetCode Review

C++ function API参考网站，查STL API和库函数： https://en.cppreference.com/w/

国际版: https://leetcode.com/ ；中文版：https://leetcode-cn.com/



**做题方法论：**

1. 思考。想不明白的时候在纸上写写画画，帮助思考。特别是图论的题目，拿最简单的test case画出来就能帮助思考，效果拔群。在草稿上想好为代码怎么写再下笔。思考好架构，再实现。

2. 手机倒计时。时间：10～20分钟。20分钟足够把解题相关的知识和技巧拿出来枚举一遍了。想不到方法多半因为有的知识你还不知道。快去看答案吧。



**做题顺序：**

第一遍，按照题号做。easy >> medium >> hard ， 题目编号前300题。

easy：熟悉cpp语法以及STL的用法

medium：重温基础的数据结构和算法，重点总结各种常见数据结构和算法

hard： 去discuss上学习大神的解法思路，自己写一遍提交。其他看discuss的情况：自己写的代码很繁杂，逻辑不清晰，自己理不顺；题目tag里面提示有别的解法的时候；想了半个小时无思路的时候。



第二遍，按照tag做。

按照题号做完一遍之后，按照tag刷第二遍，总结同类题型的套路。发现共性，总结套路和模版，然后才能斩瓜切菜。目标效果：

- 思路和代码要变得简洁。大部分题目代码量控制在50行以内。
- bug free 快速写出常用代码块(union find, dfs/bfs 几个变种，binary search，partition)。熟练掌握的模版和套路，就可以bug free解决medium的题目。
- 掌握各种数据结构的时空复杂度，实现的难易程度。选用更加简单的数据结构，运行时间更快。时间复杂度相同时，可以选更简单的数据结构，化繁为简。用vector，不用 unordered_map



评价：见多识广也是能力，熟练套路不等于生搬硬套。快速识别出题目套路并且解决已经是非常优秀，活用知识，甚至发明算法则需要更深入的理解。

LeetCode的OJ也可以试一试。



### Q1 - Add two sums

*First submission/brutal force:*

![sub1](/Users/zhangweilin/Desktop/CS知识总结/LeetCode/photos/Q1_1.png)

- 知识点

1. `std::vector` 的 public member function 有哪些，该怎么用？

![sub2](/Users/zhangweilin/Desktop/CS知识总结/LeetCode/photos/Q1_2.png)

***

size: 目前已经加进去的元素的数量

capacity：`vector`的大小是动态分配的，因此大小延展到一定程度就会自动扩展占据的内存大小。就像一个地产项目不断增加楼盘之前，首先要开辟出更大的建筑面积。capacity就是所谓的“更大的建筑面积”，即这个object所占据的内存。

***

clear：AOE，把`vector`里的东西像垃圾一样全部丢掉。

erase：定点清除，把你不想要的具体数字；不想要的索引范围；通通干掉

***

push_back: 把新的元素放在`vector`的最后一个位置

insert：定点插入到vector的开头、末尾、或者中间某个位置；可以定点插入另一个array！

***

resize：改变`vector`的size。如果缩短了，砍掉多余的元素；如果变长了，增加default数字

swap：Exchanges the contents of the container with those of other。就vector1 和 vector2内容互换

***



2. `std::unordered_map/hash_map` 怎么用？

![sub3](/Users/zhangweilin/Desktop/CS知识总结/LeetCode/photos/Q1_3.png)

- 知识点

`unordered map` 的成员函数该怎么用？`unordered map` 是通过`hash_table`来实现的。

![sub3](/Users/zhangweilin/Desktop/CS知识总结/LeetCode/photos/Q1_4.png)

***

- Insert的**2种**用法：

```c++
container.insert(pair<int, int>(nums[i],i));
//container.insert({nums[i],i});  
```

具体的还有更多种用法。

***

- map.find(key) 返回的是什么值?

iterator。一般用map.begin() 和 map.end() 去接这个函数。如果想要测试map.find(key)是否存在，看它是否等于 map.end()。map.end() 这个iterator处于最后一个元素的后一位。

一般如果要取key对应的value，有两种方法：

```C++
map<int,int>::iterator iter; iter = container.find(difference); int a = iter->second;
int a = container.find(difference)->second;
```

就可以顺利取出value的值了。

***



### 总结

- 第一种解法：暴力搜索。挑出每个元素*i*，依次遍历剩下的元素以寻找配对。已经被pick过的元素*i*，在接下来其余的搜索中不会再出现。时间复杂度：O($$n^2 $$), 空间复杂度O(1).算法稳定、常用、直接，但是不够聪明。
- 第二种解法：遍历2次哈希表。把元素从`vector`中一个个放进哈希表中，先**全部**放进去。放进去以后，利用哈希表O(1)的查找来寻找差值。全部放进`Hash_Table` 需要O(n), n次哈希表查找需要O(n)。具体实现是利用`unordered_map`：它是用`hashtable`实现的。`map`的数据结构为<key,value>，因此把元素的(index,
  element) 以 (value, key)放进去，即以element为key，我们的value是index(题目要求返回2个数的index)。利用`unordered_map`近似于O(1)的查找，实现O(n). 总和：O(n)，O(n) = O(2n) = O(n)
- 第三种解法：遍历一次哈希表。放一个元素进`hash`的时候，同时查找表，如果已经发现互补，直接return。如果没有发现互补，继续放元素。放元素需要O(n), 查找n次O(1) 需要O(n), 共需要 O(2n)次。第三种解法跟第二种时间空间复杂度差不多，只是第三种写法更为简洁一些。

Q：如果不用`hash_map`, `vector`的元素放到另一个`vector`里，可以达到时空复杂度的降低吗？

A：**不可以，放入第n个元素需要O(1), 同时需要n-1次顺序查找。放入：O(n)；查找：1 + 2 + .. + n-1 = O($n^{2}$)。跟暴力搜索没有差别。**


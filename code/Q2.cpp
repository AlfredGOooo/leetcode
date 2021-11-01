/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// How to construct a data-structure with struct?
// first, think of instance variable you need.
// second, how many ways of construction/destructor? (How many constructors?)
// third, what are your member functions?

// Think of the boundary conditions!!

// boundary cond1: no more digits in one list
// cond2: overflow bit
// construct a new list -- what is the lengh?
// how to store the intermediate result?

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=0, len2=0, length=0, partialSum=0, iterator=0, overflow=0;
        ListNode* longerListNode;
        // do length check;
        do {len1++;} while (l1->next != nullptr);
        do {len2++;} while (l2->next != nullptr);
        length = (len1>=len2) ? len1+1:len2+1;
        
        ListNode result[length];
        do {
            partialSum = l1->val + l2->val + overflow;
            // next I have to check any overflow
            result[iterator].val=(partialSum>10) ? partialSum-10 : partialSum;
            overflow = (partialSum>10) ? 1:0;
            l1 = l1->next; l2 = l2->next;
            result[iterator].next = &result[iterator+1];
            partialSum = 0;
            iterator++;
        } while ((l1->next!=nullptr) && (l2->next!=nullptr));
        longerListNode = (len1>=len2) ? l1:l2;
        for (iterator = iterator; iterator<length-1; iterator++)  {
            partialSum = longerListNode->val + overflow;
            result[iterator].val = (partialSum>10) ? partialSum-10:partialSum;
            overflow = (partialSum>10) ? 1:0;
            longerListNode = longerListNode->next;
            result[iterator].next = &result[iterator+1];
            partialSum=0;
        }
        if (overflow) result[iterator].val = 1;
        else    result[iterator-1].next = nullptr;
        return &result[0];
    }
};


/*
 1. 不知道new 怎么用, OMG
 2. 不知道Constructor 有啥用, 晕倒
 3. (打破思维定势!)没想到node1 和 node2两个东西可以同时进行!! 完全没必要两个同时loop下去, 只要有一个遇到了null, 就让它停下来, 让另一个loop
 4. 为什么要建一个list? 每loop一次能创建一个node, 然后指向下一个node, 那就完全没必要提前建好所有的node。
 5. 单链表的创建方法、使用方法的熟悉度有待提高
 6. 对指针和它的实体一点也不熟悉
 7. do-while 和 问号比较 不够熟悉
 */

/*
 1. 指针变量 contains 地址
 2. 物体变量 contains 那个 type 的 value
 3. 当两个物体变量互相赋值的时候, 根本的含义是：它们的存储的type value是一样的。
 4. 当两个指针指向同一个物体时(p1 = p2), 根本的含义是: 两个指针存的地址值是一样的。
 5. 当两个指针指向同一个物体时(p1 = p2), p1改变所指向的物体的值，p2所指向的物体的值同样会改变: 
 指针 startNode = 指针 currNode; currNode->next=b; 那么 startNode->next 也会等于b。
 原因：因为这个是引用，call by pointer. 
 6. 当指针被赋予了新的变量的时候, 例如 (p2 = p3), 它的真正意义: p2 和 p3指向同一个物体, p1和p2不再指向同一个物体了.
 p2 和 p3 现在存储着同一个address, p1 和 p2过去存储同一个address 但现在不是同一个了。
 7. Java 和 python的Class 都需要用Object的视角来看待。即当 Class Object a = Class Object b的时候,
 它们指的是同一个物体, a改变instance variable, 会导致b的instance variable同时改变, 因为refer to same object.
 对于Java Pyhon来说，Class Object 的赋值是 referential pointing。这也就是为什么, 链表的curr = head (head 赋值给curr时),
 我们改变了 curr的instance variable, 会导致head的instance variable也改变。
 8. 但是, 如果java 和 python的class object 被赋值了新的物体, 比如 curr = curr.next, 那么curr就再也不是head了
 也就是说, 当Class Object curr 被赋予了新的值的时候, curr ≠ head, 因此instance variable 也就不一样了.
 9. 从这里我们可以看见C++ 和 Java/Python的联系: C++要让变量a和b指向同一个物体的话, 应该要用指针, 因为指针指向物体地址(该物体独一无二的标识)
C++的指针 和 Java和Python的Object 有异曲同工之妙, 都是直接引用(refer to)这个物体本身。
C++的变量赋值 跟 Java/Python的Object 赋值不在同一个层次上, C++变量赋值, 只是pass by value, 不是pass by reference. 它们是两个Object, 不同address
甚至struct/Class 里需要重载 = operator才能定义 “等号” 是干什么的
10. 在C++里, 关注一个变量, 要关注它4个点: 变量名,变量类型(普通变量还是pointer variable?), 变量值, 和变量地址。
例如pointer: 变量名, type pointer(比如是整数型变量), 变量值=address, 变量地址通常不用关心, 除非有指向指针的指针。
11. 当要构建while 循环对数据进行操作的时候, 需要一个代理人。不可能将header或者第一个node/char 丢进去做循环的。这个代理人还需要能够修改header/node,
因此这种事情必须要用指针来做,或者有Object 是referential类型的来做。
12. shallow copy就是两个变量指向同一个object. 当一个变量改变了object的行为的时候, 另一个变量的行为也作出了相应的变化。
deep copy是堆上重新开辟一个空间，复制原有的attribute, 最终变成两个不同的物体, 指针地址不一样的。

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int overflow=0, partialSum, val1, val2;
    	ListNode* startNode = new ListNode(0);
    	ListNode* currNode = startNode;

    	while ((l1!=nullptr) || (l2!=nullptr))	{
    		val1 = (l1==nullptr) ? 0 : l1->val;
    		val2 = (l2==nullptr) ? 0 : l2->val;
    		partialSum = overflow+val1+val2;
    		overflow = partialSum/10;
    		partialSum = (overflow>=1) ? partialSum-10 : partialSum;  // partialSum = partialSum%10
    		ListNode* nextNode = new ListNode(partialSum);
    		currNode->next = nextNode;
    		currNode = nextNode;
    		if (l1!=nullptr) l1=l1->next;
    		if (l2!=nullptr) l2=l2->next;
    	}
    	if (overflow)  {
    		ListNode* nextNode = new ListNode(1);
    		currNode->next = nextNode;
    	}	
        return startNode->next;
    }
};

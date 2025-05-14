//Date: 14-05-2025
//Problem: https://leetcode.com/problems/middle-of-the-linked-list
//Final submission : https://leetcode.com/problems/middle-of-the-linked-list/submissions/1633830209
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Approach1
//Iterate throught the list and find the number of nodes, go to the middle node and return it
//Time complexity - O(n), Space complexity - O(1)
class Solution1 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;

        int count = 0;
        while(current){
            count++;
            current = current->next;
        }

        int middle = count/2+1;

        current = head;
        count = 1;

        while(middle!=1) {
            current = current->next;
            middle--;
        }
        return current;
    }
};

//Approach2 (from solution)
//Two pointers, fast and slow, fast moves two nodes at a time and slow moves one node at a time. By the time fast reaches the end of the list, slow reaches the middle.
//Time complexity - O(n), Space complexity - O(1)
class Solution2 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
};
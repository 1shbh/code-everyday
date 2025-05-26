//Date: 26-05-2025
//Problem: https://leetcode.com/problems/swap-nodes-in-pairs
//Final submission: https://leetcode.com/problems/swap-nodes-in-pairs/submissions/1645187851

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Approach 1: Move two nodes at a time and swap adjacent nodes. (SWAPS VALUES AND NOT NODES)
//Time complexity - O(n), space complexity - O(1)
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        int temp;

        while(curr && curr->next){
            temp = curr->val;
            curr->val = curr->next->val;
            curr->next->val = temp;

            curr = curr->next->next;            
        }
        return head;
        
    }
};

//Approach 2: Swap actual nodes and not values
//Time complexity - O(n), space complexity - O(1)
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        return dummy.next;
    }
};


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
//Go upto the middle of the linkd list (n/2) and push all node values to a vector. Now iterate through the list from the back and add rest of the node values to effectively calculate sum of twin nodes. Finally get the max sum from the vector.
//Time complexity - O(n), Space complexity - O(n)
class Solution1 {
public:
    int pairSum(ListNode* head) {

        ListNode* current = head;
        int count = 0;

        while(current) {
            count++;
            current = current->next;
        }

        int counter = 0;
        current = head;

        vector<int> sum;

        while (counter < count/2) {
            sum.push_back(current->val);
            current = current->next;
            counter++;
        }

        for (auto it = sum.rbegin(); it!=sum.rend(); ++it) {
            (*it)+=current->val;
            current = current->next;
        }

        int maxval = sum[0];
        for (int i = 0; i < sum.size(); ++i) {
            if (sum[i] > maxval)
                maxval = sum[i];
        }
        return maxval;
        
    }
};

//Approach2
//Reverse the second half of the list in place and then simultaneously iterate through the both lists and find max.
//Time complexity - O(n), Space complexity - O(1)
class Solution2 {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* first = head;
        ListNode* second = prev;

        int maxSum = 0;
        while (second) {
            maxSum = max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }
        return maxSum;
    }
};
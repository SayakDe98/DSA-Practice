//Problem statement:
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
 

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

//How to approach this problem:
//We have two nodes which are in reverse order. We need to add them and show the answer.
//Let's think assuming we the nodes aren't in reverse order.
//We will add the two nodes current index but the value at that node will be value % 10 because if we can have only have a single digit per node.
//We will have a carry variable which adds with the next index. carry = index / 10
//We will create a l3 node which will store the value. We will have null checks for l1 and l2.
//There is an edge case where we can have a carry for the last node then we need to check if carry exists at the end of execution of loop, if yes we will add it to l3 next by doing: l3 -> next = new ListNode(carry)

//Solution:
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * l3 = new ListNode(0); //initialzing list node with 0
        ListNode * head = l3;
        int carry = 0;

        while(l1 && l2) {
                int value = l1 -> val + l2 -> val + carry;
                carry = value / 10;
                l3 -> next = new ListNode(value % 10);
                l3 = l3 -> next;
                l1 = l1 -> next;
                l2 = l2-> next;
        }
        
        while(l1) {
                int value = l1 -> val + carry;
                carry = value / 10;
                l3 -> next = new ListNode(value % 10);
                l3 = l3 -> next;
                l2 = l2-> next;
        }
        
        while(l2) {
                int value = l2 -> val + carry;
                carry = value / 10;
                l3 -> next = new ListNode(value % 10);
                l3 = l3 -> next;
                l2 = l2-> next;
        }

        if(carry) //if carry still exists
            l3 -> next = new ListNode(carry);
        
        return head -> next;
    }
};
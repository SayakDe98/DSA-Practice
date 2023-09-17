// 141. Linked List Cycle
//     Easy

//     14137

//     1158

//     Add to List

//         Share
//             Given head,
//     the head of a linked list, determine if the linked list has a cycle in it.

//                                There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.Internally,
//     pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

//     Return true if there is a cycle in the linked list.Otherwise,
//     return false.

//            Example 1 :

//     Input : head = [ 3, 2, 0, -4 ],
//             pos = 1 Output : true Explanation : There is a cycle in the linked list, where the tail connects to the 1st node(0 - indexed).Example 2 :

//     Input : head = [ 1, 2 ],
//             pos = 0 Output : true Explanation : There is a cycle in the linked list, where the tail connects to the 0th node.Example 3 :

//     Input : head = [1],
//             pos = -1 Output : false Explanation : There is no cycle in the linked list.

//                                                   Constraints :

//     The number of the nodes in the list is in the range[0, 104]
//         .- 105 <= Node.val
//                       <= 105 pos is - 1 or
//                   a valid index in the linked - list.
#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        unordered_set<ListNode *> hashset;
        while (head != nullptr)
        {
            if (hashset.find(head) != hashset.end())
            {
                return true;
            }
            hashset.insert(head);
            if (head->next == NULL)
            {
                return false;
            }
            head = head->next;
        }
        return false;
    }
};

int main () {
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(1);
    l1->next = l2;
    l2 -> next = l3;
    l3 -> next = l1;// this creates a cycle 
    cout << s.hasCycle(l1);
    delete l1;
    delete l2;
    delete l3;
    return 0;
}
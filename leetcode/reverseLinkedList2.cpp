// 92. Reverse Linked List II
//         Medium

//     10780

//     496

//     Add to List

//         Share
//             Given the head of a singly linked list and two integers left and right where left <= right,
//     reverse the nodes of the list from position left to position right, and return the reversed list.

//                                                                         Example 1 :

//     Input : head = [ 1, 2, 3, 4, 5 ],
//             left = 2, right = 4 Output : [ 1, 4, 3, 2, 5 ] Example 2 :

//     Input : head = [5],
//             left = 1, right = 1 Output : [5]

//                                          Constraints :

//     The number of nodes in the list is n.1 <= n <= 500 - 500 <=
//                               Node.val <= 500 1 <= left <= right <= n
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        for (int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
        }

        ListNode *curr = prev->next;
        for (int i = 0; i < right - left; i++)
        {
            ListNode *forw = curr->next;
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dummy->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode *reversedList = s.reverseBetween(l1, 2, 4);

    while (reversedList != nullptr)
    {
        cout << reversedList->val << endl;
        reversedList = reversedList->next;
    }

    // Free the memory
    while (l1 != nullptr)
    {
        ListNode *temp = l1;
        l1 = l1->next;
        delete temp;
    }

    return 0;
}

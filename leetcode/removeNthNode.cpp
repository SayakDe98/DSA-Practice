// Remove Nth Node From End of List
//     Medium 15.6K 656 Companies
//         Given the head of a linked list,
//     remove the nth node from the end of the list and return its head.

//     Example 1 :

//     Input : head = [ 1, 2, 3, 4, 5 ],
//             n = 2 Output : [ 1, 2, 3, 5 ] Example 2 :

//     Input : head = [1],
//             n = 1 Output : [] Example 3 :

//     Input : head = [ 1, 2 ],
//             n = 1 Output : [1]

//                            Constraints :

//     The number of nodes in the list is sz. 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
#include <bits/stdc++.h>
using namespace std;

*struct ListNode
{
    *int val;
    *ListNode *next;
    *ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next){}
                                                                                                                                      *
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
        {
            return head;
        }

        int count = 0;
        ListNode *ptr = head;

        while (ptr)
        {
            count++;
            ptr = ptr->next;
        }

        if (count == n)
        {
            head = head->next;
            return head;
        }

        ptr = head;
        n = count - n - 1;
        count = 0;

        while (ptr)
        {
            if (count == n)
            {
                ptr->next = ptr->next->next;
                return head;
            }

            ptr = ptr->next;
            count++;
        }
        return head;
    }
};

int main()
{
    Solution s;
    s.removeNthFromEnd();
    return 0;
}
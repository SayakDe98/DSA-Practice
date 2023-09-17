// For this question : Rotate List

//                         Given the head of a linked list,
//                     rotate the list to the right by k places.

//                     Example 1 : Input : head = [ 1, 2, 3, 4, 5 ],
//                                         k = 2 Output : [ 4, 5, 1, 2, 3 ] Example 2 :

//     Input : head = [ 0, 1, 2 ],
//                                         k = 4 Output : [ 2, 0, 1 ]

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head or k == 0)
        {
            return head;
        }

        // calculate length of linked list
        int n = 0;
        ListNode *curr = head;
        while (curr)
        {
            n++;
            curr = curr->next;
        }
        // check the value of k after rotation
        k %= n;

        if (k == 0)
        { // if updated k == 0 return head
            return head;
        }

        // move the fast pointer k steps ahead
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < k; i++)
        {
            fast = fast->next;
        }

        // move both pointers till fast -> next != nullptr
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // adjust rotation
        ListNode *newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};
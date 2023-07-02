// You are given an array of k linked - lists lists, each linked - list is sorted in ascending order.

//                                                                 Merge all the linked -
//                                                       lists into one sorted linked - list and return it.

//                                                                                      Example 1 :

//     Input : lists = [ [ 1, 4, 5 ], [ 1, 3, 4 ], [ 2, 6 ] ] Output : [ 1, 1, 2, 3, 4, 4, 5, 6 ] Explanation : The linked - lists are : [
//     1->4->5,
//     1->3->4,
//     2->6
// ] merging them into one sorted list : 1->1->2->3->4->4->5->6 Example 2 :

//     Input : lists = [] Output : [] Example 3 :

//     Input : lists = [[]] Output : []

//                                   Constraints :

//     k == lists.length 0 <= k <= 10^4, 0 <= lists[i].length <= 500, - 10^4 <= lists[i][j] <= 10^4 lists[i] is sorted in ascending order.The sum of lists[i].length will not exceed 10^4.

// Intuition:
// The problem can be solved by merging two sorted linked lists at a time. If we have K linked lists, we can merge the first and second linked lists, then merge the result with the third linked list, and so on. This process will result in a single sorted linked list containing all elements.

// Approach:
// Define a function mergeTwoLists that takes two sorted linked lists as input and merges them into a single sorted linked list using a recursive approach.
// In the mergeKLists function, initialize a pointer ans to NULL.
// Iterate over the input vector lists, and at each iteration, merge ans with the current linked list using the mergeTwoLists function.
// Return ans.
// Complexity:
// Time complexity:
// The time complexity of this solution is O(N log k), where N is the total number of elements in all linked lists, and k is the number of linked lists. The reason for this complexity is that we are merging two lists at a time, and the number of merged lists is reduced by a factor of 2 at each iteration. Thus, the total number of iterations is log k. In each iteration, we perform N comparisons and updates, so the total time complexity is O(N log k).

// Space Complexity:
// The space complexity of this solution is O(1) since we are not using any additional data structures. The only extra space used is the recursion stack space, which is O(log k) for the recursive approach used in mergeTwoLists.

#include<vector>
#include<iostream>
using namespace std;
//   Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class Solution
  {
  public:
      ListNode *mergeTwoLists(ListNode *&list1, ListNode *&list2)
      {
          ListNode *ptr1 = list1;
          ListNode *ptr2 = list2;

          if (list1 == NULL)
          {
              return ptr2;
          }

          if (list2 == NULL)
          {
              return ptr1;
          }

          if (ptr1->val < ptr2->val)
          {
              ptr1->next = mergeTwoLists(ptr1->next, ptr2);
              return list1;
          }
          else
          {
              ptr2->next = mergeTwoLists(ptr1, ptr2->next);
              return list2;
          }
      }

      ListNode *mergeKLists(vector<ListNode *> &lists)
      {
          ListNode *ans;
          int count = 0;

          while (count < lists.size())
          {
              ans = mergeTwoLists(ans, lists[count]);
              count++;
          }

          return ans;
      }
  };

int main () {
    Solution s;
    // s.mergeLists();
    return 0;
}
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

bool isPossibleToAllocate(vector<int> books, int students, int barrier) {
    int pagesAllocated = 0;//initally pagesAllocated to student = 0
    int studentAllocated = 1;//initally we find out books for 1 student till pages reach barrier    

    for (size_t i = 0; i < books.size(); i++)//we will run a loop to check all elements in vector
    {
        /* code */
        if(books[i] > barrier) {//if barrier is lesser than any one of the individual element then that is invalid barrier
            return false;
        } 
        if(books[i] + pagesAllocated > barrier) {//if pagesAllocated + current book is more than barrier
            studentAllocated++;//we increase student
            pagesAllocated = books[i];//we keep pagesAllocated to new student to books[i]
        } else {
            pagesAllocated += books[i];//we add pages of current book to current student since it is less than barrier
        }
    }
    if(studentAllocated > students) {
        return false;//if students needed to allocate the books and its pages exceeds total students return false
    } else {//otherwise return true 
        return true;
    }
}

int minPages(vector<int> books, int m) {
    //initially let's keep start = end = 0
    int start = 0;
    int end = 0;

    //then we make a search space where start = 0, end = sum of all elements
    for(size_t i = 0; i < books.size(); i++) {
        end += books[i];
        // start = max(books[i], start);
    }
    int res = INT_MAX;//initializing answer = -1
    //then we run binary search in this search space then modify the search space
    while (start <= end)//binary search condition of start <= end
    {
        /* code */
        int mid = (start + end) / 2;//binary search logic of mid = (start + end) / 2
        
        //then we reduce the search space
        if(isPossibleToAllocate(books, m, mid)){
            // res = min(mid, res);
            res = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return res;
}

int main() {
    vector<int> books{10, 20, 30, 15};
    int students = 2;
    cout << minPages(books, students) << endl;
    return 0;
}
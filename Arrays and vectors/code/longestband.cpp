//Given an array containing N integers , find length of longest band.
//A band is defined as a subsequence which can be reordered in such a manner all elements appear 
//consecutive(i.e. with absolute difference of 1 between neighbouring elements)
//A longest band is the band(subsequence) which contains maximum integers.

//Input:
//[1,9,3,0,18,5,2,4,10,7,12,6]

//Output: 8

//Explanation:
//Largest subset containg consectuive numbers is {0,1,2,3,4,5,6,7}

//Approach 1
//Sort in nlogn time
//we then iterate over elements if we can't find an element with diff of +/- 1 then we stop current band and start new band from next element
//T.C. : O(nlogn + n)

//Approach 2
//check if the first element is that staarting of the band.
//assume the first ele is 1 then check if there is a 0 then if 0 present check if -1 is present and so on...
//once we find start element we can generate entire chain.
//we need a lookup whether a given element is present in the array or not.
//the best data structure for lookup is unordered_set

//In this array we check if 1 can be start but no because 0 is present,
//we move to 9 and see there is NO 8 hence it is start of band.
//we will look for 10,we get 10, wecreate band of 9 and 10
//we check for 11 but it is absent , hence our band length is 2
//although we have used value 10 we haven't scanned index of 10
//when we go to 10 then we will see 10 has a parent which is 9 hence we will ignore this
//now we go to 3 , number before 2 is present so it can't be starting point
//we go to 0 and it is starting point because -1 ain't present
//we will look for 1 we get 1 we make a band
//we look for 2 we get 2 we add to band
//we keep going till 7 , 8 is not there
//hence we get band of length 8 .we can keep checking or we can see that the length of band is more than half so it is the largest band.

//T.C. Iterating over array is O(n) and Forming the chains take O(n) time.
//Total T.c. is O(n)

//for most elements which dont have chain we are doing 1 operation for rest lets suppose we have an element which forms band of x hence there will be x operations
//hence total operations = 1+x+...

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestChain(vector<int> &arr)
{
    int n = arr.size();

    unordered_set<int> s;
    for(int i : arr)
    {
        s.insert(i);
    }

    int largestChain = 1;
    
    for(auto element : s)//this loop runs for all elements
    {
        int parent = element - 1;

        if(s.find(parent) == s.end())//means we didn't get the parent since we reached end of iterator trying to find the parent element
        {
            int next_no = element + 1;

            int count = 1;

            while(s.find(next_no)!=s.end() && (n/2) > largestChain)//this loop runs for some of the elements
            {
                count++;

                next_no++;
            }

            if(count > largestChain)
                largestChain = count;
        }
    }    

    return largestChain;
}

int main()
{
    vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<longestChain(arr);

    return 0;
}
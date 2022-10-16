// Array Products
// Implement a function that takes in a vector of integers, and returns a vector of the same length, where each element in the output array is equal to the product of every other number in the input array. Solve this problem without using division.

// In other words, the value at output[i] is equal to the product of every number in the input array other than input[i]. You can assume that answer can be stored inside int datatype and no-overflow will occur due to products.

// Sample Input

// Both inputs and outputs are vectors.

// {1,2,3,4,5}
// Sample Output

// {120, 60, 40, 30, 24}
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//Expected Complexity O(N)
//My Approach
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //update the output array and return
    //complete the code

    int pdt = 1;

    for(int i = 0; i < n; i++){
        pdt *= arr[i];
    }

    for(int i = 0; i < n; i++){
        output[i] = pdt / arr[i];
    }
    
    return output;
}

//leetcode approach 1:divide by self, they considered multiple 0's, single 0's also
// ✔️ Solution - I (Calculate product & divide by self)

// We can simply calculate product of the whole array and for each element in nums, divide the product by nums[i]. This effectively leaves us with product of whole array except self at each index. We need to take care of zeros that may occur in the array -

// 1. If there are more than one 0s in nums, the result is an array consisting of all 0.
// 2. If there is a single 0 in nums, then the result is an array consisting of all 0 except at the index where there was 0 in nums, which will contain product of rest of array.
// 3. If there's no 0 in nums, then the result is an array ans where ans[i] = prod / nums[i] (prod = product of all elements in nums).
//TC:O(n),SC:O(1)
vector <int> productArray1(vector<int> &nums){
    int pdt = 1;
    int zeroCnt = count(begin(nums),end(nums),0);//counts the number of zeroes in vector

    if(zeroCnt > 1){
        return vector <int>(size(nums));//returns a vector with only 0's of size nums vector
    }

    //below this only vectors with one or none zeroes are present
    for(auto c: nums){
        if(c) pdt *= c;//finds the product of all the elements except self 
    }

    for(auto& c:nums){
        if(zeroCnt){//if zeroCnt = 1
            c = c? 0 : pdt;
        } else{
            c = pdt / c;
        }
    }
    return nums;
}

//leetcode approach 2
// ✔️ Solution - II (Prefix & Suffix Products)
// We are required to solve this problem without using the division operator. We can do this by calculating two arrays pre and suf where pre[i] contains product of all nums[j] such that j <= i, and suf[i] contains product of all nums[j] such that j >= i.
// Finally, the resulting array ans can be calculated as ans[i] = pre[i-1] * suf[i+1] which is product of all elements with index less than i multiplied by product of all elements with index greater than i. This is essentially equal to product of array except self at each index.
//Time Complexity : O(N), calculating pre and suf arrays takes O(N) time and then another O(N) to compute ans. Total complexity comes out to be O(3*N) = O(N).
// Space Complexity : O(N), required to store pre and suf arrays
#include<numeric>//for multiples<int>() it is Function object for performing multiplication.
vector <int> productArray2(vector <int> &nums){
    vector <int> pre(nums), suf(nums), ans(size(nums));//initializing the arrays prefix for pdt of ele before current ele, suffix for pdt of ele after current ele and ans for storing the answer

    partial_sum(begin(pre), end(pre), begin(pre), multiplies<int>());//partial_sum(): This function assigns a partial sum of the corresponding elements of an array to every position of the second array. It returns the partial sum of all the set of values lying between [first, last) and stores it in another array b.
    //Syntax:

    // partial_sum(first, last, b);
    // or

    // partial_sum(first, last, b, myfun);
    // Parameters:
    // first, last: first and last element of range whose elements are to be added
    // b: index of array where  corresponding partial sum will be stored
    // myfun: a user-defined function for performing any specific task
    partial_sum(rbegin(suf),rend(suf), rbegin(suf),multiplies<int>());
    // The rbegin() is a function in C++ STL. 
    // It returns a reverse iterator which points to the last element of the map. 
    // The reverse iterator iterates in reverse order and incrementing it means moving towards beginning of map.

    for(int i = 0; i < size(nums); i++){
        ans[i] = (i? pre[i - 1] : 1)  * (i + 1 < size(nums) ? suf[i + 1] : 1);//pdt of prefix and suffixes
    }

    return ans;
}

// ✔️ Solution - III (Space-Optimized Prefix & Suffix Products)

// We can calculate ans without maintaining two extra pre and suf arrays.

// We can initialize the result array ans of length equal to nums filled with 1.
// Then, for each i, we can calculate prefix product (without self), i.e, ans[i] = ans[i-1]*nums[i-1]. This is same as calculating pre in previous approach but this time we are storing it within our result array.
// Then we iterate from the last index with a variable suffixProd=1 denoting suffix product. For each i, we multiply ans[i] with suffixProd. Each time we will also update suffixProd = suffixProd * nums[i].
// The above again gives us product of array except self at each index. This is because, firstly we are storing prefix product (without self) in ans and then multiplying each ans[i] with suffix product which is the same that we did in the previous approach.
// Time Complexity : O(N), one iteration is required to calculate prefix product for each index and another iteration to calculate suffix product. Total time complexity comes out to be O(2*N) = O(N)
// Space Complexity : O(1), ignoring the output, we are only using constant extra space.

vector <int> productArray3(vector <int>& nums){
    vector <int> ans(size(nums), 1);//initializing ans vector with 1's only

    for(int i = 1; i < size(nums); i++){
        ans[i] = ans[i - 1] * nums[i - 1];//for storing the prefix
    }

    for(int i = size(nums) - 1, suffixPdt = 1; i >= 0; i--){
        ans[i] *= suffixPdt;//for multiplying the prefix and suffix
        suffixPdt *= nums[i];//updating the suffix
    }

    return ans;//returning the ans vector to the main function
}

// ✔️ Solution - IV (Space-Optimized Prefix & Suffix Products in One-Pass)

// The above process can be done in single pass as well. We were first calculating prefix product in one loop and then multiplying it with suffix product in another loop. These two process are independent of each other and can be done in the same loop. We just need to keep another prefix product variable similar to suffix_prod in previous approach.

// We iterate from start and keep calculating prefix product & update corresponding ans[i] & at the same time we can calculate keep calculating suffix product from the end & update ans[n-1-i].

// Note that the final result would be product of array except self because we only update & multiply pre with nums[i] after updating ans[i] and similarly for suf.

// Time Complexity : O(N)
// Space Complexity : O(1)

vector <int> productArray4(vector <int>& nums){
    vector <int> ans(size(nums), 1);//initliaizing all the elements of ans with 1

    for(int i = 0, pre = 1, suf = 1, n = size(nums); i < n; i++){
        ans[i] *= pre;// storing the pdt of all the prefixes
        pre *= nums[i];//updating the prefix
        ans[n - 1 - i] *= suf;//storing the pdt of all the suffixes
        suf *= nums[n - 1 -i];//updating the suffix
    }

    return ans;
}

int main(){
    vector<int> arr{1, 2, 3, 4, 5};

    // auto result = productArray(arr);
    // auto result = productArray1(arr);
    // auto result = productArray2(arr);
    // auto result = productArray3(arr);
    auto result = productArray4(arr);

    for(auto i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}
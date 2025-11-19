#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // arr[i] → stores the input numbers from index 1 to n
    vector<long long> arr(n + 1, 0);

    // prefix_sum[i] → sum of first i elements
    // Example: prefix_sum[3] = arr[1] + arr[2] + arr[3]
    vector<long long> prefix_sum(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];


    /* ---------------------------------------------------------
       1️⃣ BUILDING PREFIX SUM ARRAY
       
       Goal: Quickly calculate any subarray sum in O(1) time.
       
       Why prefix sum?
         If you want sum from index l to r:
           sum(l, r) = prefix_sum[r] - prefix_sum[l - 1]

       So prefix_sum[i] stores total sum from arr[1] to arr[i].
    --------------------------------------------------------- */
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }


    /* ---------------------------------------------------------
       2️⃣ FINDING MAXIMUM SUBARRAY SUM

       ✔ What we want?
         Find the maximum possible sum of any continuous subarray.
         (Classic "Maximum Subarray Sum" problem)

       ✔ Idea:
         For each index i,
           maximum subarray ending at i =
             prefix_sum[i] - minimum prefix sum seen before i

         Why?
           prefix_sum[i] gives total sum from 1 → i  
           minimum prefix sum before i represents the best place to "cut"
           to get the largest remaining sum.

       Example:
         prefix_sum: [0, 2, -1, 4, 1]
         minimum so far = -1
         best subarray ending at 4 = 4 - (-1) = 5

       ✔ So we do:
         - Keep track of the smallest prefix sum visited so far
         - At each step, calculate possible subarray sum
         - Update answer
    --------------------------------------------------------- */

    long long minimum_prefix_sum = 0;  // Smallest prefix sum seen so far
    long long mx = INT_MIN;            // Maximum subarray sum

    for (int i = 1; i <= n; i++) {

        // Calculate best subarray ending at index i
        mx = max(mx, prefix_sum[i] - minimum_prefix_sum);

        // Update the minimum prefix sum for future use
        minimum_prefix_sum = min(minimum_prefix_sum, prefix_sum[i]);
    }

    cout << mx << endl;


    /* ---------------------------------------------------------
       3️⃣ TIME COMPLEXITY

       - Read input: O(n)
       - Build prefix sum: O(n)
       - Find maximum subarray sum: O(n)

       Total Time Complexity = O(n)

       4️⃣ SPACE COMPLEXITY
       - arr array: O(n)
       - prefix_sum array: O(n)

       Total Space Complexity = O(n)
    --------------------------------------------------------- */

    return 0;
}

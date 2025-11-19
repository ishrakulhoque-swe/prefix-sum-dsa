// Question - Find the maximum subarray sum in an array , time complexity - o(n)


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;



    vector<long long> a(n+1, 0);
    vector<long long> prefix_sum(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Finding the maximum subarray sum - o(n)

    int current_sum =0;
    int mx = INT_MIN;
    for(int i = 1;i<=n;i++){
        current_sum += a[i];
        mx = max(current_sum,mx);
        if(current_sum<0){
            current_sum=0;
        }

    }

    cout<<mx<<endl;

}

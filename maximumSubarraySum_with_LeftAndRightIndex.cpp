#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<long long>arr(n+1,0);
    vector<long long>prefix_sum(n+1,0);

    for(int i =1 ;i<=n;i++) cin>>arr[i];

    for(int i =1;i<=n;i++){
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }

   
    long long  minimum_prefix_sum = 0;
    int minimum_prefix_sum_index = 0;

    long long mx = INT_MIN;
    int l, r;
    l =1;
    r =1;

    for(int i =1;i<=n;i++){

        int current_sum = prefix_sum[i] - minimum_prefix_sum;

        if(current_sum>mx){
            mx = current_sum;
            r = i;
            l = minimum_prefix_sum_index+1;
        }

        if(prefix_sum[i]<minimum_prefix_sum){
            minimum_prefix_sum = prefix_sum[i];
            minimum_prefix_sum_index = i;
        }


    }

    cout<<mx<<" "<<l<<" "<<r<<endl;

   






    return 0;
}

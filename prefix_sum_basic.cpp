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

    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }

    for(int i = 1; i <= n; i++) {
        cout << prefix_sum[i] << " ";
    }
    cout << endl;
}

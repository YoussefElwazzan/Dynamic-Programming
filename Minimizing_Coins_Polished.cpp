#include<bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 5;

void solve(){
    // input
    int n, k; cin >> n >> k;
    int arr[n+1];
    arr[0] = 0;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    // initializing 2d dp array
    int dp[n+1][k+1];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = (j == 0)? 0 : MXN;

    dp[0][0] = 0;

    // finding minimum number of coins to construct each sum from 1 to k
    for(int j = 1; j <= n; j++){
        int num = arr[j];  // current coin value

        for(int i = 1; i <= k; i++){
            // base condition to check if we can't subtract the current coin value from the current target sum
            if(i - num < 0){
                dp[j][i] = dp[j - 1][i];
                continue;
            }
            int curr = i - num;  // current sum after subtraction

            // we should have the minimum number of coins to construct the current target sum (curr)

            // so we get the minimum value between the previous combinaton to get this sum
            // and the current computed value

            dp[j][i] = min(dp[j - 1][i], dp[j][curr] + 1);
        }
    }


    if(dp[n][k] == MXN) cout << -1;  // case where no combinations of coins gave our target sum
    else cout << dp[n][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    solve();

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
#include <queue>
#include <map>
#include <string>

using ll = long long;

using namespace std;
using pi=pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define eb emplace_back

using vi = vector<ll>;
using vvi = vector<vi>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n);
    vector<vector<int>> dp(n,vector<int>(n,0));
    int ans = 1;
    rep(i,n){
        cin >> h[i];
        for(int j = 1;j<n;j++){
            if(i-j >= 0 && h[i]==h[i-j]){
                dp[i][j] = dp[i-j][j] + 1;
                ans = max(ans,dp[i][j]);
            }else{
                dp[i][j] = 1;
            }
        }
    }
    cout << ans << endl;
}
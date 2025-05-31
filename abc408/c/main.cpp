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
#include <climits>
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
    
    int n, m;
    cin >> n >> m;
    vector<int> diff(n + 2, 0); 

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    int min_cover = INT_MAX;
    int curr = 0;
	for(int i=0;i<n;i++){
		cout << diff[i] << " ";
	}
    for (int i = 1; i <= n; ++i) {
        curr += diff[i];     
        min_cover = min(min_cover, curr);
    }

    cout << min_cover << '\n';
}
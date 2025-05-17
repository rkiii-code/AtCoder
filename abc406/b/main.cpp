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

int GetDigit(unsigned long long num){
	return std::to_string(num).length();
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
	cin >> n >> k;
	unsigned long long ans = 1;
	unsigned long long mod = 1;
	rep(i,k){
		mod *= 10;
	}
	unsigned long long in;
	rep(i,n){
		cin >> in;
		ans *= in;
		
	}
	cout << ans << endl;
}
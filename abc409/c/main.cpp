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
    int n,l;
	cin >> n >> l;
	vector<int> points(l,0);
	ll ans = 0;
	points[0]++;
	if(l%3 != 0){
		cout << "0"<<endl;
		return 0;
	}
	int interval = l/3;
	int now = 0;
	rep(i,n-1){
		int tmp ;
		cin >> tmp;
		now = (now + tmp) % l;
		points[now]++;
	}
	rep(i,interval){
		ll tmp=1;
		rep(j,3){
			tmp *=points[i + j*interval];
		}
		if(tmp != 0){
			ans += tmp;
		}
	}
	cout << ans <<endl;
}
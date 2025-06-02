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
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define eb emplace_back

using vi = vector<ll>;
using vvi = vector<vi>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;

void slove(){
	int n;
	cin >> n;
	std::string s;
	cin >> s;
	vector<int> c(n+1);
	rep(i,n){
		c[i+1] = c[i] + (s[i]=='0' ? 1 : -1);
	}
	int sum = count(s.begin(),s.end(),'1');
	int ma=0,res=0;
	rep(i,n+1){
		res = min(res,c[i]-ma);
		ma = max(ma,c[i]);
	}
	cout << sum + res << endl;
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
	cin >> t;
	rep(i,t){
		slove();
	}

}
/*



*/


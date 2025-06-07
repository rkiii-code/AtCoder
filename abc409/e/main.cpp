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
#include <stack>
#include <iomanip>

using namespace std;
using ll = long long;
using pi=pair<int,int>;
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
template<class T> using V=vector<T>;
template<class T> using VV=vector<vector<T>>;
template<class T> using VVV=vector<vector<vector<T>>>;
const ll INF=1LL << 60;
#define press(v) v.erase( unique(v.begin(), v.end()), v.end() ) //隣接被り削除
#define each(x,v) for(auto& x : (v))
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define rep2(i,j,n) for(ll i = j; i < (n); i++)
#define each(x,v) for(auto& x : (v))
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

//
int main(){
    init();
	
	string s;
	cin >> s;
	sort(rall(s));
	press(s);
	cout << s <<endl;
	return 0;
}
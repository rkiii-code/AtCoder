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

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using pi=std::pair<int,int>;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define eb emplace_back

using vi = vector<ll>;
using vvi = vector<vi>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;

int score(vector<vector<int>> t, vector<vector<int>> d){
	int w,h;
	w=t.size();
	h=t[0].size();
	int cnt = 0;
	int ans;
	int a,b;
	rep(i,w)rep(j,h){
		if(d[i][j] == 0) continue;
		if(cnt == 0){
			cnt++;
			a = t[i][j];
		}else if(cnt == 1){
			cnt++;
			b = t[i][j];
			ans = a ^ b;
		}else{
			ans = ans ^ t[i][j];
		}
	}
	if(cnt == 0)return 0;
	if(cnt == 1)return a;
	return ans;
}
int solve(vector<vector<int>> t,vector<vector<int>> d , int i ,int j){
	int w,h;
	w=t.size();
	h=t[0].size();
	if(i == w-1){
		if(j == h-1){
			return score(t,d);
		}
		
		int a = solve(t,d,0,j+1);
		if(d[i][j] == 1) return a;
		d[i][j] = 1;
		d[i][j+1] = 1;
		int b = solve(t,d,0,j+1);
		d[i][j] = 0;
		d[i][j+1] = 0;
		return std::max(a,b);
	}else if(j == h-1){
		int a = solve(t,d,i+1,j);
		if(d[i][j] == 1) return a;
		d[i][j] = 1;
		d[i+1][j] = 1;
		int b = solve(t,d,i+1,j);
		d[i][j] = 0;
		d[i+1][j] =0;
		return std::max(a,b);
	}else{
		int a = solve(t,d,i+1,j);
		if(d[i][j] == 1) return a;
		d[i][j] = 1;
		d[i+1][j] = 1;
		int b = solve(t,d,i+1,j);
		a = std::max(a,b);
		d[i+1][j] = 0;
		d[i][j+1] = 1;
		int c = solve(t,d,i+1,j);
		a = std::max(a,c);
		d[i][j] = 0;
		d[i][j+1] = 0;
		return a;
	}
}
int main(){
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
	int w,h;
	cin >> w >> h;
	vector<vector<int>> t(w,vector<int>(h));
	vector<vector<int>> d(w,vector<int>(h,0));
	rep(i,w)rep(j,h) cin >> t[i][j];
	cout<<solve(t,d,0,0)<<endl;
}
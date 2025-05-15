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
	 
    queue<pair<int,int>> q;
	int h,w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i,h){
		cin >> s[i];
	}
	rep(i,h){
		rep(j,w){
			if(s[i][j] == 'E') q.emplace(i,j);
		}
	}
	if(q.empty()){
		rep(i,h) cout << s[i] << endl;
		return 0;
	}
	vector<int> diri = {1,0,-1,0};
	vector<int> dirj = {0,1,0,-1};
	vector<char> dirchar = {'^','<','v','>'};

	while(!q.empty()){
		pair now = q.front();
		q.pop();
		rep(i,4){
			if(now.first + diri[i] >= 0 && now.first + diri[i] < h){
				if(now.second + dirj[i] >= 0 && now.second + dirj[i] < w){
					if(s[now.first + diri[i]][now.second + dirj[i]] == '.'){
						s[now.first + diri[i]][now.second + dirj[i]] = dirchar[i];
						q.emplace(now.first + diri[i],now.second + dirj[i]);
					}
				}
			}
		}
	}
	
	rep(i,h){
		cout << s[i] << endl;
	}
	return 0;
}
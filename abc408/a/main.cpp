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
    
	int n,s;
	int t;
	cin >> n >> s;
	int ans=0;
	rep(i,n){
		cin >> t;
			if(t-ans <= s){
			ans = t;
		}else{
			cout <<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
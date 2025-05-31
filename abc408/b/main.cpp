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
    set<int> a;
	int n;
	cin >> n;
	rep(i,n){
		int tmp;
		cin >> tmp;
		a.insert(tmp);
	}
	cout<<a.size()<<endl;
	int cnt = 0;
	for(int ans : a){
		cout <<ans <<(cnt==a.size()-1? "" : " ");
		cnt++;
	}
	cout << endl;
}
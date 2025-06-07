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
#define rep2(i,j,n) for(int i = j; i < (n); i++)
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
	string t,a;
	cin >> n;
	cin >>t >> a;
	rep(i,n){
		if(t[i] == a[i] && t[i] == 'o'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
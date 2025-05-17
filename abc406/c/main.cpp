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
    int n;
	cin >> n;
	vector<int> a(n);
	vector<int> ud;
	bool flag = 0;
	int ans = 0;
	rep(i,n){
		cin >> a[i];
	}
	int i=0;
	for(int i = 0 ; i < n ; i++){
		while(i<n){
			if(a[i] < a[i+1]){
				ud.emplace_back(1);
				break;
			}
			i++;
		}
		while(i < n && a[i] <= a[i+1]){
			ud[(int)ud.size()-1]++;
		}
	}
	

}
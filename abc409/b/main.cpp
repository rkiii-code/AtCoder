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
	cin >> n;
	vector<int> A(n);
	rep(i,n){
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int max = A[A.size()-1];
	int now = 0;
	int ans = 0;
	rep(i,max+1){
		while(A[now]<i){
			now++;
		}

		if(n-now < i){
			cout<<ans<<endl;
			return 0;
		}
		ans = i;
	}
	cout <<max << endl;

}
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
    
	int t;
	cin >> t;
	rep(i,t){
		int n;
		string s;
		cin >> n;
		cin >> s;
		rep(i,n-1){
			if(s[i] > s[i+1]){
				int sento = s[i];
				int index = i+1;
				rep2(j,i+2,n){
					if(sento < s[j]){
						break;
					}
					index = j;
				}
				for(int j = i; j < index ;j++){
					s[j] = s[j+1];
				}
				s[index] = sento;
				break;
			}
		}
		cout << s << endl;
	}
}
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
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(17);}
template<class T> using V=vector<T>;
template<class T> using VV=vector<V<T>>;
template<class T> using VVV=vector<VV<T>>;
const ll INF=1LL << 60;
#define dump(x)  cout << #x << " = " << (x) << endl;
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
#define SCOUT(x) cout<<(x)<<" "
#define ENDL cout<<endl
#define COUT(x) cout<<(x)<<endl
void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail){
    cin>>head;
    CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
template <class T = ll>
T IN(){T x;cin>>x;return (x);}
#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_
#define VECCOUT(x) for(size_t i = 0; i < (x).size(); ++i) cout << (x)[i] << (i + 1 == (x).size() ? '\n' : ' ')
template <class Head>
void VT(Head head){}
template <class Head,class Seco,class... Tail>
void VT(Head&& head,Seco&& seco,Tail&&... tail){ //vectorのresize
    seco.resize(head);
    VT(head,move(tail)...);
}
void VT2(){}
template <class Head,class... Tail>
void VT2(Head&& head,Tail&&... tail){ //vectorへの入力
  VECCIN(head);
  VT2(move(tail)...);
}
template <class Head>
void VT3(Head&& head){}
template <class Head,class Seco,class... Tail>
void VT3(Head&& head,Seco&& seco,Tail&&... tail){ //vector要素の値変更
  seco[head]=IN();
  VT3(head,move(tail)...);
}

long double calc(int t,int x){

  return (long double)(x-2)/(t-2);
}
//
int main(){
  init();
  SCIN(s);
  int n = s.size();
  V<int> a(n);
  
  rep(i,n){
    a[i] = (s[i]=='t') ? 1 : 0;
  }
  long double ans = 0;
  rep(i,n-3){
    if(a[i] == 0) continue;
    int cnt=1;
    rep2(j,i+1,n){
      cnt += a[j];
      if(a[j] == 1 && j-i >= 3){
        long double c = calc(j-i+1,cnt);
        if(ans < c)ans = c;
      } 
    }
  }
  COUT(ans);
	return 0;
}
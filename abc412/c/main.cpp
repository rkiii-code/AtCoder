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
int solve(set<ll> st, ll front, ll end){
    int cnt = 1;
    auto it1 = st.lower_bound(front);
    auto it2 = st.upper_bound(end);
    
    while(it1 != it2){
        ll current = *it1;
        ll target = current * 2;
        
        auto next = st.lower_bound(target);
        if(next == st.end()){
            cnt++;
            break;
        }
        // 2倍以上の値がない場合
        if(next == st.end() || *next > target){
            // 直前の値を探す
            if(next == st.begin()){
                return -1; // 適切な値がない
            }
            next--;
            // 現在の値より大きく、targetより小さい値が必要
            if(*next <= current || *next > target){
                return -1; // 適切な値がない
            }
        }
        
        cnt++;
        it1 = next; // 次のステップに進む
    }
    
    return cnt;
}


int main(){
    init();
    CIN(T);
    rep(i,T){
        CIN(N);
        set<ll> st;
        int front;
        int end;
        rep(j,N){
            CIN(s);
            st.insert(s);
            if(j == 0){
                front = s;
            }else if(j== N-1){
                end = s;
            }
            
        }
        COUT(solve(st,front,end));
    }
    return 0;
}
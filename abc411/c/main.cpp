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
//
int main(){
    init();

	CIN(n,q);// nとq入力
    V<int> l(n,0);//白黒保持するベクター　最初全部白(0)
    int ans = 0;//現在の区間数

    //1個しかないときイランかもだけど
    if(n==1){
        rep(i,q){
            ans = (ans+1)%2;
            COUT(ans);
        }
        return 0;
    }

    rep(i,q){
        CIN(a);
        a--;

        //先頭の反転の時
        if(a==0){
            if(l[a]==1 && l[a+1]==0){//反転前が黒で隣は白の時 デクリメント
                ans--;
            }else if(l[a]==0 && l[a+1]==0){//反転前が白で隣が白の時　インクリメント
                ans++;
            }
        //末尾の反転の時
        }else if(a==n-1){
            if(l[a]==1 && l[a-1]==0){ //反転前が黒で隣は白の時 デクリメント
                ans--;
            }else if(l[a]==0 && l[a-1]==0){//反転前が白で隣が白の時　インクリメント
                ans++;
            }
        //先頭末尾以外の反転の時
        }else{
            //反転前が白の時
            if(l[a]==0){
                if(l[a-1] == 0 && l[a+1] == 0){//両隣が白の時　インクリメント
                    ans++;
                }else if(l[a-1] == 1 && l[a+1] == 1){//両隣が黒の時 
                    ans--;
                }

            //反転前が黒の時
            }else{
                if(l[a-1] == 0 && l[a+1] == 0){//両隣が白の時
                    ans--;
                }else if(l[a-1] == 1 && l[a+1] == 1){//両隣が黒の時
                    ans++;
                }
            }
        }
        COUT(ans);
        l[a] = (l[a]+1) %2; //割り算遅くてゴミ
    }
	return 0;
}
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
    int h,w,x,y;
    cin >> h >> w >> x >> y;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    string t;
    cin >> t;
    int cnt  = 0;
    for(char c : t){
        if(c == 'U'){
            if(x-1>0 && s[x-2][y-1] != '#'){
                x--;
            }
        }else if(c == 'D'){
            if(x+1<=h && s[x][y-1] != '#'){
                x++;
            }
        }else if(c == 'R'){
            if(y+1<=w && s[x-1][y] != '#'){
                y++;
            }
        }else{
            if(y-1>0 && s[x-1][y-2] != '#'){
                y--;
            }
        }
        if(s[x-1][y-1] =='@'){
            cnt++;
            s[x-1][y-1] ='.';
        }
        
    }
    cout<<x<<" "<<y<<" "<<cnt<<endl;
}
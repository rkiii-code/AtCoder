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
class UnionFind
{
public:

	UnionFind() = default;

	/// @brief Union-Find 木を構築します。
	/// @param n 要素数
	explicit UnionFind(size_t n)
		: m_parentsOrSize(n, -1) {}

	/// @brief 頂点 i の root のインデックスを返します。
	/// @param i 調べる頂点のインデックス
	/// @return 頂点 i の root のインデックス
	int find(int i)
	{
		if (m_parentsOrSize[i] < 0)
		{
			return i;
		}

		// 経路圧縮
		return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
	}

	/// @brief a のグループと b のグループを統合します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a != b)
		{
			// union by size (小さいほうが子になる）
			if (-m_parentsOrSize[a] < -m_parentsOrSize[b])
			{
				std::swap(a, b);
			}

			m_parentsOrSize[a] += m_parentsOrSize[b];
			m_parentsOrSize[b] = a;
		}
	}

	/// @brief a と b が同じグループに属すかを返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @return a と b が同じグループに属す場合 true, それ以外の場合は false
	bool connected(int a, int b)
	{
		return (find(a) == find(b));
	}

	/// @brief i が属するグループの要素数を返します。
	/// @param i インデックス
	/// @return i が属するグループの要素数
	int size(int i)
	{
		return -m_parentsOrSize[find(i)];
	}

private:

	// m_parentsOrSize[i] は i の 親,
	// ただし root の場合は (-1 * そのグループに属する要素数)
	std::vector<int> m_parentsOrSize;
};
int main() {
	int h,w;
	int a,b,c,d;
	int x,y,z,nx,ny;
	bool wall;
	deque<int>dq;
	const int dx[4]={-1,1,0,0};
	const int dy[4]={0,0,-1,1};
	cin>>h>>w;
	vector<string>s(h);
	vector<vector<int> >ans(h,vector<int>(w,h*w)); 
	for(int i=0;i<h;i++)cin>>s[i];
	cin>>a>>b>>c>>d;
	a--,b--,c--,d--;
	
	ans[a][b]=0;
	dq.push_front(a*w+b);
	while(!dq.empty()){
		z=dq.front();
		dq.pop_front();
		if(z==(c*w+d)){
			cout<<ans[c][d]<<endl;
			return 0;
		}
		x=z/w,y=z%w;
		for(int i=0;i<4;i++){
			wall=false;
			for(int j=1;j<=2;j++){
				nx=x+dx[i]*j;
				ny=y+dy[i]*j;
				if((nx<0)||(nx>=h)||(ny<0)||(ny>=w))break;
				if(s[nx][ny]=='#')wall=true;
				if(!wall){
					if(j==1){
						if(ans[nx][ny]>ans[x][y]){
							ans[nx][ny]=ans[x][y];
							dq.push_front(nx*w+ny);
						}
					}
				}
				else{
					if(ans[nx][ny]>ans[x][y]+1){
						ans[nx][ny]=ans[x][y]+1;
						dq.push_back(nx*w+ny);
					}
				}
			}
		}
	}
	return 0;
}
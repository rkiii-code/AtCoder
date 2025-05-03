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
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,M,K;
	cin >> N >> M;
    vector<ll> C(N);
	vector<vector<int>> A(N);
	ll ans = 0;
	rep(i,N){
		cin >> C[i];
		ans += C[i]*2;

	}
	rep(i,M){
		cin >> K;
		rep(j,K){
			int tmp;
			cin >> tmp;
			--tmp;
			A[tmp].emplace_back(i);
		}
	}
    for (int bit = 0; bit < (1<<N*2); ++bit)
    {
		ll sum = 0;
		vector<int> check(M,0);
        for (int i = 0; i < N*2; ++i) {
            if (bit & (1<<i)) { // i が bit に入るかどうか
                sum += C[i%N];
				int n = A[i%N].size();
				rep(j,n){
					++check[A[i%N][j]];
				}
            }
			bool flag = false;
			rep(j,M){
				if(check[j] < 2){
					flag = true;
					break;
				}
			}
			if(!flag){
				if(ans > sum){
					ans = sum;
				}
			}
        }

    }
	cout << ans << endl;
}
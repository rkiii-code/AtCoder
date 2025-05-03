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

vector<string> rotate(vector<string> input){
	vector<string> output = input;
	int n = input[0].size();
	rep(i,n){
		rep(j,n){
			output[i][j] = input[n-j-1][i];
		}
	}
	return output;
} 
int count(vector<string> S,vector<string> T){
	int sum = 0;
	int n = S[0].size();
	rep(i,n){
		rep(j,n){
			if(S[i][j] != T[i][j]){
				++sum;
			}
		}
	}
	return sum;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
	cin >> N;
	vector<string> S(N),T(N);
	rep(i,N){
		cin >> S[i];
	}
	rep(i,N){
		cin >> T[i];
	}
	int min = count(S,T);
	int tmp;
	vector<string> G = S;
	rep(i,3){
		tmp = i + 1;
		G = rotate(G);
		tmp += count(G,T);
		if(tmp < min){
			min = tmp;
		}
	}
	cout << min << endl;
	return 0;
}
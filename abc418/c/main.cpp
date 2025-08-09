#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    vector<ll> S(N);
    S[0] = A[0];
    for (int i = 1; i < N; i++) S[i] = S[i-1] + A[i];

    auto ok = [&](ll x, int b) {
        int val = b - 1;
        int idx = (int)(std::lower_bound(A.begin(), A.end(), val) - A.begin());
        ll sum = 0;
        if (idx > 0) sum += S[idx - 1];
        sum += (ll)(N - idx) * val;
        return sum < x;
    };

    for (int _ = 0; _ < Q; _++) {
        int b; cin >> b;
        if (A.back() < b) {
            cout << -1 << "\n";
            continue;
        }

        ll ng = b - 1;
        ll okv = S.back() + 1;

        while (okv - ng > 1) {
            ll mid = (okv + ng) / 2;
            if (ok(mid, b)) okv = mid;
            else ng = mid;
        }

        if (okv == S.back() + 1) cout << -1 << "\n";
        else cout << okv << "\n";
    }
}

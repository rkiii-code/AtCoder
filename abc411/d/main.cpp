int main() {
    init();
    CIN(n, q);
    V<query> Q(q);
    rep(i, q) {
        cin >> Q[i];
    }
    
    // 結果となる文字列を管理（逆順）
    string rev_ans = "";
    int t = q;
    int i = 0;
    
    // クエリを後ろから処理
    while (t > 0) {
        t--;
        const query &cur = Q[t];
        
        if (cur.type == 1 && cur.p == i) {
            // PC pの文字列をPC 0にコピー
            i = 0;
        } 
        else if (cur.type == 2 && cur.p == i) {
            // PC pに文字列を追加
            string rev_s = cur.s;
            reverse(all(rev_s));
            rev_ans += rev_s;
        } 
        else if (cur.type == 3 && i == 0) {
            // PC pの文字列をPC 0にコピー
            i = cur.p;
        }
    }
    
    // 最後に逆順の文字列を元に戻して出力
    string ans = rev_ans;
    reverse(all(ans));
    cout << ans << endl;
    
    return 0;
}
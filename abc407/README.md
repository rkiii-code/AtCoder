# ABC407 2025/05/24 SAT

## A - Approximation

$`\frac{A}{B}`$を四捨五入する．$`0.5`$足して整数部分を取り出す．

## B - P(X or Y)

全ての組み合わせを調べても36通りしかないので、全ての組み合わせを調べる．

## C - Security 2

ボタンBを押す回数は，$`j`$番目のボタンについて $`10+S_j-S_{j+1}`$ 一番左のボタンについては$`S_N`$回．ボタンAはN回押す．

## D - Domino Covering XOR 

時間制限に余裕があるので全探索する．XORでスコアを図るのでDPなどはきつそう．

どこにドミノがおかれているかを$`MN`$bitで管理する．

bitで全列挙は重要そう．

```cpp
//全部の置き方を列挙する方法
//std::ranges::moveを使うと簡潔に書ける．　C++20以降

vector<unsigned> possible_domino{0}; // はじめは何も置かれていない盤面だけ
const unsigned domino_vertical = (1U << W) + 1, domino_horizontal = 3;
for (unsigned i = 0, bit = 0; i < H; ++i)
        for (unsigned j = 0; j < W; ++j, ++bit) { // 各マスについて
            vector<unsigned> tmp;
            for (const auto b : possible_domino) {
                // 縦に置けるなら置いたものを追加する
                if (j + 1 < W && !(b & domino_horizontal << bit))
                    tmp.emplace_back(b | domino_horizontal << bit);
                // 横に置けるなら置いたものを追加する
                if (i + 1 < H && !(b & domino_vertical << bit))
                    tmp.emplace_back(b | domino_vertical << bit);
            }
            std::ranges::move(tmp, back_inserter(possible_domino));
        }
```

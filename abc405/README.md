# ABC405 2025/05/10 SAT

## A - Is it rated?

if文書けばおけい

## B -  Not All

$1 \leq m \leq M$ の mそれぞれの先頭要素を見て，最も末尾に近いものから答えを出した．N-m.
愚直に一つずつ消していく方法でも計算は間に合いそう．

## C - Sum of Product

累積和を使う．
$\sum_{1 \le i < j \le N} A_i A_j = \sum_{j=2}^{N} \sum_{i=1}^{j-1} A_i A_j = \sum_{j=2}^{N} \left( A_j \cdot \sum_{i=1}^{j-1} A_i \right) = \sum_{j=2}^{N} A_j S_{j-1}$

## D - Escape Route

すべてのEからBFSするのが楽．

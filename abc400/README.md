# ABC400 2025-04-05 SAT 

## A - ABC400 Party 

## B - Sum of Geometric Series 

素直に解けばよい．\
$`N^i`$なので大きな値の足し算は数回ほどで済む．\
計算は29回ほど\

## C - 2^a b^2

N以下の全ての非負整数に対して計算すると計算量大きくなる．\
$`2^a`$を固定して可能なbの値をさがすといい.\

## D - Takahashi the Wall Breaker 

最短経路を求める問題(Dijkstraが使えそう)\
今回はコストが**0か1の二つ**したがって**01BFS**使える．\
dequeでコスト0の辺を先頭にコスト1の辺を末尾に追加で優先キューとできる.\
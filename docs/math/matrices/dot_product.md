If `A` is an `m x n` matrix and `B` is an `n x p` matrix, then the dot product of `A` and `B` is an `m x p` matrix represented by `C = A.B`. Each element of `C` can be computed as follows:

```
// assuming 1-based indexing

C[i][j] = 0
for k in [1, n]:
    C[i][j] += A[i][k] * B[k][j]
```

In other words:

```
C[i][j] = summation(k = 1 to n, A[i][k] * B[k][j])
```

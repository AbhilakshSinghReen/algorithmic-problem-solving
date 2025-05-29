# Algorithm

A polynomial of degree `n` can be represented as:

```
a[n] * (x ^ n) + a[n - 1]
    + (x ^ (n - 1))
    + ...
    + a[2] * (x ^ 2)
    + a[1] * x
    + a[0]
```

To make this more computationally efficient, we compute a running power of `x` and keep multiplying the coefficients of that power.

TODO: is there more to this method?

When we look at input sizes large enough to make only the order of growth of the running time relevant, we are studying the asymptotic efficiency of algorithms.

Asymptotic notations apply to functions. For example:

```
a * (n ^ 2) + b * n + c = Θ(n ^ 2)
```

## Θ Notation (Average case, two-sided bound)

[Figure 3.1 of Intro to algos book]

A function `f(n)` belongs to the set `Θ(g(n))` if there exist positive constants `c1` and `c2` such that it can be “sandwiched” between `c1 * g(n)` and `c2 * g(n)`, for suffi ciently large `n`. We say that `g(n)` is an asymptotically tight bound for `f(n)`. To prove that `f(n) == Θ(g(n))`, we need to find real values for the constants `c1`, `c2`, and `n0`. Note that `n0` will be a non-negative interger as it represents the size of the input.

```
Θ(g(n)) = {
    f(n) such that
        there exist positive constants c1, c2, and n0 such that
            0 <= c1 * g(n) <= f(n) <= c2 * g(n) for all n >= n0
}
```

This is not restricted to one variable `n`. Neither are any of the following asymptotic notations.

```
Θ(g(n, m)) = {
    f(n, m) such that
        there exist positive constants c1, c2, n0, and m0 such that
            0 <= c1 * g(n, m) <= f(n, m) <= c2 * g(n, m) for all n >= n0 or m >= m0
}
```

The definition of `Θ(g(n))` requires that `f(n) >= 0 for all n >= n0`. Such a function is called asymptotically non-negative.

## O Notation (tight upper bound)

A function `f(n)` belongs to the set `O(g(n))` if there exist a positive constant `c` such that it is always less than or equal to `c * g(n)` for suffi ciently large `n`.

```
O(g(n)) = {
    f(n) such that
        there exist positive constants c and n0 such that
            0 <= f(n) <= c * g(n) for all n >= n0
}
```

If `f(n) == Θ(g(n))`, then `f(n) == O(g(n))`, but not vice-versa.

## Ω Notation (tight lower bound)

A function `f(n)` belongs to the set `Ω(g(n))` if there exist a positive constant `c` such that it is always greater than or equal to `c * g(n)` for suffi ciently large `n`.

```
Ω(g(n)) = {
    f(n) such that
        there exist positive constants c and n0 such that
            0 <= c * g(n) <= f(n) for all n >= n0
}
```

If `f(n) == Θ(g(n))`, then `f(n) == Ω(g(n))`, but not vice-versa.

If `f(n) == O(g(n))` and `f(n) == Ω(g(n))`, then `f(n) == Θ(g(n))`.

For example, the running time of Insertion Sort is not `Θ(n ^ 2)`, as no matter how big `n` gets, we can have a sorted input that will run in Linear time.

It is not necessary that `O` defines the worse case and `Ω` defines the best case. But they do define the upper and lower bounds respectively. For example, it can be said that the worse-case running time of Insertion Sort is `Θ(n ^ 2)`.

## o Notation (loose upper bound)

A function `f(n)` belongs to the set `o(g(n))` if for any `c > 0`, there exists an `n0 > 0` such that `0 <= f(n) < c * g(n)`.

```
o(g(n)) = {
    f(n) if
        for all c > 0, there exists an n0 > 0 such that
            0 <= f(n) < c * g(n)
}
```

For example: `2 * n = o(n ^ 2)`, but `2 * (n ^ 2) != o (n ^ 2)`.

The definitions of O-notation and o-notation are similar. The main difference is that in `f(n) = O(n)`, the bound `0 <= f(n) <= c * g(n)` holds for some `c > 0`; but in `f(n) = o(n)`, the bound `0 <= f(n) < c * g(n)` holds for all `c > 0`.

If `f(n) = o(n)`, then:

```
exp = f(n) / g(n)
lim(n -> ∞, exp) = 0
```

## ω Notation (loose lower bound)

A function `f(n)` belongs to the set `ω(g(n))` if for any `c > 0`, there exists an `n0 > 0` such that `0 <= c * g(n) < f(n)`.

```
ω(g(n)) = {
    f(n) if
        for all c > 0, there exists an n0 > 0 such that
            0 <= c * g(n) < f(n)
}
```

If `f(n) = ω(n)`, then:

```
exp = f(n) / g(n)
lim(n -> ∞, exp) = ∞
```

# Asymptotic Notations in Equations

An equation such as `2 * (n ^ 2) + 3 * n + 1 = 2 * (n ^ 2) + Θ(n)` <br />
means that `2 * (n ^ 2) + 3 * n + 1 = 2 * (n ^ 2) + f(n)` where `f(n)` belongs to the set `Θ(n)`.

Using asymptotic notation in this manner can help eliminate inessential detail and clutter in an equation.

For example, `T(n) = 2 * T(n / 2) + Θ(n)`. If we are interested only in the asymptotic behavior of `T(n)`, there is no point in specifying all the lower-order terms exactly; they are all understood to be included in the anonymous function denoted by the term `Θ(n)`.

If an asymptotic notation appears on the LHS, `2 * (n ^ 2) + Θ(n) = Θ(n ^ 2)`. Then we interpret such equations using the following rule: No matter how the anonymous functions are chosen on the left of the equal sign, there is a way to choose the anonymous functions on the right of the equal sign to make the equation valid.

# Relational Properties of Asymptotic Notations

Many of the relational properties of real numbers apply to asymptotic comparisons as well.
[Intro to Algos, page 72]

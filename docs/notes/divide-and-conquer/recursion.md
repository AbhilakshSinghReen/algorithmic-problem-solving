Recurrences can take many forms. For example, a recursive algorithm might divide subproblems into unequal sizes, such as a `2/3`-to-`1/3` split. If the divide and combine steps take linear time, such an algorithm would give rise to the recurrence `T(n) = T(2 * n / 3) + T(n / 3) + Θ(n)`.

Subproblems are not necessarily constrained to being a constant fraction of the original problem size. For example, a recursive version of linear search would create just one subproblem containing only one element fewer than the original problem. Each recursive call would take constant time plus the time for the recursive calls it makes, yielding the recurrence `T(n) = T(n - 1) + Θ(1)`.

If a recurrence is an inequality, we can use the `O` or `Ω` notations.

When we state and solve recurrences, we often omit floors, ceilings, and boundary conditions. We forge ahead without these details and later determine whetheror not they matter. They usually do not, but you should know when they do.

# Solving Recurrences

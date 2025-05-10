// the following code would prevent the compiler from applying loop-invariant
// code motion. This is despite there being no overlap between pointers
// a[0] to a[n-1] and b. That means that this optimization is valid because *b is a constant for the entire loop and can be computed once undefined

void func(int *a, int *b, int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = *b;
    }
}

void func(int *__restrict a, int *__restrict b, int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = *b;
    }
}

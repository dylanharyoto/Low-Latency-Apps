// Loop unrolling duplicates the body of the loop multiple times in order to
// avoid the checks and branching that determine whether a loop should continue.

int main()
{
    int a[5];
    a[0] = 0;
    for (int i = 1; i < 5; ++i)
    {
        a[i] = a[i - 1] + 1;
    }
    {
        int a[5];
        a[0] = 0;
        a[1] = a[0] + 1;
        a[2] = a[1] + 1;
        a[3] = a[2] + 1;
        a[4] = a[3] + 1;
    }
}

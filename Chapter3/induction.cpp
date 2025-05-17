// Registers, however, are limited, so the compiler needs to choose the
// variables to store effectively, and the effectiveness of this choice can make
// a significant difference to performance. The compiler typically picks
// variables such as local variables, loop counter and iterator variables,
// function parameters, commonly used expressions, or induction variables
// (variables that change by fixed amounts on each loop iteration).

int main()
{
    [[maybe_unused]] int a[100];

    for (auto i = 0; i < 100; ++i)
    {
        a[i] = i * 10 + 12;
    }

    int temp = 12;
    for (auto i = 0; i < 100; ++i)
    {
        a[i] = temp;
        temp += 10;
    }
}
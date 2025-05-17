// The first block is what the developer originally wrote, but the compiler can
// understand that the call to doSomething() and the expression involving the b
// variable are loop invariants and only need to be computed once.

#include <cstdlib>
int main()
{
    auto doSomething = [](double r) noexcept
    { return 3.14 * r * r; };
    [[maybe_unused]] int a[100], b = rand();
    // Original
    for (auto i = 0; i < 100; ++i)
    {
        a[i] = (doSomething(50) + b * 2) + 1;
    }
    // Loop invariant code movement
    auto temp = (doSomething(50) + b * 2) + 1;
    for (auto i = 0; i < 100; ++i)
    {
        a[i] = temp;
    }
}
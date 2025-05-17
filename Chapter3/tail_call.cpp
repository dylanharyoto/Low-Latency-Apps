// Tail call optimization refers to compiler optimization techniques in which
// recursive function calls are replaced by loops. For this implementation, we
// would expect that in the machine code for the factorial() function, we would
// find a call to itself, but when compiled with optimization turned on, the
// compiler performs tail call optimization and implements the factorial()
// function as a loop and not a recursion.

auto __attribute__((noinline)) factorial(unsigned n) -> unsigned
{
    return (n ? n * factorial(n - 1) : 1);
}
int main()
{
    [[maybe_unused]] volatile auto res = factorial(100);
}
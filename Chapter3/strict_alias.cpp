// This example uses a conversion from double * into uint64_t * and modifies the
// sign bit using the uint64_t pointer. This is nothing more than a convoluted
// and more efficient method of achieving x = -std::abs(x) but demonstrates how
// this violates the strict aliasing rule

#include <cstdio>
#include <cstdint>
int main()
{
    double x = 100;
    const auto orig_x = x;
    auto x_as_ui = (uint64_t *)(&x);
    *x_as_ui |= 0x8000000000000000;
    printf("orig_x:%0.2f x:%0.2f &x:%p &x_as_ui:%p\n", orig_x, x, &x, x_as_ui);
}
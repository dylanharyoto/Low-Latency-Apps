// The simplest example we could think of is presented here, where we try to
// convert a price from its double notation into its integer notation by
// dividing the floating value by its minimum valid price increment. The variant
// that demonstrates the strength reduction that a compiler would perform is a
// simple multiplication instead of a division.

#include <cstdint>
int main() {
    const auto price = 10.125; // e.g. 10.125, 10.130, 10.135, ...
    constexpr auto min_price_increment = 0.005;
    [[maybe_unused]] int64_t int_price = 0;
    // no strength reduction
    int_price = price / min_price_increment;
    // strength reduction
    constexpr auto inv_min_price_increment = 1 / min_price_increment;
    int_price = price * inv_min_price_increment;
}
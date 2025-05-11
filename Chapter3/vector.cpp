// For architectures that support special vector registers such as the SSE2
// instruction set we discussed before, it can hold 4 4-byte float values
// simultaneously and perform 4 additions at a time. In this case, the compiler
// can leverage the vectorization optimization technique and re-write this as
// the following with loop unrolling to use the SSE2 instruction set

#include <cstddef>

int main()
{
    const size_t size = 1024;
    [[maybe_unused]] float x[size], a[size], b[size];

    for (size_t i = 0; i < size; ++i)
    {
        x[i] = a[i] + b[i];
    }

    // Vectorization
    for (size_t i = 0; i < size; i += 4)
    {
        x[i] = a[i] + b[i];
        x[i + 1] = a[i + 1] + b[i + 1];
        x[i + 2] = a[i + 2] + b[i + 2];
        x[i + 3] = a[i + 3] + b[i + 3];
    }
}
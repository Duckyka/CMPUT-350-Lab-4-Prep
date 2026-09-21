#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t
#include <iostream>
#include <cmath>

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    if (scale > 16)
    {
        assert(("Shift scale cannot exceed 16", false));
    }

    auto inputCopy = input;
    int n = 0;

    while (pow(2, n) <= inputCopy)
    {
        n++;
    }

    uint64_t shiftedInput = 0;

    while (n > 0)
    {
        uint64_t bit = pow(2, n-1);
        uint64_t tempBit = input & bit;
        if (tempBit != 0)
        {
            tempBit = 1;
            tempBit = tempBit << ((n-1) * scale);
            shiftedInput = shiftedInput | tempBit;
        }
        n--;
    }
    return shiftedInput;  // replace this with your impl!
}

int main() {
    uint64_t test = expand(0b0101, 5);
    std::cout << "Test on expand() is: " << test << "\n";
    // test here...
    return 0;
}

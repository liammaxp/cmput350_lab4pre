#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    assert(scale >= 1);
    uint64_t result = 0;
    for (uint32_t i = 0; i < 64; ++i){
        if (static_cast<uint64_t>(i) * scale >=64){
            break;
        }
        if (input & (1ULL << i)){
            result |= (1ULL << (i * scale));
        }
    }
    return result;  // replace this with your impl!
}

int main() {
    assert(expand(0b1111, 3) == 0b001001001001);
    assert(expand(0b0101, 2) == 0b00010001);
    assert(expand(0b101101, 1) == 0b101101);
    assert(expand(0, 5) == 0);
    assert(expand(0, 5) == 0);
    assert(expand(0b11, 64) == 0b1);
    // test here...
    return 0;
}

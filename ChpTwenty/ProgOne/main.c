
#include <stdio.h>

struct float_bits {
    unsigned int fraction : 23;   // bits 0-22
    unsigned int exponent : 8;    // bits 23-30
    unsigned int sign : 1;        // bit 31
};

union float_view {
    float value;
    struct float_bits bits;
};

int main(void)
{
    union float_view u;

    u.bits.sign = 1;
    u.bits.exponent = 128;
    u.bits.fraction = 0;

    printf("Float value: %f\n", u.value);

    return 0;
}

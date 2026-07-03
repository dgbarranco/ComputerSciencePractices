#include <stdio.h>

int main(void)
{
    int areaCode;
    int prefix;
    int lineNumber;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &areaCode, &prefix, &lineNumber);

    printf("You entered %03d.%03d.%04d\n",
           areaCode,
           prefix,
           lineNumber);

    return 0;
}

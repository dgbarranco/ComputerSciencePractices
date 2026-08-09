
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int ch;
  int beginning = 1;

  while ((ch = getchar()) != EOF) {
    if (isspace(ch)) {
      beginning = 1;
      putchar(ch);
    } else {
      if (beginning) {
        ch = toupper(ch);
        beginning = 0;
      }

      putchar(ch);
    }
  }

  return 0;
}


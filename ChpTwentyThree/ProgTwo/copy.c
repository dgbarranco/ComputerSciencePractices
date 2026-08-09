
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int ch;
  int beginning = 1;
  int has_text = 0;

  while ((ch = getchar()) != EOF) {
    if (beginning) {
      if (isspace(ch) && ch != '\n') {
        continue;
      }

      if (ch == '\n') {
        beginning = 1;
        has_text = 0;
        continue;
      }

      beginning = 0;
      has_text = 1;
      putchar(ch);
    } else {
      putchar(ch);

      if (ch == '\n') {
        beginning = 1;
        has_text = 0;
      }
    }
  }

  return 0;
}


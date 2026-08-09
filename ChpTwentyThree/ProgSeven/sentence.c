
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int ch;
  int next;
  int count = 0;

  while ((ch = getchar()) != EOF) {
    if (ch == '.' || ch == '?' || ch == '!') {
      next = getchar();

      if (next != EOF) {
        if (isspace(next))
          count++;

        ungetc(next, stdin);
      }
    }
  }

  printf("Number of sentences: %d\n", count);

  return 0;
}

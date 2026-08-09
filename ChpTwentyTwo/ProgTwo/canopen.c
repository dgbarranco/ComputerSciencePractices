
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int ch;

  if (argc != 2) {
    printf("usage: upper filename\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (isalpha(ch))
      ch = toupper(ch);

    putchar(ch);
  }

  fclose(fp);

  return 0;
}
```

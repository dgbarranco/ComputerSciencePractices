
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int ch;
  int count = 0;
  int in_word = 0;

  if (argc != 2) {
    printf("usage: countwords filename\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (isspace(ch)) {
      in_word = 0;
    } else if (!in_word) {
      count++;
      in_word = 1;
    }
  }

  printf("Number of words: %d\n", count);

  fclose(fp);

  return 0;
}


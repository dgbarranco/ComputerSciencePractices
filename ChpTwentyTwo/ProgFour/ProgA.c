
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int ch;
  int count = 0;

  if (argc != 2) {
    printf("usage: count filename\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((ch = fgetc(fp)) != EOF) {
    count++;
  }

  printf("Number of characters: %d\n", count);

  fclose(fp);

  return 0;
}


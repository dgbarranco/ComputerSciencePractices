
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int i;
  int ch;

  if (argc < 2) {
    printf("usage: fcat file...\n");
    exit(EXIT_FAILURE);
  }

  for (i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      printf("can't open %s\n", argv[i]);
      exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF) {
      putchar(ch);
    }

    fclose(fp);
  }

  return 0;
}

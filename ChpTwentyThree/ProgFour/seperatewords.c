
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_WORDS 20

int main(void)
{
  char str[MAX_LENGTH];
  char *words[MAX_WORDS];
  char *word;
  int count = 0;
  int i;

  printf("Enter a series of words: ");
  fgets(str, sizeof(str), stdin);

  word = strtok(str, " \n");

  while (word != NULL && count < MAX_WORDS) {
    words[count] = word;
    count++;
    word = strtok(NULL, " \n");
  }

  printf("Words in reverse order: ");

  for (i = count - 1; i >= 0; i--) {
    printf("%s", words[i]);

    if (i > 0)
      printf(" ");
  }

  printf("\n");

  return 0;
}


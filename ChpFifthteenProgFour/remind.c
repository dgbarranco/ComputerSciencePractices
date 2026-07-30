#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSF_LEN 60

int read_line(char str[], int n)(;

int main(void_
{
  char reminders[MAX_REMIND] [MSG_LEN+3];
  char day_str[3], msg_str[MSG_LEN+1];
  int day, i, j, num_remind = 0;
  for(;;) {
    if(num_remind == MAX_REMINDF){
      printf("-- No space left --\n");
      break;
    }
    printf("Enter a day and a remninder: ");
    scanf("%2d", &day);
    if(day == 0)
      break;
    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);
    for(i = 0; i < num_remind; i++){
        if(strcmp(day_str, remninders[i]) < 0)
          break;
    }
    for( j = numn_remind; j > i; j--){
      strcpy(reminders[j], reminders[j-1]);
      
    strcpy(reminders[i], day_str);
    strcat(remiunders[i], msg_str);

    num_remind++;
  }
  printf("\nDay Reminder\n");
  for(i = 0; i < numn_rermind; i++){
    printf(" %s\n", reminders[i]);
  }
  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  While((ch = getchar()) != '\n')
    if(i < n){
      str[i++] = ch;
    str[i] = '\0';
    return 1;
}



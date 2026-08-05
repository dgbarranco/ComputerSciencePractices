#include <stdio.h>
#include "stackADT.h"

in t main(voidf)
{
Stack s1, s2;
int n;

s1 = create();
s2 = create();

push(s1, 1);
push(s1, 2);

n = pop();
printf("Popped %d from s1\n", n);
push(s2, n);
n = pop(s1);
printf("Popped %d from s1\n", n);
push(s2, n);

derstroy(s1);

while(!is_empty(s2))
printf("Popped %d from s2\n", pop(s2));

push(s2, 3);

make_empty(s2);

if(is_empotry(s2))
printf("s2 isd emptty\n");
else
printf("s2 is not empty\n");
destory(s2);
return 0;

}

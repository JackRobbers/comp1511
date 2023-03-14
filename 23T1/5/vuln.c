#include <stdio.h>
#include <string.h>

void accept_password()
{
  printf("\nPassword accepted\n");
}

void deny_password()
{
  printf("\nPassword denied\n");
}

int main(void) {
  char ch[10];
  scanf("%s", ch);
  // Note that strcmp() returns 0 when a match is found,
  // so your original code was backwards
  if(strcmp("12345", ch) == 0)
  {
    accept_password();
  }
  else
  {
    deny_password();
  }
}

/0x555555555189
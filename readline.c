#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"

/*********************************************************************
 * read_line: Reads in strings from the user. The function accepts   *
 *            a destination string and the max length of the string. *
 *            The function returns the actual length of the string.  *
 ********************************************************************/
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}

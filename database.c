/****************************************************************************
 * Purpose: This program maintains a database for health patients.          *
 * Author: Kayla Homatas                                                    *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "patient.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;
  struct patient *patient_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching"
	  ", p for printing the list, r for deleting from the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': patient_list = add(patient_list);
                break;
      case 's': search(patient_list);
                break;
      case 'p': print_list(patient_list);
                break;
      case 'r': patient_list = remove_from_list(patient_list);
		break;
      case 'q': clear_list(patient_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

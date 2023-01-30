#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "patient.h"
#include "readline.h"

/*************************************************************
 * add: Asks the user to enter a patient's last name, first  *
 *      name, email, sex, diagnosis, and prescription and    *
 *      then adds the patient to the end of the linked list. *
 *      The function accepts a linked list of student        *
 *      structures and returns a pointer to the list.        *  
 ************************************************************/
struct patient *add(struct patient *list){
  
  /* Declaring destination strings to hold data about the patient. */
  char last_name[NAME_LEN + 1];
  char first_name[NAME_LEN + 1];
  char email[EMAIL_LEN + 1];
  char sex[SEX_LEN+1];
  char diagnosis[DIAGNOSIS_LEN+1];
  char prescription[PRESCRIPTION_LEN+1];

  /*********************************************************** 
   * Asks the user for the patient's last name, first name,  *
   * email, sex, diagnosis, and prescription, and stores it  *
   * in the destination strings using the readline function. *
   **********************************************************/
  printf("Enter patient's last name: ");
  read_line(last_name, NAME_LEN + 1);
  printf("Enter patient's first name: ");
  read_line(first_name, NAME_LEN + 1);
  printf("Enter patient's email address: ");
  read_line(email, EMAIL_LEN + 1);
  printf("Enter patient's sex: ");
  read_line(sex, SEX_LEN + 1);
  printf("Enter patient's diagnosis: ");
  read_line(diagnosis, DIAGNOSIS_LEN + 1);
  printf("Enter patient's prescription: ");
  read_line(prescription, PRESCRIPTION_LEN + 1);
  
  /******************************************************************** 
   * Declaring a temporary structure to use to iterate througb the    *
   * database of patients and find if the patient the user requested  *
   * to add to the database already exists. Checks to see if the last *
   * name and email entered by the user both match a patient already  *
   * in the database. Exits the function if there is.                 *
   *******************************************************************/
  struct patient *temp;
  for (temp = list; temp != NULL; temp = temp->next) {
    if (strcmp(email, temp->email) == 0 && strcmp(last_name, temp->last) == 0) {
      printf("Request already exists\n");
      return list;
    }
  }

  /*********************************************************************** 
   * Declaring a new patient structure to hold the data entered by the   * 
   * user. Allocates memory for the patient and copies the data into the * 
   * patient structure.                                                  *
   ********************************************************************* */
  struct patient *new_patient;
  new_patient = malloc(sizeof(struct patient));
  
  strcpy(new_patient->last, last_name);
  strcpy(new_patient->first, first_name);
  strcpy(new_patient->email, email);
  strcpy(new_patient->sex, sex);
  strcpy(new_patient->diagnosis, diagnosis);
  strcpy(new_patient->prescription, prescription);

  /************************************************************************
   * Declaring a temporary patient structure to use to iterate through    *
   * the database and check if the database is empty. If the database is  *
   * empty, the function adds the patient to linked list and returns the  *
   * pointer to the patient.                                              *
   ********************************************************************** */
  struct patient *p;
  if (list == NULL) {
    new_patient->next = NULL;
    list = new_patient;
    return new_patient;
  }
  /************************************************************************
   * If the database is not empty, the program finds the last patient in  *
   * the database and then adds the patient to the end of the linked list *
   * and returns a pointer to the list.                                   *
   ************************************************************************/
  else {
    for (p = list; p != NULL; p = p->next) {
      if (p->next == NULL) {
        break;
      }
    }
    new_patient->next = NULL;
    p->next = new_patient;
  }

  return list; 

}

/*****************************************************************
 * search: Finds a patient by last name and first name. Prints   *
 *         the last name, first name, email, sex, diagnosis,     *
 *         and prescription of the patient(s) matching the last  *
 *         and first name. If no patient is found with the last  *
 *         name and first name, the program prints a message.    *
 *         The function accepts a linked list of patient         *
 *         structures (the current database) and does not return *
 *         a value or make any modifications to the list.        *
 ****************************************************************/
void search(struct patient *list)
{
  char last_name[NAME_LEN + 1];
  char first_name[NAME_LEN + 1];
  
  /********************************************************************** 
   * Asks the user for the last name and first name of the patient they *
   * are searching for and uses read_line to store the strings.         * 
   **********************************************************************/
  printf("Enter patient's last name: ");
  read_line(last_name, NAME_LEN + 1);
  printf("Enter patient's first name: ");
  read_line(first_name, NAME_LEN + 1);

  /************************************************************************
   * Declares a temporary patient structure to iterate through the linked *
   * list and prints the last name, first name, email, sex, diagnosis,    *
   * and prescription of the matching patient.                            *
   ************************************************************************/
  struct patient *p;
  int found = 0;
  for (p = list; p != NULL; p = p->next) {
    if (strcmp(p->last, last_name) == 0 && strcmp(p->first, first_name) == 0) {
      found++;
      printf("%s\t%s\t%s\t%s\t%s\t%s\n", p->last, p->first, p->email, p->sex, p->diagnosis, p->prescription);  
    }
  }
  /* If the patient is not found, the program prints a message. */
  if (found == 0) {
    printf("Patient not found\n");
  }

}

/************************************************************************
 * print_list: Prints the last name, first name, email, sex, diagnosis, *
 *             and prescription of all the patients in the database.    *
 *             The function accepts a linked list of patient structures *
 *             (the database of patients) and doesn't return a value    *
 *             or make any modifications to the list.                   *
 ************************************************************************/
void print_list(struct patient *list){

  /************************************************************************
   * Declares a temporary patient structure to iterate through the linked *
   * list and print the data for each patient in the database.            *
   ************************************************************************/
  struct patient *p;
  for (p = list; p != NULL; p = p->next) {
    printf("%s\t%s\t%s\t%s\t%s\t%s\n", p->last, p->first, p->email, p->sex, p->diagnosis, p->prescription);  
  }  

}

/***********************************************************************
 * remove_from_list: Removes a patient from the database. The function *
 *                   has one parameter: the linked list of patient     *
 *                   structures (the database). The function removes   *
 *                   the patient from the list if they exist and       *
 *                   returns a pointer to the list.                    *
 ***********************************************************************/
struct patient *remove_from_list(struct patient *list){

  /************************************************************************
   * Declaring three string variables to hold the last name, first name,  *
   * and email of the patient the user wants to remove from the database. *
   ************************************************************************/
  char last_name[NAME_LEN + 1];
  char first_name[NAME_LEN + 1];
  char email[EMAIL_LEN + 1];

  /* Asks the user for the patient's last name, first name, and email. */
  printf("Enter patient's last name: ");
  read_line(last_name, NAME_LEN + 1);
  printf("Enter patient's first name: ");
  read_line(first_name, NAME_LEN + 1);
  printf("Enter patient's email: ");
  read_line(email, EMAIL_LEN + 1);

  /* Declaring two pointer variables of the type struct patient to be used to point to various patients in the database. */
  struct patient *prev;
  struct patient *cur;

  /*************************************************************************** 
   * Iterating through the database and searching for the patient with the   *
   * matching last name, first name, and email that was entered by the user. *
   ***************************************************************************/
  for (cur = list, prev = NULL;
       cur != NULL && (strcmp(last_name, cur->last) != 0 || strcmp(first_name, cur->first) != 0 || strcmp(email, cur->email) != 0); 
       prev = cur, cur = cur->next)
    ;
  /* If the patient exists, cur should point to the patient to be removed and prev should point to the patient before cur. */  

  /************************************************************************* 
   * If cur points to NULL, then that means the loop reached the end       *
   * of the list; the patient wasn't found in the database. The function   * 
   * returns a pointer to the database without having made changes to it.  *
   *************************************************************************/
  if (cur == NULL) {
    printf("Patient not found\n");
    return list;
  }
  /**********************************************************************
   * If prev points to NULL, that means cur points to the first patient *
   * in the database. The function removes the patient by having the    *
   * beginning of the list now point to the second patient.             *
   **********************************************************************/
  if (prev == NULL) {
    list = list->next;
  }
  /*****************************************************************
   * Otherwise, the patient was found in the list and cur points   *
   * to the patient to be removed and prev points to the patient   *
   * before cur. The previous node is altered so that it bypasses  *
   * cur. The patient has now been essentially removed.            *
   *****************************************************************/
  else {
    prev->next = cur->next;  
  }  
  printf("%s\t%s\t%s\t%s\t%s\t%s removed\n", cur->last, cur->first, cur->email, cur->sex, cur->diagnosis, cur->prescription);
 
  /* Deallocates the space occupied by the removed patient and returns a pointer to the new list. */
  free(cur);
  return list;

}

/*******************************************************************
 * clear_list: When the user chooses to exit the program, all the  *
 *             memory allocated for the linked list is deallocated.*
 *             The function accepts a linked list of patient       *
 *             structures (the database of patients) and doesn't   *
 *             return a value.                                     *
 ******************************************************************/
void clear_list(struct patient *list){

  /************************************************************************
   * Declares a temporary patient structure to prevent dangling pointers. *
   * While the list is not empty, the function deallocates the memory of  *
   * each patient.                                                        *
   ************************************************************************/
  struct patient *temp;
  while (list != NULL) {
    temp = list;
    list = list->next;
    if (temp != NULL) {
      free(temp);
    }
  }

}

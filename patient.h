#ifndef PATIENT_H
#define PATIENT_H

#define EMAIL_LEN 100
#define NAME_LEN 30
#define SEX_LEN 30
#define DIAGNOSIS_LEN 500
#define PRESCRIPTION_LEN 200

struct patient {
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	char sex[SEX_LEN+1];
	char diagnosis[DIAGNOSIS_LEN+1];
	char prescription[PRESCRIPTION_LEN+1];
	struct patient *next;
};

struct patient *add(struct patient *list);
void search(struct patient *list);
void print_list(struct patient *list);
void clear_list(struct patient *list);
int read_line(char str[], int n);
struct patient *remove_from_list(struct patient *list);

#endif
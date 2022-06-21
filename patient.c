#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"

// Creates a new patient
// To be added to the linked list
patient *init_patient() {
  patient *new_patient = (patient *)malloc(sizeof(patient));
  printf("\n\nCase ID: ");
  scanf("%d", &(new_patient->case_id));

  printf("Age: ");
  scanf("%d", &(new_patient->age));

  printf("Sex:\n");
  printf("\t0. Male\n");
  printf("\t1. Female\n");
  printf("\tChoice: ");
  scanf("%d", &(new_patient->sex));

  printf("Status:\n");
  printf("\t0. Recovered\n");
  printf("\t1. Admitted\n");
  printf("\t2. Deceased\n");
  printf("\tChoice: ");
  scanf("%d", &(new_patient->status));

  get_date(new_patient);

  new_patient->next = NULL;

  printf("\n");

  return new_patient;
}

// Auxiliary to init_patient
void get_date(patient *new_patient) {
  printf("Date when tested positive:\n");
  printf("\tMonth (1-12): ");
  scanf("%d", &(new_patient->tested_positive).month);

  printf("\tDay (1-31): ");
  scanf("%d", &(new_patient->tested_positive).day);

  printf("\tYear (20XX): ");
  scanf("%d", &(new_patient->tested_positive).year);
}

void print_patient(patient p) {
  printf("\nCase ID: %d\n", p.case_id);
  printf("Age: %d years old\n", p.age);
  printf("Sex: %s\n", p.sex == 0 ? "Male" : "Female");
  printf("Status: ");
  switch (p.status) {
    case 0:
      printf("Recovered\n");
      break;
    case 1:
      printf("Admitted\n");
      break;
    case 2:
      printf("Deceased\n");
      break;
  }
  printf("Tested positive: %d/%d/%d\n", p.tested_positive.month, p.tested_positive.day,
    p.tested_positive.year);
}
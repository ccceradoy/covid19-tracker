#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"


int choose_menu() {
  int choice;
  printf("\n++++++MENU++++++\n");
  printf("+ 1. Add         +\n");
  printf("+ 2. Delete      +\n");
  printf("+ 3. Edit        +\n");
  printf("+ 4. Print       +\n");
  printf("+ 5. Rates       +\n");
  printf("+ 6. Exit        +\n");
  printf("++++++++++++++++++\n");
  printf("Enter choice: ");
  scanf("%d", &choice);
  return choice;
}

// Add new patient to the database
// Add to the linked list in sorted age order
void add(list *L, patient *new_patient) {
  // List still empty or new_patient's age is the least
  if (L->head == NULL || new_patient->age <= L->head->age) {
    new_patient->next = L->head;
    L->head = new_patient;
  } else {
    patient *tmp = L->head;
    while (tmp->next != NULL && tmp->next->age < new_patient->age) {
      tmp = tmp->next;
    }
    new_patient->next = tmp->next;
    tmp->next = new_patient;
  }
  printf("Successfully added patient!\n");
}

void delete(list *L) {
  int case_id;
  printf("Enter case ID: ");
  scanf("%d", &case_id);

  patient *to_delete;
  
  // At first position
  if (L->head->case_id == case_id) {
    to_delete = L->head;
    L->head = L->head->next;
    printf("Successfully deleted\n");
    free(to_delete);
    return;
  }

  // Nth position
  patient *tmp = L->head;
  while (tmp->next != NULL) {
    if (tmp->next->case_id == case_id) {
      to_delete = tmp->next;
      tmp->next = to_delete->next;
      free(to_delete);
      printf("Successfully deleted\n");
      return;
    }
    tmp = tmp->next;
  }

  printf("Case ID does not exist!\n");
}


// Edit/change the status
void edit(list *L) {
  int case_id;
  printf("Enter case ID: ");
  scanf("%d", &case_id);

  patient *to_edit;
  int found = 0; // 0 - not found, 1 - found

  // At first position
  if (L->head->case_id == case_id) {
    to_edit = L->head;
    found = 1;
  }

  // Nth position
  patient *tmp = L->head;
  while (found != 1 && tmp->next != NULL) {
    if (tmp->next->case_id == case_id) {
      to_edit = tmp->next;
      found = 1;
    }
    tmp = tmp->next;
  }

  if (found == 1) {
    printf("Patient %d's status: ", to_edit->case_id);
    switch (to_edit->status) {
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

    printf("New status:\n");
    printf("\t0. Recovered\n");
    printf("\t1. Admitted\n");
    printf("\t2. Deceased\n");
    printf("Choice: ");
    scanf("%d", &(to_edit->status));

    printf("Successfully edited Patient %d\n", to_edit->case_id);
    return;
  }

  printf("Case ID does not exist!");
}

void print(list *L) {
  int choice;
  printf("1. Print All\n");
  printf("2. Print Recovered\n");
  printf("3. Print Admitted\n");
  printf("4. Print Deceased\n");
  printf("Choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      print_all(L);
      break;
    case 2:
      print_list(L, 0);
      break;
    case 3:
      print_list(L, 1);
      break;
    case 4:
      print_list(L, 2);
      break;
  }
}

void print_all(list *L) {
  patient *tmp = L->head;
  while (tmp != NULL) {
    print_patient(*tmp);
    tmp = tmp->next;
  }
  printf("\n");
}

// Print based on condition; 0 - Recovered, 1 - Admitted, 2 - Deceased
void print_list(list *L, int condition) {
  patient *tmp = L->head;
  while (tmp != NULL) {
    if (tmp->status == condition) {
      print_patient(*tmp);
    }
    tmp = tmp->next;
  }
  printf("\n");
}


// Compute based on condition; 0 - Recovery rate, 1 - Fatality rate
void compute_rate(list *L) {
  int mode, rec_rate = 0, mort_rate = 0, total = 0;
  
  printf("1. Recovery rate\n");
  printf("2. Mortality rate\n");
  printf("Choice: ");
  scanf("%d", &mode);

  patient *tmp = L->head;
  while (tmp != NULL) {
    total++;
    tmp = tmp->next;
  }

  tmp = L->head;
  while (tmp != NULL) {
    if (tmp->status == 0) {
      rec_rate++;
    } else if (tmp->status == 2) {
      mort_rate++;
    }
    tmp = tmp->next;
  }


  if (mode == 1) {
    printf("Recovery rate is %.2f\n", (float) ((float) rec_rate/ (float) total));
  } else {
    printf("Mortality rate is %2.f\n", (float) (mort_rate/total));
  }

}

void dealloc(list *L) {
  printf("Deallocating...\n");
  patient *tmp;

  while (L->head != NULL) {
    tmp = L->head;
    L->head = L->head->next;
    free(tmp);
  }
  printf("Bye!\n");
}
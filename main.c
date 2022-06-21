#include <stdlib.h>
#include <stdio.h>
#include "prototype.h"


int main() {
  list *L = (list *)malloc(sizeof(list));
  L->head = NULL;

  int choice = 1;

  do {
    choice = choose_menu();
    switch (choice) {
      case 1:
        add(L, init_patient());
        break;
      case 2:
        delete(L);
        break;
      case 3:
        edit(L);
        break;
      case 4:
        print(L);
        break;
      case 5:
        compute_rate(L);
        break;
      case 6:
        dealloc(L);
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  } while (choice != 6);
}
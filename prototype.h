typedef struct date_tag {
  int month;
  int day;
  int year;
}date;

typedef struct patient_tag {
  int case_id;
  int age;
  int sex;
  int status;
  date tested_positive;
  struct patient_tag *next;
}patient;

typedef struct linked_list {
  patient *head;
}list;

// From patient.c
patient *init_patient();
void get_date(patient *new_patient);
void print_patient(patient p);

// From database.c
int choose_menu();
void add(list *L, patient *new_patient);
void delete(list *L);
void edit(list *L);
void print(list *L);
void print_all(list *L);
void print_list(list *L, int condition);
void compute_rate(list *L);
void dealloc(list *L);
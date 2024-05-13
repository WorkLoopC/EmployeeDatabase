#include <stdio.h>
#include <stdlib.h>

struct employee {
  int idNum;
  char *firstName;
  char *lastName;
  int age;
  int salary;
  char *jobTitle;
};

void setNumberOfEmployees(int *numOfEmployees) {
  printf("How Many Employees Are Employed At Your Company?\n");
  scanf("%d", numOfEmployees);
}
void fillOutEmployeeInfo(struct employee *employee, int *numEmployees) {
  static int idNum = 1;

  for (int i = 0; i < *numEmployees; i++) {
    printf("Enter The Employee's First Name, Last Name, Age, Salary, and Job "
           "Title\n");
    scanf(" %20s", employee[i].firstName);
    scanf(" %20s", employee[i].lastName);
    scanf(" %hd", &employee[i].age);
    scanf(" %d", &employee[i].salary);
    scanf(" %64[^\n]", employee[i].jobTitle);
    employee[i].idNum = idNum;
    idNum++;
  }
};

int main() {
  int numOfEmployees;
  setNumberOfEmployees(&numOfEmployees);
  struct employee *emp = malloc(sizeof(struct employee) * numOfEmployees);

  if (emp == NULL) {
    printf("The allocator failed\n");
    return -1;
  }
  const int SIZE_OF_NAMES = 21;
  const int SIZE_OF_JOB_TITLE = 65;

  for (int i = 0; i < numOfEmployees; i++) {
    emp[i].firstName = malloc(SIZE_OF_NAMES);
    emp[i].lastName = malloc(SIZE_OF_NAMES);
    emp[i].jobTitle = malloc(SIZE_OF_JOB_TITLE);

    if (emp[i].firstName == NULL || emp[i].lastName == NULL ||emp[i].jobTitle == NULL) {
      printf("The allocator failed\n");
      return -1;
    }
  }
  fillOutEmployeeInfo(emp, &numOfEmployees);

  for (int i = 0; i < numOfEmployees; i++) {
    printf("\nEmployee ID = %d\n Employee First Name = %s\n Employee Last Name "
           "= %s\n Employee Age = %hd\n Employee Salary = %d\n Employee Job "
           "Title = %s\n",
           emp[i].idNum, emp[i].firstName, emp[i].lastName, emp[i].age,
           emp[i].salary, emp[i].jobTitle);

    free(emp[i].firstName);
    free(emp[i].lastName);
    free(emp[i].jobTitle);
    emp[i].firstName = NULL;
    emp[i].lastName = NULL;
    emp[i].jobTitle = NULL;
  }
  free(emp);
  emp = NULL;
  return 0;
}

//An attempt to make listing employee database to practice memory in C 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_IDS 1000

struct emp
{
int income;
int id;
bool staff;
};
int initialize_employee(struct emp *st_emp){
static int numEmployees=0;
numEmployees++;
st_emp->id=numEmployees;
st_emp->income=0;
st_emp->staff=false;
return numEmployees;
}

int main(){
int n=4; //value from the database header
struct emp *st_emp=malloc(sizeof(struct emp)*n);
if(st_emp==NULL){
    printf("Failed");
    return -1;
}
for(int i=0;i<n;i++){
initialize_employee(&st_emp[i]);
printf("New employee ID is %d\n", st_emp[i].id);
}
free(st_emp); //Giving back memory to the system to avoid leaking memory 
st_emp=NULL; //Setting pointer to null to avoid dangling pointer or a pointer that points to memory that is no longer valid
    
}
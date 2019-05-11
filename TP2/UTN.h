#include <stdio.h>
#include <conio.h>

#define LIBRE 0
#define OCUPADO 1


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;


void initEmployees(Employee arrayEmp[], int tam);
int findplace(Employee arrayEmp[], int tam);
void addEmployees(Employee arrayEmp[], int tam,int idincremental);
void removeEmployee(Employee arrayEmp[], int tam);
void ModEmployee(Employee arrayEmp[], int tam);
void showEmployee(Employee unEmp);
void printEmployees(Employee arrayEmp[], int tam);
void menuEmployees(Employee arrayEmp[],int tam,int idincremental);
int OpMenu(char mensaje[]);
int findEmployeeById(Employee arrayEmp[], int tam);

void OrdenarPorApellido(Employee arrayEmp[], int tam);


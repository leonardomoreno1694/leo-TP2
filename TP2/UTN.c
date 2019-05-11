#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "UTN.h"




/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return void
 */
void initEmployees(Employee arrayEmp[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        arrayEmp[i].isEmpty = LIBRE;
    }
}



int findplace(Employee arrayEmp[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(arrayEmp[i].isEmpty==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return void
**/
void addEmployees(Employee arrayEmp[], int tam,int idincremental)
{



    int i;
    char sn;
    system("cls");
    printf("\n\n::::::::ALTA EMPLEADO::::::::\n\n");
do{
    i = findplace(arrayEmp,50);
    if(i!=-1)
    {

        printf("INGRESAR NOMBRE DEL EMPLEADO: ");
        fflush(stdin);
        gets(arrayEmp[i].name);

        printf("INGRESAR APELLIDO DEL EMPLEADO: ");
        fflush(stdin);
        gets(arrayEmp[i].lastName);


        printf("INGRESAR SALARIO DEL EMPLEADO: ");
        fflush(stdin);
        scanf("%f", &arrayEmp[i].salary);

         printf("INGRESAR SECTOR DEL EMPLEADO: ");
        fflush(stdin);
        scanf("%d", &arrayEmp[i].sector);


        arrayEmp[i].isEmpty = OCUPADO;

        idincremental++;
        arrayEmp[i].id=idincremental;


        printf("\n\nEL JUEGO FUE CARGADO CON EXITO!\n\n ");


    }
    else
    {
        printf("NO HAY ESPACIO PARA CARGAR EL JUEGO\n\n");
    }


        printf("\n\n\nDESEA REALIZAR OTRA CARGA:S/N \n\n\n");
         fflush(stdin);
         scanf("%c",&sn);

}while(sn=='s');

}

void removeEmployee(Employee arrayEmp[], int tam)
{

    system("cls");
    printf("\n\n::::::::BAJA EMPLEADO:::::::\n\n: ");

    int i;
    int loEncontro = 0;
    int aux;
    printEmployees(arrayEmp,50);
    printf("INGRESE ID DEL EMPLEADO A DAR DE BAJA: ");
    scanf("%d",&aux);



    for(i=0; i<tam; i++)
    {
        if(aux == arrayEmp[i].id)
        {

           arrayEmp[i].isEmpty = LIBRE;


            loEncontro = 1;
            break;//modifcar
        }

    }

    printf("\n\nEL EMPLEADO FUE DADO DE BAJA CON EXITO!\n\n ");

    if(loEncontro==0)
    {
        printf("El dato no existe");
    }

}
void ModEmployee(Employee arrayEmp[], int tam)
{
    system("cls");
    printf("\n\n::::::::MODIFICAR EMPLEADO:::::::\n\n ");
    char sn;
    int i;
    int loEncontro = 0;
    int opcionMod;
    int aux;
    printEmployees(arrayEmp,50);
    printf("INGRESE ID DEL JUEGO A MODIFICAR:\n ");
    scanf("%d", &aux);

    for(i=0; i<tam; i++)
    {
        if(aux == arrayEmp[i].id)
        {
    do{
        printf("\n1 MOD NOMBRE:\n2 MOD APELLIDO:\n3 MOD SALARIO:\n4 MOD ID :\nINGRESE DATO A MODIFICAR:\n");
        fflush(stdin);
        scanf("%d",&opcionMod);

        switch(opcionMod)
        {

        case 1:
            printf("MOD NOMBRE: ");
            fflush(stdin);
            gets(arrayEmp[i].name);
            break;
        case 2:
            printf("MOD APELLIDO: ");
            fflush(stdin);
            gets(arrayEmp[i].lastName);
             break;

        case 3:
            printf("MOD SALARIO : ");
            fflush(stdin);
            scanf("%f", &arrayEmp[i].salary);

        case 4:
            printf("MOD ID: ");
            fflush(stdin);
            scanf("%d", &arrayEmp[i].id);
        }
            printf("DESEA REALIZAR OTRA MODIFICACION: ");
             fflush(stdin);
            scanf("%c", &sn);

      }while(sn=='s');
          }
    }

    if(loEncontro==0)
    {
        printf("EL ID NO EXISTE");
    }
}

void showEmployee(Employee unEmp)
{
    printf("%d - %s - %s - %.2f \n\n\n",unEmp.id,unEmp.name,unEmp.lastName,unEmp.salary);
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return void
 *
 */
void printEmployees(Employee arrayEmp[], int tam)
{
printf("\n\n::::::::LISTA DE EMPLEADO::::::::\n\n ");
    int i;
    for(i=0; i<tam; i++)
    {
        if(arrayEmp[i].isEmpty==OCUPADO)
        {
            showEmployee(arrayEmp[i]);
        }

    }

}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return void
 *
 */
int findEmployeeById(Employee arrayEmp[], int tam)
{
    int idaux;
    int flag = 0;
    int i;

    printf("\n\n::::::::BUSCAR EMPLEADO::::::::\n\n ");

    printf("\nINGRESE ID DEL EMPLEADO\n ");
    fflush(stdin);
    scanf("%d",&idaux);


    for(i=0; i<tam; i++)
    {
        if(arrayEmp[i].isEmpty==OCUPADO)
        {
            if(flag==0||idaux==arrayEmp[i].id)
            {
               arrayEmp[i].id = idaux;
                flag = 1;
                printf("EMPLEADO: %d - %s %s\n\n",arrayEmp[i].id,arrayEmp[i].name,arrayEmp[i].lastName);
            }
        }
    }





    return idaux;

}
void menuEmployees (Employee arrayEmp[],int tam,int idincremental)
{

    int op;

  //  int sn;

     printf(":::::::::::::::::::::::::::::\n::::::::::: T P 2 :::::::::::\n:::::::::::::::::::::::::::::\n\n\n");
    do
    {

        fflush(stdin);

        op = OpMenu("1.ALTA EMPLEADO\n2.BAJA EMPLEADO\n3.MODIFICAR EMPLEADO\n4.MOSTRAR EMPLEADO\n5.BUSCAR EMPLEADO POR ID.\nSALIR\n ELIJA UNA OPCION: ");
        switch(op)
        {
            case 1:
                addEmployees(arrayEmp,50,idincremental);
                break;

            case 2:
               removeEmployee(arrayEmp,50);
                break;

            case 3:
              ModEmployee(arrayEmp,50);
                break;

            case 4:

                printEmployees(arrayEmp,50);
                break;
            case 5:
               findEmployeeById(arrayEmp,50);

               break;




        }
    }while(op!=0);

}

int OpMenu(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return void
 *
 */
/* NO PUDE HACER ARRANCAR :/
void  sortEmployees(Employee arrayEmp[], int tam)

{
    char auxiliarEmp;
    int i,j;

    for(i=0; i < tam - 1; i++)
                {
                    if(arrayEmp[i].isEmpty == -1)
                    {
                    continue;
                    }
                    for(j=i+1; j < tam; j++)
                    {
                        if(arrayEmp[j].id == -1)
                        {
                        continue;
                        }
                        if(strcmp(arrayEmp[i].lastName,arrayEmp[j].lastName) > 0)
                        {
                            auxiliarEmp = arrayEmp[j];
                            arrayEmp[j] = arrayEmp[i];
                            arrayEmp[i] = auxiliarEmp;
                        }
                    }
                }



}



*/









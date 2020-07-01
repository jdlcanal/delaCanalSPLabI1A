#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pais.h"
#include "Controller.h"
#include "time.h"

int menu();

int main()
{
    char seguir='s';
    char confirm;
    int primeraVez=0;

    srand(time(NULL));

    LinkedList* lista = ll_newLinkedList();
    if(lista==NULL){
        printf("No se pudo asignar memoria\n");
        exit(EXIT_FAILURE);
    }

    do{
        switch(menu())
        {
            case 1:
                if(ll_isEmpty(lista)==0){
                    printf("ERROR!!! Ya cargaste los datos!!!\n\n");
                }
                else{
                    controller_loadFromText("pandemia.csv" , lista);
                }
                break;
            case 2:
                if(ll_isEmpty(lista)==1){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                    controller_ListPais(lista);
                }
                break;
            case 3:
                if(ll_isEmpty(lista)==1){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                    controller_map(lista);
                    primeraVez=1;
                }
                break;
            case 4:
                if(ll_isEmpty(lista)==1 && primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                    controller_filterExitosos(lista);
                }
                break;
            case 5:
                if(ll_isEmpty(lista)==1 && primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{

                }
                break;
            case 6:
                if(ll_isEmpty(lista)==1 && primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{
                controller_sortPaisInfeccion(lista);
                }
                break;
            case 7:
                if(ll_isEmpty(lista)==1 && primeraVez==0){
                    printf("ERROR!!! Primero debes cargar los datos!!!\n\n");
                }
                else{

                }
                break;
            case 8:
                printf("Esta seguro que desea salir? s/n: ");
                fflush(stdin);
                scanf("%c",&confirm);
                if(confirm=='s'){
                    seguir='n';
                    printf("Adios!! \n\n");
                }
                break;
            default:
                printf("ERROR!!! INGRESE UNA OPCION VALIDA!!!\n\n");
                break;
        }
        system("pause");
    }while(seguir=='s');
    return 0;
}
/** \brief Menu general del programa
 *
 * \return int
 *
 */

int menu(){
    int opcion;

    system("cls");
    printf("Bienvenido!!!\n");
    printf("1.Cargar Archivo \n");
    printf("2.Imprimir Lista \n");
    printf("3.Asignar Estadisticas \n");
    printf("4.Filtrar x Paises Exitosos \n");
    printf("5.Filtrar x Paises en el Horno \n");
    printf("6.Ordenar x Nivel de Infeccion \n");
    printf("7.Mostrar mas Castigado \n");
    printf("8.Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

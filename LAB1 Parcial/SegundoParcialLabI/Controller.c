#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pais.h"

void controller_ListOnePais(ePais* pais){
    if(pais!= NULL){
        printf("%4d   %18s %4d %4d %4d\n",pais->id,pais->paises,pais->recuperados,pais->infectados,pais->muertos);
    }
}

int controller_ListPais(LinkedList* pArrayListPais){
    int todoOk=-1;
    ePais* pais;

    if(pArrayListPais!=NULL){
        todoOk=1;
        system("cls");
        printf("   ID              PAIS          RECUPERADOS   INFECTADOS   MUERTOS\n");
        for(int i=0; i<ll_len(pArrayListPais);i++){
            pais=(ePais*)ll_get(pArrayListPais,i);
            controller_ListOnePais(pais);
        }
    }

    return todoOk;
}

int controller_loadFromText(char* path , LinkedList* pArrayListPais){
    int todoOk=-1;

    FILE* f;
    if(path!=NULL && pArrayListPais!=NULL){
        f=fopen(path,"r");
        if(f!=NULL){
            if(parser_InfectadosFromText(f,pArrayListPais)){
                printf("Datos cargados con Exito!!!\n\n");
                fclose(f);
                todoOk=1;
            }
            else{
                printf("Hubo un error al cargar!!!\n\n");
            }
        }
    }

    return todoOk;
}

int controller_saveAsText(char* path,LinkedList* pArrayListPais){
    FILE* f;
    ePais* pais;
    int len=-1;
    int id;
    int recuperados;
    int muertos;
    int infectados;
    char nombrePais[20];
    int todoOk=-1;
    int i;

    if(path!=NULL && pArrayListPais!=NULL){
        len=ll_len(pArrayListPais);
        if(len>0){
            f=fopen(path,"w");
            if(f!=NULL){
                fprintf(f,"ID,PAIS,RECUPERADOS,INFECTADOS,MUERTOS\n");
                for(i=0;i<len;i++){
                    pais=(ePais*)ll_get(pArrayListPais,i);
                    pais_getId(pais,&id);
                    pais_getRecuperados(pais,&recuperados);
                    pais_getInfectados(pais,&infectados);
                    pais_getMuertos(pais,&muertos);
                    pais_getPais(pais,nombrePais);
                    fprintf(f,"%d,%s,%d,%d,%d\n",id,nombrePais,recuperados,infectados,muertos);
                }
                fclose(f);
                if(i==len){
                    todoOk=1;
                }
            }
        }
    }
    if(todoOk == 1){
        printf("Datos guardados correctamente!!!\n\n");
    } else{
        if(len==0){
            printf("ERROR!!! No hay datos para guardar!!!\n\n");
        } else{
            printf("ERROR!!! No se pudo guardar los datos!!!\n\n");
        }
    }

    return todoOk;
}

int controller_map(LinkedList* pArrayListPais){
    int todoOk=-1;

    if(pArrayListPais!=NULL){
        pArrayListPais=ll_map(pArrayListPais,pais_RecuperadosRandomSet);
        pArrayListPais=ll_map(pArrayListPais,pais_MuertosRandomSet);
        pArrayListPais=ll_map(pArrayListPais,pais_InfectadosRandomSet);
        if(controller_ListPais(pArrayListPais)){
            printf("Estadisticas Asignadas con exito!!!\n");
        }
        todoOk=1;
    }
    return todoOk;
}
int controller_filterExitosos(LinkedList* pArrayListPais){
    int todoOk=-1;
	LinkedList* lista=NULL;
    lista=ll_filter(pArrayListPais,paises_filterExitosos);
    if(controller_saveAsText("paisesExitosos.csv", lista)){
				printf("Lista guardada con exito!\n");
				todoOk=1;
			}
    return todoOk;
}
int controller_sortPaisInfeccion(LinkedList* pArrayListPais){
    int todoOk=-1;
	if(pArrayListPais!=NULL){
		if(ll_len(pArrayListPais)>0);
            ll_sort(pArrayListPais,pais_sortInfectados,0);
            todoOk=1;
    }
    return todoOk;
}
/*
int controller_sortPaisCastigado(LinkedList* pArrayListPais){
    int todoOk=-1;
	if(pArrayListPais!=NULL){
		if(ll_len(pArrayListPais)>0);
            ll_sort(pArrayListPais,pais_sortMuertos,1);
            todoOk=1;
    }
    return todoOk;
}
*/

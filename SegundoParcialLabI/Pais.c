#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pais.h"
#include <time.h>

ePais* pais_new(){
    ePais* newPais=(ePais*) malloc(sizeof(ePais));

    if(newPais!=NULL)
    {
        newPais->id=0;
        newPais->infectados=0;
        newPais->muertos=0;
        newPais->recuperados=0;
        strcpy(newPais->paises," ");
    }

    return newPais;
}
ePais* pais_newParametros(char* idStr,char* paisesStr,char* recuperadosStr,char* infectadosStr,char* muertosStr){
    ePais* pais = pais_new();

    if(idStr!=NULL && paisesStr!=NULL && recuperadosStr!=NULL && infectadosStr!=NULL && muertosStr!=NULL){
        pais_setId(pais,atoi(idStr));
        pais_setPais(pais,paisesStr);
        pais_setRecuperados(pais,atoi(recuperadosStr));
        pais_setInfectados(pais,atoi(infectadosStr));
        pais_setMuertos(pais,atoi(muertosStr));
    }

    return pais;
}


int pais_setId(ePais* pais,int id){
    int todoOk = -1;

    if(pais != NULL && id >-1)
    {
        pais->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int pais_getId(ePais* pais,int* id){
    int todoOk = -1;

    if(pais != NULL && id != NULL)
    {
        *id=pais->id;
        todoOk = 1;
    }
    return todoOk;
}

int pais_setPais(ePais* pais,char* nombre){
    int todoOk = -1;

    if(pais != NULL && strlen(nombre) > 0)
    {
        strcpy(pais->paises, nombre);
        todoOk = 1;
    }
    return todoOk;
}
int pais_getPais(ePais* pais,char* nombre){
    int todoOk = -1;

    if(pais != NULL && strlen(nombre) > 0)
    {
        strcpy(nombre,pais->paises);
        todoOk = 1;
    }
    return todoOk;
}

int pais_setRecuperados(ePais* pais,int recuperados){
    int todoOk = -1;

    if(pais != NULL && recuperados >-1)
    {
        pais->recuperados = recuperados;
        todoOk = 1;
    }
    return todoOk;
}
int pais_getRecuperados(ePais* pais,int* recuperados){
    int todoOk = -1;

    if(pais != NULL && recuperados != NULL)
    {
        *recuperados=pais->recuperados;
        todoOk = 1;
    }
    return todoOk;
}

int pais_getRecuperadosRandom(){
    int random;
    random = rand()% 50000 + 1000001;

    return random;
}

int pais_RecuperadosRandomSet(void* recu){
    ePais* pais=NULL;

    if(recu!=NULL){
        pais=(ePais*)recu;
        pais_setRecuperados(pais,pais_getRecuperadosRandom());

    }
    return pais;
}

int pais_setInfectados(ePais* pais,int infectados){
    int todoOk = -1;

    if(pais != NULL && infectados >-1)
    {
        pais->infectados = infectados;
        todoOk = 1;
    }
    return todoOk;
}

int pais_getInfectados(ePais* pais,int* infectados){
    int todoOk = -1;

    if(pais != NULL && infectados != NULL)
    {
        *infectados=pais->infectados;
        todoOk = 1;
    }
    return todoOk;
}

int pais_getInfectadosRandom(){
    int random;
    random = rand()% 40000 + 2000001;

    return random;
}

int pais_InfectadosRandomSet(void* infec){
    ePais* pais=NULL;

    if(infec!=NULL){
        pais=(ePais*)infec;
        pais_setInfectados(pais,pais_getInfectadosRandom());

    }
    return pais;
}

int pais_setMuertos(ePais* pais,int muertos){
    int todoOk = -1;

    if(pais != NULL && muertos >-1)
    {
        pais->muertos = muertos;
        todoOk = 1;
    }
    return todoOk;
}

int pais_getMuertos(ePais* pais,int* muertos){
    int todoOk = -1;

    if(pais != NULL && muertos != NULL)
    {
        *muertos=pais->muertos;
        todoOk = 1;
    }
    return todoOk;
}

int pais_getMuertosRandom(){
    int random;
    random = rand()% 1000 + 4901;

    return random;
}

int pais_MuertosRandomSet(void* muertos){
    ePais* pais=NULL;

    if(muertos!=NULL){
        pais=(ePais*)muertos;
        pais_setMuertos(pais,pais_getMuertosRandom());

    }
    return pais;
}


int parser_InfectadosFromText(FILE* pFile , LinkedList* pArrayListPais)
{
    int todoOk = -1;
    int cant;
    char buff[5][20];
    ePais* pais=NULL;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3], buff[4]);

    if(pFile!=NULL && pArrayListPais!=NULL){
        while(!feof(pFile)){
            cant= fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3],buff[4]);
            pais=pais_newParametros(buff[0], buff[1], buff[2], buff[3],buff[4]);
            if(pais!=NULL){
                ll_add(pArrayListPais,pais);
                todoOk=1;
              }
            if(cant < 5){
                if(feof(pFile)){
                    break;
                }
                else{
                  todoOk=0;
                break;
                }
            }

        }
      }


    return todoOk;
}
int pais_sortInfectados(void* pA, void* pB){
	int todoOk=-1;
	ePais* pais1=NULL;
	ePais* pais2=NULL;
	int inf1;
	int inf2;

	if(pA!=NULL && pB!=NULL){
		pais1=(ePais*)pA;
		pais2=(ePais*)pB;
		pais_getInfectados(pais1,&inf1);
		pais_getInfectados(pais2,&inf2);
		if(inf1 > inf2){
			todoOk=1;
		} else if(inf1 < inf2){
			todoOk=0;
		}
	}
	return todoOk;
}
int movie_sortMuertos(void* pA, void* pB){
	int todoOk=-1;
	ePais* pais1=NULL;
	ePais* pais2=NULL;
	int muer1;
	int muer2;

	if(pA!=NULL && pB!=NULL){
		pais1=(ePais*)pA;
		pais2=(ePais*)pB;
		pais_getMuertos(pais1,&muer1);
		pais_getMuertos(pais2,&muer2);
		if(muer1 > muer2){
			todoOk=1;
		} else if(muer1 < muer2){
			todoOk=0;
		}
	}
	return todoOk;
}

int paises_filterExitosos(void* pais){
	int todoOk=-1;
	ePais* auxPais=(ePais*)pais;

	if(pais!=NULL){
		auxPais=(ePais*)pais;
		if(auxPais->muertos<5000){
			todoOk=1;
		}
	}
	return todoOk;
}

#include "LinkedList.h"
#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct{
int id;
char paises[50];
int recuperados;
int infectados;
int muertos;
}ePais;

ePais* pais_new();
ePais* pais_newParametros(char* idStr,char* paisesStr,char* recuperadosStr,char* infectadosStr,char* muertosStr);

int pais_setId(ePais* pais,int id);
int pais_getId(ePais* pais,int* id);

int pais_setPais(ePais* pais,char* nombre);
int pais_getPais(ePais* pais,char* nombre);

int pais_setRecuperados(ePais* pais,int recuperados);
int pais_getRecuperados(ePais* pais,int* recuperados);
int pais_getRecuperadosRandom();
int pais_RecuperadosRandomSet(void* recu);

int pais_setInfectados(ePais* pais,int infectados);
int pais_getInfectados(ePais* pais,int* infectados);
int pais_getInfectadosRandom();
int pais_InfectadosRandomSet(void* infec);

int pais_setMuertos(ePais* pais,int muertos);
int pais_getMuertos(ePais* pais,int* muertos);
int pais_getMuertosRandom();
int pais_MuertosRandomSet(void* muertos);

int pais_sortInfectados(void* pA, void* pB);
int pais_sortMuertos(void* pA, void* pB);

int parser_InfectadosFromText(FILE* pFile , LinkedList* pArrayListPais);

int paises_filterExitosos(void* pais);

#endif // PAIS_H_INCLUDED



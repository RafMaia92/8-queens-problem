#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define MAXPILHA 8

struct tpinfo
{
       int x, y;       
};

struct TpPilha
{
    int topo;    
    tpinfo vet[MAXPILHA];
};
void inicializa(TpPilha &p)
{
    p.topo=-1;
}

bool pilhavazia(int t)
{
  return (t==-1);    
}
bool pilhacheia(int t)
{
  return (t==MAXPILHA-1);
}
void insere(TpPilha &p,tpinfo el)
{
    p.vet[++p.topo]=el;
}


tpinfo retira(TpPilha &p)
{
    tpinfo aux=p.vet[p.topo--];
    return aux;
}
tpinfo eltopo(TpPilha p)
{
    return p.vet[p.topo];
}

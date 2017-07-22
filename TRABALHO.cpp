#include "aux_pilha.h"
#include "INTERFACE.h"
bool insere_primeira(TpPilha &p)
{     
    tpinfo elem; 
    gotoxy(69, 20);printf(" ");
    gotoxy(57, 20);printf(" ");
    gotoxy(48, 19);  
    printf("Digite a Posicao");    
    gotoxy(48, 20);  
    printf("Pos. X:  ");scanf("%d",&elem.x);
    gotoxy(60, 20); 
    printf("Pos. Y:  ");scanf("%d",&elem.y);       
    if(elem.x >0 && elem.x <=8 && elem.x >0 && elem.y <=8)
    {     insere(p,elem);   
          return true;
     }
    return false;
        
}

bool retorna_disponiveis(TpPilha p, tpinfo disp[], int &cont)
{
     tpinfo el;
     int x,y,i=0;
     int auxX,auxY;
       cont=0;
        el = retira(p);
        for(x=1;x<=8;x++)      
           for(y=1;y<=8;y++)
           {       
               auxX = abs(el.x -x);          
               auxY = abs(el.y -y);          
                 if(auxY != auxX )
                   if(el.x != x)
                     if(el.y != y)              
                     {   
                         disp[cont].x = x;
                         disp[cont].y = y;
                         cont++;                           
                     }      
                                   
           }  
                  
        while(!pilhavazia(p.topo)) 
        {   
            el = retira(p);           
            for(i=0; i<cont; i++)
            {
               auxX = abs(el.x - disp[i].x);          
               auxY = abs(el.y - disp[i].y);          
                 if(auxY == auxX || disp[i].x == el.x || disp[i].y == el.y)                                           
                 {
                     for(int r=i; r<cont-1; r++)                     
                       disp[r] = disp[r+1];                       
                     cont--;
                     i--;
                 }
                     
            }     
      }   
      if(cont > 0)
         return true;
      
      cont=0;
      return false;  
}
void faz_bagaca_toda(TpPilha p)
{
     bool ganhou;
     int tp_p,pos[8],tl_c; // tl_c contador  de possibilidades
     tpinfo vdisp[64];  // tp_p controlador do topo
  
     ganhou=false;
     tp_p = 0;
     pos[tp_p] = 0; int cvr=0;
     
     retorna_disponiveis(p,vdisp,tl_c);
     insere(p,vdisp[pos[tp_p]]);
     while(pos[0]<=tl_c && !ganhou)
     {
          while(pos[tp_p]<tl_c && !ganhou)
          {
               if(retorna_disponiveis(p,vdisp,tl_c))
               {
                   tp_p++;                                   
                   pos[tp_p]=0;
                   insere(p,vdisp[pos[tp_p]]);
               }
               else
               {
                   if(!pilhacheia(p.topo))
                   {
                       retira(p);
                       retorna_disponiveis(p,vdisp,tl_c);
                       pos[tp_p]++;                   
                       while(pos[tp_p]>=tl_c)
                       {
                            tp_p--;                 
                            retira(p);
                            retorna_disponiveis(p,vdisp,tl_c);
                            pos[tp_p]++;                   
                       }
                       insere(p,vdisp[pos[tp_p]]);
                      
                   }
                   else
                   {
                       ganhou=true;
                       exibe_pilha(p);
                       getch();
                       
                   } cvr++;
                   gotoxy(64,14);
                   printf("Tentativas");
                   gotoxy(67,15);
                   printf("%d",cvr);
               }
          }        
     }
}

main()
{
      TpPilha p;
      
      constroi_a_bagaca();
      inicializa(p);
      while(insere_primeira(p)) 
      {
       faz_bagaca_toda(p);
       constroi_a_bagaca();
       inicializa(p);
      }     
      clrscr();             
      gotoxy(29,12);       
      printf("DIGITA ESSA PORRA CERTA");
      getch();
}

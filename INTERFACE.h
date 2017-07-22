void desenhaXY(char c,int cor, int x, int y)
{   gotoxy(x,y); textcolor(cor); printf("%c",c);
 }
void casas_brancas(int ch,int cor,int x, int y)
{
     int xi=0, yi=0;    
     while(xi<=4)
     {   desenhaXY(ch,cor,x+xi,y);  xi++; 
       }    
     xi=0; 
     while(xi<=4)
     {   desenhaXY(ch,cor,x+xi,y+1);  xi++;   }  
     xi=0; 
     while(xi<=4)
     {   desenhaXY(ch,cor,x+xi,y+2);  xi++;   }  
   
}
void bordas_tabuleiro()
{
       
     int x=1,y=0,n;
     int cor =9;
     while(y<26) // desenha Borda y
     { 
       desenhaXY(178,cor,43,++y); 
       desenhaXY(178,cor,1,y);
       desenhaXY(178,cor,44,y); 
       desenhaXY(178,cor,2,y);       
     }
     while(x<43) // desenha Borda y
     {     
      desenhaXY(178,cor,++x,1); 
      desenhaXY(178,cor,x,26);
     }
}
int CPY(int y)
{
    y = (y+y)+(y-1);
    return y;
}
int CPX(int x)
{
    x = (x+x)+ ((x-1)*3) +1;
    return x;
}
// essas duas funcoes calculam onde será posta as rainhas ( graficamente ) 
void exibe_pilha(TpPilha p)
{
     tpinfo ele;
     int x=0, py, px;   
     textcolor(15);
     while(!pilhavazia(p.topo))
     { 
         textcolor(15);
         ele=retira(p);
         gotoxy(50,10+x); printf("| %d |",ele.x); 
         gotoxy(57,10+x); printf("| %d |",ele.y);  
         px = CPX(ele.x);
         py = CPY(ele.y);
         casas_brancas(206,12,px,py);      
         x++;         
     } 
}
void informacoes()
{
     int x=1,y=0,n;
     int cor =9;
      x = 44;
     while(x<80) // desenha Borda y
     {      
      desenhaXY(178,cor,++x,1); 
      desenhaXY(178,cor,x,26);
     }
     while(y<26)
     desenhaXY(178,cor,80,++y);      
     textcolor(15);
     gotoxy(49,2);
     printf("Trabalho Bimestral de ED1 ");
     gotoxy(47,3);
     printf("Problema das 8 Rainhas - PILHA");     
     gotoxy(50,7); printf("  Posicoes");
     gotoxy(50,8); printf("  X  ");
     gotoxy(57,8); printf("  Y  ");
     gotoxy(49,9); printf("______________");            
     gotoxy(49,24);
     printf("Desenvolvido por:");
     gotoxy(47,25);
     printf("Rafael Maia");    
}

void constroi_a_bagaca()
{
  int yi=2, xi=3, cor1=1, cor2=15,ch=178;
 bordas_tabuleiro(); 
 informacoes();
  while(yi<=23)
  {
     while(xi<=38)
     {
        casas_brancas(ch,cor1,xi,yi); _sleep(20); 
        casas_brancas(ch,cor1,xi+5,yi+3); _sleep(20);
        casas_brancas(ch,cor2,xi+5,yi);  _sleep(20);
        casas_brancas(ch,cor2,xi,yi+3); _sleep(20);                  
        xi+=10;                    
     }  
     xi=3;            
   yi+=6;         
  }
 
}



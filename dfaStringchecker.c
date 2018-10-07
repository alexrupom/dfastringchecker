#include<stdio.h>
#include<conio.h>

int inputNum;
int dfa[10][10];
char c[10], string[10];
int nstates, nfinals;
int f[10];
int i,j,s=0,final=0;

int check(char,int );
int check(char b,int d)
{
     int j;
     for(j=0; j<inputNum; j++)
     if(b==c[j])
     return(dfa[d][j]);
     return -1;
}


int main()
{

     printf("number of state in dfa \n");
     scanf("%d",&nstates);
     printf("number of symbols in dfa \n");
     scanf("%d",&inputNum);
     printf("\nenter input symbols\t");

     for(i=0; i<inputNum; i++)
     {
           printf("\n\n %d input\t", i+1);
           printf("%c",c[i]=getch());
     }

     printf("\n\number of final states\t");
     scanf("%d",&nfinals);

     for(i=0;i<nfinals;i++)
     {
          printf("\n\nFinal state %d : q",i+1);
          scanf("%d",&f[i]);
     }


     printf("\n\(initial state, input symbol ) = final state\n");

     for(i=0; i<inputNum; i++)
     {
          for(j=0; j<nstates; j++)
          {
               printf("\n(q%d , %c ) = q",j,c[i]);
               scanf("%d",&dfa[i][j]);
          }
     }

     do
     {
          i=0;
          printf("\n\input string ");
          scanf("%s",string);

          while(string[i]!='\0')
          if((s=check(string[i++],s))<0)
          break;
          for(i=0 ;i<nfinals ;i++)
          if(f[i] ==s )
          final=1;
          if(final==1)
          printf("\n valid string");
          else
          printf("invalid string");
          getch();

          printf("\nDo you want to continue.?  \n(y/n) ");
     }
     while(getch()=='y');

     getch();
}

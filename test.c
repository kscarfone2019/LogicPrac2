#include<stdio.h>
int fun(int a)
{
int r=1;
while(a--)
{
 r*= 2;
}
return r;
}



int main()
{
int i,ch,j,n,or=0,mask,and,xor,xnor,nand;
printf("enter the value of n\n");
scanf("%d",&n);
printf("enter ur choice 1 for Or gate 2 for and gate 3 for xor 4 for xnor 5 for nand\n");
scanf("%d",&ch);
switch(ch)
 {
 case 1: for(i=0;i<=fun(n)-1;i++)
 {
 for(j=n-1;j>=0;j--)
 {
 mask=i>>j;
 printf("%d\t", mask & 1);
 or=or |(mask & 1);
 }
 printf("%d\n",or);
 }
 break;
 case 2 : for(i=0;i<=fun(n)-1;i++)
 {and=1;
 for(j=n-1;j>=0;j--)
 {
 mask=i>>j;
 printf("%dh\t",mask & 1);

 and=and &(mask & 1);
 }

 printf("%d\n", and);
 }
 break;
 case 3: for(i=0;i<=fun(n)-1;i++)
 {xor=0;
 for(j=n-1;j>=0;j--)
 {
 mask=i>>j;
 printf("%d\t",mask & 1);
 xor=xor ^(mask & 1);
 }
 printf("%d\n",xor);
 }
 break;
case 4:for(i=0;i<=fun(n)-1;i++)
 {xnor=1;
 for(j=n-1;j>=0;j--)
 {
 mask=i>>j;
 printf("%d\t",mask & 1);
 xnor=xnor ^(mask & 1);
 }
 printf("%d\n",xnor);
 }
 break;
case 5:for(i=0;i<=fun(n)-1;i++)
 {nand=1;
 for(j=n-1;j>=0;j--)
 {
 mask=i>>j;
 printf("%d\t",mask & 1);
 nand=nand &(mask & 1);
 }nand=!nand;
 printf("%d\n",nand);
 }
 break;

default:printf("wrong input\n");break;

 }
}

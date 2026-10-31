#include <stdio.h>
int main()
{
    int key[56],l[28],r[28],i,j,shift[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    printf("Enter 56-bit key:\n");
    for(i=0;i<56;i++)scanf("%d",&key[i]);
    for(i=0;i<28;i++)l[i]=key[i],r[i]=key[i+28];
    for(i=0;i<16;i++)
    {
        for(j=0;j<shift[i];j++)
        {
            int x=l[0],y=r[0];
            for(int k=0;k<27;k++)l[k]=l[k+1],r[k]=r[k+1];
            l[27]=x;r[27]=y;
        }
        printf("Round %d: ",i+1);
        for(j=0;j<28;j++)printf("%d",l[j]);
        for(j=0;j<28;j++)printf("%d",r[j]);
        printf("\n");
    }
}
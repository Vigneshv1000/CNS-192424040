#include <stdio.h>
int main()
{
    int p[16]={0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1};
    int iv[8]={1,0,1,0,1,0,1,0};
    int key[10]={0,1,1,1,1,1,1,1,0,1};
    int c[16],d[16],i;
    printf("CBC Encryption:\n");
    for(i=0;i<16;i++)
    {
        c[i]=p[i]^iv[i%8]^key[i%10];
        iv[i%8]=c[i];
        printf("%d",c[i]);
    }
    for(i=0;i<8;i++)iv[i]=(i%2==0);
    printf("\nCBC Decryption:\n");
    for(i=0;i<16;i++)
    {
        d[i]=c[i]^key[i%10]^iv[i%8];
        iv[i%8]=c[i];
        printf("%d",d[i]);
    }
}
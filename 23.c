#include <stdio.h>
int main()
{
    int p[24]={0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0};
    int key[10]={0,1,1,1,1,1,1,1,0,1};
    int c[24],i;
    printf("CTR Encryption:\n");
    for(i=0;i<24;i++)
    {
        c[i]=p[i]^key[i%10]^((i/8)&1);
        printf("%d",c[i]);
    }
    printf("\nCTR Decryption:\n");
    for(i=0;i<24;i++)
        printf("%d",c[i]^key[i%10]^((i/8)&1));
}
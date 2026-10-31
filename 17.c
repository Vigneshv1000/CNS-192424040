#include <stdio.h>
int main()
{
    int shift[]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    int key[16][48],i,j;
    printf("Enter 16 DES subkeys (48 bits each):\n");
    for(i=0;i<16;i++)
        for(j=0;j<48;j++)
            scanf("%d",&key[i][j]);
    printf("Decryption key order:\n");
    for(i=15;i>=0;i--)
    {
        printf("K%d: ",16-i);
        for(j=0;j<48;j++)printf("%d",key[i][j]);
        printf("\n");
    }
    return 0;
}
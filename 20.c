#include <stdio.h>
int main()
{
    int p[4],c[4],iv=10,k=7,i;
    printf("Enter plaintext blocks:\n");
    for(i=0;i<4;i++)scanf("%d",&p[i]);
    for(i=0;i<4;i++)
    {
        c[i]=p[i]^k^iv;
        iv=c[i];
    }
    printf("CBC Ciphertext:\n");
    for(i=0;i<4;i++)printf("%d ",c[i]);
    printf("\nError in C1 affects P1 and P2 only.");
    printf("\nError in P1 affects all subsequent CBC ciphertext blocks.");
}
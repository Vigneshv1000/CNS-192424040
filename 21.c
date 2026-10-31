#include <stdio.h>
int main()
{
    int p[20],n,i;
    printf("Enter number of bits: ");
    scanf("%d",&n);
    printf("Enter bits:\n");
    for(i=0;i<n;i++)scanf("%d",&p[i]);
    p[n++]=1;
    while(n%8)p[n++]=0;
    printf("Padded data:\n");
    for(i=0;i<n;i++)printf("%d",p[i]);
    printf("\nPadding identifies the original message length.");
}
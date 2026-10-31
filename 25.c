#include <stdio.h>
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    int n,e,m,g;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter public exponent e: ");
    scanf("%d",&e);
    printf("Enter plaintext block: ");
    scanf("%d",&m);
    g=gcd(n,m);
    if(g>1&&g<n)
    {
        printf("Common factor = %d\n",g);
        printf("Other factor = %d\n",n/g);
        printf("RSA modulus is factored!\n");
    }
    else if(g==n)
        printf("Plaintext is a multiple of n.\n");
    else
        printf("No common factor found.\n");
    return 0;
}
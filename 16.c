#include <stdio.h>
#include <string.h>
int main()
{
    char s[500],p[500];
    int f[26]={0},used[26]={0},map[26],i,j,n;
    printf("Enter ciphertext: ");
    scanf(" %[^\n]",s);
    printf("Enter top number: ");
    scanf("%d",&n);
    for(i=0;s[i];i++)
        if(s[i]>='A'&&s[i]<='Z')f[s[i]-'A']++;
    for(i=0;i<26;i++)
    {
        int max=-1,x=0;
        for(j=0;j<26;j++)
            if(!used[j]&&f[j]>max)max=f[j],x=j;
        used[x]=1;
        map[x]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;s[j];j++)
            p[j]=(s[j]>='A'&&s[j]<='Z')?map[s[j]-'A']+'A':s[j];
        p[j]='\0';
        printf("%s\n",p);
        for(j=0;j<26;j++)map[j]=(map[j]+1)%26;
    }
}
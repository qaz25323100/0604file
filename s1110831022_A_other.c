#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
FILE *fp;
void main(void)
{
	int x[26]={0};
	int i;
	int n[i];
	srand((unsigned) time (NULL));
	for(i=1;i<=26;i++)
	{
		x[i]=rand()%11111+1;
		printf("%d\n",x[i]);
	}
    
    if((fp=fopen("1110831022.dat","ab"))==NULL)
	{
		printf("Error!\n");
		exit(0);
	}
	i=fwrite(&x[i],sizeof(int),26,fp);
	fclose(fp);
}

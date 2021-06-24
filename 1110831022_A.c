#include<stdio.h> 
#include<stdlib.h> 


void main(void)
{
	int x[26]={0};
	int i;
	int n[i];
	
	for(i=1;i<=26;i++)
	{
		x[i-1]=rand()%11111+1;
		printf("%d\n",x[i-1]);
	}
    FILE *fp;
   char str[] = "This is gitbook.net";

   fp = fopen( "file.txt" , "w" );
   fwrite(str , 1 , sizeof(str) , fp );

   fclose(fp);
  
   return(0);
}

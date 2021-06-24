#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDOM_START 1
#define RANDOM_END 11111
int main()
{  /*
        int i=0,arr[26];
        FILE *fp;
        char *a;

        fp = fopen("1110831022_C.dat","a");
        srand( time(NULL));
        for(i=0;i<26;i++)
		{
               
                int x = (rand()% RANDOM_END)+ 1;
                //fprintf(fp, "%d ",x);
                arr[i]=x;
                
        }
        fwrite(arr,sizeof(int),26,fp);
*/
      
        FILE *fp;
        fp =fopen("1110831022_C.dat","r");

        int ch;

        while(!feof(fp))
		{
                fread(&ch, sizeof(int), 1, fp);
                printf("%d\n ",ch);
        }
        
        fclose(fp);
 
        return 0;
		
        
       
}

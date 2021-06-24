#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#define RANDOM_START 1
#define RANDOM_END 11111

using namespace std;

int main(){
        /*
        int i=0,arr[26];
        FILE *fp;
        char *a;
        //fstream file;
        const char* FILENAM = "123.dat";

        //file = fstream("123.dat", ios::app  | ios::binary);
        ofstream o(FILENAM,ios::binary);
        srand( time(NULL));
        for(int i=0;i<26;i++){
                int x = (rand()% RANDOM_END)+ RANDOM_START;
                o.write((char *)&x,sizeof(int));
        }
        o.close();*/

        const char* FILENAM = "123.dat";
        ifstream i(FILENAM,ios::binary);

        int ch,max=-1,min=11112;
        int sz = i.tellg(); // Get File size
        printf("Bytes: %d\n",sz);
        printf("Numbers: %ld\n",sz/sizeof(int)); // Numbers in File

        while(1){
                i.read((char*)&ch,sizeof(int));
                if(i.eof()) break;
                if(ch>max) max =ch;
                if(ch<min) min= ch;
                printf("%d ",ch);
        }

        printf("\nMinimum: %5d",min);
        printf("\nMaximum: %5d\n",max);
        i.close();

}

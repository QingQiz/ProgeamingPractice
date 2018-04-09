#include <stdio.h>
int main()
{
    char GET[50],PUT[60];
    int cont=0;
    FILE *in,*out;
    in=fopen("DATA5612.CPP","r");
    if(in!=NULL){
        out=fopen("DATA5612.TXT","w");
        while(!(feof(in))){
            if(fgets(GET,sizeof(GET)-1,in)==NULL)continue;
            sprintf(PUT,"%04d %s",++cont,GET);
            fputs(PUT,out);
        }
        fclose(in);
        fclose(out);
    }
    return 0;
}
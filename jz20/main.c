#include <stdio.h>
#define bool char
#define true 1
#define false 0

bool isNumber(char* s){
    char faftere=0,fdot=0,fsymbol=0,fsymbolaftere=0,fspace=0,fhas=0,chr=0;
    int size1=0,size2=0;
    while(*s != '\0')
    {
        chr = *s;
        if(chr >= '0' && chr <= '9' )
        {
            fhas = 1;
            if(fspace == 1)
                return false;
            if(faftere == 1)
                size2++;
            else 
                size1++;
        }
        else if(chr == 'e' || chr == 'E')
        {
            fhas = 1;
            if(fspace == 1)
                return false;
            if(faftere == 1 || size1 == 0)
                return false;
            faftere = 1;
        }
        else if(chr == '.')
        {
            fhas = 1;
            if(fspace == 1)
                return false;
            if(fdot == 1 || faftere == 1)
                return false;
            else
                fdot = 1;
        }
        else if(chr == '+' || chr == '-')
        {
            fhas = 1;
            if(faftere == 0 && fdot == 1)
                return false;
            if(fspace == 1)
                return false;
            if(faftere==0)//
                if(fsymbol == 1 || size1 != 0)
                    return false;
                else
                    fsymbol = 1;
            else//
                if(fsymbolaftere == 1 || size2 != 0)
                    return false;
                else    
                    fsymbolaftere = 1;
        }
        else if(chr == ' ')
        {
            if(fhas == 1)
                fspace = 1;
        }
        else
            return false;

        s++;
    }

    if(faftere == 1 && size2 == 0)
        return false;
    if(size1 == 0 )
        return false;
    return true;
}

 int main()
 {
 	char *s = "1 .";
 	
 	if(isNumber(s))
 		printf("true\n");
	else
		printf("flase\n");
 	
 	
 	
 	return 0;
 }

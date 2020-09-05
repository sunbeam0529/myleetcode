#include <stdio.h> 

int mypow(int num)
{
    int val=1;
    while(num > 0)
    {
        val *= num;
        num--;
    }
    return val;
}
char * getPermutation(int n, int k){
    char * str,*numbuf;
    int i,j,numNo,numSel;
    str = (char *)malloc((n+1)*sizeof(char));
    numbuf = (char *)malloc((n)*sizeof(char));
    str[n] = '\0';
    for(i=0;i<n;i++)
    {
        numbuf[i] = '1'+i;
    }
    k--;
    for(numNo=0;numNo<n;numNo++)
    {
        numSel = k/mypow(n-numNo-1);
        for(i=0,j=0;i<n;i++)
        {
            if(numbuf[i] == 0)continue;

            if(j == numSel)
            {
                str[numNo] = numbuf[i];
                numbuf[i] = 0;
                break;
            }
            else
            {
                j++;
            }
        }
        k %= mypow(n-numNo-1);
    }
    return str;
}

int main()
{
	printf("%s",getPermutation(3,3));
	
	return 0;
}

#include <stdio.h>

int min(int a,int b)
{
	if(a > b)
		return b;

	return a;
}

int pick(int *arr,int size,int buf1,int buf2,int persion)
{
	int i,sum=0,val;
    if(size==0)
    	return arr[0];
	
	for(i=0;i<size;i++)
		sum+=arr[i];
	
	val = sum - min(pick(arr,size-1,buf1,buf2,1),pick(arr+1,size-1,buf1,buf2,1));
    return val;

}

unsigned char PredictTheWinner(int* nums, int numsSize){
	int i1=0,sum1=0,val=0;
    for(i1=0;i1<numsSize;i1++)
    {
    	sum1+=nums[i1];
	}
	val = pick(nums,numsSize,0,0,1);
	//printf("val=%d,sum=%d\n",val,sum1);
	if(val > sum1-val)
		return 1;

    return 0;
}

 
int main(void)
{
    int numarr[]={1, 5, 233, 7};
    
    if(PredictTheWinner(numarr,4))
        printf("win\n");
    else
    {
        printf("lose\n");
    }
    
    return 0;
}

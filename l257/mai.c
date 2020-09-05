#include <stdio.h>
#include <stdlib.h> 

//#define NULL 0
#define null 0

struct  TreeNode{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
 
int calcnum(struct TreeNode* node)
{
    int retval=0;
    if(node->left != NULL )
    {
        retval += calcnum(node->left);
    }
    if( node->right != NULL)
    {
        retval += calcnum(node->right);
    }
    if(node->left == NULL && node->right == NULL)
        return 1;

    return retval;
}

void func(struct TreeNode* node,int deep,char ** bt,int *pointer,char * str)
{
    int numlen=0,lentemp=0,valtemp,i,strlen=0;
    char * strbuf,*numbuf,*p;
    if(node->val < 0)
    {
    	valtemp = -(node->val);
	}
	else
	{
		valtemp =  (node->val);
	}
	numlen = 1;
	while(valtemp/10!=0)
	{
		numlen++;
		valtemp/=10;
	}
	numbuf = (char *)malloc(numlen*sizeof(char));
	if(node->val < 0)
    {
    	valtemp = -(node->val);
	}
	else
	{
		valtemp =  (node->val);
	}
	i=numlen-1;
	do
	{
		numbuf[i] = valtemp%10+'0';
		i = i-1; 
		valtemp /= 10;
	}while(i>=0);
	p = str;
	while(*p!='\0')
	{
		p++;
		strlen++;
	}
    strbuf = (char *)malloc((strlen+numlen)*sizeof(char));
    if(deep != 0)
    {
        for(lentemp=0;lentemp<(strlen);lentemp++)
        {
            strbuf[lentemp] = str[lentemp];
        }
        strbuf[lentemp++] = '-';
        strbuf[lentemp++] = '>';
    }
    if(node->val < 0)
    strbuf[lentemp++] = '-';
    for(i=0;i<numlen;i++)
    strbuf[lentemp++] = numbuf[i];
    free(numbuf);
    //strbuf[lentemp++] = '0'+node->val;
    strbuf[lentemp++] = '\0';
    if(node->left != NULL )
    {
        func(node->left,deep+1,bt,pointer,strbuf);
        //free(strbuf);
    }
    if( node->right != NULL)
    {
        func(node->right,deep+1,bt,pointer,strbuf);
        //free(strbuf);
    }
    
    if(node->left == NULL && node->right == NULL)
    {
        bt[*pointer] = strbuf;
        (*pointer)++;
    }
    else
    {
    	free(strbuf);
	}
    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    char ** temp;
    int num,pointer;
    if(root == NULL)
    {
        *returnSize = 0;
        return 0;
    }
        
    num = calcnum(root);
    pointer = 0;
    temp = (char ** )malloc(num*sizeof(char*));
    *returnSize = num;
    func(root,0,temp,&pointer,"");
    return temp;
}

int main()
{
	char **output;
	int len,i;
	struct  TreeNode root,l,r,lr;
	root.val = 11;
	l.val = -22;
	r.val = -33;
	lr.val = 55;
	root.left = &l;
	root.right = &r;
	l.left = null;
	l.right = &lr;
	r.left = null;
	r.right = null;
	lr.left = null;
	lr.right = null;
	output = binaryTreePaths(&root,&len);
	for(i=0;i<len;i++)
	{
		printf("%s\n",output[i]);
	}
	
	return 0;
}

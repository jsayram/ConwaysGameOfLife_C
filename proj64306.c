/* Project #6
  EGRE245 Spring 2014
  Jose Ramirez */

#include <stdio.h>
#include <math.h>

#define MAX 100

int main (void)
{
	printf("Proj. #6 - Jose Ramirez\n\n");
     
	 char a[MAX]={0};
	 char a_int[MAX]={0};
	 char a_inta[MAX]={0};
	 
	 char b[MAX]={0};
	 char b_int[MAX]={0};
	 char b_intb[MAX]={0};
	 
	 char sum[MAX]={0};
	 char fsum[MAX]={0};
	 
	 int i1=0;
	 int i2=0;
	 char c1=0;
	 char c2=0;
	 int j1=0;
	 int j2=0;


	int count1=0;
	int count2=0;
	int count3=0;

//***Operand #1****
  printf("Operand #1: ");	 
	while((c1=getchar())!='\n')
	{   
	  
	   a[i1]=c1-48;
	   count1++;
	   i1++;
	  
	}
	if(count1>MAX)
	{
	   printf("[ERROR] OVERFLOW");
	   return 0;
	}
  printf("Values Entered: " );
  for (j1=0;j1<count1;j1++)
	{
	   printf("%d",a[j1]);
	}	
//***Operand #2
 printf("\nOperand #2: ");
  while((c2=getchar())!='\n')
	{   
	   
	   b[i2]=c2-48;
	   i2++;
	   count2++;
	   
	}
  if(count2>MAX)
	{
	   printf("[ERROR] OVERFLOW");
	   return 0;
	}
 printf("Values Entered: " );
  for (j2=0;j2<count2;j2++)
	{   
	   printf("%d",b[j2]);
	}	
 
 int countdiff=0;
if(count1>count2)
{
   count3=count1;
}
if(count2>count1)
{
   count3=count2;
} 
if(count2==count1)
{
   count3=count2+1;
}
 int inc;
 for ( inc = 0; inc < count3; inc++) 
 {
  a_int[inc] = a[count1-inc];
  }  
  int j;
 
 for ( inc = 0; inc < count3; inc++) 
 {
  b_int[inc] = b[count2-inc];
  }   
  j;
   
printf("\nAnswer =: ");

int carry=0;
int i=0;
int number1=0;

for(i = count3; i >0; i--) 
	{

		number1 = a_int[i] + b_int[i]+carry;
		if(number1>9)
		{
			
			carry = 1;
			number1= number1-10;
		}
		else
		{
			carry = 0;
		}
		sum[i] = number1;
	}
		
for ( inc = 0; inc < count3; inc++) 
  {
	fsum[inc] = sum[count3-inc];
  } 
  
int k;
	for( k=0; k < count3; k++)
	{
		printf("%d",fsum[k]);
	}
		
	
return 0;
	
}
/* Project #8
  EGRE245 Spring 2014
  Jose Ramirez */
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 'X'
#define FALSE ' '
#define ROWS 30
#define COLUMNS 70

int rows(FILE *dataFile);
int columns(FILE *dataFile);
int generations(FILE *dataFile);
void errorCheck(FILE *dataFile);
void secondNumbers(char array[][COLUMNS],int r , int c);
void populate(char array[][COLUMNS],int r, int c);
void cells(FILE *dataFile ,int r ,char array[][COLUMNS],int c);
void printTop(int c);
void printArray(char array[][COLUMNS],int r , int c);
void printBottom(int c);
int checkAround(char array[][COLUMNS],int row, int col);
void upDate(char array[][COLUMNS],int r, int c);
int limits(char array[][COLUMNS], int row, int col);
void loop(int oneLoop,int count,char array[][COLUMNS], int r , int c, int g ,char enter);
void swap(char array[][COLUMNS],char array2[][COLUMNS],int r, int c);

int main (void)
{  
  printf("\nProj. #8 - Jose Ramirez\n\n");
  char array[ROWS][COLUMNS];
  int r,c,g;
  int count=2;
  char enter='a';
  int oneLoop=0;
  FILE *dataFile; 
  char dFile[20];  
  printf("Data File Name: ");
  scanf("%s",dFile);
  dataFile = fopen(dFile,"r");
  errorCheck(dataFile); 
  
  printf("Number of Rows: %9d",r=rows(dataFile));
  printf("\nNumber of Columns: %6d",c=columns(dataFile));
  printf("\nNumber of Generations: %2d\n\n",g=generations(dataFile));
  cells(dataFile,r,array,c);
  loop(oneLoop,count,array,r,c,g,enter);

return 0; 
}
void loop(int oneLoop,int count, char array[][COLUMNS], int r , int c,int g, char enter)
{    int g1=g;
   while(((enter=getchar()=='\n') && count!=g+1)|| g1==1)
   { 
     if(oneLoop==0 )
	 {  oneLoop++;
	    printf("\nGeneration %d\n", oneLoop);printf("-------------\n");
  	    secondNumbers(array,r,c);
		printArray(array,r,c);
		secondNumbers(array,r,c);
	    printf("\n(Press Enter To continue)");
		
	 }
	 else
	 { 
     	 printf("\nGeneration %d\n", count);
	     printf("-------------\n");
      upDate(array,r,c);
      secondNumbers(array,r,c);
	  printArray(array,r,c);
	  secondNumbers(array,r,c);
	  count++;
	  printf("\n(Press Enter To continue)");
	  }
      g1++;
  }
   if(count>g){printf("\nGeneration Limit,\nThanks For Playing The Game Of Life!!, GOODBYE!!\n");}	
}
void errorCheck(FILE *dataFile)
{  
   if (dataFile == NULL) 
    {
       printf("\n[ERROR]- That file does not exist,\nPlease input a different data file. \n");
	   main();
	   exit(0);
    }
} 
int rows(FILE *dataFile)
{ 
    int rows=0;
   fscanf(dataFile,"%d",&rows);
   if(rows >=3 && rows <=20)
    {
       return rows;
	}
   else
	{
	   printf("\n[Error]-( %d ) ROWS OUTSIDE OF LEGAL RANGE,\nRows must be >=3 and <=20\nPlease input a different file.\n",rows);
	  main();
	  exit(0);
	}
}
int columns(FILE *dataFile)
{  
   int columns=0;
    fscanf(dataFile,"%d",&columns);
    if(columns >=3 && columns <=60)
    {
       return columns;
	}
	else
	{
	  printf("\n[Error]-( %d )Columns OUTSIDE OF LEGAL RANGE,Please input a different file.\n",columns);
	  main();
	  exit(0);
	}
}   
int generations(FILE *dataFile)
{  
    int generations=0;
    fscanf(dataFile,"%d",&generations);
    if(generations >=1 && generations <=100)
      {
        return generations;
	  }
	else
	 {
	   printf("\n[Error]- ( %d )GENERATIONS is OUTSIDE OF LEGAL RANGE,\nPlease fix or input a different data file.\n",generations);
	   main();
	   exit(0);
	 }
}  

void populate(char array[][COLUMNS],int r, int c)  // this populates the array with all false cells wich are replaced with true cells in design
{     int count1,count2;
     for(count1=1;count1<=r;count1++)         //populates 2 dimentional array
     { 
	   for(count2=1;count2<=c;count2++)
            {  
			   array[count1][count2]=FALSE;
		    }
	 }
}
void cells(FILE *dataFile ,int r ,char array[][COLUMNS],int c)    //this populates the cells in the array that are going to be the organism
{   int p1,p2;
      populate(array,r,c);
    while(p1 >0)
	    {    fscanf(dataFile,"%d%d",&p1,&p2);
	     if((p1 >=1 && p1 <=r) && (p2 >=1 && p2 <=c) || (p1==0 && p2==0))
            {   
              array[p1][p2]=TRUE;
	        }	 
           else 
	         {
      			  printf("\n[Error]-COORDINATE [Row %d, column %d] OUTSIDE OF LEGAL RANGE,\nPlease Fix or input a different data file.\n",p1,p2);
	              main();
				  exit(0);
			 }	
		 }
}
void secondNumbers(char array[][COLUMNS],int r , int c)  //this is the bottom border
{    int count1;int count2=1;
       printf("   ");
       for(count1=0; count1<=c;count1++)
	   {   
       		  if(count1%10 ==1 && c>=10) 
		    	{
		          printf("%10d",count2++);
	            }	  
        }
      printf("\n");
}

void printArray(char array[][COLUMNS],int r , int c)   //this prints the cells in the array with side borders
{    int count1,count2,count3;	
	printTop(c);
	for(count1=1;count1<=r;count1++)
	 {     printf("%2d",count1);
		   printf("|");    
	     for(count2=1;count2<=c;count2++)
	      { 
      		  printf("%c",array[count1][count2]);	 
		  }
		  printf("|");
		  printf("%d",count1);
		  printf("\n");
	} 
	printBottom(c);
}
void printTop(int c)   //prints top border border
{   int count1;
	    printf("   ");
	  for(count1=1;count1<=c;count1++)
	    {     
            printf("%d",count1%10);
		}
			printf("\n"); 
			printf("  +");
	    for(count1=0;count1<c;count1++)
	     {  
		    printf("-");
		 }
		 printf("+");
		 printf("\n");
}
void printBottom(int c)  // prints bottom border
{    int count1;
      printf("  +");
	    for(count1=0;count1<c;count1++)
	     {
		   printf("-");
		 }
		   printf("+"); 
		   printf("\n");
		   printf("   ");
	  for(count1=1;count1<=c;count1++)
	    {
     	   printf("%d",count1%10);   
		}
		printf("\n");  

}

int limits(char array[][COLUMNS], int r, int c)
 {       int rowLimit=r;
         int columLimit=c;
		 
	if (r < 1 || r > rowLimit || c < 1 || c > columLimit || array[r][c] != TRUE)
	{ 
		return FALSE;
	} 
	else
	{
		return TRUE;
	}
}
int checkAround(char array[][COLUMNS],int r, int c)
{    int nextTo = 0;
    if(limits(array, r - 1, c - 1)==TRUE)
    nextTo++;	
	if(limits(array, r - 1, c)==TRUE)
	nextTo++;
	if(limits(array, r - 1, c + 1)==TRUE)
	nextTo++;
	if(limits(array, r, c - 1)==TRUE)
	nextTo++;
	if(limits(array, r, c + 1)==TRUE)
	nextTo++;
	if(limits(array, r + 1, c - 1)==TRUE)
	nextTo++;
	if(limits(array, r + 1, c)==TRUE)
	nextTo++;
	if(limits(array, r + 1, c + 1)==TRUE)
	nextTo++;
  return nextTo;
}
void upDate(char array[][COLUMNS],int r, int c)
{  
	char array2[ROWS][COLUMNS];int nextTo, count1, count2;int r1=r;int c1=c;
	for (count1 = 0; count1 <= r1; count1++) 
	{ for (count2 = 0; count2 <=c1; count2++)
		{  nextTo = checkAround(array, count1, count2);
		    //printf("Neighbor: %d\n",nextTo);
			if (nextTo==3) 
			{
			  array2[count1][count2] = TRUE;
			}
			else if (nextTo == 2 && array[count1][count2] == TRUE) 
			{
			  array2[count1][count2] = TRUE;
			} 
			else
			{
			  array2[count1][count2] = FALSE;
			}
		}
	}
	  swap(array,array2,r,c);
}
void swap(char array[][COLUMNS],char array2[][COLUMNS],int r, int c)
{    
	int count1,count2;
   	for (count1 = 1; count1 <= r; count1++)
	{
		for (count2 = 1; count2 <= c; count2++)
		{
			array[count1][count2] = array2[count1][count2];
		}
	}
}








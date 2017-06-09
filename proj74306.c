/* Project #7
  EGRE245 Spring 2014
  Jose Ramirez */
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5000000
int main (void)
{   printf("Proj. #7 - Jose Ramirez\n\n");

  FILE *ppmFile;
  char Image[20]; 
  printf("Image Name: ");
  scanf("%s",Image);
  ppmFile = fopen(Image,"r");
  
  if (ppmFile == NULL) 
  {
    printf("[ERROR]- File %s does not exist!\n",Image);
  }
  else 
  {
    char magic[3];
	int width=0;
	int height=0;
	int colVal=0;
	//Scans Magic number
	printf("Magic Number  = ");
    fscanf(ppmFile,"%s",magic);
    printf("%s\n",magic);
	//scans height
	printf("Width, Height = ");
	fscanf(ppmFile,"%d",&width);
    printf("%d,",width);
	//scans width
	fscanf(ppmFile,"%d",&height);
    printf("%d\n",height);
    //scans color value 255
	printf("Color Val     = ");
	fscanf(ppmFile,"%d",&colVal);
    printf("%d\n",colVal);

	
	//scans integers one by one
	int num[height+1][width+1];
	//counters for arrays
	int count1=0;
	int count2=0;
	int count3=0;
	int count4=0;

	//rgb Tripplets
	int red=0;
	int green=0;
	int blue=0;	
	
	//initialize darkestValue
	int darkestValue=colVal*3;
   
   //total number of pints
	 int size=0;	
     size=width*height;
	 //checks if size of within boundaries of 500,000
	 if(MAX<size)
	 {
	     printf("[ERROR]- File (%s) has to many RGB points!\n",Image);
	     printf("You may have up to %d points, file has %d points,\nand it exceeds the limit. Sorry, Restart Program & input another file.\n[Exit Code: 793]",MAX,size);
	 }
	 else
	 {
	 printf("# Points      = %d\n",size);  
	 
    //scans rest of rgb triplets
	 for(count1=1;count1<height+1;count1++)
	   {
	      for(count2=1;count2<width+1;count2++)
		     {   fscanf(ppmFile, "%d %d %d", &red, &green, &blue);
				 num[count1][count2]=red+green+blue;	 
				 if(num[count1][count2]<darkestValue)
				 {
				    darkestValue=num[count1][count2];
				 }
			}
		}	
//printf("This is Darkest Value: %d\n",darkestValue);
printf("Darkest points of sky within 30.0%% of Darkest Point:\n");
	// Prints array with added rgb triplet values values 
    // coordinates of darkest points within 30% of darkest point 	
	for(count3=1;count3<height;count3++)
	{
	   for(count4=1;count4<width;count4++)
	   { 
	       
			if(num[count3][count4]<=rintf(darkestValue*(1.300)))
			{
			   printf("[%d,%d]",count3,count4);
			   }
		 
	   }
	}	
	printf("\n");
	fclose(ppmFile);
   }
  }
   return 0;
}
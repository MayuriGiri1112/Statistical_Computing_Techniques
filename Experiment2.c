//Program to calculate Mean, Median and Mode for discrete series

#include<stdio.h>

void Mean()
{
	int length, i;
    int x[10], f[10], fx[10];
	float sum_f=0, sum_fx=0, AM;
    
    printf("\nEnter the number : ");
    scanf("%d",&length);
    
    //Enter x
    printf("\nEnter values of x : ");
    for(i=0; i<length; i++)
    {
        scanf("%d",&x[i]);
    }
    
    //Enter frequencies (f)
    printf("\nEnter the frequencies : ");
    for(i=0; i<length; i++)
    {
        scanf("%d",&f[i]);
        sum_f += f[i];
    }
    
    //Calculate fx
    for(i=0; i<10; i++)
    {
        fx[i] = f[i] * x[i];
        sum_fx += fx[i];
    }
    
    //Print Data
    printf("\nData : ");
    printf("\n	x	|	f	|	fx");
    for(i=0; i<length; i++)
    {
    	printf("\n	%d	|	%d	|	%d", x[i], f[i], fx[i]);
	}
    
    //Arithmetic Mean of Discrete Series
    AM = sum_fx / sum_f;
    printf("\nArithmetic Mean of the Discrete Series is %0.2f\n",AM);
}

void Median()
{
	int i, j, temp, n, row, CF, c_f, c_x;
	int x[20], f[20], cf[20], sum_f=0;
    float term;

    printf("\nEnter the length : ");
    scanf("%d",&n);
    
    printf("\nEnter the values for x : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&x[i]);
    }

    printf("\nEnter the values for f : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&f[i]);
        sum_f += f[i];
    }

    //Sort the array x in ascending order
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(x[i] > x[j])
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
                
                temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }
        }
    }
    
    //Calculate cumulative frequency 
    cf[0] = f[0];
    for(i=0; i<n; i++)
    {
        cf[i+1] = f[i+1] + cf[i];
    }
    
    printf("\nData after sorting : ");
    printf("\n	x	|	f	|	CF");
    for(i=0; i<n; i++)
    {
    	printf("\n	%d	|	%d	|	%d", x[i], f[i], cf[i]);
	}
    
    //Calculate median
    term = (sum_f + 1)/2;
    printf("\nTerm : %0.2f",term);
	
	for(i=0; i<n; i++)
	{
		if(term>cf[i])
		{
			row = i;
			CF = cf[i+1];
			c_f = f[i+1];
			c_x = x[i+1];
		}
	}
	
	printf("\nCummulative frequency just greater than the term %0.2f : %d",term, CF);
	printf("\nCorresponding frequency : %d",c_f);
	printf("\nCorresponding value of x : %d",c_x);
	printf("\nHence, the median of the given data is %d",c_x);
}

void Mode()
{
	int n, i, j, x[i], f[i], mode=0, maxNum=0;
	
	printf("\nEnter the length : ");
    scanf("%d",&n);
    
    printf("\nEnter the values for x : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&x[i]);
    }

    printf("\nEnter the values for f : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&f[i]);
    }
    
    printf("\nData : ");
    printf("\n	x	|	f");
    for(i=0; i<n; i++)
    {
    	printf("\n	%d	|	%d", x[i], f[i]);
	}
	
	//Maximum value
	for(i=1; i<n; i++)
    {
    	if(f[i] > maxNum)
    	{
    		maxNum = f[i];
    		mode = x[i];
		}	
	}
	
	printf("\nIt is visible that variable %d has the highest frequency value of %d", mode, maxNum);
	printf("\nHence, the mode of the given data is %d", mode);
}

int main()
{
	int choice;
	printf("\n|---------------------------------------|");
	printf("\n|Mean, Median & Mode for discrete series|");
	printf("\n|---------------------------------------|");
	printf("\n|             1) Mean                   |");
	printf("\n|             2) Median                 |");
	printf("\n|             3) Mode                   |");
	printf("\n|             4) Exit                   |");
	printf("\n|---------------------------------------|");
    do
    {
    	printf("\nEnter the choice which operation you want to perform : ");
		scanf("%d",&choice);
    	switch(choice)
		{
			case 1:
	    		Mean();
	    		break;
	    	case 2:
	    		Median();
	    		break;
	    	case 3:
	    		Mode();
	    		break;
	    	case 4:
	    		printf("\nExit!!");
	    		break;
	    	default:
	    		printf("\nINVALID CHOICE! Please choose valid operation!");
	    		break;
		}
	}while(choice!=4);
	return 0;
}

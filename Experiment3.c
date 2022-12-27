//Program to calculate Mean, Median and Mode for continuous series

#include<stdio.h>

void Mean()
{
	int length, i, l[10], u[10];
    float f[10], x[10], fx[10], sum_fx=0, sum_f=0, AM;
    
    //Enter the length
    printf("\n Enter the number : ");
    scanf("%d",&length);
    
    //Enter lower limits
    printf("\n Enter the lower limits : ");
    for(i=0; i<length; i++)
    {
        scanf("%d",&l[i]);
    }
    
    //Enter upper limits
    printf("\nEnter the upper limits : ");
    for(i=0; i<length; i++)
    {
        scanf("%d",&u[i]);
    }
    
    //Enter frequency
    printf("\nEnter the frequencies : ");
    for(i=0; i<length; i++)
    {
        scanf("%f",&f[i]);
        sum_f += f[i];
    }
    
    //Calculate mid-point (x) and sum_x
    for(i=0; i<length; i++)
    {
        x[i] = (u[i] + l[i]) / 2;
    }
    
    //Calculate fx and sum_fx  
    for(i=0; i<length; i++)
    {
        fx[i] = f[i] * x[i];
        sum_fx += fx[i];
    } 
    
    //Print Data
    printf("\nData : ");
    printf("\n	Class	|	f	|	x	|	fx");
    for(i=0; i<length; i++)
    {
    	printf("	%d-%d	|	%d	|	%d	|	%d", l[i], u[i], f[i], x[i], fx[i]);
	}
    
    //Arithmetic Mean of continuous series
    AM = sum_fx / sum_f;
    printf("\nArithmetic Mean for continuous series is %0.2f\n",AM);
}

void Median()
{
	int n, i, row, CF, c_l, c_u, c_f, h, l[20], u[20];
	float f[20], cf[20];
	float sum_f=0, term=0, median=0;
	
	printf("\nEnter the length : ");
    scanf("%d",&n);
    
    printf("\nEnter the lower limits : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&l[i]);
    }

    printf("\nEnter the upper limits : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&u[i]);
    }
	
	printf("\nEnter the values for f : ");
    for(i=0; i<n; i++)
    {
        scanf("%f",&f[i]);
        sum_f += f[i];
    }
    
    //Calculate cumulative frequency 
    cf[0] = f[0];
    for(i=0; i<n; i++)
    {
        cf[i+1] = f[i+1] + cf[i];
    }
    
    printf("\nData : ");
    printf("\n	Class	|	f	|	CF");
    for(i=0; i<n; i++)
    {
    	printf("\n	%d-%d	|	%0.2f	|	%0.2f", l[i], u[i], f[i], cf[i]);
	}
	
	h = u[0] - l[0];
	
    term = sum_f/2;
    
    for(i=0; i<n; i++)
	{
		if(term>cf[i])
		{
			row = i;
			CF = cf[i];
			c_f = f[i+1];
			c_l = l[i+1];
			c_u = u[i+1];
		}
	}
	
	printf("\nHere, N/2 : %f", term);
	printf("\nMedian class : %d-%d", c_l, c_u);
	printf("\nLower limit : %d", c_l);
	printf("\nCummulative frequency : %0.2f",CF);
	printf("\nFrequency : %0.2f", c_f);
	printf("\ni : %d", h);
	
	median = c_l + ((term - CF) / c_f) * h;
	
	printf("\nHence, median of the given data is %0.2f",median);	
}

void Mode()
{
	int n, i, j, row, c_l, c_u, c_f0, c_f1, c_f2, h, maxNum=0;
	int l[20], u[20], f[20];
	float mode=0;
		
	printf("\nEnter the length : ");
    scanf("%d",&n);
    
    printf("\nEnter the lower limits : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&l[i]);
    }

    printf("\nEnter the upper limits : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&u[i]);
    }
	
	printf("\nEnter the values for f : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&f[i]);
    }
    
    printf("\nData : ");
    printf("\n	Class	|	f	");
    for(i=0; i<n; i++)
    {
    	printf("\n	%d-%d	|	%d	", l[i], u[i], f[i]);
	}
    
    h = u[0] - l[0];
    
    //Maximum frequency
    for(i=1; i<n; i++)
    {
    	if(f[i] > maxNum)
    	{
    		maxNum = f[i];
    		c_f0 = f[i];
            row = i;
			c_l = l[i];
			c_u = u[i];
            c_f1 = f[i-1];
            c_f2 = f[i+1];
		}	
	}
	
	printf("\nMaximum frequency is %d", c_f0);
	printf("\nHence, modal class : %d-%d", c_l, c_u);
	printf("\nLower limit : %d", c_l);
	printf("\nf(0) : %d",c_f0);
	printf("\nf(0-1) : %d",c_f1);
	printf("\nf(0+1) : %d",c_f2);
	printf("\ni : %d",h);
	
	int a = c_f0 - c_f1;
	int b = 2 * c_f0 - c_f1 - c_f2;
	mode = c_l + a / (float)b * h;
	
	printf("\nAs calculated, the mode of given data is %0.2f", mode);
}

int main()
{
	int choice;
	printf("\n|-----------------------------------------|");
	printf("\n|Mean, Median & Mode for continuous series|");
	printf("\n|-----------------------------------------|");
	printf("\n|             1) Mean                     |");
	printf("\n|             2) Median                   |");
	printf("\n|             3) Mode                     |");
	printf("\n|             4) Exit                     |");
	printf("\n|-----------------------------------------|");
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

//Program to calculate mean deviation from mean, median and mode in continuous series

#include<stdio.h>

void MD_Mean()
{
	int n, i, l[20], u[20], x[20], f[20], fx[20], x_mean[20], fx_mean[20], mean=0;
	float MD=0, sum_f=0, sum_fx=0, sum_fx_mean=0;
	
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
        sum_f += f[i];
    }
    
    for(i=0; i<n; i++)
    {
    	x[i] = (u[i] + l[i]) / 2;
    	fx[i] = f[i] * x[i];
    	sum_fx += fx[i];
	}
	
	mean = sum_fx / sum_f;
	
	for(i=0; i<n; i++)
	{
		x_mean[i] = abs(x[i] - mean);
	}
	
	for(i=0; i<n; i++)
	{
		fx_mean[i] = f[i] * x_mean[i];
		sum_fx_mean += fx_mean[i];
	}
    
    printf("\nData : ");
    printf("\n	Class	|	f	|	x	|	fx	|	u	|	fu");
    for(i=0; i<n; i++)
    {
    	printf("\n	%d-%d	|	%d	|	%d	|	%d	|	%d	|	%d",l[i], u[i] , f[i], x[i], fx[i], x_mean[i], fx_mean[i]);
	}
    
    MD = sum_fx_mean / sum_f;
    printf("\nMean deviation from mean of the above data is %0.2f",MD);
}

void MD_Median()
{
	int n, i, row, CF, c_l, c_u, c_f, h;
	int l[20], u[20], f[20], x[20], cf[20], x_median[20], fx_median[20], median=0;
	float MD=0, sum_f=0, term=0, sum_fx_median=0;
	
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
        sum_f += f[i];
    }
    
    //Calculate cumulative frequency 
    cf[0] = f[0];
    for(i=0; i<n; i++)
    {
        cf[i+1] = f[i+1] + cf[i];
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
	
	median = c_l + ((term - CF) / c_f) * h;
	
	printf("\nHence, median of the given data is %d",median);
	
	//Mid-point
	for(i=0; i<n; i++)
    {
    	x[i] = (u[i] + l[i]) / 2;
	}
	
	for(i=0; i<n; i++)
	{
		x_median[i] = abs(x[i] - median);
	}
	
	for(i=0; i<n; i++)
	{
		fx_median[i] = f[i] * x_median[i];
		sum_fx_median += fx_median[i];
	}
	
	printf("\nData : ");
    printf("\n	Class	|	f	|	CF	|	x	|	u	|	fu");
    for(i=0; i<n; i++)
    {
    	printf("\n	%d-%d	|	%d	|	%d	|	%d	|	%d	|	%d", l[i], u[i], f[i], cf[i], x[i], x_median[i], fx_median[i]);
	}
	
	MD = sum_fx_median / sum_f;
	printf("\nMean deviation from median for the given data is %0.2f",MD);
}

void MD_Mode()
{
	int n, i, j, row, c_l, c_u, c_f0, c_f1, c_f2, h, maxNum=0;
	int l[20], u[20], f[20], x[20], x_mode[20], fx_mode[20], mode=0;
	float MD=0, sum_f=0, term=0, sum_fx_mode=0;
		
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
        sum_f += f[i];
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
	
	//Calculate mode
	int a = c_f0 - c_f1;
	int b = 2 * c_f0 - c_f1 - c_f2;
	mode = c_l + a / (float)b * h;
	
	printf("\nAs calculated, the mode of given data is %d", mode);
	
	//Mid-point
	for(i=0; i<n; i++)
    {
    	x[i] = (u[i] + l[i]) / 2;
	}
	
	for(i=0; i<n; i++)
	{
		x_mode[i] = abs(x[i] - mode);
	}
	
	for(i=0; i<n; i++)
	{
		fx_mode[i] = f[i] * x_mode[i];
		sum_fx_mode += fx_mode[i];
	}
	
	printf("\nData : ");
    printf("\n	Class	|	f	|	x	|	u	|	fu");
    for(i=0; i<n; i++)
    {
    	printf("\n	%d-%d	|	%d	|	%d	|	%d	|	%d", l[i], u[i], f[i], x[i], x_mode[i], fx_mode[i]);
	}
	
	MD = sum_fx_mode / sum_f;
	printf("\nMean deviation from mode for the given data is %0.2f", MD);
}

int main()
{
	int choice;
	printf("\n|-------------------------------------------------------------|");
	printf("\n|Mean Deviation from Mean, Median & Mode for continuous series|");
	printf("\n|-------------------------------------------------------------|");
	printf("\n|               1) Mean Deviation from Mean                   |");
	printf("\n|               2) Mean Deviation from Median                 |");
	printf("\n|               3) Mean Deviation from Mode                   |");
	printf("\n|               4) Exit                                       |");
	printf("\n|-------------------------------------------------------------|");
    do
    {
    	printf("\nEnter the choice which operation you want to perform : ");
		scanf("%d",&choice);
    	switch(choice)
		{
			case 1:
	    		MD_Mean();
	    		break;
	    	case 2:
	    		MD_Median();
	    		break;
	    	case 3:
	    		MD_Mode();
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

//Program to calculate standard deviation for continuous series by step-deviation method

#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, a_mean, h;
	int l[20], up[20], x[20], f[20], fx[20], u[20], uu[20], fu[20], fuu[20];
	float SD=0, sum_f=0, sum_fu=0, sum_fuu=0, val=0;
	
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
        scanf("%d",&up[i]);
    }
    
    h = up[0] - l[0];
	
	printf("\nEnter the values for f : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&f[i]);
        sum_f += f[i];
    }
    
    //Mid-point
	for(i=0; i<n; i++)
    {
    	x[i] = (up[i] + l[i]) / 2;
	}
    
    printf("\nAssume mean : ");
    scanf("%d",&a_mean);
    
    //Calculate u, fu, sum_fu, u2, fu2, sum_fu2
    for(i=0; i<n; i++)
    {
    	u[i] = (x[i] - a_mean) / h;
    	fu[i] = f[i] * u[i];
    	sum_fu += fu[i];
    	
    	uu[i] = u[i] * u[i];
    	fuu[i] = f[i] * uu[i];
    	sum_fuu += fuu[i];
	}
	
	printf("\nData : ");
    printf("\n	Class	|	f	|	x	|	u	|	u*u	|	fu	|	fu*u");
    for(i=0; i<n; i++)
    {
    	printf("\n	%d-%d	|	%d	|	%d	|	%d	|	%d	|	%d	|	%d", l[i], up[i], f[i], x[i], u[i], uu[i], fu[i], fuu[i]);
	}
	
	val = (sum_fuu / sum_f) - ((sum_fu / sum_f) * (sum_fu / sum_f));
	SD = sqrt(val) * h;
	printf("\nStandard deviation for the given data is %0.2f", SD);
	
	return 0;
}

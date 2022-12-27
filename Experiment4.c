//Program to calculate Geometric and Harmonic mean for discrete series

#include<stdio.h>
#include<math.h>

void GeometricMean()
{
	int n, i;
    float x[20], f[20], logx[20], f_logx[20], sum_f=0, sum_flogx=0, GM=0, val, l, al;
    
    //Enter length
    printf("\nEnter the length of series : ");
    scanf("%d",&n);
    
    //Enter values of x
    printf("Enter values of x : ");
    for(i=0; i<n; i++)
    {
        scanf("%f",&x[i]);
    }
    
    //Enter frequencies
    printf("Enter frequencies : ");
    for(i=0; i<n; i++)
    {
        scanf("%f",&f[i]);
        sum_f += f[i];
    }
    
    //Log values of x i.e. log(x)
    for(i=0; i<n; i++)
    {
        logx[i] = log10(x[i]);
    }
    
    //Calculate flog(x) and sum of flog(x)
    for(i=0; i<n; i++)
    {
        f_logx[i] = f[i] * logx[i];
        sum_flogx += f_logx[i];
    }
    
    //Print data
    printf("\nData : ");
    printf("\n	x	|	f	|	logx	|	flogx	");
    for(i=0; i<n; i++)
    {
    	printf("\n	%0.3f	|	%0.3f	|	%0.4f	|	%0.4f	", x[i], f[i], logx[i], f_logx[i]);
	}
    
    //Print sum of flogx
    printf("\nSum of flogx : %0.4f",sum_flogx);
    
    //Calculate Geometric Mean
    val = sum_flogx / sum_f;
    GM = pow(10, val);
    printf("\nGeometric Mean of the above data is %0.3f\n",GM);
}

void HarmonicMean()
{
	int n, i;
    float x[20], f[20], fx[20], sum_f=0, sum_fx=0, HM;
    
    //Enter length
    printf("\nEnter the length of series : ");
    scanf("%d",&n);
    
    //Enter values of x
    printf("\nEnter values of x : ");
    for(i=0; i<n; i++)
    {
        scanf("%f",&x[i]);
    }
    
    //Enter frequencies
    printf("\nEnter frequencies : ");
    for(i=0; i<n; i++)
    {
        scanf("%f",&f[i]);
        sum_f += f[i];
    }
    
    //Calculate f/x
    for(i=0; i<n; i++)
    {
        fx[i] = f[i] / x[i];
        sum_fx += fx[i];
    }
    
    //Print data
    printf("\nData : ");
    printf("\n	x	|	f	|	f/x");
    for(i=0; i<n; i++)
    {
    	printf("\n	%0.3f	|	%0.3f	|	%0.3f	", x[i], f[i], fx[i]);
	}
    
    //Harmonic Mean
    HM = sum_f / sum_fx;
    printf("\nHarmonic Mean is %0.3f\n",HM);
}

int main()
{
	int choice;
	printf("\n|-----------------------------------------|");
	printf("\n|      GM and HM for discrete series      |");
	printf("\n|-----------------------------------------|");
	printf("\n|            1) Geometric Mean            |");
	printf("\n|            2) Harmonic Mean             |");
	printf("\n|            3) Exit                      |");
	printf("\n|-----------------------------------------|");
    do
    {
    	printf("\nEnter the choice which operation you want to perform : ");
		scanf("%d",&choice);
    	switch(choice)
		{
			case 1:
	    		GeometricMean();
	    		break;
	    	case 2:
	    		HarmonicMean();
	    		break;
	    	case 3:
	    		printf("\nExit!!");
	    		break;
	    	default:
	    		printf("\nINVALID CHOICE! Please choose valid operation!");
	    		break;
		}
	}while(choice!=4);
	return 0;
}

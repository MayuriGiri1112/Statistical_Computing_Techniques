//Program to calculate Mean, Median and Mode for individual series

#include<stdio.h>
void Mean()
{
	int length, i;
    float arr[10], sum=0, AM;
    
    printf("\nEnter the length : ");
    scanf("%d",&length);
    
    printf("\nEnter numbers to calculate arithmetic mean : ");
    for(i=0; i<length; i++)
    {
        scanf("%f",&arr[i]);
    }
    
    for(i=0; i<length; i++)
    {
        sum = sum + arr[i];
    }
    
    AM = sum / length;
    printf("\nArithmetic mean of Individual Series is %0.2f\n",AM);
}

void Median()
{
	int i, j, n, temp, term, term1, term2;
	int x[50];
    float median;

    printf("\nEnter the length : ");
    scanf("%d",&n);
    
    printf("\nEnter the values for which median to be calculated : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&x[i]);
    }

    //Sort the array in ascending order
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(x[i] > x[j])
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    //Data after sorting
    printf("\nData after sorting : ");
    for(i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }

    //Calculate Median
    if(n%2==0)
    {
        term1 = n/2;
        term2 = n/2+1;
        median = (x[term1-1]+x[term2-1])/2;
    }
    else
    {
        term = (n+1)/2;
        median = x[term-1];
    }

    printf("\nMedian of the above data is %0.2f\n",median);
}

void Mode()
{
	int n, i, j, x[20], count, maxCount=0, mode=0;
	
	printf("\nEnter the length : ");
    scanf("%d",&n);
    
    printf("\nEnter the values : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&x[i]);
    }
    
    //Maximum value
    for(i=0; i<n; i++)
    {
    	count =0;
    	for(j=0; j<n; j++)
    	{
    		if(x[j] == x[i])
    		{
    			count++;
			}
		}
		if(count > maxCount) 
		{
            maxCount = count;
            mode = x[i];
        }
	}
	
	printf("\nMode of the given data is %d", mode);
}

int main()
{
	int choice;
	printf("\n|-----------------------------------------|");
	printf("\n|Mean, Median & Mode for individual series|");
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

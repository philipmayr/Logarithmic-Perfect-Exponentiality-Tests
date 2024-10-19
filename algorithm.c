// Perfect Exponentiality Test

#include <stdio.h>
#include <math.h>

int exponentiate(int base, int index)
{
    int power = 1;
    
    if (index == 0) return power;
    if (index == 1) return base;
    
    while (index > 0)
    {
        if (index & 1) power *= base;
        
        base *= base;
        index >>= 1;
    }
    
    return power;    
}

int test_perfect_exponentiality(int n)
{
    for (int k = 2; k <= n; k++)
    {
        for (int i = 2; i <= log2(n); i++)
        {
            int power = exponentiate(k, i);
            
            if (power > n) break;
            if (power == n) return 1;
        }
    }
    
    return 0;
}

int main()
{
    int perfect_power_candidate;

    for (;;)
    {    
        printf("Enter a perfect power candidate to test for perfect exponentiality: ");
        
        // integer input validation
        // https://jackstromberg.com/2013/02/how-to-validate-numeric-integer-input-in-c/
        
        int input, status, temp;

    	status = scanf("%d", &input);
    	
    	while(status != 1)
    	{
            while((temp = getchar()) != EOF && temp != '\n');
            
            printf("Invalid input.");
            printf("\n\n");
            printf("Enter a perfect power candidate to test for perfect exponentiality: ");
            
            status = scanf("%d", &input);
    	}
    
    	perfect_power_candidate = input;
    	
    	if (test_perfect_exponentiality(perfect_power_candidate)) printf("%d is a perfect power.", perfect_power_candidate);
        else printf("%d is not a perfect power.", perfect_power_candidate);
        
        printf("\n\n");
    }
}

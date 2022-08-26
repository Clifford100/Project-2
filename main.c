#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Nyiko"
#define YEAR "2022"

void print_header(){                            // Prints the header of the program
    printf("***************************");
    printf("\n%s",TITLE);                       // Prints the title of the program
    printf("\nWritten by: %s",AUTHOR);          // Prints the author of the program
    printf("\nDate: %s",YEAR);                  // Prints the year of the program
    printf("\n***************************\n");
}

char* Dec2RadixI(int decValue, int radValue)
    {                                               // Converts a decimal value to a radix-i value
    char *radixI = (char*)malloc(sizeof(char)*100);
    int i = 0;
    while(decValue > 0){
        radixI[i] = decValue % radValue + '0';      // Converts the decimal value to a radix-i value
        decValue /= radValue;
        i++;
    }
    radixI[i] = '\0';                               // Adds a null character to the end of the string
    // reverse the string
    int j = 0;
    int k = i - 1;
    while(j < k){
        char temp = radixI[j];           // Stores the value of the first character in a temporary variable
        radixI[j] = radixI[k];           // Stores the value of the last character in the first character
        radixI[k] = temp;                // Stores the value of the temporary variable in the last character
        j++;
        k--;
    }
    return radixI;                        // Returns the radix-i value
}

int main(){
    print_header(); // Prints the header of the program
    int decValue;   // Stores the decimal value
    int radValue;   // Stores the radix-i value

    while (1){
        printf("Enter a decimal number: "); // Prompts user for decimal number
        scanf("%d",&decValue);
        if(decValue == -1){
            printf("EXIT\n");
            break;
        }
        printf("The number you have entered is %d\n",decValue);
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d",&radValue);
        if(radValue == -1 || radValue < 2 || radValue > 16){
            printf("EXIT\n");
            break;
        }
        printf("The radix you have entered is %d\n",radValue);
        printf("The log2 of the number is %.2lf\n",log2(decValue));
        printf("The integer result of the number divided by 2 is %d\n",decValue/2);
        printf("The remainder is %d\n",decValue%2);
        printf("The radix-%d value is ",radValue);
        printf("%s\n",Dec2RadixI(decValue,radValue));
    }
    return 0;
}

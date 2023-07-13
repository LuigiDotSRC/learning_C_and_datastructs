#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Printing Patterns Using Loops -- from HackerRank 

/*
double nested loop? 
first layer: create each row 
second layer: place numbers within the row 
append to string and print? 
*/

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      
    // side length = 1 + 2(n-1)
    int side_length = (1 + 2 * (n-1))*2; // *2 to account for spaces in between
    char final_string[side_length*side_length+n]; // + n to account for the \n chars 
    int counter = 0; 
    for(int i=0; i<side_length; i++){
        for(int j=0; j<side_length; j++){
            
            if(j % 2 == 0){
                char current_num = (char) n;
                final_string[counter] = 'a'; // how to get integer to char? 
                counter++;
            }else{
                final_string[counter] = ' ';
                counter++;
            }
        }
        final_string[counter] = '\n';
        counter++;
    }
    
    // BUGS AFTER INTRODUCING SPACES IN BETWEEN ! ! ! !
    printf("%s", final_string);
    return 0;
}

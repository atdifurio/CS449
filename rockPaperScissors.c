#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int main(){
    char str1[4], str2[9];
    printf("Welcome to Rock, Paper, Scissors \n Would you like to play? ");
    scanf("%s", str1);
    printf("\nWhat is your choice? ");
    scanf("%s", str2);
    srand((unsigned int)time(NULL)); //seed the rand num gen.
    int compNum = rand() %(2-0 + 1) + 0;
    printf("The rand num is: %d", compNum);


}

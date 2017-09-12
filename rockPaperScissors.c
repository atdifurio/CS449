#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int main(){
    //GATHERING USER INPUTS...
    char str1[4], playerChoice[9];
    char compChoice[9];
    int pScore = 0, cScore = 0;
    printf("Welcome to Rock, Paper, Scissors \n Would you like to play? ");
    scanf("%s", str1);
    rpsSelector(compChoice, playerChoice);
    // END GATHERING USER INPUTS

    int victor = comparePlays(compChoice, playerChoice);
    if(victor == 0){
        printf("There was a tie\n");
        rpsSelector(compChoice, playerChoice);
    }
    if(victor == 1){
        printf("You won this game!\n The score is now you: %d, computer %d", pScore, cScore);
    }
    return 0;
}

void rpsSelector(char compChoice[], char playerChoice[]){
    printf("\nWhat is your choice? ");
    scanf("%s", playerChoice);
    srand((unsigned int)time(NULL)); //seed the rand num gen.
    int compNum = rand() % (2-0 + 1);
    printf("The rand num is: %d", compNum);

    switch(compNum){
        case 0:
            strcpy(compChoice, "rock");
            break;
        case 1:
            strcpy(compChoice, "paper");
            break;
        case 2:
            strcpy(compChoice, "scissors");
            break;
        default:
            printf("error! invalid random number generated\n");
    }

    printf("The computer chooses %s\n", compChoice);
}

int comparePlays(char compChoice[], char playerChoice[]){
    //if returns 1 player won, 0 tie, -1 comp won

    if(strcmp(compChoice, playerChoice) == 0){ //tie
        return 0;
    }
    else if((strcmp(compChoice,"rock") == 0) && (strcmp(playerChoice, "paper") == 0)
        return 1;
    else if((strcmp(compChoice,"rock") == 0) && (strcmp(playerChoice, "scissors") == 0)
        return -1;
    else if((strcmp(compChoice,"paper") == 0) && (strcmp(playerChoice, "rock") == 0)
        return -1;
    else if((strcmp(compChoice,"paper") == 0) && (strcmp(playerChoice, "scissors") == 0)
        return 1;
    else if((strcmp(compChoice,"scissors") == 0) && (strcmp(playerChoice, "paper") == 0)
        return -1;
    else if((strcmp(compChoice,"scissors") == 0) && (strcmp(playerChoice, "rock") == 0)
        return 1;

}

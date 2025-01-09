#include<stdio.h>
#include<stdlib.h>
#include<time.h> //generates random number

int main (){
    int guessNumber = 0, randomNumber = 0, numberOfGuesses;
    time_t t;
    
    //Random number generator initialization
    srand((unsigned) time(&t));
    randomNumber = rand() % 21; //Ensures random number stays between 0 to 20.
    
    
    printf("Welcome to the guessing game\nI have chosen a number between 0 to 20 which you must guess in 5 tries to win.");
    printf("\nEnter a guess:");
    scanf("%d", &guessNumber);
    
    //to check if the entered number is between 0 to 20.
    
    if(guessNumber<=20 && guessNumber>=0){
        printf("\nYour guessed number is %d", guessNumber);
    } else{
        printf("\nEnter a valid number between 0 to 20 only.");
    }

    //To check random number is lesser than, greater than or equal to random number generated.
    
    for(numberOfGuesses = 5; numberOfGuesses>0; --numberOfGuesses ){
        printf("\nNo. of tries left %d", numberOfGuesses);
        printf("\n Enter a guess:");
        scanf("%d", &guessNumber);
        
    if(randomNumber == guessNumber){
        printf("\nCongratulations! You guessed it correct.\n");
        break;
    }
    
    else if(guessNumber < 0 || guessNumber > 20){
        printf("Enter a number between 0 to 20 only");
        
    }
    
    else if(randomNumber < guessNumber){
        printf("\nThe guessed number is higher\n");
        
    }
    else if (randomNumber > guessNumber){
        printf("\nThe guessed number is lower\n");
    }
        printf("You lost all your tries. The random number was %d", randomNumber);
    }
    
    
    
    return 0;
    
}

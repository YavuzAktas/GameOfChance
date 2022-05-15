#include <stdio.h>
#include <stdlib.h>
#include <time.h>


enum status { WON, LOSE, CONTINUE };		// enumeration constants represent game status

int diceTotal( void );				// function prototype


int main( void ){
		
	int sum;
	int gamePoint;
	
	srand( time( NULL ) );			// randomize random number generator using current time
	enum status gameStatus;		// can contain CONTINUE, WON, or LOST
	
	sum = diceTotal();
	
	switch( sum ){
		
		case 6:
		case 12:
			gameStatus = WON;
			break;
			
		case 2:
		case 3: 
		case 11:
			gameStatus = LOSE;
			break;	
		
		default:
			gameStatus = CONTINUE;		// player should keep rolling
			gamePoint = sum;
			printf("Player Point : %d\n", gamePoint );
			puts("The Game Continues!!!");
			break;		
	}
	
	while( gameStatus == CONTINUE ){
		
		sum = diceTotal();		// roll dice again
		
		
		if( sum == gamePoint ){
			
			gameStatus = WON;
		}//if end
		
		else if( sum == 6 ){
			
			gameStatus = LOSE;
		}//if end	
	}//while end
	
	if( gameStatus == WON ){
		
		puts("Player Wins!");
	}//if end
	
	else if( gameStatus == LOSE ){
		
		puts("Player Loses!");
	}//else end
}


int diceTotal( void ){
	
	unsigned int dice1;
	unsigned int dice2;
	unsigned int sumOfDice;
	
	dice1 = 1 + ( rand() % 6 );
	dice2 = 1 + ( rand() % 6 );
	sumOfDice = dice1 + dice2;
	
	printf("Player Rolled %d + %d = %d\n", dice1, dice2, sumOfDice );
	
	return sumOfDice;		// return sum of dice
}



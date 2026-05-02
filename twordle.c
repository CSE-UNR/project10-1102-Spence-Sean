//Author: Sean Spence
//Project 10

#include<stdio.h>
#include<stdbool.h>

#define STR_CAP 5
#define MAX_GUESSES 6

void getWord (char word []);
void lowerCaseEm(char str[]);

bool validGuess (char guess[]);
bool correctGuess(char guess[], char word[]);
bool inWord (char letter, char word[]);

void displayGuess(char guess[], char word[]);

int wordLength(char str[]);

int main(){

char word[STR_CAP + 1];
char guess[STR_CAP + 1];

int attempts = 1;

getWord(word);
lowerCaseEm(word);
	
	while (attempts < MAX_GUESSES) {
		printf("\nGuess #%d\n", attempts);
		
		printf("Enter your guess: ");
		scanf("%s", guess);
		lowerCaseEm(guess);
		
		if (validGuess(guess)) {
			displayGuess(guess, word);
			
			if(correctGuess(guess, word)) {
				printf("You guessed the word!\n     %s\n", guess);
				if (attempts == 1) {
					printf("\n   FANTASTIC!\n");
					printf("You got it in %d guess!\n", attempts);
					}
				if (attempts == 2 || attempts == 3) {
					printf("Amazing!\n");
					printf("You got it in %d guesses!\n", attempts);
					}
				if (attempts == 4) {
					printf("Nice job!\n");
					printf("You got it in %d guesses!\n", attempts);
					}
				if (attempts == 5) {
					printf("Well done!\n");
					printf("You got it in %d guesses!\n", attempts);
					}
				if (attempts == 6) {
					printf("You got it in %d guesses!\n", attempts);
					}
				
				return 0;
			}
				attempts++;
		}
		else {
			printf("Invalid guess. Try again.\n");
		}
	}
	printf("\nYou lost.\n");
		
	return 0;
}

void getWord (char word[]) {
	
	FILE *fp;
	fp = fopen("word.txt", "r");
	
	if (fp == NULL) {
	   printf("Cannot read file.\n");
	   return;
	}
	
	fscanf(fp, "%s", word);
	fclose(fp);
}

int wordLength(char str[]) {
	int count = 0;
    
	while (str[count] != '\0') {
		count++;
	}
    
	return count;
}

void lowerCaseEm(char str[]) {
	int i = 0;
	
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z') {
		    str[i] = str[i] + 32;
		}
		
		i++;
	}
}

bool validGuess(char guess[]) {
	int i = 0;
	
	if(wordLength(guess) != STR_CAP) {
		return false;
	}
	
	while (guess[i] != '\0') {
		if ((guess[i] < 'a' || guess[i] > 'z') && (guess[i] < 'A' || guess[i] > 'Z')) {
		return false;
		}
		i++;
	}
	return true;
}

bool correctGuess(char guess [], char word[]) {
	int i = 0;
	
	while (guess[i] != '\0') {
		if (guess[i] != word[i]) {
			return false;
		}
		i++;
	}
	return true;
}

bool inWord (char letter, char word[]) {
	int i = 0;
	
	while (word[i] != '\0') { 
		if (letter == word[i]) {
			return true;
		}
		i++;
	}
	return false;
}

void displayGuess(char guess[], char word[]) {
	int i;
	
	for (i = 0; i < STR_CAP; i++) {
		if (guess[i] == word[i]) { 
			if (guess[i] >= 'a' && guess[i] <= 'z') {
				printf("%c", guess[i] - 32);
			}
			else {
				printf("%c", guess[i]);
			}
		}
		else {
			printf("%c", guess[i]);
		}
	}
	
	printf("\n");
	
	for (i = 0; i < STR_CAP; i++) {
		if (guess[i] != word[i] && inWord(guess[i], word)) {
			printf("^");
		}
		else {
			printf(" ");
		}
	}
	
	printf("\n");
}




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DIGITS 12

int initialize(int *maxNumberPress)
{
FILE *readVal = fopen("gamePress.config", "r");

if (readVal == NULL)
{
// File is not present, Fall to default value
*maxNumberPress = 10;
return -1;
}

fscanf(readVal, "%d", maxNumberPress);
fclose(readVal);
return 1;
}

// Function to write maxNumberPress into a file for accessing next time the program executes
int write_maxNumberPress(const int *maxNumberPress)
{
FILE *writeVal = fopen("gamePress.config", "w");

if (writeVal == NULL)
{
printf("Error opening file for storing max numberPess");
return -1;
}
fprintf(writeVal, "%d", *maxNumberPress);
fclose(writeVal);
return 1;
}

// Function to show menu and get choice from the user
int get_response(int *response)
{
printf("\n1. Play the gamePress\n");
printf("2. Change the max numberPress\n");
printf("3. Quit\n");
printf("Enter your response: ");
scanf("%d", response);
}

// Function to start the game
int play_game(const int correct_number)
{
char number[MAX_DIGITS];
// Prompt for a number
get_number:
printf("Enter a number: ");
scanf("\n%s", &number);
if (strcmp(number, "q") == 0)
{
printf("Ending the game..");
return 0;
}

int val = atoi(number);
if (correct_number == val)
{
printf("You won the game!!..\n");
}
else
{
if (correct_number > val)
{
printf("Number is too small. Try again..\n");
goto get_number;
}
else
{
printf("Number is too high, Try again..\n");
goto get_number;
}
}
}

// Function to change the maxNumberPress value
void change_max_numberPress(int *maxNumberPress)
{
int temp;
get_number:
printf("Enter new value for max numberPress: ");
scanf("%d", &temp);
if (temp <= 0)
{
printf("Invalid value for max numberPress. Try again..\n");
goto get_number;
}

*maxNumberPress = temp;
}

int main()
{
int maxNumberPress;
initialize(&maxNumberPress);

srand(time(NULL));
// Generate a random number in between 1 and maxNumberPress
int correct_number;
int response = 0;
while (response != 3)
{
// Display menu and get response
get_response(&response);
switch (response)
{
case 1:
correct_number = rand() % (maxNumberPress) + 1;
play_game(correct_number);
break;

case 2:
change_max_numberPress(&maxNumberPress);
printf("Updated successfully..\n");
break;

case 3:
// Write maxNumberPress into file and exit
write_maxNumberPress(&maxNumberPress);
printf("Thank you for playing game..\n");
return 0;

default:
printf("Invalid choice. Try again..\n");
break;
}
}
}
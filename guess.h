#ifndef GUESS_H_
#define GUESS_H_
/* Print the information of the game like: The range of the actual price and
how many chances to guess. */
void PrintWelcomeInfo();

/* Initialized the guess game like: generating the actual price*/
void InitializeGame();

/* Actually play the game
 * @return The winning rate
*/
double PlayGame();

/* The function to show the information after game is over
 * @param prevailed_ratio The winning rate
*/
void PrintGameOverInfo(double prevailed_ratio);

#endif
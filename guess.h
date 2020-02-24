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

/* The fuction used to initialize each round
 * @return The new random actual price for this round
*/
static int InitializeBout();

/* The actual running function for playing each round
 * @param 
 * @return whether the player won this round or not
*/
static bool PlayBout(int actual_price, int lower_price, int higher_price, int chance_left);

/* The function to see if the player wants to play for another game or not
 * @return wheter the player wants to play for another game or not
*/
static bool Again();

/* The function used to get the guessed price from the player
 * @param lower_price The lower limit of the guess range
 * @param higher_price The higher limit of the guess range
 * @return The price from the user
*/
static int GetPrice(int lower_price, int higher_price, int chances_left);

/* The function used to check the guessed price from the player
 * @param lower_price The lower limit of the guess range
 * @param higher_price The higher limit of the guess range
 * @param guess_price The guessed price from the user
 * @return The final guessed price from player
*/
static int CheckPrice(int lower_price, int higher_price, int guess_price);

/* The function used to compare the guessed price from the player with the actual price
 * @param actual_price The actual price
 * @param guess_price The guessed price from the user
 * @return 1 - The guessed price is higher, -1 - The guessed price is lower, 
 * 0 - The guessed price is the actual price
*/
static int JudgePrice(int actual_price, int guess_price);

#endif
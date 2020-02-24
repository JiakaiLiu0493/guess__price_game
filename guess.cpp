#include <iostream>
#include <iomanip>

#include "random.h"
#include "guess.h"

/* The range of the actual price and the guess count*/
const int lowest_price = 100;
const int highest_price = 200;
const int guess_count = 6;

/* Enum class of the result of guess*/
enum Judged_Result{
    LOW = 0,
    HIGH,
    RIGHT
};

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
static Judged_Result JudgePrice(int actual_price, int guess_price);

void PrintWelcomeInfo(){
    std::cout << "The program lists a product with price between" << lowest_price << "and"
    << highest_price << "(RMB Yuan)" << std::endl;

    std::cout << "You give a guess price. If the price you give is correct, you win"
    << std::endl;
 
}

void InitializeGame(){
    Randomize();
}

double PlayGame(){
    int actual_price;
    int lower_price = lowest_price;
    int higher_price = highest_price;
    int chances_left = guess_count;
    int bout_count = 0, prevailed_bout_count = 0;
    while(true){
        actual_price = InitializeBout();
        if(PlayBout(actual_price, lower_price, higher_price, chances_left)){
            prevailed_bout_count++;
        }
        bout_count++;
        if(!Again()){
            break;
        }
    }
    return (double)prevailed_bout_count/(double)bout_count;
}

void PrintGameOverInfo(double prevailed_ratio){
    std::cout << "Prevailed ratio = " << std::setw(3) << prevailed_ratio * 100 << "%"
    << std::endl;
    if(prevailed_ratio >= 0.75){
        std::cout << "Perfect!" << std::endl;

    }
    else if(prevailed_ratio >= 50){
        std::cout << "Nice!" << std::endl;
    }
    else{
        std::cout << "Ok! You can do better next time!" << std::endl;
    }
}

static int InitializeBout(){
    return GenerateRandomNumber(lowest_price, highest_price);
}

static bool PlayBout(int actual_price, int lower_price, int higher_price, int chance_left){
    int guess_price;
    Judged_Result judged_result;
    while(chance_left > 0){
        guess_price = GetPrice(lower_price, higher_price, chance_left);
        guess_price = CheckPrice(lower_price, higher_price, guess_price);
        chance_left--;
        judged_result = JudgePrice(actual_price, guess_price);
        switch(judged_result){
            case HIGH:
                if(chance_left > 0){
                    std::cout << "Higher" << std::endl;
                    higher_price = guess_price - 1;
                }
                else{
                    std::cout << "You lose this bout. The actual price is " << actual_price << std::endl;
                    return false;
                }
                break;
            case LOW:
                if(chance_left > 0){
                    std::cout << "Lower" << std::endl;
                    lower_price = guess_price + 1;
                }
                else{
                    std::cout << "You lose this bout. The actual price is " << actual_price << std::endl;
                    return false;
                }
                break;
            default:
                std::cout << "You win this game!!!" << std::endl;
                return true;
        }
    }
    return false;
}

static bool Again(){
    int choice;
    std::cout << "Play a new game? or stop for now?" << std::endl;
    std::cout << "Enter 0 to stop, anyother numbers to play again" << std::endl;
    std::cin >> choice;
    return choice;
}

static int GetPrice(int lower_price, int higher_price, int chances_left){
    int guess;
    std::cout << "The actual price is in [" << lower_price << "," << higher_price << "]." << std::endl;
    std::cout << "Chances left: " << chances_left << std::endl;
    std::cin >> guess;
    return guess;
}

static int CheckPrice(int lower_price, int higher_price, int guess_price){
    int guess = guess_price;
    while(guess < lower_price || guess > higher_price){
        std::cout << "guess price: "<< guess << " is out of range" << std::endl;
        std::cout << "Please choose in [" << lower_price << "," << higher_price << "]." << std::endl;
        std::cin >> guess;
    }
    return guess;
}

static Judged_Result JudgePrice(int actual_price, int guess_price){
    int diff = actual_price - guess_price;
    if(diff == 0){
        return RIGHT;
    }
    else if(diff < 0){
        return HIGH;
    }
    else{
        return LOW;
    }
}
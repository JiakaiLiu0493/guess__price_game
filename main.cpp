#include "guess.h"

int main(){
    double prevailed_ratio;
    PrintWelcomeInfo();
    InitializeGame();
    prevailed_ratio = PlayGame();
    PrintGameOverInfo(prevailed_ratio);
    return 0;
}
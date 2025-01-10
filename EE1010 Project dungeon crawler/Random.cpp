#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

// setup random number generator
void setupRandomSeed()
{
    srand(static_cast<int>(time(NULL))); // static cast to get rid of complier narrowing conversion warning
}

// generate random number between startNum and endNum
int generateRandomNumber(int startNum, int endNum) {
    int range{ endNum - startNum };
    int randomNumber{ (rand() % range) + startNum }; // get random number inside the range passed to function

    return randomNumber;
}
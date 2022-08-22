#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <random>
using namespace std;

// Calculate the probability of success

float probSuccess(string doors[3], int n, string change) {

    // Number of successes.
    int successes = 0;

    // Default_random_engine object
    default_random_engine generator;

    // Initializing of uniform_int_distribution class
    uniform_int_distribution<int> distribution(0, 2);

    // Choosing a door n times
    for (int i = 0; i < n; i++) {
        srand(time(NULL));
        //int randNum = rand() % 3;
        int randNum = distribution(generator);
        string door = doors[randNum];
        if (change == "yes") {
            if (door == "goat") {
                successes += 1;
            }
        } else {
            if (door == "car") {
                successes += 1;
            }
        }
    }

    // the probability of success
    float p;
    p = (float(successes)/float(n))*100;
    return p;
}


int main() {
    cout << "Hello\n";
    // Three doors
    string doors[3] = {"goat", "goat", "car"};
    // Number of times the protocol will be run
    int n;
    // Change the door or not
    string change;

    cout << "How many times do you want to run the test?\n";
    cin >> n;
    cout << "Do you want to change the door every time? yes|no\n";
    cin >> change;
    cout << "Running " << n << " times the process.\n";
    cout << "Door change: " << change << "\n";

    // Probability of success
    float p = probSuccess(doors, n, change);

    cout << "The probability of success is: " << p << " %.";
    return 0;
}
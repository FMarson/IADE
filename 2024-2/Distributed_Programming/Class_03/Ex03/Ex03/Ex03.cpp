/*
Exercise 3: Dungeon Escape (Using Condition Variables)
In a dungeon escape game, multiple players are trapped inside a dungeon.
They can only escape when they find a key that is hidden.
The key can be discovered by one of the players at any moment (chance of 35%).
Since players can only escape once the key is found, they must search until the key be found
before making their escape.

Use condition variables to manage the synchronization between players searching for the key and
the player who finds it.
Implement a simulation where multiple players searching for the key, and once it is found,
all players are notified to escape the dungeon.

Key Requirements:
* Create multiple player threads that search for the key to be found.
* Use a condition variable to signal players when the key is found.
* Once the key is found, all players searching should be notified to exit.
* Ensure proper synchronization using mutexes to protect shared state.

Example Output:
Player 1 is searching for the key...
Player 2 is searching for the key...
Player 3 is searching for the key...
Player 1 is searching for the key...
Player 3 is searching for the key...
Player 2 is searching for the key...
Player 2 is searching for the key...
Player 1 is searching for the key...
Player 3 is searching for the key...
Player 1 is searching for the key...
Player 2 is searching for the key...
Player 3 is searching for the key...
Player 1 found the key!
Congratulations to Player 1 for finding the key!
 */

#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <random>

using namespace std;

mutex mtx; // Mutex for synchronizing access to shared state
condition_variable cv; // Condition variable for signaling
bool keyFound = false; // Flag indicating if the key has been found
int playerIdWhoFoundKey = -1; // ID of the player who found the key

// Function representing a player searching for the key
void Player(int id) {
    random_device rd; // Obtain a random number from hardware
    mt19937 eng(rd()); // Seed the generator
    uniform_int_distribution<> chanceDistr(1, 100); // Distribution for chance (1-100)

    while (!keyFound) {
        // Search for the key

        // Simulate searching time
        this_thread::sleep_for(chrono::milliseconds(500));

        // Check if the key has already been found

        // Generate a random chance to find the key
     
        // Check if the player finds the key (35% chance)

            // Check again if the key has already been found
            // Mark the key as found
            // Record and print which player found it
            // Print which         cout << "Player " << id << " found the key!" << endl;
            // Notify all players that the key has been found
            // Exit since this player found the key
    }
}

// Function to simulate the escape room game
void StartEscapeRoom(int numPlayers) {
    vector<thread> players;

    // Create player threads

    // Wait for all players to finish

    // Announce who found the key
}

int main() {
    int numPlayers = 3; // Number of players

    StartEscapeRoom(numPlayers); // Start the escape room with the specified number of players

    return 0;
}

/*
Exercise 1: Treasure Hunt (Using Mutex with Random Chance)

Enunciate:
In a treasure hunt game, multiple players are searching for treasures in a shared area.
Each player gets three attempts to find a treasure during their search. There is a 50%
chance of finding a treasure with each attempt. To avoid conflicts, only one player can
search at a time. Implement a simple simulation where multiple players search for
treasures concurrently while using a mutex to ensure that only one player can search at
a time. After all players have completed their searches, display the total number of
treasures found.

Key Requirements:

- Each player should be able to make three attempts to find a treasure.
- The chance of finding a treasure during each attempt should be randomized (50% chance).
- Use a mutex to ensure thread-safe access to the shared resource (total treasures found).
- Print the results after all players have finished their attempts, showing how many treasures were found by all players combined.

Example Output:

Player 1 found a treasure!
Player 2 found nothing on this search.
Player 3 found a treasure!
...
Total treasures found: X
 */
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <random>

using namespace std;

mutex mtx; // Mutex for synchronizing access to treasures
int treasuresFound = 0; // Total treasures found

// Function to simulate treasure hunting by a player
void Player(int id) {
    random_device rd; // Obtain a random number from hardware
    mt19937 eng(rd()); // Seed the generator
    uniform_int_distribution<> distr(0, 1); // Define the range (0 or 1)

    for (int i = 0; i < 3; ++i) { // Each player searches 3 times
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate searching time
        lock_guard<mutex> lock(mtx); // Lock the mutex before searching
        if (distr(eng) == 1) { // Random chance (50%)
            cout << "Player " << id << " found a treasure!" << endl;
            treasuresFound++;
        } else {
            cout << "Player " << id << " found nothing on this search." << endl;
        }
    }
}

int main() {
    const int numPlayers = 5;
    vector<thread> players;

    // Create player threads
    for (int i = 1; i <= numPlayers; ++i) {
        players.emplace_back(Player, i);
    }

    // Wait for all players to finish
    for (auto& player : players) {
        player.join();
    }

    cout << "Total treasures found: " << treasuresFound << endl;

    return 0;
}

/*
Exercise 2: Racing Game (Using Future)
In a racing game, players can choose the number of cars racing on a track.
Each car has a specific speed and distance to cover. Use std::future to simulate the time
it takes for each car to finish the race. After all cars have finished, display the top
three finishers in order along with their finishing times.

Key Requirements:
* Allow the user to input the number of racers.
* Each car should have a distance (200) and a speed (between 10 and 25)
  defined in the simulation.
* Use std::future to manage asynchronous racing for each car.
* After all cars have finished, output the top three finishers and their
  finishing times.

Example Output:

Enter the number of racers: 6
Car 5 finished the race in 8.3 minutes!
Car 1 finished the race in 9.5 minutes!
Car 4 finished the race in 10.0 minutes!
Car 3 finished the race in 14.3 seconds!
Car 6 finished the race in 14.3 seconds!
Car 2 finished the race in 16.7 seconds!
*/

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to hold car information
struct Car {
  int id;
  double time; // Time taken to finish the race
};

// Function to simulate car racing
double RaceCar(int carId, int distance, int speed) {
  double raceTime = static_cast<double>(distance) / speed; // Calculate race time
  this_thread::sleep_for(chrono::milliseconds(static_cast<int>(raceTime * 1000))); // Simulate race time
  cout << "Car " << carId << " finished the race in " << fixed << setprecision(1) << raceTime << " seconds!" << endl;
  return raceTime; // Return the time taken to finish
}

int main() {
  int numCars;
  cout << "Enter the number of racers: ";
  cin >> numCars;

  vector<future<double>> results(numCars);
  vector<Car> finishers(numCars);

  // Start the race for each car
  for (int i = 0; i < numCars; ++i) {
    int distance = 200; // Random distance between 100 and 200
    int speed = 10 + (rand() % 15); // Random speed between 10 and 25
    results[i] = async(launch::async, RaceCar, i + 1, distance, speed);
  }

  // Collect results and store them
  for (int i = 0; i < numCars; ++i) {
    finishers[i].id = i + 1; // Car ID starts from 1
    finishers[i].time = results[i].get(); // Get race result
  }

  // Sort finishers by time
  sort(finishers.begin(), finishers.end(), [](const Car& a, const Car& b) {
      return a.time < b.time;
  });

  // Output top 3 finishers
  cout << "\nTop 3 finishers:\n";
  for (int i = 0; i < min(3, numCars); ++i) {
    cout << (i + 1) << ". Car " << finishers[i].id << " - " << fixed << setprecision(1) << finishers[i].time << " seconds" << endl;
  }

  return 0;
}

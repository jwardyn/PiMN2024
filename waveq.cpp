#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Parameters
const double c = 1.0;  // Wave speed
const double dx = 0.1; // Spatial step
const double dt = 0.05; // Time step
const double L = 2.0; // Length of the domain
const double T = 4.0; // Total simulation time

// Function to initialize the wave profile
void initialize(vector<double>& u) {
    // Initial conditions: u(x,0) = sin(2*pi*x)
    for (int i = 0; i < u.size(); ++i) {
        double x = i * dx;
        u[i] = sin(2 * M_PI * x);
    }
}



// Function to simulate the wave equation and write the solution to a file
void solveWaveEquation() {
    // Number of grid points
    int N = static_cast<int>(L / dx) + 1;

    // Initialize vectors
    vector<double> u(N); // Current time step
    vector<double> u_prev(N); // Previous time step

    // Initialize the wave profile
    initialize(u_prev);

    // Open output file
    ofstream outFile("wave_solution.txt");
    if (!outFile) {
        cerr << "Error: Unable to open output file!" << endl;
        return;
    }

    // Simulation loop
    double t = 0.0;
    while (t < T) {
        // Write current state to file
        for (int i = 0; i < N; ++i) {
            outFile << u_prev[i] << " ";
        }
        outFile << endl;

        // Perform one time step
        step(u, u_prev);

        // Update previous time step
        u_prev = u;

        // Increment time
        t += dt;
    }

    // Close output file
    outFile.close();
}

int main() {
    solveWaveEquation();
    return 0;
}

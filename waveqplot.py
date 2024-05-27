import numpy as np
import matplotlib.pyplot as plt

# Function to read solution from file
def read_solution(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        solution = []
        for line in lines:
            solution.append([float(x) for x in line.split()])
    return np.array(solution)

# Read solution from file
solution = read_solution('wave_solution.txt')

# Parameters
c = 1.0  # Wave speed
dx = 0.1 # Spatial step
dt = 0.05 # Time step
L = 2.0 # Length of the domain
T = 4.0 # Total simulation time

# Create spatial grid
x = np.arange(0, L + dx, dx)

# Create time grid
t = np.arange(0, T + dt, dt)

# Plotting
plt.figure(figsize=(10, 6))
plt.title('Wave Equation Solution')
plt.xlabel('Position (x)')
plt.ylabel('Time (t)')
plt.imshow(solution, extent=[0, L, 0, T], origin='lower', aspect='auto', cmap='viridis')
plt.colorbar(label='Amplitude')
plt.show()

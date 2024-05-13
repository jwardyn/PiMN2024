import numpy as np
import matplotlib.pyplot as plt

# Define the parameter 'a'
a = 1

# Define the range for theta
theta = np.linspace(0, 2*np.pi, 100000)

# Calculate x and y coordinates
x = np.sqrt(2*a**2 * np.cos(2*theta)) * np.cos(theta)
y = np.sqrt(2*a**2 * np.cos(2*theta)) * np.sin(theta)

# Plot the lemniscate
plt.plot(x, y)
plt.title('Lemniscate Plot')
plt.xlabel('x')
plt.ylabel('y')
plt.axis('equal')
plt.grid(True)
plt.show()

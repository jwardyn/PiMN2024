import numpy as np
import matplotlib.pyplot as plt

# Define the range for theta
theta = np.linspace(0, 2*np.pi, 1000)

# Calculate x and y coordinates for cardioid
x = 2 * np.cos(theta) * (1 - np.cos(theta))
y = 2 * np.sin(theta) * (1 - np.cos(theta))

# Plot the cardioid
plt.plot(x, y)
plt.title('Cardioid Plot')
plt.xlabel('x')
plt.ylabel('y')
plt.axis('equal')
plt.grid(True)
plt.show()

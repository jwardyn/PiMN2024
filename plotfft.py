import matplotlib.pyplot as plt
import numpy as np

# Load the data
data = np.loadtxt('wavefunction_evolution.dat')

# Extract x values
x = data[:, 0]

# Plot each time step
for i in range(1, data.shape[1]):
    plt.plot(x, data[:, i], label=f'Time step {i-1}')

plt.xlabel('x')
plt.ylabel('Wavefunction')
plt.title('Wavefunction Evolution')
plt.legend()
plt.show()

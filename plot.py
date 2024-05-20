import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Load data from CSV files
euler_data = pd.read_csv("euler_method.csv")
heun_data = pd.read_csv("heun_method.csv")
rk4_data = pd.read_csv("runge_kutta_method.csv")

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(euler_data['x'], euler_data['y'], label='Euler Method')
plt.plot(heun_data['x'], heun_data['y'], label="Heun's Method")
plt.plot(rk4_data['x'], rk4_data['y'], label='RK4 Method')
plt.scatter(rk4_data['x'], np.exp(rk4_data['x']), label='exact')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Comparison of ODE Solving Methods')
plt.legend()
plt.grid(True)
plt.savefig("diff1_compare_Euler_Heun_RK4.pdf")
 

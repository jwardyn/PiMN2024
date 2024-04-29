import sys
import matplotlib.pyplot as plt

def plot_integration_output(filename):
    x_values = []
    f_values = []
    rectangular_values = []
    trapezoid_values = []
    simpson_values = []

    with open(filename, 'r') as file:
        next(file)
        next(file)  
        for line in file:
            data = line.strip().split()
            x_values.append(float(data[0]))
            f_values.append(float(data[1]))
            rectangular_values.append(float(data[2]))
            trapezoid_values.append(float(data[3]))
            simpson_values.append(float(data[4]))

    plt.plot(x_values, f_values, label='f(x)')
    plt.plot(x_values, rectangular_values, label='Rectangular')
    plt.plot(x_values, trapezoid_values, label='Trapezoid')
    plt.plot(x_values, simpson_values, label='Simpson')

    plt.xlabel('x')
    plt.ylabel('Function value')
    plt.title('Integration Methods Comparison')
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <filename>")
        sys.exit(1)
    filename = sys.argv[1]
    plot_integration_output(filename)

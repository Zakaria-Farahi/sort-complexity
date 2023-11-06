import numpy as np
from scipy.optimize import curve_fit
import sys

# Read the data from the file and store it in a NumPy array
data = np.genfromtxt('data.txt')

# Generate x values (indices) for the data
x = np.arange(100)

# Define a quadratic function
def quadratic_function(x, a, b, c, d):
    return a * x**3 + b * x**2 + c * x + d

results = []

for i in range(data.shape[1]):
    column_data = data[:, i]  

    params, covariance = curve_fit(quadratic_function, x, column_data)

    a, b, c, d = params

    results.append((a, b, c, d))

with open('res.txt', 'w') as f:
    sys.stdout = f

    for i, (a, b, c, d) in enumerate(results):
        print(f"Sort {i + 1}:")
        print(f"a: {a:.15f}")
        print(f"b: {b:.15f}")
        print(f"c: {c:.15f}")
        print(f"d: {d:.15f}")
        print()

sys.stdout = sys.__stdout__

import matplotlib.pyplot as plt
import numpy as np

from sys import argv
from ast import literal_eval 

f = open(argv[1], 'r')
diff = [e[0] for e in list(literal_eval(f.read().strip()))]
N = len(diff)
x = np.linspace(0, 2*np.pi, N, endpoint=False)
xx = np.linspace(0, 2*np.pi, 10**4, endpoint=False)

plt.figure()
plt.plot(x, diff, label='Computed Solution')
plt.plot(xx, -np.sin(xx), label='True Solution')
plt.legend()
plt.show()

#plt.semilogy(xx, np.abs( diff - (-np.sin(xx)) ))

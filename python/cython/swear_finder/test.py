from timeit import timeit
import matplotlib.pyplot as plt
from automod_cy import contains_bad_words as ctb_cy
# from automod_py import contains_bad_words as ctb_py


# for i in range(1, 1000):
#     cy = timeit("automod_cy.contains_bad_words(string)", setup=f"import automod_cy; string = 'Привет ' * {i} + 'пидорads'", 
#                 number=5)
#     py = timeit("automod_py.contains_bad_words(string)", setup=f"import automod_py; string = 'Привет ' * {i} + 'пидорads'", 
#                 number=5)

#     cys.append(cy)
#     pys.append(py)

# plt.plot(cys, label='Cython')
# plt.plot(pys, label='Python')
# plt.show()
# print(f"Cy: {cy}\nPy: {py},\nfaster: {py/cy}")

string = 'ебланоид'
print(ctb_cy(string))
# print(ctb_py(string))

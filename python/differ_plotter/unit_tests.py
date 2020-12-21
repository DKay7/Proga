from math import sin, cos, log
from plotter import Plotter
from differentiator import Differentiator


funcs = ['y = x**2', 'y = x**3 + 8*x**2 + 1', 'y = sin(x)', 'y = cos(x)']
derivs = [lambda x: 2*x, lambda x: 3*x**2 + 16*x, lambda x: cos(x), 
            lambda x: -sin(x)]
            
type_ = input('Enter manual for manual test of auto for auto test\n')
assert type_ in ['manual', 'auto']

if type_ == 'manual':
    func = input('Input function in format \'y = x etc. \'\n')
    deriv = input('Input derivative in format \'y = x etc. \'\n')

    dif = Differentiator(func)


    dif.unit_test(dif.parse(deriv),
                    tuple(map(float, input('Input range as: start stop\n').split(' '))),
                    float(input('Input step\n')))

if type_ == 'auto':

    for func, deriv in zip(*(funcs, derivs)):

        dif = Differentiator(func)
        dif.unit_test(deriv,
                        (1, 100),
                        1e-1)

print('All tests were passed!')
print('Goodbye!')
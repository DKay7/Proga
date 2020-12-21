import numpy as np
from types import FunctionType
import matplotlib.pyplot as plt

class Plotter:
    """
    Class which plots function and its derivative
    """
    def __init__(self, 
                func: FunctionType, deriv: FunctionType, 
                _range: tuple, step: float=1e-1, 
                figsize: tuple=(8, 6)):
        """
        Initializes Plotter class

        Args:
            func (function): function to plot
            deriv (function): deriv of funtion to plot
            _range (tuple): range to plot function in
            step (float, optional): step to find function values. Defaults to 1e-7.
            figsize (tuple, optional):  figure size
        """

        plt.style.use('seaborn')

        self.function = func
        self.deriv = deriv

        self._range = _range
        self.step = step

        self.func_data, self.deriv_data = self.prepare_to_plot()

        self.fig, self.axes = plt.subplots(1, 2, figsize=figsize)

    def plot_2d_function(self):
        
        self.axes[0].plot(self.func_data)
        self.axes[0].set_title('Original function')
        
        self.axes[1].plot(self.deriv_data)
        self.axes[1].set_title('Derivative of original function')

        for ax in self.axes:
            ax.set_xlabel('x')
            ax.set_ylabel('y')

        
    def save_plot(self, path=None):
        if path is None:
            path = 'function'
        path += '.png'
        plt.savefig(fname=path, format='png')

    def show_plot(self):
        plt.show()

    def prepare_to_plot(self):
        """
        Prepares data to plot

        """
        interval = np.arange(*self._range, self.step)

        return np.array([self.function(x) for x in interval]), \
        np.array([self.deriv(x) for x in interval])

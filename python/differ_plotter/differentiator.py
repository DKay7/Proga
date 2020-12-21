import re
import numpy as np
from math import *
from types import FunctionType


class Differentiator:
    """
    This class' designation is to differentiate functions R^2 -> R
    """

    def __init__(self, function: str, eps: float=1e-9):
        self.function = self.parse(function)
        self.deriv_value = None
        self.eps = eps

        self.data_function_values = None
        self.data_deriv_values = None



    def diff(self, point: float)-> float:
        """
        Finds derrivative value in given point

        Args:

            point (int): Point to find derivative value in

        Returns:
        
            float: Derivation value in given point
        """

        assert self.eps != 0

        deriv = (self.function(point + self.eps) - self.function(point)) / (self.eps)

        return deriv

    def parse(self, function: str) -> FunctionType:
        """
        Parses function to make it lambda-expression

        Args:

            function (str): function to parse

        Returns:
            function: Parsed function
        """
        
        function = re.sub(r'[y, =]', r'', function)
        assert re.search(r'x', function) is not None

        return eval('lambda x: ' + function)
    
    def unit_test(self, deriv: FunctionType, _range: tuple, step: float=1e-1) -> bool:

        for point in np.arange(*_range, step):
            assert abs(self.diff(point) - deriv(point)) < 1, \
                f'Ошибка: различие аналитической и численной производной на ' +\
                f'{self.diff(point) - deriv(point)} в точке {point}. '

        print(f'{__name__} test was passed')


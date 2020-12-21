from plotter import Plotter
from differentiator import Differentiator


if __name__ == '__main__':

    continue_ = True

    while continue_:
        
        func = input('Input function in format \'y = x etc. \'\n')
        dif = Differentiator(func)

        range_ = tuple(map(float, 
            input('Input the range to plot graph in like: start stop\n').split()))

        plotter = Plotter(dif.function, dif.diff, range_)
        plotter.plot_2d_function()

        if input('type y if you want to save plot, else type n\n') == 'y':
            filename = input('Type the filename, or enter to keep it default\n')
            plotter.save_plot(filename if filename != '' else None)

        if input('type y if you want to see the plot, else type n\n') == 'y':
            plotter.show_plot()

        print('type q to close the program or enter to do it again\n')
        continue_ = input() == ''

    print('Goodbye!')
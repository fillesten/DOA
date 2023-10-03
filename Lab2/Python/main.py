import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def extract_column_data(file_name, column_index):
    # Initialize a list to store the extracted column data
    column_data = []

    # Open the text file for reading
    with open(file_name, 'r') as file:
        # Skip the first two lines
        next(file)
        next(file)
        # Iterate through the remaining lines
        for line in file:
            # Split the line into columns using whitespace as the delimiter
            columns = line.split()
            if len(columns) > column_index:
                try:
                    # Extract data from the specified column (column_index)
                    data = float(columns[column_index])  # Assuming the data is numeric
                    column_data.append(data)
                except ValueError:
                    # Handle cases where the data is not numeric
                    pass
    return column_data

# Function to extract the second column (index 1)
def extract_second_column(file_name):
    return extract_column_data(file_name, 1)

# Function to extract the third column (index 2)
def extract_third_column(file_name):
    return extract_column_data(file_name, 2)


def f1(i, a):
    return a * i ** 2


def n_log_n(N, a, b):
    return a * N * np.log(N) + b



def plot_sorting_algorithm(x, y, std_deviation, title, filename):

    fig, ax = plt.subplots()

    # Plot the data points
    ax.errorbar(x, y, yerr=std_deviation, fmt='+', label="data Points with Std Deviation Error Bars")

    # Fit the data to N^2 function
    params_n2, covariance_n2 = curve_fit(f1, x, y)
    x_fit_n2 = np.linspace(min(x), max(x), 1000)
    y_fit_n2 = f1(x_fit_n2, params_n2[0])
    ax.plot(x_fit_n2, y_fit_n2, label=f"Fit N^2")

    # Fit the data to N * log(N) function
    params_logn, covariance_logn = curve_fit(n_log_n, x, y)
    x_fit_logn = np.linspace(min(x), max(x), 1000)
    y_fit_logn = n_log_n(x_fit_logn, params_logn[0], params_logn[1])
    ax.plot(x_fit_logn, y_fit_logn, label=f"Fit N*log(N): {params_logn[0]:.4f} * N * log(N) + {params_logn[1]:.4f}")

    # Set labels and legend
    ax.set_xlabel("N elements")
    ax.set_ylabel("t [ms]")
    ax.set_title(title)
    ax.legend()

    x_ticks = np.arange(0, max(x) + 2000, 2000)
    ax.set_xticks(x_ticks)

    # Save the plot to a PDF file
    plt.savefig(filename)

    # Show the plot
    plt.show()



def four_way_plot(x, y_values, y_labels, algorithm):
    for i, y in enumerate(y_values):
        label = y_labels[i] if y_labels else f'Curve {i + 1}'
        plt.plot(x, y, label=label)

    plt.xlabel('N elements')
    plt.ylabel('T [ms')
    plt.title(algorithm)
    plt.legend()  # Add legend to differentiate the curves

    plt.grid(True)  # Optional: Add grid lines

    plt.savefig(algorithm)

    plt.show()  # Display the plot




if __name__ == '__main__':

    x = np.array([2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000])

    # --------------------------------------------- FALLING ---------------------------------------------
    # data for InsertionSort
    y_insertionSort_falling = extract_second_column("Falling/data/InsertionSortFalling.txt")
    std_deviation_insertionSort_falling = extract_third_column("Falling/data/InsertionSortFalling.txt")
    plot_sorting_algorithm(x,y_insertionSort_falling, std_deviation_insertionSort_falling, "InsertionSort -- Falling Series", "Falling/pdf/InsertionSortFalling.pdf")

    # data for QuickSort
    y_quickSort_falling = extract_second_column("Falling/data/QuickSortFalling.txt")
    std_deviation_quickSort_falling = extract_third_column("Falling/data/QuickSortFalling.txt")
    plot_sorting_algorithm(x, y_quickSort_falling, std_deviation_quickSort_falling, "QuickSort -- Falling Series", "Falling/pdf/QuickSortFalling.pdf")

    # data for QuickSortMedian3
    y_quickSortMedian3_falling = extract_second_column("Falling/data/QuickSortMedian3Falling.txt")
    std_deviation_quickSortMedian3_falling = extract_third_column("Falling/data/QuickSortMedian3Falling.txt")
    plot_sorting_algorithm(x, y_quickSortMedian3_falling, std_deviation_quickSortMedian3_falling, "QuickSortMedian3 -- Falling Series", "Falling/pdf/QuickSortMedian3Falling.pdf")

    # data for SelectionSort
    y_selectionSort_falling = extract_second_column("Falling/data/SelectionSortFalling.txt")
    std_deviation_selectionSort_falling = extract_third_column("Falling/data/SelectionSortFalling.txt")
    plot_sorting_algorithm(x, y_selectionSort_falling, std_deviation_selectionSort_falling, "SelectionSort -- Falling Series", "Falling/pdf/selectionSortFalling.pdf")

    # data for stdSort
    y_stdSort_falling = extract_second_column("Falling/data/stdSortFalling.txt")
    std_deviation_stdSort_falling = extract_third_column("Falling/data/stdSortFalling.txt")
    plot_sorting_algorithm(x, y_stdSort_falling, std_deviation_stdSort_falling, "stdSort -- Falling Series", "Falling/pdf/stdSortFalling.pdf")


    # --------------------------------------------- RANDOM ---------------------------------------------
    # Data for InsertionSort -- Random Series
    y_insertionSort_random = extract_second_column("Random/data/InsertionSortRandom.txt")
    std_deviation_insertionSort_random = extract_third_column("Random/data/InsertionSortRandom.txt")
    plot_sorting_algorithm(x, y_insertionSort_random, std_deviation_insertionSort_random, "InsertionSort -- Random Series", "Random/pdf/InsertionSortRandom.pdf")

    # Data for QuickSortMedian3 -- Random Series
    y_quickSortMedian3_random = extract_second_column("Random/data/QuickSortMedian3Random.txt")
    std_deviation_quickSortMedian3_random = extract_third_column("Random/data/QuickSortMedian3Random.txt")
    plot_sorting_algorithm(x, y_quickSortMedian3_random, std_deviation_quickSortMedian3_random, "QuickSortMedian3 -- Random Series", "Random/pdf/QuickSortMedian3Random.pdf")

    # Data for QuickSort -- Random Series
    y_quickSort_random = extract_second_column("Random/data/QuickSortRandom.txt")
    std_deviation_quickSort_random = extract_third_column("Random/data/QuickSortRandom.txt")
    plot_sorting_algorithm(x, y_quickSort_random, std_deviation_quickSort_random, "QuickSort -- Random Series", "Random/pdf/QuickSortRandom.pdf")

    # Data for SelectionSort -- Random Series
    y_selectionSort_random = extract_second_column("Random/data/SelectionSortRandom.txt")
    std_deviation_selectionSort_random = extract_third_column("Random/data/SelectionSortRandom.txt")
    plot_sorting_algorithm(x, y_selectionSort_random, std_deviation_selectionSort_random, "SelectionSort -- Random Series", "Random/pdf/SelectionSortRandom.pdf")

    # Data for stdSort -- Random Series
    y_stdSort_random = extract_second_column("Random/data/stdSortRandom.txt")
    std_deviation_stdSort_random = extract_third_column("Random/data/stdSortRandom.txt")
    plot_sorting_algorithm(x, y_stdSort_random, std_deviation_stdSort_random, "stdSort -- Random Series", "Random/pdf/stdSortRandom.pdf")


    # --------------------------------------------- RISING ---------------------------------------------
    # Data for InsertionSort -- Rising Series
    y_insertionSort_rising = extract_second_column("Rising/data/InsertionSortRising.txt")
    std_deviation_insertionSort_rising = extract_third_column("Rising/data/InsertionSortRising.txt")
    plot_sorting_algorithm(x, y_insertionSort_rising, std_deviation_insertionSort_rising, "InsertionSort -- Rising Series", "Rising/pdf/InsertionSortRising.pdf")

    # Data for QuickSortMedian3 -- Rising Series
    y_quickSortMedian3_rising = extract_second_column("Rising/data/QuickSortMedian3Rising.txt")
    std_deviation_quickSortMedian3_rising = extract_third_column("Rising/data/QuickSortMedian3Rising.txt")
    plot_sorting_algorithm(x, y_quickSortMedian3_rising, std_deviation_quickSortMedian3_rising, "QuickSortMedian3 -- Rising Series", "Rising/pdf/QuickSortMedian3Rising.pdf")

    # Data for QuickSort -- Rising Series
    y_quickSort_rising = extract_second_column("Rising/data/QuickSortRising.txt")
    std_deviation_quickSort_rising = extract_third_column("Rising/data/QuickSortRising.txt")
    plot_sorting_algorithm(x, y_quickSort_rising, std_deviation_quickSort_rising, "QuickSort -- Rising Series", "Rising/pdf/QuickSortRising.pdf")

    # Data for SelectionSort -- Rising Series
    y_selectionSort_rising = extract_second_column("Rising/data/SelectionSortRising.txt")
    std_deviation_selectionSort_rising = extract_third_column("Rising/data/SelectionSortRising.txt")
    plot_sorting_algorithm(x, y_selectionSort_rising, std_deviation_selectionSort_rising, "SelectionSort -- Rising Series", "Rising/pdf/SelectionSortRising.pdf")

    # Data for stdSort -- Rising Series
    y_stdSort_rising = extract_second_column("Rising/data/stdSortRising.txt")
    std_deviation_stdSort_rising = extract_third_column("Rising/data/stdSortRising.txt")
    plot_sorting_algorithm(x, y_stdSort_rising, std_deviation_stdSort_rising, "stdSort -- Rising Series", "Rising/pdf/stdSortRising.pdf")


    # --------------------------------------------- SAME ---------------------------------------------
    # Data for InsertionSort -- Same Series
    y_insertionSort_same = extract_second_column("Same/data/InsertionSortSame.txt")
    std_deviation_insertionSort_same = extract_third_column("Same/data/InsertionSortSame.txt")
    plot_sorting_algorithm(x, y_insertionSort_same, std_deviation_insertionSort_same, "InsertionSort -- Same Series", "Same/pdf/InsertionSortSame.pdf")

    # Data for QuickSortMedian3 -- Same Series
    y_quickSortMedian3_same = extract_second_column("Same/data/QuickSortMedian3Same.txt")
    std_deviation_quickSortMedian3_same = extract_third_column("Same/data/QuickSortMedian3Same.txt")
    plot_sorting_algorithm(x, y_quickSortMedian3_same, std_deviation_quickSortMedian3_same, "QuickSortMedian3 -- Same Series", "Same/pdf/QuickSortMedian3Same.pdf")

    # Data for QuickSort -- Same Series
    y_quickSort_same = extract_second_column("Same/data/QuickSortSame.txt")
    std_deviation_quickSort_same = extract_third_column("Same/data/QuickSortSame.txt")
    plot_sorting_algorithm(x, y_quickSort_same, std_deviation_quickSort_same, "QuickSort -- Same Series", "Same/pdf/QuickSortSame.pdf")

    # Data for SelectionSort -- Same Series
    y_selectionSort_same = extract_second_column("Same/data/SelectionSortSame.txt")
    std_deviation_selectionSort_same = extract_third_column("Same/data/SelectionSortSame.txt")
    plot_sorting_algorithm(x, y_selectionSort_same, std_deviation_selectionSort_same, "SelectionSort -- Same Series", "Same/pdf/SelectionSortSame.pdf")

    # Data for stdSort -- Same Series
    y_stdSort_same = extract_second_column("Same/data/stdSortSame.txt")
    std_deviation_stdSort_same = extract_third_column("Same/data/stdSortSame.txt")
    plot_sorting_algorithm(x, y_stdSort_same, std_deviation_stdSort_same, "stdSort -- Same Series", "Same/pdf/stdSortSame.pdf")


    y_insertionSort = [y_insertionSort_falling, y_insertionSort_random, y_insertionSort_rising, y_insertionSort_same]
    y_quickSortMedian3 = [y_quickSortMedian3_falling, y_quickSortMedian3_random, y_quickSortMedian3_rising, y_quickSortMedian3_same]
    y_quickSort = [y_quickSort_falling, y_quickSort_random, y_quickSort_rising, y_quickSort_same]
    y_selectionSort = [y_selectionSort_falling, y_selectionSort_random, y_selectionSort_rising, y_selectionSort_same]
    y_stdSort = [y_stdSort_falling, y_stdSort_random, y_stdSort_rising, y_stdSort_same]

    y_labels = ['Falling', 'Random', 'Rising', 'Same']

    four_way_plot(x, y_insertionSort, y_labels, 'Insertion Sort')
    four_way_plot(x, y_quickSortMedian3, y_labels, 'QuickSort median 3')
    four_way_plot(x, y_quickSort, y_labels, 'QuickSort')
    four_way_plot(x, y_selectionSort, y_labels, 'Selection Sort')
    four_way_plot(x, y_stdSort, y_labels, 'stdSort')





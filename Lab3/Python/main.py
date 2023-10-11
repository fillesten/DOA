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


def n_log_n(N, a, b):
    return a * N * np.log(N) + b

def plot_sorting_algorithm(x, y, std_deviation, title, filename):

    fig, ax = plt.subplots()

    # Plot the data points
    ax.errorbar(x, y, yerr=std_deviation, fmt='+', label="data Points with Std Deviation Error Bars")

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

    x_ticks = np.arange(0, max(x) + 10000, 10000)
    ax.set_xticks(x_ticks)
    ax.set_ylim(-0.01, 0.1)


    # Save the plot to a PDF file
    plt.savefig(filename)

    # Show the plot
    plt.show()


def four_way_plot(x, binary_file_name, bst_file_name, hash_file_name, linear_file_name):


    y_binary = extract_column_data(binary_file_name, 1)
    std_deviation_binary = extract_column_data(binary_file_name, 2)
    plt.errorbar(x, y_binary, yerr=std_deviation_binary, fmt='+', label="Binary")
    plt.plot(x, y_binary, label="_nolegend_")  # Plot lines without adding a new legend entry

    y_binarysearchtree = extract_column_data(bst_file_name, 1)
    std_deviation_binarysearchtree = extract_column_data(bst_file_name, 2)
    plt.errorbar(x=x, y=y_binarysearchtree, yerr=std_deviation_binarysearchtree, fmt='+', label="Binary Search Tree")
    plt.plot(x, y_binarysearchtree, label="_nolegend_")  # Plot lines without adding a new legend entry

    y_hash = extract_column_data(hash_file_name, 1)
    std_deviation_hash = extract_column_data(hash_file_name, 2)
    plt.errorbar(x, y_hash, yerr=std_deviation_hash, fmt='+', label="Hash")
    plt.plot(x, y_hash, label="_nolegend_")  # Plot lines without adding a new legend entry

    y_linear = extract_column_data(linear_file_name, 1)
    std_deviation_linear = extract_column_data(linear_file_name, 2)
    plt.errorbar(x, y_linear, yerr=std_deviation_linear, fmt='+', label="Linear")
    plt.plot(x, y_linear, label="_nolegend_")  # Plot lines without adding a new legend entry

    plt.xlabel('N elements')
    plt.ylabel('T [ms]')
    plt.title("Comparison")
    plt.legend(loc='best')  # Add legend to differentiate the curves
    # plt.legend()  # Add legend to differentiate the curves
    plt.grid(True)  # Optional: Add grid lines
    plt.savefig("SearchingCompariosn")
    plt.show()  # Display the plot


if __name__ == '__main__':

    x = np.array([10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000])

    y_binarysearch = extract_column_data("Data/BinarySearch.txt", 1)
    std_deviation_binarysearch = extract_column_data("Data/BinarySearch.txt", 2)
    plot_sorting_algorithm(x, y_binarysearch, std_deviation_binarysearch, "BinarySearch", "PDF/BinarySearch.pdf")

    y_bst = extract_column_data("Data/BinarySearchTree.txt", 1)
    std_deviation_bst = extract_column_data("Data/BinarySearchTree.txt", 2)
    plot_sorting_algorithm(x, y_bst, std_deviation_bst, "BinarySearchTree", "PDF/BinarySearchTree.pdf")

    y_hashtable = extract_column_data("Data/HashTable.txt", 1)
    std_deviation_hashtable = extract_column_data("Data/HashTable.txt", 2)
    plot_sorting_algorithm(x, y_hashtable, std_deviation_hashtable, "HashTable", "PDF/HashTable.pdf")

    y_linearsearch = extract_column_data("Data/LinearSearch.txt", 1)
    std_deviation_linearsearch = extract_column_data("Data/LinearSearch.txt", 2)
    plot_sorting_algorithm(x, y_linearsearch, std_deviation_linearsearch, "LinearSearch", "PDF/LinearSearch.pdf")

    four_way_plot(x, "Data/BinarySearch.txt", "Data/BinarySearchTree.txt", "Data/HashTable.txt", "Data/LinearSearch.txt")














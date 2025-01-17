import matplotlib.pyplot as plt

def calculator_with_labels():
    print("Welcome to the Calculator with Bar Chart Visualization!")
    print("1. Addition (+)")
    print("2. Subtraction (-)")
    print("3. Multiplication (*)")
    print("4. Division (/)")
    
    labels = []  # Operations as labels for the bar chart
    values = []  # Results as values for the bar chart
    
    n = int(input("How many calculations do you want to perform? "))
    
    for i in range(n):
        print(f"\nCalculation {i + 1}:")
        choice = input("Choose an operation (1/2/3/4): ")
        try:
            num1 = float(input("Enter the first number: "))
            num2 = float(input("Enter the second number: "))
            
            if choice == '1':
                result = num1 + num2
                labels.append(f"{num1} + {num2}")
                values.append(result)
            elif choice == '2':
                result = num1 - num2
                labels.append(f"{num1} - {num2}")
                values.append(result)
            elif choice == '3':
                result = num1 * num2
                labels.append(f"{num1} * {num2}")
                values.append(result)
            elif choice == '4':
                if num2 != 0:
                    result = num1 / num2
                    labels.append(f"{num1} / {num2}")
                    values.append(result)
                else:
                    print("Error: Division by zero is not allowed.")
                    labels.append(f"{num1} / {num2}")
                    values.append(0)  # Append zero for invalid division
            else:
                print("Invalid operation! Skipping this calculation.")
                labels.append("Invalid Operation")
                values.append(0)  # Append zero for invalid operations
            
        except ValueError:
            print("Invalid input! Please enter numeric values.")
            labels.append("Invalid Input")
            values.append(0)  # Append zero for invalid inputs
    
    return labels, values

def plot_bar_chart(labels, values):
    plt.bar(labels, values, color='blue')
    plt.xlabel("Operations")
    plt.ylabel("Results")
    plt.title("Calculator Results Visualization")
    plt.xticks(rotation=45, ha='right')  # Rotate labels for better visibility
    plt.tight_layout()  # Adjust layout to fit all labels
    plt.show()

# Main Program
labels, values = calculator_with_labels()
if labels and values:
    print("\nGenerating bar chart for your calculations...")
    plot_bar_chart(labels, values)
else:
    print("No calculations performed.")

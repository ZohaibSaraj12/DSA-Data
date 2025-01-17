import tkinter as tk

# Initialize the main window
window = tk.Tk()
window.title("Calculator")
window.geometry("400x500")
window.config(bg="lightgray")

# Entry widget to display the expression/result
expression = ""

def update_expression(value):
    global expression
    expression += str(value)
    entry_var.set(expression)

def clear():
    global expression
    expression = ""
    entry_var.set(expression)

def calculate():
    global expression
    try:
        # Evaluate the expression
        result = str(eval(expression))
        entry_var.set(result)
        expression = result
    except:
        entry_var.set("Error")
        expression = ""

# Entry widget for displaying the result
entry_var = tk.StringVar()
entry = tk.Entry(window, textvariable=entry_var, font=("Arial", 20), bd=10, insertwidth=4, width=14, borderwidth=4, justify="right")
entry.grid(row=0, column=0, columnspan=4)

# Creating buttons
button_texts = [
    ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('+', 1, 3),
    ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('-', 2, 3),
    ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('*', 3, 3),
    ('0', 4, 0), ('C', 4, 1), ('=', 4, 2), ('/', 4, 3)
]

# Create and place buttons dynamically
for (text, row, col) in button_texts:
    if text == "=":
        button = tk.Button(window, text=text, padx=20, pady=20, font=("Arial", 18), command=calculate)
    elif text == "C":
        button = tk.Button(window, text=text, padx=20, pady=20, font=("Arial", 18), command=clear)
    else:
        button = tk.Button(window, text=text, padx=20, pady=20, font=("Arial", 18), command=lambda t=text: update_expression(t))
    button.grid(row=row, column=col, padx=10, pady=10)

# Run the application
window.mainloop()

#functions to modulate a basic calucalator 
def add(n1, n2):
    return(n1 + n2)
def div(n1, n2):
#exception handling if divide by zero
    if n2==0:
        return("Error, Divide by zero")
    else:
        return(n1 / n2)
def sub(n1, n2):
     return(n1 - n2)
def mul(n1, n2):
    return(n1 * n2)
def rem(n1, n2):
    print(n1 % n2)


#printing the results
n1 = int(input("Enter First Number: "))
n2 = int(input("Enter Second Number: "))

print("Sum is: ", add(n1, n2))
print("Division is: ", div(n1, n2))
print("Subtraction is: ", sub(n1, n2))
print("Multiplication is: ", mul(n1, n2))
rem(n1, n2)




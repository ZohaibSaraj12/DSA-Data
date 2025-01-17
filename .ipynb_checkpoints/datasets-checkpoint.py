import pandas as pd

# Sample discrete dataset
data = {'Values': [3, 7, 4, 7, 10, 4, 3, 8, 7, 5]}
df = pd.DataFrame(data)

# Mean
mean_value = df['Values'].mean()
print(f"Mean (Discrete): {mean_value}")

# Median
median_value = df['Values'].median()
print(f"Median (Discrete): {median_value}")

# Mode
mode_value = df['Values'].mode()
print(f"Mode (Discrete): {mode_value.values}")  # Output all modes if there are multiple

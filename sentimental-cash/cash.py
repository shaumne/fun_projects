from cs50 import get_float

# Prompt the user for a non-negative float value for the amount of change owed
while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        break

# Convert dollars to cents
coins = round(dollars * 100)

# Initialize count of coins
count = 0

# Greedily select the largest coin denomination that fits and update the count
while coins > 0:
    if coins >= 25:
        coins -= 25
        count += 1
    elif coins >= 10:
        coins -= 10
        count += 1
    elif coins >= 5:
        coins -= 5
        count += 1
    else:
        coins -= 1
        count += 1

# Print the total number of coins used
print(count)

while True:
    height = input("Height: ")
    if height.isdigit():
        height = int(height)
        if 1 <= height <= 8:
            break
    print("Invalid input. Please enter a number between 1 and 8.")

for i in range(height):
    # Print the necessary number of spaces before each row of the pyramid.
    for j in range(height - i - 1):
        print(" ", end="")

    # Print the left half of the pyramid for this row.
    for j in range(i + 1):
        print("#", end="")

    # Print the gap between the left and right halves of the pyramid.
    print("  ", end="")

    # Print the right half of the pyramid for this row.
    for j in range(i + 1):
        print("#", end="")

    # Move to the next line to start the next row of the pyramid.
    print()
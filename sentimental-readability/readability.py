# Prompt user for a text input
text = input("Enter text: ")

# Initialize variables to count the number of letters, words, and sentences
num_of_letters = 0
num_of_words = 1
num_of_sentences = 0

# Iterate over each character in the text
for i in range(len(text)):
# If the character is a letter, increment the letter count
    if text[i].isalpha():
        num_of_letters += 1
    # If the character is a space, increment the word count
    elif text[i].isspace():
        num_of_words += 1
    # If the character is a period, exclamation point, or question mark, increment the sentence count
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        num_of_sentences += 1

# Calculate the average number of letters and sentences per 100 words
letters_per_100_words = num_of_letters / num_of_words * 100
sentences_per_100_words = num_of_sentences / num_of_words * 100

# Calculate the Coleman-Liau index of the text
index = 0.0588 * letters_per_100_words - 0.296 * sentences_per_100_words - 15.8
index = round(index)

# Print the grade level of the text
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
import re
import string

# Got help with opening a file in read and write mode for Python on GeeksForGeeks.org

def OptionOne(): # This function displays the amount of times each item in the list was purchased
    text = open("CS210_Project_Three_Input_File.txt", "r") # Open the file in read mode
    dictionary = {} # Create an empty dictionary
  
    for line in text: # Loop through each line of the file
        line = line.strip() # Remove the leading spaces and newline character
        words = line.split(" ") # Split the line into words
        
        for word in words:  # Iterate over each word in line
            if word in dictionary:  # Check if the word is already in dictionary
                dictionary[word] = dictionary[word] + 1  # Increment count of word by 1
            else:
                # Add the word to dictionary with count 1
                dictionary[word] = 1
  
    for key in list(dictionary.keys()): # Prints the contents of the dictionary
        print(key, ":", dictionary[key])
    text.close() #Close the file

def OptionTwo(word_search): # This function counts the amount of times searched word is repeatedd in .txt file
    text = open("CS210_Project_Three_Input_File.txt", "r") # Open the file in read mode
    dictionary = {word_search : 0} # Initialize the dictionary with key as the search word
    
    for line in text: # Loop through each line of the file
        line = line.strip() # Remove the leading spaces and newline character
        words = line.split(" ") # Split the line into words
        
        for word in words:  # Iterate over each word in line
            if word_search in dictionary:  # Check if the word user entered is already in dictionary
                count = words.count(word_search) # Count the word we are searching, if it is not there, it will be 0
                dictionary[word_search] = dictionary[word_search] + count  # Increment count of word by 1
            
    return dictionary[word_search] # Returns the amount of times the searched item was purchased
    text.close() #CLose the file
              
def OptionThree(): # Writes to a new file called frequency.dat 
    file1 = open("CS210_Project_Three_Input_File.txt", "r") # Open the file in read mode
    dictionary = {} # Create an empty dictionary
    file2 = open("frequency.dat", "w") # Creates frequency.dat and opens file for writing using "w"
  
    for line in file1: # Loop through each line of the file
        line = line.strip() # Remove the leading spaces and newline character
        words = line.split(" ") # Split the line into words
        
        for word in words:  # Iterate over each word in line
            if word in dictionary:  # Check if the word is already in dictionary
                dictionary[word] = dictionary[word] + 1  # Increment count of word by 1
            else:
                # Add the word to dictionary with count 1
                dictionary[word] = 1
    
    for key in list(dictionary.keys()): # Prints the contents of the dictionary
        string = key + " " + str(dictionary[key]) + "\n" #In order to concatenate, turn dictionary[key] into string, file2.write will oncle accept a string
        file2.write(string) #Writes item and number of times each item was purchased in frequency.dat file

    # Close both files
    file1.close()
    file2.close()
   

 
            
  
    
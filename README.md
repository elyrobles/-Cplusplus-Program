# -Cplusplus-Program

# Summarize the project and what problem it was solving.
For this project, I created an item-tracking app for a grocery store that analyzes the text records they generate throughout the day. These records list items from the time the store opens, to the time it closes. The store wanted to know how often specific items were purchased so they could create the best layout for their store. I then created a menu that lets the user choose to either list the frequency each item was purchased, a specific item that the user would like to look up and its frequency, and lastly, a histogram that displays all items and the amount of times each was purchased. 

# What did you do particularly well?
What I did particularly well in this project is linking between Python and C++, I created code in C++ that called for a fucntion in Python by either CallProcedure() or callIntFunc(). Then my functions in Python properly calculated each menu item and returned the value either back to C++ or was displayed directly from Python. 

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I am not very familiar with writing secure code, although I believe I do a good job at completeing the tasks required in the projects, I am still unfamiliar with the security aspect of coding, and that is something I need to improve on. 

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The most challenging part of creating this item-tracking app was when working on the second part of the project, which was to get the user input and search for the amount of times the user input was repeated in the txt file, return the frequency of each item from Python to C++,  then display the user input and frequency. I was confused on how to display the function from C++ when I was assuming it would display from Python. I then took a break out of frustration, came back the next day and re read the instructions, I then figured out that I needed to call a C++ function from main, and then from that C++ function, I used the callIntFunc() to call the Python function to calculate the amount of times the searched word was repeated, and lastly, that return value was displayed to C++ with cout << callintFunc("OptionTwo", userString). 

# What skills from this project will be particularly transferable to other projects or course work?
The skills from this project will be paritcularly transferable to other projects or course work because in future assignments I may be asked to integrate two languages again and call functions from a C++ file to a Python file, I now have a good understanding on how to accomplish that and apply it to many different scenarios.  

# How did you make this program maintainable, readable, and adaptable?
I made this program maintainable and readable by demonstrating industry standard best practices in my code that was clear and consistent, for example, user errors were corrected by displaying a message that would prompt the user to pick a number between 1-4, and the menu would display again. I also left in-line comments to describe the functionality of my code. 

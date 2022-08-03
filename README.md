# CLC
This is a Command Line Calculator capable of performing binary or unary operations, defining variables and assigning them values, performing operations with said variables, as well as accessing or erasing memory.
Running the code causes a menu to show up, asking which option you are interested in choosing. After the completion of each task you will continue to be asked for your next opetion until you choose to exit. Additionally, following each operation each result will be assigned to a new position in an array and be kept as memory.

Selecting B will allow you to peform binary calculations (ie. addition, substraction, etc.). For any reason if an invalid entry is made such as a character, then the previous quetion will be repeated to you until a valid number is entered. If an invalid number is entered, such as dividing by zero then a new number will be requested.
Selecting U will allow you to perform unary calculations (ie. square root, log). This follows the same parameters as option B. The entrnace of an invalid number of character will reprompt you for a valid entry.
Selecting V will allow you to pick a variable from 'a' to 'e' and then assign that character to a value. This variable and its value will then be assigned to memory.
Selecting A will allow you to use the previously assigned variables in other operations. When 'A' is selected a new menu will pop up and let you choose what type of operations you wish to perform as well as allowing you to choose any variable you'd already assigned a value to if you want to.
Selecting M will first display how many answers have been stored in memory then ask you to enter what element(answer) you would like to see or if you would like to exit.
Selecting R will erase all stored memory in the array.
Selecting X will exit the command line calculator and prompt a goodbye message.

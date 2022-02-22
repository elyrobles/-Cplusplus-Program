/*
* Project Three Submission by Elizabeth Robles
* Date: February 16, 2022
*/

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip> // For use of setw()
#include <fstream> //ftream class to read and write to files
#include <cctype> // For use of toupper in optionTwoFunction in C++

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);


}
/* This function will ask user for item they'd like to search for, then call the OptionTwo function in Python, we will get the returned value
   from Python and it will be displayed to the screen through our optionTwoFunction in C++ */
void optionTwoFunction() { 
	string userString;
	cout << "Input the item you wish to look for: " << endl;
	cin >> userString;
	userString[0] = toupper(userString[0]); // Will capitalize first letter of userString so it can be searched for in CS210_Project_Three_Input_File.txt file
	cout << endl;
	cout << userString << " was purchased ";
	cout << callIntFunc("OptionTwo", userString); // Calls OptionTwo function in Python
	cout << " times.";
	cout << endl;
}

void main() {
	system("Color 70"); // white background, black letters (not very familiar w/ colors yet)
	// Declaring variables
	int userInput;
	string item;
	int frequency;
	char star = '*';

	while (1) { // while(1) is an infinite loop that will continue to run until user enters 4 (which has the break statement)

		// Displays menu
		cout << "*******************************************************************************************************************" << endl;
		cout << "*                                                                                                                 *" << endl;
		cout << "*    1: Produce a list of all items purchased in a day along with the # of times each item was purchased          *" << endl;
		cout << "*    2: Produce a # representing how many times a specific item was purchased in a day                            *" << endl;
		cout << "*    3: Produce a text based histogram listing all items purchased in a given day                                 *" << endl;
		cout << "*    4: Exit program                                                                                              *" << endl;
		cout << "*                               Enter your selection as a number 1, 2, 3, or 4                                    *" << endl;
		cout << "*                                                                                                                 *" << endl;
		cout << "*******************************************************************************************************************" << endl;

		cin >> userInput;
		cout << endl;

		if (userInput == 1) { // If user enters 1, then call OptionOne function in Python to display the # of times each word is repeated in the list
			CallProcedure("OptionOne"); 
			cout << endl;
		}

		else if (userInput == 2) { // If user enters two, we call the optionTwoFunction in C++
			optionTwoFunction();
			cout << endl;
		}

		else if (userInput == 3) { // If user enters 3, we call OptionThree function in python then use frequency.dat created in the Python function to build histogram in C++
			CallProcedure("OptionThree");
			cout << endl;

			/* File object to read FROM a file */
			ifstream inFile;
			inFile.open("frequency.dat"); // frequency.dat opens using the input file object

			cout << "   Histogram of Items Purchased" << endl;
			cout << "-----------------------------------" << endl;
			if (!inFile) { // This will check if the file cannot be opened
				cout << "Cannot open file." << endl;
			}
			else {
				while (inFile >> item >> frequency) { // Will read item name and amount each item was purchased in each line
					cout << setw(15) << item << setw(5) << " " << string(frequency, star) << endl; // Displays item name and number of asteriks by multiplying asterik and frequency
				} 
			}
			inFile.close(); // Closes file object
		}
		
		else if (userInput == 4) { // If user enters 4, exit program
			break;
		}

 		else { // If user enters any number that is not 1-4 this message will display and menu will prompt user to enter a new value
			cout << "Please enter a number between 1 and 4" << endl; 
			cout << endl;
		}
	}
}
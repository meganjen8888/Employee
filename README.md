# Employee

This project is to store Employee objects using a binary search tree.

# Employee Class

It's the Employee.h file, with each object representing a single employee record to be stored.

Its InvalidEmployeeNmber class is an exception class.

Its Employee class contains private variables called name, number, and hireDate, which represents the Employee name, the Employee number, and the hire date.

## Public section

Its public things include the default constructor, which must be included in a header file when defining a class. It has all the private variables set to blank.

Its constructor has the strings aName, aNumber, and aDates as the parameters. It is to turn the employee numbers into integers and identify them as a "num" integer variable, which is used inside an if statement, where num is ranging from 0 to 9999. It puts the private variables as the parameters of the constructor, or else throw an InvalidEmployeeNumber exception. 

The setHireDate is simply to put the private hireDate variable as the parameter of that function, which is the date variable.

The function finally has three get Functions, which simply return the private variable of each one.

## EmployeeDB Class

The EmployeeDB class first needs a default constructor, which consists of simply a new EmpBinaryTree object named db being created.

It then has a definition of insertEmployee, which is a pointer of this pointing to db, calling the insertEmployee function on the parameter, which is an Employee object named e, which means it inserts that employee in the Employee Binary Tree.

The deleteEmployee takes a temp employee as an argument, and deletes the Employee from the BST with a matching name. It contains an if and else statement. If this is pointing to the searched employee named e from the db Employee Binary Tree, it removes "e" (the remove function is from the Binary Tree class), and then returns true, since it's a boolean function. If they didn't find said employee, they would return false.

The search Employee takes a string and returns this pointing to the db Employee Binary Tree getting the employee with the getEmployee function from the Binary Tree class, with a string named s in the parameter. 

## EmpBinaryTree class

The EmpBinary Tree class first defines the function insert, which has two TreeNode parameters, which are objects named nodePtr and newNode. TreeNode is a struct with an Employee object named e, and TreeNode objects left and right as members. The employee member is for getting the employee for the Employee class, and the left and right functions are for shifting to the left or right to insert or delete Employee objects. 

It is stating that if nodePtr is null, then it is defined to the newNode, which is a newly created Employee in the list. The nodePtr pointing to the left is then called null, and so is the nodePtr to the right. The nodePtr represents the location in the Employee list where the new Employee points to.

However if the name of the employee is on the left of the pointer of the name, then the nodePtr will move to the left. 

If none of the conditions in the insert function are happening, then the nodePtr is just inserted to the right.


For the destroySubTree class, it only contains one TreeNode object called nodePtr, which is again the pointer of the said node, which is an Employee object for the list. If the nodePtr is to the left of its location, then the function is called for the nodePtr on the left. Same goes with the nodePtr on the right, except it is called with the ptr on the right as an argument. If the nodePtr is on the desired location, then it just gets removed.

The deleteNode function first has an if statement; if nodePtr is null, then it returns a void. However, if the name of the employee object named e is on the left of the nodePtr, then it deletes the employee on the left, since e is an argument of the deleteNode function. If the name of the e employee object is on the right of the nodePtr's employee name, then it calls deleteNode on the e employee object, with the nodePtr to the right. When there are no nodePtrs to the left or the right, the makeDeletion function is called on the nodePtr, and void is returned. 

The makeDeletion function has nodePtr as the only argument. It introduces a TreeNode struct named tempNodePtr, and in the function first sets it as null. If the nodePtr is null, then the program releases a warning, saying it can't delete an empty node.

However, if the nodePtr is set on the left and the nodePtr set on the right is null, or there is nothing in the right of the desired location of the nodePtr, then tempNodePtr struct is set as nodePtr, and nodePtr is set as the pointer to the left. The new struct points to the Employee object's name which is blank at this time, and then the struct itself is set to null.

If the nodePtr is set to the right and there is nothing in the left of the desired location of the node, then the tempNodePtr is set to nodePtr once again, but the nodePtr is pointed to the right. TempNodePtr is once again having the employee object's name set to blank before going null.

If there is nothing in the list, then the nodePtr has the name of the employee object set to blank before the TreeNode object itself goes null.

If none of the events in the destroySubTree class is happening, then the tempNodePtr is set to nodePtr, and another TreeNode object named workPtr is created, and defined as the nodePtr going to the right.

The rightmost child employee info is then to be found to replace the employee info of the node to be deleted.

While the workPtr to the left is not null, the workPtr is repeatedly defined as the workPtr going to the left, until the workPtr to the left is all null. The tempNodePtr object is then having the employee's name set to the workPtr's employee's name.

The workPtr's employee's name is then set to blank, before the TreeNode object itself is declared null. This doesn't delete the node, but it overwrites the node with the employee to be deleted. It's cheaper in performance.

UPDATE 10/27/2021: Added a feature for the user. They can now enter the number of employees to be generated, and enter a name of an employee to be searched and deleted. I am currently making a menu for the main.cpp file.

UPDATE 10/27/2021, 9:55 PM: The menu has been added.
```cpp
	int choice;
	cout >> "Enter choice: "
	cin << choice;
	while (choice != 999) {
		switch (choice) {
		case 1:
			cout << "Enter the number of employees: " << endl;
			cin >> numEmployees;
			for (int i=0;i<numEmployees;i++){
				Employee e;
				std::string name = "Employee" + to_string(i);
				e.setName(name);
				std::cout << "Inserting: " << e.getName() << std::endl;
				db.insertEmployee(e);
			}
			break;
		case 2:
			std::cout << "\nDisplay Records" << std::endl;
			db.displayRecords();
			break;
		case 3:
			cout << endl << "Enter the name of the employee to be deleted " << endl;
			cin >> employeeToBeDeleted;
			Employee temp = db.searchEmployee(employeeToBeDeleted);

			std::cout << "Deleting: " << temp.getName()  << std::endl;
			db.deleteEmployee(temp);
			break;
		}
		case 4:
			std::cout << "\nDisplay Records" << std::endl;

			db.displayRecords();
			break;
		case 999:
			return 0;
		default:
			cout << "Invalid input";

	}
```
EDIT: That menu didn't work because there were syntax errors in the code. The cases all needed to be in the switch method, and there should be curly brackets around the working parts before I put "break" right outside the curly bracketed functions. Also, I only needed to put in the while(true) thing.
This is my fixed menu.
```cpp
	while (true) {
		cout << "Enter choice: " << endl;
		cin >> choice;
		switch (choice) {
		case 1:
		{
			cout << "Enter the number of employees: " << endl;
			cin >> numEmployees;
			for (int i=0;i<numEmployees;i++){
				Employee e;
				std::string name = "Employee" + to_string(i);
				e.setName(name);
				std::cout << "Inserting: " << e.getName() << std::endl;
				db.insertEmployee(e);
			}
		}
			break;
		case 2:
		{
			std::cout << "\nDisplay Records" << std::endl;
			db.displayRecords();
		}
			break;
		case 3:
		{
			cout << endl << "Enter the name of the employee to be deleted " << endl;
			cin >> employeeToBeDeleted;
			Employee temp = db.searchEmployee(employeeToBeDeleted);

			std::cout << "Deleting: " << temp.getName()  << std::endl;
			db.deleteEmployee(temp);
		}
			break;
		case 4:
			std::cout << "\nDisplay Records" << std::endl;

			db.displayRecords();
			break;
		case 999:
			return 0;
		default:
			cout << "Invalid input" << endl;
		}



	}
```
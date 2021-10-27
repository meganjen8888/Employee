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




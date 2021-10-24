#include <iostream>
#include <string>
#include "EmployeeDB.h"

using namespace std;

int main() {
	EmployeeDB db;

	for (int i=0;i<100;i++){
		Employee e;
		std::string name = "Employee" + to_string(i);
		e.setName(name);
		std::cout << "Inserting: " << e.getName() << std::endl;
		db.insertEmployee(e);
	}

	std::cout << "\nDisplay Records" << std::endl;
	db.displayRecords();

	Employee temp = db.searchEmployee("Employee99");

	std::cout << "Deleting: Employee99" << std::endl;
	db.deleteEmployee(temp);

	std::cout << "\nDisplay Records" << std::endl;
	db.displayRecords();
	return 0;
}

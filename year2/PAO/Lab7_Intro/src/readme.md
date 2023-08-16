### Implement console interaction as described in HrApplication class
#Implement get, update, delete for each repository
#Implement controller, service, repository methods

### Move the capitalizeString method in PersonUtil class in order to use it across the controllers

### Add an interface named PublicInformation that defines the method 
String displayPublicInformation();
#The interface will be implemented by Employee and Student classes 
#Use default method in interface in order to reuse the code

### Add a interface named CRUDRepository that will be implemented by StudentRepository / EmployeeRepository
#The interface will define the CRUD operations

### AUDIT - Log to the console each operation in the Repository
#Use Java records

### In the Repository, when adding a new object, check if it was not already added (same Student, same Employee)
#The CNP should be unique

### Add a new method in EmployeeController that will facilitate getting a copy of an Employee - see Clonenable interface 
#Add a new class, Address.java. Add a property of this type to each Employee. How is this affecting copying an Employee?








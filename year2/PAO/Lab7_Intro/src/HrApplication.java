import unibuc.controller.EmployeeController;
import unibuc.controller.StudentController;
import unibuc.model.Employee;
import unibuc.model.Person;
import unibuc.model.Student;

import java.util.Arrays;
import java.util.Scanner;

public class HrApplication {

    public static void main(String[] args) {
        //Using layered architecture

        EmployeeController employeeController = new EmployeeController();
        StudentController studentController = new StudentController();

        /*Add console interaction. Read instructions from the keyboard so the following is achieved:
         * Choose action using keyboard
         * "\nInsert option: \"1\": Add Student; \"1.1\": Get Student by CNP; " +
                    "\"1.2\": Update Student by CNP; \"1.3\": Delete Student by CNP; \"1.4\":List all Students;\n " +
                    "\"2\": Add Employee; \"2.1\": Get Employee by CNP; " +
                    "\"2.2\": Update Employee by CNP; \"2.3\": Delete Employee by CNP;" +
                    "\"2.4\": List all Employees"
         * Accept new commands until "stop" is eneterd from keyboard.
         * Display result of each action (e.g. New employee successful created: ...)
         * and display the available options to be inserted from the keyboard after executing each command.*/
        //INSERT code here

        System.out.println("HR Application ");
        Scanner sc = new Scanner(System.in);
        String option;
        do {
            System.out.println("\nInsert option: \"1\": Add Student; \"1.1\": Get Student by CNP; " +
                    "\"1.2\": Update Student by CNP; \"1.3\": Delete Student by CNP; \"1.4\":List all Students;\n " +
                    "\"2\": Add Employee; \"2.1\": Get Employee by CNP; " +
                    "\"2.2\": Update Employee by CNP; \"2.3\": Delete Employee by CNP;" +
                    "\"2.4\": List all Employees");
            option = sc.nextLine().trim();
            System.out.println("You inserted: " + option);
            switch (option) {
                case ("1") -> {
                    //read Student details from keyboard then call StudentController to insert Student
                    //TODO read firstName, lastName, cnp etc
                    boolean addedStudent = studentController.addStudent("mIrCiCa", "IONescU", "cnp");
                    System.out.println("Student added: " + addedStudent);
                }
                case ("1.4") -> {
                    Student[] allStudents = studentController.getAllStudents();
                    System.out.println("Students: " + Arrays.toString(allStudents));
                }
                case ("2") -> {
                    //read Employee details from keyboard then call EmployeeController to insert Employee
                    //TODO read firstName, lastName, cnp etc
                    boolean addedEmployee = employeeController.addEmployee("iONicA", "PopescU", "cnp");
                    System.out.println("Employee added: " + addedEmployee);
                }
                case ("2.4") -> {
                    Employee[] allEmployees = employeeController.getAllEmployees();
                    System.out.println("Employees: " + Arrays.toString(allEmployees));
                }
            }
        } while (!option.equals("stop"));
        sc.close();
    }
}
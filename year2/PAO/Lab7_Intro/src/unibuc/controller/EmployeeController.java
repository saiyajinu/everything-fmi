package unibuc.controller;

import unibuc.model.Employee;
import unibuc.service.EmployeeService;

public class EmployeeController {

    private EmployeeService employeeService;

    public EmployeeController() {
        this.employeeService = new EmployeeService();
    }

    public boolean addEmployee(String firstName, String lastName, String cnp) {
        //prelucrare si validare date primite de la interfata
        //delegare procesare date catre layerul de service - EmployeeService
        firstName = capitalizeString(firstName);
        lastName = capitalizeString(lastName);
        return employeeService.addEmployee(firstName, lastName, cnp);
    }

    public Employee[] getAllEmployees() {
        return employeeService.getAllEmployees();
    }

    private String capitalizeString (String str) {
        return str.substring(0,1).toUpperCase() + str.substring(1).toLowerCase();
    }
}

package unibuc.service;

import unibuc.model.Employee;
import unibuc.repository.EmployeeRepository;

public class EmployeeService {

    private EmployeeRepository employeeRepository;

    public EmployeeService() {
        employeeRepository = new EmployeeRepository();
    }

    public boolean addEmployee(String firstName, String lastName, String cnp) {
        //todo allocate registration number - procesari suplimentare
        Employee employee = new Employee(firstName, lastName, cnp);
        employee.setRegistrationNo(0); //TODO
        return this.employeeRepository.add(employee);
    }

    public Employee[] getAllEmployees() {
        return this.employeeRepository.getAll();
    }
}

package unibuc.repository;

import unibuc.model.Employee;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class EmployeeRepository {

    private Employee[] storedEmployees = new Employee[0];
    public boolean add(Employee employee) {
        try {
            //Create a new ArrayList using result of Arrays.asList, that returns a fixed size list
            List<Employee> arrlist = new ArrayList<>(
                    Arrays.asList(storedEmployees)
            );
            // Add the new element
            arrlist.add(employee);
            // Convert the Arraylist to array
            storedEmployees = arrlist.toArray(storedEmployees);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return false;
        }
        return true;
    }

    public Employee get(String cnp) {
        return null;
    }

    public Employee[] getAll() {
        return storedEmployees;
    }

    public boolean update(Employee student) {
        return false;
    }

    public boolean delete(String cnp) {
        return false;
    }
}

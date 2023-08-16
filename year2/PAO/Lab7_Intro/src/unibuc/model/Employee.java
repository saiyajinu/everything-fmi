package unibuc.model;

import java.util.Objects;

public class Employee extends Person {
    String departmentName;
    float salary;

    public Employee() {

    }

    public Employee(String firstName, String lastName, String cnp) {
        super(firstName, lastName, cnp);
        this.departmentName = "N/A";
        this.salary = 0;
    }

    public Employee(String firstName, String lastName, int registrationNo, String departmentName, float salary, String cnp) {
        super(firstName, lastName, registrationNo, cnp);
        this.departmentName = departmentName;
        this.salary = salary;
    }

    public String getDepartmentName() {
        return departmentName;
    }

    public void setDepartmentName(String departmentName) {
        this.departmentName = departmentName;
    }

    public float getSalary() {
        return salary;
    }

    public void setSalary(float salary) {
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", registrationNo=" + registrationNo +
                ", cnp='" + cnp + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        Employee employee = (Employee) o;
        return Float.compare(employee.salary, salary) == 0 && Objects.equals(departmentName, employee.departmentName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), departmentName, salary);
    }
}

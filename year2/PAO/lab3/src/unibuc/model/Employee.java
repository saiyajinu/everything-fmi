package unibuc.model;

public class Employee extends Person {
    String departmentName;
    float salary;

    public Employee(String fN, String lN, Integer regNo, String departmentName, float salary) {
        super(fN, lN, regNo);
        this.departmentName = departmentName;
        this.salary = salary;
        System.out.println("He is an employee in dep. " + departmentName + " and has a salary of " + salary);
    }

    public String getDepartmentName() {
        return departmentName;
    }

    public float getSalary() {
        return salary;
    }

    public void setDepartmentName(String departmentName) {
        this.departmentName = departmentName;
    }

    public void setSalary(float salary) {
        this.salary = salary;
    }
}

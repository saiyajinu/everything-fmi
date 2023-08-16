package unibuc.model;

import java.util.Objects;

public class Student extends Person {
    String group;
    int startYear;

    public Student() {
    }

    public Student(String firstName, String lastName, String cnp) {
        super(firstName, lastName, cnp);
        this.group = "N/A";
        this.startYear = 2023;
    }

    public Student(String firstName, String lastName, int registrationNo, String group, int startYear, String cnp) {
        super(firstName, lastName, registrationNo, cnp);
        this.group = group;
        this.startYear = startYear;
    }

    public String getGroup() {
        return group;
    }

    public void setGroup(String group) {
        this.group = group;
    }

    public int getStartYear() {
        return startYear;
    }

    public void setStartYear(int startYear) {
        this.startYear = startYear;
    }

    @Override
    public String toString() {
        return "Student{" +
                "group='" + group + '\'' +
                ", startYear=" + startYear +
                ", firstName='" + firstName + '\'' +
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
        Student student = (Student) o;
        return startYear == student.startYear && Objects.equals(group, student.group);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), group, startYear);
    }
}

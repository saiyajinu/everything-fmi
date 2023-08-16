package unibuc.repository;

import unibuc.model.Employee;
import unibuc.model.Student;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class StudentRepository {

    private Student[] storedStudents = new Student[0];
    public boolean add(Student student) {
        try {
            //Create a new ArrayList using result of Arrays.asList, that returns a fixed size list
            List<Student> arrlist = new ArrayList<>(
                    Arrays.asList(storedStudents)
            );
            // Add the new element
            arrlist.add(student);
            // Convert the Arraylist to array
            storedStudents = arrlist.toArray(storedStudents);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return false;
        }
        return true;
    }

    public Student get(String cnp) {
        return null;
    }

    public Student[] getAll() {
        return storedStudents;
    }

    public boolean update(Student student) {
        return false;
    }

    public boolean delete(String cnp) {
        return false;
    }
}

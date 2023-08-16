package unibuc.service;

import unibuc.model.Employee;
import unibuc.model.Student;
import unibuc.repository.StudentRepository;

public class StudentService {

    private StudentRepository studentRepository;

    public StudentService() {
        studentRepository = new StudentRepository();
    }

    public boolean addStudent(String firstName, String lastName, String cnp) {
        //todo allocate registration number - procesari suplimentare
        Student student = new Student(firstName, lastName, cnp);
        student.setRegistrationNo(0); //TODO
        return this.studentRepository.add(student);
    }

    public Student[] getAllStudents() {
        return this.studentRepository.getAll();
    }
}

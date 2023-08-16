package unibuc.controller;

import unibuc.model.Employee;
import unibuc.model.Student;
import unibuc.service.StudentService;

public class StudentController {
    private StudentService studentService;

    public StudentController() {
        this.studentService = new StudentService();
    }

    public boolean addStudent(String firstName, String lastName, String cnp) {
        //prelucrare si validare date primite de la interfata
        //delegare procesare date catre layerul de service - StudentService
        firstName = capitalizeString(firstName);
        lastName = capitalizeString(lastName);
        return studentService.addStudent(firstName, lastName, cnp);
    }

    public Student[] getAllStudents() {
        return studentService.getAllStudents();
    }

    private String capitalizeString (String str) {
        return str.substring(0,1).toUpperCase() + str.substring(1).toLowerCase();
    }
}

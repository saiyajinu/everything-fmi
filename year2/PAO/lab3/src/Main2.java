import unibuc.model.Employee;
import unibuc.model.Person;
import unibuc.model.Student;

import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        Person[] pers;

        Scanner sc = new Scanner(System.in);
        String line = "";
        System.out.println("1: Create Person");
        System.out.println("2: Create Student");
        System.out.println("3: Create Employee");

        while(!line.equals("stop")){

            line = sc.nextLine();
            if (line.toString().equals("1")){
                System.out.print("Insert first name: ");
                String fn = sc.nextLine();
                System.out.print("Insert last name: ");
                String ln = sc.nextLine();
                System.out.println("Insert reg no: ");
                Integer reg = Integer.valueOf(sc.nextLine());
                Person pers = new Person(fn,ln,reg);
            }
            if(line.toString().equals("3")){
                System.out.print("Insert first name: ");
                String fn = sc.nextLine();
                System.out.print("Insert last name: ");
                String ln = sc.nextLine();
                System.out.println("Insert reg no: ");
                Integer reg = Integer.valueOf(sc.nextLine());
                System.out.print("Insert dep. name: ");
                String dep = sc.nextLine();
                System.out.print("Insert salary: ");
                Float sal = Float.valueOf(sc.nextLine());
                Employee emp = new Employee(fn,ln,reg,dep,sal);
            }
            if(line.toString().equals("2")){
                System.out.print("Insert first name: ");
                String fn = sc.nextLine();
                System.out.print("Insert last name: ");
                String ln = sc.nextLine();
                System.out.println("Insert reg no: ");
                Integer reg = Integer.valueOf(sc.nextLine());
                System.out.print("Insert group: ");
                String gr = sc.nextLine();
                System.out.print("Insert startYear: ");
                Integer yr = Integer.valueOf(sc.nextLine());
                Student stud = new Student(fn,ln,reg,gr,yr);
            }
            System.out.println("1: Create Person");
            System.out.println("2: Create Student");
            System.out.println("3: Create Employee");

        }
        sc.close();




    }
}

import unibuc.model.Employee;
import unibuc.model.Person;
import unibuc.model.Student;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //System.out.println("Hello world!");
        /* Create an object of type Person, p1, using the implicit constructor.
         * Display the created object */

        Person p1 = new Person();
        System.out.println(p1);


        /* Override toString() method to display the attributes of the Person class, concatenated.
         * How does the output change when displaying the created object with the new toString() implementation. */
        Boolean b = true;
        System.out.println(p1.toString(b));


        /* Set values to the attributes of Person class using a custom constructor.

        Add a custom constructor to Person.java. Fix issues in child classes.
        Create a new object of type Person, p2, using custom constructor. */
        //INSERT code here

        String fN = "fName";
        String lN = "lName";
        Integer regNo = 123;
        Person p2 = new Person(fN, lN, regNo);
        System.out.println(p2);
        System.out.println(p2.toString(b));


        /*Display "firstName" attribute of objects of type Person by changing the access modifier.
         * What changes are required in Person class? */
        //INSERT code here




        /* Display attributes of objects of type Person using getter methods, applying encapsulation.
         * Add getter methods to class. Call the getters for a Person object. */
        //INSERT code here
        System.out.println(p2.getFirstName());



        /* Change attributes of objects of type Person using setter methods.
         * Add setter methods to class. Call the setters for a Person object and display the new values. */
        //INSERT code here
        p2.setFirstName("Firstname");
        System.out.println(p2.toString(b));




        /*Add constructors, getters, setters, override toString for child classes.
         * Create and display objects of each type. */
        //INSERT code here



        /*Add console interaction. Read instructions from the keyboard so the following is achieved:
         * Choose action by typing: "1": Create Person; "2": Create Student; "3": Create Employee;
         * Accept new commands until "stop" is eneterd from keyboard.
         * Display result of each action (e.g. New person successful created with the following attributes: ...)
         * and display the available options to be inserted from the keyboard after executing each command.*/
        //INSERT code here




    }
}
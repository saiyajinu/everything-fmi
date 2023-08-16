package unibuc.model;

import java.util.Objects;

public class Person {
    String firstName;
    String lastName;
    int registrationNo;

    String cnp;

    public Person() {
    }

    public Person(String firstName, String lastName, String cnp) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.cnp = cnp;
    }

    public Person(String firstName, String lastName, int registrationNo, String cnp) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.registrationNo = registrationNo;
        this.cnp = cnp;
    }

    /*Add getters, setters*/
    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public int getRegistrationNo() {
        return registrationNo;
    }

    public void setRegistrationNo(int registrationNo) {
        this.registrationNo = registrationNo;
    }

    public String getCnp() {
        return cnp;
    }

    public void setCnp(String cnp) {
        this.cnp = cnp;
    }

    /* Override toString() method*/

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Person person = (Person) o;
        return registrationNo == person.registrationNo && Objects.equals(firstName, person.firstName) && Objects.equals(lastName, person.lastName) && Objects.equals(cnp, person.cnp);
    }

    @Override
    public int hashCode() {
        return Objects.hash(firstName, lastName, registrationNo, cnp);
    }
}

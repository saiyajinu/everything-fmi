package unibuc.model;

public class Person {
    private String firstName;
    private String lastName;
    private int registrationNo;

    public Person(){
        this.firstName = "null";
        this.lastName = "null";
        this.registrationNo = 0;
    }

    /*Custom constructor.*/
    //INSERT code here
    public Person(String fN, String lN, Integer regNo){
        this.firstName = fN;
        this.lastName = lN;
        this.registrationNo = regNo;
        System.out.println("Initialized Person: " + fN +" " + lN +" "  + regNo);
    }



    /*Add getters, setters*/
    //INSERT code here

    public String getFirstName(){
        return this.firstName;
    }

    public String getLastName(){
        return this.lastName;
    }

    public Integer getRegNo(){
        return this.registrationNo;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setRegistrationNo(int registrationNo) {
        this.registrationNo = registrationNo;
    }

    /* Override toString() method*/
    public String toString(Boolean b){
        return this.getFirstName() + ' ' + this.getLastName() + ", reg no. " + getRegNo();
    }




}

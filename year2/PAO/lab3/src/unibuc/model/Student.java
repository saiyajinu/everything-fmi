package unibuc.model;

public class Student extends Person {
    String group;
    int startYear;

    public Student(String fN, String lN, Integer regNo, String group, int startYear) {
        super(fN, lN, regNo);
        this.group = group;
        this.startYear = startYear;
        System.out.println("He/She is a student in group " + group + " and started in " + startYear);
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
}

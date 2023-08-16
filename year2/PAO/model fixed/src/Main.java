class A{
    public static void metoda(String s) {
        System.out.println("A"+s);
    }
}
class B extends A{
    public static void metoda(String s){
        System.out.println("B"+s);
    }
    public void metoda(String s, String t){
        System.out.println("B"+s+t);
    }
}

public class Main {
    public static void main(String[] args) {
        A ob = new B();
        String q = "q";
        String r = "r";
        ob.metoda("P");
        ob.metoda(q,r);
    }
}
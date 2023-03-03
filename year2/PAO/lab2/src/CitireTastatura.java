import java.util.Scanner;

public class CitireTastatura {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //System.out.print("Enter your name: ");
        String name = sc.nextLine();
        //System.out.println("Name is: " + name);
        while(!name.equals("stop"))
            name = sc.nextLine();
        sc.close();

    }
}
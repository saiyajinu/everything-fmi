public class Main {
    public static void main(String[] args) {
        Byte varsta = new Byte((byte)20);
        System.out.println(varsta);
        int hash = varsta.hashCode();
        System.out.println(hash);
        Byte varstaMajorat = new Byte("18");
        varsta = varstaMajorat;
        System.out.println(varsta);
        varsta = 2;
        System.out.println(varsta);
        System.out.println(varstaMajorat);
    }
}
package Sub_2Iunie;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

class Suvenir{
    private String denumire;
    private String material;
    private int cantitate;
    private double pret;

    public String getDenumire() {
        return denumire;
    }

    public void setDenumire(String denumire) {
        this.denumire = denumire;
    }

    public String getMaterial() {
        return material;
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    public int getCantitate() {
        return cantitate;
    }

    public void setCantitate(int cantitate) {
        this.cantitate = cantitate;
    }

    public double getPret() {
        return pret;
    }

    public void setPret(double pret) {
        this.pret = pret;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Suvenir suvenir = (Suvenir) o;
        return cantitate == suvenir.cantitate && Double.compare(suvenir.pret, pret) == 0 && Objects.equals(denumire, suvenir.denumire) && Objects.equals(material, suvenir.material);
    }

    @Override
    public int hashCode() {
        return Objects.hash(denumire, material, cantitate, pret);
    }

    @Override
    public String toString() {
        return "Suvenir{" +
                "denumire='" + denumire + '\'' +
                ", material='" + material + '\'' +
                ", cantitate=" + cantitate +
                ", pret=" + pret +
                '}';
    }
}

class Fir extends Thread{
    String fileTaraba;
    String material;
    Double pret;

    public Double getPret() {
        return pret;
    }

    public Fir(String file, String mat){
        fileTaraba = file;
        material = mat;
    }

    @Override
    public void run(){
        try{
            Scanner sc = new Scanner(new File(fileTaraba));
            double pret = 0.0;
            while(sc.hasNextLine()){
                String[] line = sc.nextLine().split("[, ]+");   // denumire material cantitate pret_unitar
                System.out.println(line[0]);
                if(line[1].equals(material)){
                    pret = pret + Double.parseDouble(line[2]) * Double.parseDouble(line[3]);
                }
            }
            this.pret = pret;
            sc.close();
        }catch(FileNotFoundException e){throw new RuntimeException(e);}
    }


}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Scanner sc = new Scanner(System.in);
        String mat = sc.nextLine();
        sc.close();
        Fir trb1 = new Fir("stoisko_1.txt", mat);
        Fir trb2 = new Fir("stoisko_2.txt", mat);
        trb1.start();
        trb2.start();
        trb1.join();
        trb2.join();
        double pretTotal = trb1.getPret() + trb2.getPret();
        System.out.println(pretTotal);
    }
}

package Subiect_1Iunie;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

class Fir extends Thread{
    int nivel;
    static int numar = 0;
    public Fir(int n){nivel = n;}

    @Override
    public void run(){
        System.out.print(nivel + " ");
        if(nivel < 2){
            Fir fir = new Fir(nivel+1);
            fir.start();
        }
        if(nivel < 14){
            Fir fir = new Fir(nivel+1);
            fir.start();
        }
    }
}

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Fir fir = new Fir(0);
        fir.start();

    }
}


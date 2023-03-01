using System.ComponentModel;

namespace Lab2App
{
    class Program
    {
        void Palindrom(int n)
        {
            int cn = n, pn = 0;
            while(cn != 0)
            {
                pn = pn * 10;
                pn = pn + cn % 10;
                cn = cn / 10;
            }
            if (n == pn) 
            { 
                Console.WriteLine("Numarul {0} este palindrom", n); 
            }
            else
            { 
                Console.WriteLine("Numarul {0} nu este palindrom", n); 
            }
        }

        void CheckParity(int[] arr, int n)
        {
            bool parity = true;
            for(int i = 0; i < n-1; i++)
            {
                if (arr[i] % 2 == arr[i + 1] % 2)
                    parity = false;
            }
            if(parity) { Console.WriteLine("paritate alternanta"); }
            else { Console.WriteLine("paritate consecutiva"); }
        }
        static void Main(string[] args)
        {
            var program = new Program();
            int n;
            //Console.WriteLine("Verifica palindrom: ");
            //n = int.Parse(Console.ReadLine());
            //program.Palindrom(n);

            Console.WriteLine("Marime vector: ");
            n = int.Parse(Console.ReadLine());

            int[] arr = new int[n];

            for (int i = 0; i < n; i++)
                arr[i] = int.Parse(Console.ReadLine());

            program.CheckParity(arr, n);
        }
    }

}


using Microsoft.AspNetCore.Mvc;

namespace Curs3.Controllers
{
    public class ExamplesController : Controller
    {
        public string Index(string str1, string str2)
        {
            string response = str1 + str2;

            return response;

            //return View();
        }

        public string Index1(int int1, int? int2)
        {
            if (int2 != null)
            {
                string response = (int1 * int2).ToString();
                return response;
            }
            else 
            {
                string response = "Introduceti ambele valori";
                return response;
            }
        }

        public string Index2(int? int1, int? int2, string? op)
        {
            string response = "Introduceti parametrul ";
            if (int1 == null) 
            { 
                response = response + '1';
                return response;
            }
            if (int2 == null)
            {
                response = response + '2';
                return response;
            }
            if ( op == null)
            {
                response = response + '3';
                return response;
            }

            if(op == "plus") 
            {
                int intresponse = (int)(int1 + int2);
                response = intresponse.ToString();
                return response;
            }

            if (op == "minus")
            {
                int intresponse = (int)(int1 - int2);
                response = intresponse.ToString();
                return response;
            }

            if (op == "ori")
            {
                int intresponse = (int)(int1 * int2);
                response = intresponse.ToString();
                return response;
            }

            if (op == "div")
            {
                int intresponse = (int)(int1 / int2);
                response = intresponse.ToString();
                return response;
            }

            return response = "wrong";

        }
    }
}

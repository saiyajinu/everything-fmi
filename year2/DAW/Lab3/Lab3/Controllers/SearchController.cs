using Microsoft.AspNetCore.Mvc;
using System.Text.RegularExpressions;

namespace Lab3.Controllers
{
    public class SearchController : Controller
    {
        public string NumarTelefon(string telefon)
        {
            if (telefon.Length < 10)
                return "Numarul nu are suficiente cifre";

            Regex tel = new Regex("0\\d+");
            if (tel.IsMatch(telefon))
                return "Numar corect";
            else return "Numar gresit";
        }

        public string CNP(string cnp)
        {
            if (cnp.Length < 13)
                return "cnp-ul nu are suficiente cifre";

            Regex cnpreg = new Regex("(1|2|5|6)\\d+");
            if (cnpreg.IsMatch(cnp))
                return "cnp corect";
            else return "cnp gresit";
        }
    }
}

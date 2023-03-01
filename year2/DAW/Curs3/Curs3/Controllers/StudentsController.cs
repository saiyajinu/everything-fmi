using Microsoft.AspNetCore.Mvc;

namespace Curs3.Controllers
{
    public class StudentsController : Controller
    {
        public string Index(string name, int? id)
        {
            string response = "Hello " + name + " ";
            if (id != null)
            {
                response = response + "id = " + id;
            }
            return response;

            //return View();
        }
    }
}

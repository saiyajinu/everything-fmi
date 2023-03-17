using curs5.Models;
using Microsoft.AspNetCore.Mvc;

namespace curs5.Controllers
{
    public class ArticlesController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        private readonly AppDbContext db;
        public ArticlesController(AppDbContext context)
        {
            db = context;
        }
    }
}

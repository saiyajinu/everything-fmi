using Lab4.Models;
using Microsoft.AspNetCore.Mvc;


namespace Lab4.Controllers
{
    public class ArticlesController : Controller
    {
        public IActionResult Index()
        {
            Article[] articles = GetArticles();
            // Se adauga array-ul de articole in View
            ViewBag.Articles = articles;
            return View();
        }

        [NonAction]       
        public Article[] GetArticles()
        {
            // Se instantiaza un array de articole
            Article[] articles = new Article[3];
            // Se creeaza articolele
            for (int i = 0; i < 3; i++)
            {
                Article article = new Article();
                article.Id = i;
                article.Title = "Articol " + (i + 1).ToString();
                article.Content = "Continut articol " + (i + 1).ToString();
                article.Date = DateTime.Now;
                // Se adauga articolul in array
                articles[i] = article;
            }
            return articles;
        }
        public IActionResult ErrorShow()
        {
            return View();
        }

        public IActionResult Show(int? id)
        {
            Article[] articles = GetArticles();
            try
            {
                ViewBag.Article = articles[(int)id];
                return View();
            }
            catch (Exception e)
            {
                ViewBag.ErrorMessage = e.Message;
                return View("Error");
            }

        }

    }
}

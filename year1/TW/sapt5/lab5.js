function anotimpuri() {
    let listElements = document.getElementsByTagName("li");
  for (let i = 0; i <= listElements.length; i++) {
    const [season, emoji] = listElements[i].textContent.split(' '); // ['primavara', 'emoji'];
    const next = listElements[i].nextElementSibling?.textContent || '';
    listElements[i].textContent = `${emoji} Anotimpul ${i}
            (urmat de ${next})`;
  }
}

setTimeout(anotimpuri, 2000);


<article>
  <article>lorem...</article>
</article>


function addInfo(info, ...classes) {
  let articles = document.querySelectorAll('article article');
  articles.forEach(article => {
    const p = document.createElement('p');
    p.textContent = info;
    
    p.className = classes.join(' '); // 'cls1 cls2'
    
    // classes.forEach((cls) => {
    //   p.classList.add(cls);
    // });
    
    article.append(p);
  });
}

window.onload = () => {
  addInfo('ceva', 'cls1', 'clas2');
}


<p>lorem</p>
<p>lorem</p>
<button>Gaseste</button>

--JS
function changeStyle(p) {
  p.style.color = "blue";
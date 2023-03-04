var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapControllerRoute(
    name: "concat",
    pattern: "concatenare/{str1}/{str2}",
    defaults: new { controller = "Examples", action = "Index" });

app.MapControllerRoute(
    name: "produs",
    pattern: "produs/{int1}/{int2?}",
    defaults: new { controller = "Examples", action = "Index1" });

app.MapControllerRoute(
    name: "op",
    pattern: "operatie/{int1?}/{int2?}/{op?}",
    defaults: new { controller = "Examples", action = "Index2" }
    );

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();

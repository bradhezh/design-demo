using Minimal.Hello;

var builder = WebApplication.CreateBuilder(args);
builder.Services.AddTransient<IHelloService, HelloService>();
var app = builder.Build();

app.MapHelloEndpoints();

app.Run();

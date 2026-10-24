namespace CtlrDemo;

using CtlrDemo.Hello;

public class Program {
  public static void Main(string[] args) {
    // For DI (builder.Services), configs (builder.Configuration, appsettings.json, ...), logging
    // providers (builder.Logging, ILogger), the web host (builder.WebHost) and env
    // (builder.Environment), ...
    var builder = WebApplication.CreateBuilder(args);
    builder.Services.AddTransient<IHelloService, HelloService>();
    // Controllers are actually created for each request via DefaultControllerActivator, mainly for
    // performance, while still with dependencies for DI to manage. To register controllers
    // themselves to DI, use builder.Services.AddControllers().AddControllersAsServices(), which
    // registers them transient by default.
    builder.Services.AddControllers();
    // Build all into the app
    var app = builder.Build();

    // Wire up the controllers with attribute routing
    app.MapControllers();

    app.Run();
  }
}

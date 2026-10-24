namespace CtlrDemo.Hello;

// Actually, all public, non-generic, non-abstract, and non-static classes with the "Controller"
// suffix or [Controller] (or derived from one with [Controller], like ControllerBase) are
// controllers.
// For API features like automatic validation and param inference, requiring attribute routing
[ApiController]
// For attribute routing. Without attributes for routing, controllers should still be wired up
// imperatively like:
// app.MapControllerRoute(name: "default", pattern: "{controller=Home}/{action=Index}/{id?}");
// which wires up controllers according to their class and method names.
[Route("[controller]")]
public class HelloController(IHelloService helloService): ControllerBase {
  // Can also be used for attribute routing
  [HttpGet]
  public IActionResult Hello() {
    return Ok(helloService.Hello());
  }
}

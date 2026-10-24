namespace Minimal.Hello;

public static class HelloEndpoints {
  // `this` on the 1st param makes it (a static method in a static class) an extension method for
  // IEndpointRouteBuilder
  public static IEndpointRouteBuilder MapHelloEndpoints(this IEndpointRouteBuilder app) {
    var group = app.MapGroup("/hello");

    group.MapGet("/", (IHelloService helloService) => {
      return Results.Text(helloService.Hello());
    });

    return app;
  }
}

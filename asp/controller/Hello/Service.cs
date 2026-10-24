namespace CtlrDemo.Hello;

public interface IHelloService {
  string Hello();
}

public class HelloService: IHelloService {
  public string Hello() => "Hello, Controllers!";
}

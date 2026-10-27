namespace Ava.Hello;

public interface IHelloService {
  string Hello();
}

public class HelloService: IHelloService {
  public string Hello() => "Hello, Avalonia!";
}

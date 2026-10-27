using Ava.Views;
using Ava.ViewModels;
using Ava.Hello;

namespace Ava;

public partial class App: Application {
  public override void Initialize() { AvaloniaXamlLoader.Load(this); }

  public override void OnFrameworkInitializationCompleted() {
    if (ApplicationLifetime is IClassicDesktopStyleApplicationLifetime desktop) {
      //desktop.MainWindow = new MainWindow { DataContext = new MainViewModel() };
      // Only use DI for models and view-models, not for views because they are typically
      // instantiated with XAML (requiring param-less constructors) or possibly by ViewLocator
      var services = new ServiceCollection()
        .AddSingleton<IHelloService, HelloService>()
        .AddSingleton<MainViewModel>().BuildServiceProvider();
      desktop.MainWindow =
        new MainWindow { DataContext = services.GetRequiredService<MainViewModel>() };
      desktop.Exit += (_, _) => services.Dispose();
    }
    base.OnFrameworkInitializationCompleted();
  }
}

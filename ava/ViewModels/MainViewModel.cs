using Ava.Hello;

namespace Ava.ViewModels;

public partial class MainViewModel(IHelloService helloService): ViewModelBase {
  // Generate code for the PropertyChanged event, which will be triggered on the property changes.
  // Although views can get these properties and update controls for PropertyChanged in app-specific
  // ways, with XAML binding, views can work in a universal way, via either reflection
  // (ReflectionBinding) or source generation (CompileBinding, as the default in Avalonia 12).
  [ObservableProperty]
  public partial string Message { get; set; } = "";
  [ObservableProperty]
  public partial string CommandText { get; set; } = "Greet";

  // Generate code for a command property with the method name and "Command" suffix (ToggleCommand
  // here), and with the method as its action. Commands implement a standard interface (ICommand)
  // for XAML binding, supporting CanExecute and CanExecuteChanged out of the box.
  [RelayCommand]
  private void Toggle() {
    if (string.IsNullOrEmpty(Message)) {
      Message = helloService.Hello();
      CommandText = "Clear";
    } else {
      Message = "";
      CommandText = "Greet";
    }
  }
}

#include <gtk/gtk.h>

#include "controllers/main.h"
#include "hello/service.h"

#define GTK_BTN_ON_CLICKED "clicked"

static void on_toggle_clicked(GtkButton *toggle, gpointer editable) {
  g_return_if_fail(toggle && editable);
  GtkEditable *message = GTK_EDITABLE(editable);

  if (!g_strcmp0(gtk_editable_get_text(message), "")) {
    gtk_editable_set_text(message, hello());
    gtk_button_set_label(toggle, "Clear");
  } else {
    gtk_editable_set_text(message, "");
    gtk_button_set_label(toggle, "Greet");
  }
}

void on_app_activate(GtkApplication *app, gpointer user_data) {
  g_return_if_fail(app);
  // GtkBuilder won't take ownership of windows and widgets, and windows (with contained widgets)
  // should be destroyed via gtk_window_destroy instead of ref counts. By default, GTK also destroys
  // windows on the "close-request" signal (e.g. the close button being clicked).
  GtkBuilder *builder = gtk_builder_new_from_resource("/gtk/demo/main.ui");
  GtkWindow *window = GTK_WINDOW(gtk_builder_get_object(builder, "window"));
  GtkEntry *message = GTK_ENTRY(gtk_builder_get_object(builder, "message"));
  GtkButton *toggle = GTK_BUTTON(gtk_builder_get_object(builder, "toggle"));

  gtk_window_set_application(window, app);
  g_signal_connect(toggle, GTK_BTN_ON_CLICKED, G_CALLBACK(on_toggle_clicked), message);
  gtk_window_present(window);

  g_object_unref(builder);
}

#include <glib-object.h>
#include <raylib.h>

#include "component.h"
#include "window.h"

#define PADDING 4

// Class
struct _Com {
  GObject parent_instance;

  /* For derivable classes
  struct _ComPrivate {
  */
  char *text;
  int font_size;
  Rectangle rec;
  Win *win;
};

// G_DEFINE_TYPE(MyClass, my_class, PARENT_TYPE):
// static gpointer my_class_parent_class = NULL; // Parent metadata
// GType my_class_get_type() {
//  // Register the class for the 1st call, and return its ID
//  // Registration process:
//  // Allocate the metadata with its parent_class cloned from parent metadata, register it for the
//  // class into the system, including necessary wiring-up like my_class_init, also wire up
//  // my_class_parent_class
//  // Call my_class_class_init with the metadata
// }
// G_DEFINE_TYPE_WITH_PRIVATE also implements private members defined by `struct _MyClassPrivate`
// and provides my_class_get_instance_private to access them.
G_DEFINE_TYPE(Com, com, G_TYPE_INITIALLY_UNOWNED)

static void com_finalize(GObject *obj) {
  Com *self = COM_FLOATING_OBJ(obj);
  g_free(self->text);
  if (self->win) {
    g_object_remove_weak_pointer(G_OBJECT(self->win), (gpointer *)&self->win);
  }
  G_OBJECT_CLASS(com_parent_class)->finalize(obj);
}

/* Properties, only necessary for derivable classes
// Note that all GObject objects are created via g_object_new, which calls my_class_init in a
// universal way, and properties can be used to init objects with custom args, because g_object_new
// can set properties right after my_class_init. This is the only way to init parent_instance of
// objects with args, but only necessary for derivable classes, because my_class_new with those args
// described in the signature should typically be provided, which is enough for finals.
enum { PROP_0, TEXT, FONT_SIZE, REC, WIN, PROP_N };
enum { FONT_SIZE_MIN = 8, FONT_SIZE_MAX = 64, FONT_SIZE_DEF = 12 };
static GParamSpec *props[PROP_N] = {NULL};
static void com_set_property(GObject *obj, guint id, GValue const *value, GParamSpec *spec) {
  Com *self = COM_FLOATING_OBJ(obj);
  gpointer p;
  switch (id) {
  case TEXT:
    g_free(self->text);
    self->text = g_value_dup_string(value);
    g_return_if_fail(self->text);
    break;
  case FONT_SIZE:
    self->font_size = g_value_get_int(value);
    break;
  case REC:
    p = g_value_get_pointer(value);
    g_return_if_fail(p);
    self->rec = *(Rectangle *)p;
    break;
  case WIN:
    p = g_value_get_object(value);
    g_return_if_fail(p);
    self->win = (Win *)p;
    g_object_add_weak_pointer(G_OBJECT(self->win), (gpointer *)&self->win);
    win_add_com(self->win, self);
    break;
  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, id, spec);
    break;
  }
}
*/

enum { CLICKED, SIGNAL_N };
static guint signals[SIGNAL_N] = {0};

static void com_class_init(ComClass *klass) {
  GObjectClass *gobj_class = G_OBJECT_CLASS(klass);
  gobj_class->finalize = com_finalize;

  /* Properties, only necessary for derivable classes
  gobj_class->set_property = com_set_property;
  props[TEXT] = g_param_spec_string(P_TEXT, NULL, NULL, "", G_PARAM_CONSTRUCT | G_PARAM_WRITABLE);
  props[FONT_SIZE] = g_param_spec_int(P_FONT_SIZE,
                                      NULL,
                                      NULL,
                                      FONT_SIZE_MIN,
                                      FONT_SIZE_MAX,
                                      FONT_SIZE_DEF,
                                      G_PARAM_CONSTRUCT | G_PARAM_WRITABLE);
  props[REC] = g_param_spec_pointer(P_REC, NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_WRITABLE);
  props[WIN] =
      g_param_spec_object(P_WIN, NULL, NULL, WIN_TYPE, G_PARAM_CONSTRUCT_ONLY | G_PARAM_WRITABLE);
  g_object_class_install_properties(gobj_class, PROP_N, props);
  */

  signals[CLICKED] = g_signal_new(
      ON_CLICKED,
      COM_TYPE,
      G_SIGNAL_RUN_LAST,
      0,
      g_signal_accumulator_true_handled, // Stop emission on the 1st TRUE return from multiple slots
      NULL,
      // NULL for g_cclosure_marshal_generic handling arbitrary signatures dynamically. There are
      // also built-in static marshallers like g_cclosure_marshal_VOID__VOID
      NULL,
      G_TYPE_BOOLEAN,
      1,
      G_TYPE_STRING);
}

static void com_init(Com *self) {}

Com *com_new(char const *text, int font_size, Rectangle const *rec, Win *win) {
  /* Create with properties, only necessary for derivable classes
  return g_object_new(COM_TYPE, P_TEXT, text, P_FONT_SIZE, font_size, P_REC, rec, P_WIN, win, NULL);
  */

  // Disabled for release with G_DISABLE_CHECKS defined
  g_return_val_if_fail(text && rec && win, NULL);
  Com *com = COM_FLOATING_OBJ(g_object_new(COM_TYPE, NULL));
  com->text = g_strdup(text);
  com->font_size = font_size;
  com->rec = *rec;
  win_add_com(win, com);
  com->win = win;
  g_object_add_weak_pointer(G_OBJECT(com->win), (gpointer *)&com->win);
  return com;
}

Rectangle const *com_rec(Com const *self) {
  g_return_val_if_fail(self, NULL);
  return &self->rec;
}

void com_render(Com const *self) {
  g_return_if_fail(self);
  DrawRectangleRec(self->rec, GREEN);
  DrawText(self->text, self->rec.x + PADDING, self->rec.y + PADDING, self->font_size, BLACK);
}

void com_clicked(Com *self) {
  g_return_if_fail(self);
  gboolean ret;
  g_signal_emit(self, signals[CLICKED], 0, "emission", &ret);
  TraceLog(LOG_INFO, "Last return: %d", ret);
}

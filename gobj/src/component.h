#ifndef COMPONENT_H
#define COMPONENT_H

#include <glib-object.h>
#include <raylib.h>

/* Properties, only necessary for derivable classes
#define P_TEXT "text"
#define P_FONT_SIZE "font_size"
#define P_REC "rec"
// Only for init
#define P_WIN "win"
*/

// Signals
#define ON_CLICKED "onClicked"

typedef struct _Win Win;

// The 4th param is usually a bare name for parent objects.
// G_DECLARE_FINAL_TYPE(MyClass, my_class, MY_CLASS, OBJ, Parent):
// typedef struct _MyClass MyClass; // Class
// This class metadata is mainly a virtual function table.
// typedef struct { ParentClass parent_class; } MyClassClass;
// GType my_class_get_type(); // Get the class ID (also register the class for the 1st call)
// MY_CLASS_OBJ(obj) // Castor for instances
// MY_CLASS_IS_OBJ(obj) // Checker for instances
// G_DECLARE_DERIVABLE_TYPE:
// Differences:
// Definition instead of declaration for layout compatibility across derived classes. Real data
// members should therefore be defined in implementations.
// typedef struct _MyClass { Parent parent_instance; } MyClass;
// Declaration instead of definition since derivable classes typically have virtual functions to
// define in metadata
// typedef struct _MyClassClass MyClassClass;
// Additions: For virtual functions
// MY_CLASS_OBJ_CLASS(class) // Castor for metadata
// MY_CLASS_IS_OBJ_CLASS(class) // Checker for metadata
// MY_CLASS_OBJ_GET_CLASS(obj) // Get metadata from instances
// GInitiallyUnowned instead of GObject for floating objects. All objects derived from GObject are
// managed via reference counting, created via g_object_new with 1 initial ref, while floating
// objects must sink before their ref counts work. Floating implies no owners, but the initial ref
// count is still 1. Therefore g_object_ref increasing refs can't be used for floating objects,
// while g_object_ref_sink not increasing floating refs but eliminating floating marks has to be
// used instead to assume their ownership. Note that g_object_ref_sink is the same as g_object_ref
// for normal objects without floating marks. Typically, UI components are initially floating to be
// managed by their containers. GObject also supports weak references (g_object_add_weak_pointer,
// g_object_remove_weak_pointer), which are basically pointers without g_object_ref to assume target
// ownership, but will automatically clear the pointer to NULL when the target is finalised.
G_DECLARE_FINAL_TYPE(Com, com, COM, FLOATING_OBJ, GInitiallyUnowned)
#define COM_TYPE (com_get_type())

Com *com_new(char const *text, int font_size, Rectangle const *rec, Win *win);
Rectangle const *com_rec(Com const *self);
void com_render(Com const *self);
void com_clicked(Com *self);

#endif // COMPONENT_H

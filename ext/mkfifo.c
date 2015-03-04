#include <ruby/ruby.h>
#include <string.h>
#include <sys/stat.h>

VALUE rb_cFile_mkfifo(VALUE, VALUE);

void
Init_mkfifo(void) {
    rb_define_singleton_method(rb_cFile, "mkfifo", rb_cFile_mkfifo, 1);
}

/* Document-method: File::mkfifo
 *
 * call-seq:
 * mkfifo(path) → an_integer
 *
 * Creates a named pipe at +path+. Raises +IOError+ if
 * the operation fails.
 */
VALUE
rb_cFile_mkfifo(VALUE self, VALUE name) {
    FilePathValue(name);

    if (mkfifo(RSTRING_PTR(name), S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) < 0) {
        rb_raise(rb_eIOError, "Cannot create named pipe");
    }

    return INT2FIX(1);
}

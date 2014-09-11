#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([ac-arg-with-sample], [0.1.0], [hayashi@clear-code.com])
AC_CONFIG_SRCDIR([ac-arg-with-sample.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([config])
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

AC_ARG_WITH([gstreamer-version],
            AS_HELP_STRING([--with-gstreamer-version=@<:@auto/1.0/0.10@:>@],
                           [Gstreamer version (default: auto)]),
            [with_gstreamer_version=$withval],
            [with_gstreamer_version=auto])
echo $with_gstreamer_version
case "$with_gstreamer_version" in
    "0.10")
        GSTREAMER_REQUIRED=0.10.35
        GST_MAJORMINOR=0.10
        ;;
    "1.0")
        GSTREAMER_REQUIRED=1.0.0
        GST_MAJORMINOR=1.0
        ;;
    *)
        PKG_CHECK_EXISTS(gstreamer-1.0,
                         [GSTREAMER_REQUIRED=1.0.0 GST_MAJORMINOR=1.0],
                         [GSTREAMER_REQUIRED=0.10.36 GST_MAJORMINOR=0.10])
       ;;
esac
PKG_CHECK_MODULES(GST, gstreamer-$GST_MAJORMINOR >= $GSTREAMER_REQUIRED)
gstreamer_version=`pkg-config --modversion gstreamer-$GST_MAJORMINOR`

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

echo "GStreamer: ${gstreamer_version}"

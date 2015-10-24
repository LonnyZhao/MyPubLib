#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.69)
AC_INIT(Lonny_Base_LIB, 0.1, zhaochenglong08@126.com)
AM_INIT_AUTOMAKE()
AC_CONFIG_SRCDIR([include/dlist.h])
#AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_PROG_RANLIB
AC_CONFIG_FILES([Makefile
                 include/Makefile
                 src/Makefile
                 src/dlist/Makefile
                 src/sort/Makefile])
AC_OUTPUT

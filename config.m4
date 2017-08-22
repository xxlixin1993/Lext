dnl $Id$
dnl config.m4 for extension lx

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(lx, for lx support,
dnl Make sure that the comment is aligned:
dnl [  --with-lx             Include lx support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(lx, whether to enable lx support,
Make sure that the comment is aligned:
[  --enable-lx           Enable lx support])

if test "$PHP_LX" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-lx -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/lx.h"  # you most likely want to change this
  dnl if test -r $PHP_LX/$SEARCH_FOR; then # path given as parameter
  dnl   LX_DIR=$PHP_LX
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for lx files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       LX_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$LX_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the lx distribution])
  dnl fi

  dnl # --with-lx -> add include path
  dnl PHP_ADD_INCLUDE($LX_DIR/include)

  dnl # --with-lx -> check for lib and symbol presence
  dnl LIBNAME=lx # you may want to change this
  dnl LIBSYMBOL=lx # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LX_DIR/$PHP_LIBDIR, LX_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_LXLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong lx lib version or lib not found])
  dnl ],[
  dnl   -L$LX_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(LX_SHARED_LIBADD)

  PHP_NEW_EXTENSION(lx, lx.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi

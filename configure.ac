#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(boost_trial, 0.1, lilinj2000@gmail.com)
AC_CONFIG_SRCDIR([])
#AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
LT_INIT
AC_PROG_RANLIB
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
#AC_CHECK_HEADER_STDBOOL

dnl check c++11 features
dnl AX_CXX_COMPILE_STDCXX_11([ext|noext],[mandatory|optional])
AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])
dnl AX_CHECK_COMPILE_FLAG([-std=c++11], [CXXFLAGS="$CXXFLAGS -std=c++11"])

AC_CHECK_PROGS(GCOV, [gcov-mp-4.8 gcov], gcov)

# Checks for library functions.
LT_RELEASE=0.1
LT_CURRENT=0
LT_REVISION=1
LT_AGE=0
AC_SUBST(LT_RELEASE)
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)

home_3rd=~/3rd
home_libs=~/libs

dnl soil lib
AC_ARG_WITH([soil],
    [AS_HELP_STRING([--with-soil],
        [home path of the soil, defaults to $home_libs/soil])],
    [SOIL_HOME="$withval"],
    [SOIL_HOME="$home_libs/soil"])
AC_SUBST([SOIL_HOME])

SOIL_CPPFLAGS="-I$SOIL_HOME/include"
SOIL_LIBADD="$SOIL_HOME/lib/libsoil.la"
AC_SUBST(SOIL_CPPFLAGS)
AC_SUBST(SOIL_LIBADD)

dnl boost lib
AC_ARG_WITH([boost],
    [AS_HELP_STRING([--with-boost],
        [home path of the boost, defaults to $home_3rd/boost])],
    [BOOST_HOME="$withval"],
    [BOOST_HOME="$home_3rd/boost"])
AC_SUBST([BOOST_HOME])

BOOST_CPPFLAGS="-I$BOOST_HOME/include -DBOOST_ALL_DYN_LINK"
BOOST_LIBADD="$BOOST_HOME/lib/libboost_log_setup.so \
              $BOOST_HOME/lib/libboost_log.so \
	      $BOOST_HOME/lib/libboost_filesystem.so \
  	      $BOOST_HOME/lib/libboost_program_options.so \
	      $BOOST_HOME/lib/libboost_regex.so \
	      $BOOST_HOME/lib/libboost_thread.so \
	      $BOOST_HOME/lib/libboost_chrono.so \
	      $BOOST_HOME/lib/libboost_date_time.so \
	      $BOOST_HOME/lib/libboost_system.so"
AC_SUBST(BOOST_CPPFLAGS)
AC_SUBST(BOOST_LIBADD)

dnl gtest lib
AC_ARG_WITH([gtest],
    [AS_HELP_STRING([--with-gtest],
        [home path of the gtest, defaults to $home_3rd/googletest])],
    [GTEST_HOME="$withval"],
    [GTEST_HOME="$home_3rd/googletest"])
AC_SUBST([GTEST_HOME])

GTEST_CPPFLAGS=-I$GTEST_HOME/include
GTEST_LIBADD="$GTEST_HOME/lib/libgtest.a $GTEST_HOME/lib/libgtest_main.a"
AC_SUBST(GTEST_CPPFLAGS)
AC_SUBST(GTEST_LIBADD)

###########################
# gcov coverage reporting
###########################
AC_TDD_GCOV
AC_SUBST(COVERAGE_CFLAGS)
AC_SUBST(COVERAGE_CXXFLAGS)
AC_SUBST(COVERAGE_LDFLAGS)

AC_OUTPUT([
	Makefile
	utest/Makefile])



AUTOMAKE_OPTIONS = foreign

noinst_PROGRAMS = unittest

unittest_SOURCES = PosixTimeTest.cc RegexTest.cc

unittest_CPPFLAGS = -I$(top_srcdir) -I.. -I../include\
		$(BOOST_CPPFLAGS) \
		$(GTEST_CPPFLAGS) \
		$(SOIL_CPPFLAGS)

unittest_LDADD = \
	$(GTEST_LIBADD) \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD)


unittest_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = 

EXTRA_DIST = env.sh





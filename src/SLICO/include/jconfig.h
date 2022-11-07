/* jconfig.h.  Generated from jconfig.cfg by configure.  */
/* jconfig.cfg --- source file edited by configure script */
/* see jconfig.txt for explanations */

#define HAVE_PROTOTYPES 1
#define HAVE_UNSIGNED_CHAR 1
#define HAVE_UNSIGNED_SHORT 1
/* #undef void */
/* #undef const */
/* #undef CHAR_IS_UNSIGNED */
#define HAVE_STDDEF_H 1
#define HAVE_STDLIB_H 1
#define HAVE_LOCALE_H 1
/* #undef NEED_BSD_STRINGS */
/* #undef NEED_SYS_TYPES_H */
/* #undef NEED_FAR_POINTERS */
/* #undef NEED_SHORT_EXTERNAL_NAMES */
/* Define this if you get warnings about undefined structures. */
/* #undef INCOMPLETE_TYPES_BROKEN */

/* Define "boolean" as unsigned char, not int, on Windows systems. */
#ifdef _WIN32
#ifndef __RPCNDR_H__		/* don't conflict if rpcndr.h already read 
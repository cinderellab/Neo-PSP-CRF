#ifdef __cplusplus
# error "A C++ compiler has been selected for C."
#endif

/* Version number components: V=Version, R=Revision, P=Patch
   Version date components:   YYYY=Year, MM=Month,   DD=Day  */

#if defined(__18CXX)
# define ID_VOID_MAIN
#endif

#if defined(__INTEL_COMPILER) || defined(__ICC)
# define COMPILER_ID "Intel"
  /* __INTEL_COMPILER = VRP */
# define COMPILER_VERSION_MAJOR DEC(__INTEL_COMPILER/100)
# define COMPILER_VERSION_MINOR DEC(__INTEL_COMPILER/10 % 10)
# define COMPILER_VERSION_PATCH DEC(__INTEL_COMPILER    % 10)
# if defined(__INTEL_COMPILER_BUILD_DATE)
  /* __INTEL_COMPILER_BUILD_DATE = YYYYMMDD */
#  define COMPILER_VERSION_TWEAK DEC(__INTEL_COMPILER_BUILD_DATE)
# endif

#elif defined(__PATHCC__)
# define COMPILER_ID "PathScale"
# define COMPILER_VERSION_MAJOR DEC(__PATHCC__)
# define COMPILER_VERSION_MINOR DEC(__PATHCC_MINOR__)
# if defined(__PATHCC_PATCHLEVEL__)
#  define COMPILER_VERSION_PATCH DEC(__PATHCC_PATCHLEVEL__)
# endif

#elif defined(__clang__)
# define COMPILER_ID "Clang"
# define COMPILER_VERSION_MAJOR DEC(__clang_major__)
# define COMPILER_VERSION_MINOR DEC(__clang_minor__)
# define COMPILER
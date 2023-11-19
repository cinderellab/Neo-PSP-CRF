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
# define COMPILER_VERSION_MAJOR DEC(__INT
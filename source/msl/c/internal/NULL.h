#if !defined(NULL)
#  if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L) ||                                \
      (defined(__cplusplus) && __cplusplus >= 201103L)
#    define NULL nullptr
#  elif !defined(__cplusplus)
#    define NULL ((void*) 0)
#  else
#    define NULL 0
#  endif
#endif

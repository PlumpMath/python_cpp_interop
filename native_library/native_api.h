#ifndef NATIVE_LIBRARY_NATIVE_API_H_
#define NATIVE_LIBRARY_NATIVE_API_H_

#if defined(_WIN32)
  #ifdef NATIVE_LIBRARY_EXPORTS
    #define DLL_PUBLIC __declspec(dllexport)
  #else
    #define DLL_PUBLIC __declspec(dllimport)
  #endif
#else
  #define DLL_PUBLIC
#endif

extern "C" {

DLL_PUBLIC int CalculateSquareRoot(int length, const char* data);

DLL_PUBLIC int RetrieveResult(char* data);

}

#endif  // NATIVE_LIBRARY_NATIVE_API_H_
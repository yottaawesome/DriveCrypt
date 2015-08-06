// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CRYPTOGRAPHY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CRYPTOGRAPHY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CRYPTOGRAPHY_EXPORTS
#define CRYPTOGRAPHY_API __declspec(dllexport)
#else
#define CRYPTOGRAPHY_API __declspec(dllimport)
#endif

// This class is exported from the Cryptography.dll
class CRYPTOGRAPHY_API CCryptography {
public:
	CCryptography(void);
	// TODO: add your methods here.
};

extern CRYPTOGRAPHY_API int nCryptography;

CRYPTOGRAPHY_API int fnCryptography(void);

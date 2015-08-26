#pragma once

#ifdef WIN32GUI_EXPORTS
#define WIN32GUI_API __declspec(dllexport)
#else
#define WIN32GUI_API __declspec(dllimport)
#endif

extern WIN32GUI_API int meaningOfLife;
//Main.h

#pragma once
#ifdef REAPERDAWHUBDLL_EXPORTS
#define REAPERDAWHUBDLL_API __declspec(dllexport) 
#else
#define REAPERDAWHUBDLL_API __declspec(dllimport) 
#endif
extern bool g_juce_inited;
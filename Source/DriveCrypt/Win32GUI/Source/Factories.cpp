#include "../Headers/Win32GUI.h"

IFormBuilder* FormBuilderFactory::operator() ()
{
	return new FormBuilder();
}

void* FormBuilderFactory::Construct()
{
	return new FormBuilder();
}

FormBuilderFactory::~FormBuilderFactory() { }
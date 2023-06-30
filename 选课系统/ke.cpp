#include "ke.h"
void ke::add(int NO, char NAME[], char T[])
{
	ke_no = NO;
	strcpy_s(ke_name, NAME);
	strcpy_s(ke_teacher, T);
}

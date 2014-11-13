#ifndef RANDOMMT_C_H
#define RANDOMMT_C_H

#ifdef __cplusplus
extern "C"
{
#endif

void RandomMT_create(unsigned long int);
void RandomMT_destroy();
double genMatlabMT();

#ifdef __cplusplus
}
#endif

#endif     //-- RANDOMMT_C_H

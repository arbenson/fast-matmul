#include "RandomMT_C.h"
#include "RandomMT.h"

static RandomMT* global_object;

void RandomMT_create(unsigned long int nnSeed)
{ global_object = new RandomMT(nnSeed); }

void RandomMT_destroy()
{ delete global_object; }

double genMatlabMT()
{ return global_object->genMatlabMT(); }

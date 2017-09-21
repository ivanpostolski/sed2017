#include "pmodeladm.h"
#include "register.h"


#include "persona1.h"
#include "persona2.h"
#include "persona3.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	
	admin.registerAtomic(NewAtomicFunction<Persona1>(), "Persona1");
	admin.registerAtomic(NewAtomicFunction<Persona2>(), "Persona2");
	admin.registerAtomic(NewAtomicFunction<Persona3>(), "Persona3");
}
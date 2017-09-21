#include "pmodeladm.h"
#include "register.h"


#include "persona1.h"
#include "persona2.h"
#include "persona3.h"
#include "persona4.h"
#include "persona5.h"
#include "persona6.h"
#include "persona7.h"
#include "persona8.h"
#include "persona9.h"
#include "persona10.h"
#include "persona11.h"
#include "persona12.h"
#include "persona13.h"
#include "persona14.h"
#include "persona15.h"
#include "persona16.h"
#include "persona17.h"
#include "persona18.h"
#include "persona19.h"
#include "persona20.h"
#include "persona21.h"
#include "persona22.h"
#include "persona23.h"
#include "persona24.h"
#include "persona25.h"
#include "persona26.h"
#include "persona27.h"
#include "persona28.h"


void register_atomics_on(ParallelModelAdmin &admin)
{
	
	admin.registerAtomic(NewAtomicFunction<Persona1>(), "Persona1");
	admin.registerAtomic(NewAtomicFunction<Persona2>(), "Persona2");
	admin.registerAtomic(NewAtomicFunction<Persona3>(), "Persona3");
	admin.registerAtomic(NewAtomicFunction<Persona4>(), "Persona4");
	admin.registerAtomic(NewAtomicFunction<Persona5>(), "Persona5");
	admin.registerAtomic(NewAtomicFunction<Persona6>(), "Persona6");
	admin.registerAtomic(NewAtomicFunction<Persona7>(), "Persona7");
	admin.registerAtomic(NewAtomicFunction<Persona8>(), "Persona8");
	admin.registerAtomic(NewAtomicFunction<Persona9>(), "Persona9");
	admin.registerAtomic(NewAtomicFunction<Persona10>(), "Persona10");
	admin.registerAtomic(NewAtomicFunction<Persona11>(), "Persona11");
	admin.registerAtomic(NewAtomicFunction<Persona12>(), "Persona12");
	admin.registerAtomic(NewAtomicFunction<Persona13>(), "Persona13");
	admin.registerAtomic(NewAtomicFunction<Persona14>(), "Persona14");
	admin.registerAtomic(NewAtomicFunction<Persona15>(), "Persona15");
	admin.registerAtomic(NewAtomicFunction<Persona16>(), "Persona16");
	admin.registerAtomic(NewAtomicFunction<Persona17>(), "Persona17");
	admin.registerAtomic(NewAtomicFunction<Persona18>(), "Persona18");
	admin.registerAtomic(NewAtomicFunction<Persona19>(), "Persona19");
	admin.registerAtomic(NewAtomicFunction<Persona20>(), "Persona20");
	admin.registerAtomic(NewAtomicFunction<Persona21>(), "Persona21");
	admin.registerAtomic(NewAtomicFunction<Persona22>(), "Persona22");
	admin.registerAtomic(NewAtomicFunction<Persona23>(), "Persona23");
	admin.registerAtomic(NewAtomicFunction<Persona24>(), "Persona24");
	admin.registerAtomic(NewAtomicFunction<Persona25>(), "Persona25");
	admin.registerAtomic(NewAtomicFunction<Persona26>(), "Persona26");
	admin.registerAtomic(NewAtomicFunction<Persona27>(), "Persona27");
	admin.registerAtomic(NewAtomicFunction<Persona28>(), "Persona28");
}
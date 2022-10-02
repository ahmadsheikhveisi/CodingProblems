
#include "ZeroHandle.hpp"

int ZeroHandle::m_val{0};

int& ZeroHandle::getVal() {
    return m_val;
}

/*
 * There are two potential downsides to this implementation. First of all, this singleton cannot
 * be extended through inheritance. This is the less important of the two problems—singleton
 * objects are, or should be, rare enough in a good design, so code reuse is not a significant
 * concern.
 * The more important problem has to do with the object's lifetime—the singleton is initialized
 * as a static object before the program itself is started. The order of initialization of the static
 * objects is, in general, undefined and left to the implementation—the standard guarantees
 * that all objects defined in one file are initialized in the order of their definitions, but for
 * objects initialized in different files, there are no guarantees at all with regard to the order.
 * for example, if our singleton is the
 * memory manager, and there is only one instance of such in the program, then any static
 * object that allocates memory has to get it from the memory manager. However, unless the
 * whole program is contained in one file, there is no way to guarantee that the singleton
 * memory manager is initialized before its first use. The next implementation attempts to
 * address this problem.
 * 
*/

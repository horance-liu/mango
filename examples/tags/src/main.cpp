#include <mango/core/runtime/Runtime.h>

int main(int argc, char** argv)
{
    return MANGO_NS::Runtime::runtime().run(argc, argv);
}

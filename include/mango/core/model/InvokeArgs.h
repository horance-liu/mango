#ifndef HE4A115BC_C4E7_420D_A694_3A237644D1A1
#define HE4A115BC_C4E7_420D_A694_3A237644D1A1

#include "l0-infra/std/string.h"
#include "mango/core/base/mango.h"
#include <vector>
#include <string>

MANGO_NS_BEGIN

struct InvokeArgs
{
    typedef std::vector<std::string> args_type;
    typedef std::vector<std::string> row_type;
    typedef std::vector<row_type>    table_type;

    void addArg(const std::string& arg);
    void addRow(row_type&& row);

    template<class T>
    T getArgAt(size_t i) const
    {
        return stdext::string_as<T>(args[i]);
    }

    const table_type& getTable() const;

private:
    args_type args;
    table_type table;
};

MANGO_NS_END

#endif

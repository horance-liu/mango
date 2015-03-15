#ifndef HD0427729_04BB_4C5A_B301_B6F4CA86FDDC
#define HD0427729_04BB_4C5A_B301_B6F4CA86FDDC

#include "mango/core/base/mango.h"
#include <string>
#include <vector>

MANGO_NS_BEGIN

struct Table
{
    typedef std::vector<std::string> row_type;

    void addRow(row_type&& row);

private:
    std::vector<row_type> rows;
};

MANGO_NS_END

#endif

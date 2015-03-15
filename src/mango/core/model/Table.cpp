#include <mango/core/model/Table.h>

MANGO_NS_BEGIN

void Table::addRow(row_type&& row)
{
    rows.emplace_back(std::move(row));
}

MANGO_NS_END

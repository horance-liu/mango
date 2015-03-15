#include <mango/core/model/InvokeArgs.h>

MANGO_NS_BEGIN

void InvokeArgs::addArg(const std::string& arg)
{
    args.push_back(arg);
}

void InvokeArgs::addRow(row_type&& row)
{
    table.emplace_back(std::move(row));
}

auto InvokeArgs::getTable() const -> const table_type&
{
    return table;
}

MANGO_NS_END

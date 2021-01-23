#ifdef DEBUG
#include <iostream>
#endif
#include <utility>
#include "DBRAII.h"

DBConnectionRAII::DBConnectionRAII()
{
    connection = db_connect();
}

DBConnectionRAII::~DBConnectionRAII()
{
    db_disconnect(connection);
}

DBResultsRAII DBConnectionRAII::getQueryResults(const char* query) const
{
    return DBResultsRAII(db_query(connection, query));
}

DBResultsRAII::~DBResultsRAII()
{
    db_free_result(results);
}

// DBResultsRAII Move Constructor
DBResultsRAII::DBResultsRAII(DBResultsRAII&& src) noexcept
{
#ifdef DEBUG
    std::cout << "\t\t{DEBUG}\tDBRSULTSRAII Move-Constructor\n";
#endif
    results = src.results;
    src.results = nullptr;
}

// DBResultsRAII Move Assignment
DBResultsRAII& DBResultsRAII::operator=(DBResultsRAII&& src) noexcept
{
#ifdef DEBUG
    std::cout << "\t\t{DEBUG}\tDBResultsRAII Move-Assignment\n";
#endif
    if (&src != this)
    {
        DBResultsRAII move {std::move(src)};
        swap(move);
    }
    return *this;
}

// DBResultsRAII swap
void DBResultsRAII::swap(DBResultsRAII& src) noexcept
{
    std::swap(results, src.results);
}

// DBResultsRAII non-member swap to support convention
void swap(DBResultsRAII& one, DBResultsRAII& other)
{
    one.swap(other);
}


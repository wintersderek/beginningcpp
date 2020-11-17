/*
Need a RAII object to manage
    - Database connection
        - destructor should always call disconnect if connected
    - Database results
        - destructor should always free results if we have
*/
#ifndef DBRAII_h
#define DBRAII_h
#include "DB.h"
class DBResultsRAII
{
protected:
    DB_QUERY_RESULT *results;

public:
    DBResultsRAII(DB_QUERY_RESULT *query_result) : results{query_result} {}
    ~DBResultsRAII();

    inline operator bool() const { return results != nullptr; }
    inline operator DB_QUERY_RESULT *() { return results; }
};

class DBCustomerResultRAII : public DBResultsRAII
{
public:
    using DBResultsRAII::DBResultsRAII;
};

class DBConnectionRAII
{
protected:
    DB_CONNECTION* connection;
public:
    DBConnectionRAII();
    ~DBConnectionRAII();

    DBResultsRAII getQueryResults(const char* query) const;
};

#endif
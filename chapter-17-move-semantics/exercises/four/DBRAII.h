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

    // Remove copy constructor and copy assignment to avoid duel pointer ownership
    DBResultsRAII(const DBResultsRAII&) = delete;
    DBResultsRAII &operator=(const DBResultsRAII&) = delete;

    // Add the move constructor and move assignment
    DBResultsRAII(DBResultsRAII&& src) noexcept;
    DBResultsRAII& operator=(DBResultsRAII&& src) noexcept;

    // Swap to support the move and swap idiom
    void swap(DBResultsRAII& src) noexcept;

    inline operator bool() const { return results != nullptr; }
    inline operator DB_QUERY_RESULT *() { return results; }
};

// DBResultsRAII non-member swap to support convention
void swap(DBResultsRAII& one, DBResultsRAII& other);

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
    
    // Remove the copy constructor and copy assignment to prevent duel pointer ownership
    DBConnectionRAII(const DBConnectionRAII&) = delete;
    DBConnectionRAII& operator=(const DBConnectionRAII&) = delete;

    DBResultsRAII getQueryResults(const char* query) const;
};

#endif
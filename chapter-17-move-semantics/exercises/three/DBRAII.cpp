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
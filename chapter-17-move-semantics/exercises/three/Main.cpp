// Exercise 15-5
/* Creating RAII classes to manage resource handles returned by a C interface
   Remember: RAII is not just for dynamic memory: every resource should be managed by an object!
 */

#include <iostream>
#include <vector>

#include "DBRAII.h"
#include "DB.h"
#include "DBException.h"
#include "Customer.h"

void verifyCustomerFields(DB_QUERY_RESULT *result);           // Sanity check on the number of fields returned by our query
std::vector<Customer> readCustomers(DB_QUERY_RESULT *result); // Convert the DB result to a series of C++ objects
void print(std::ostream &stream, const Customer &customer);   // Print a given customer to a given output stream

std::ostream &getOutputStream()
{
    return std::cout;
}

int main()
{
    try
    {
        DBConnectionRAII connection {};
        DBResultsRAII result {connection.getQueryResults("SELECT * FROM A_CUSTOMER_TABLE")};
        
        if (result)
        {
            std::vector<Customer> customers = readCustomers(result);

            if (customers.empty())
            {
                std::cerr << "No customers found?" << std::endl;
                return 2;
            }

            for (auto &customer : customers)
            {
                print(std::cout, customer);
            }
        }
        else
        {
            throw DataBaseException{"Query failed"};
        }
    }
    catch (std::exception &caught)
    {
        std::cerr << "Outer exception: " << caught.what() << std::endl;
        return 1;
    }

    //db_disconnect(connection);
    return 0;
}

std::vector<Customer> readCustomers(DB_QUERY_RESULT *result)
{
    // Sanity check
    // (if the number of fields does not match 5,
    // the code below would crash!)
    verifyCustomerFields(result);

    std::vector<Customer> customers;

    auto row = db_fetch_row(result);
    while (row)
    {
        customers.push_back(Customer{
            row[0],            // Surname
            row[1],            // Name
            row[2],            // Street
            std::stoi(row[3]), // Street number
            row[4]             // City
        });

        row = db_fetch_row(result);
    }

    return customers;
}

void verifyCustomerFields(DB_QUERY_RESULT *result)
{
    int numFields = db_num_fields(result);
    if (numFields < 0)
    {
        throw DataBaseException{"db_num_fields() failed"};
    }
    if (numFields != 5)
    {
        throw DataBaseException{"Unexpected number of fields: " + std::to_string(numFields)};
    }
}

void print(std::ostream &stream, const Customer &customer)
{
    stream << customer.ToString() << std::endl;
    if (std::cout.fail())
    {
        std::cout.clear();
        throw std::runtime_error("Failed to output customer");
    }
}
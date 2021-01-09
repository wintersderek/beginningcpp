#ifndef MAIN_H
#define MAIN_H
#include <string>
#include <string_view>
#include "DoubleLinkedList.h"
#include "SparseArray.h"
/*
Supply the functional link between SparseArray and DoubleLinkedList
    - Populate sparse array: input data, parse data, put in array
        - Collect data from user
        - Create 26 sparse array
        - Create map to array index
        - Parse data into words
        - Put each
*/
constexpr char sparse_map[] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
    'r','s','t','u','v','w','x','y','z'
};

//constexpr char alphabet[] {"abcdefghijklmnopqrstuvwxyz"};
constexpr size_t index_limit {26};
const std::string alphabet {"abcdefghijklmnopqrstuvwxyz"};

void fill_data_array(SparseArray<DoubleLinkedList<std::string>>& values);
std::string_view get_user_data();
size_t get_array_index(const char lookup);
#endif
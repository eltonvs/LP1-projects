/*!
 *  @file HashTbl.hpp
 *  @brief Hash Table Header
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with the Hash Table header
 */

#ifndef _HashTbl_hpp_
#define _HashTbl_hpp_

#include <functional>
#include <exception>
#include <forward_list>
#include <list>

namespace MyHashTable {

//! Hash table entry.
/*! This class is used to make it easier to manipulate hash table entries, by handling an entry as a pair of \a key + \a data.
 * \tparam KeyType   Type definition for the key used to access the hash table
 * \tparam DataType  Type definition for the data to be stored in the hash table
 */
template <class KeyType, class DataType>
class HashEntry {
 public:
    //! Simple constructor.
    /*! \param _key Entry key.
     *  \param _data Data item.
     */
    HashEntry(KeyType _key, DataType _data) : mKey(_key), mData(_data) {}
    KeyType mKey;    //!< Stores the key for an entry.
    DataType mData;  //!< Stores the data for an entry.
};


//! A simple hash table.
/*! This class represents a hash table that uses double hasing and the external liking method to handle collisions.
 *  The external (and independent) hash funcion must be specified by the client code.
 *  Internaly, this class uses the \a division \a method to map keys to data table entries.
 *  \tparam KeyType   Type definition for the key used to access the hash table
 *  \tparam DataType  Type definition for the data to be stored in the hash table
 *  \tparam KeyHash   Function object to provide a hash value given a key.
 *  \tparam KeyEqual  Function object to compara keys types.
 */
template <typename KeyType,
          typename DataType,
          typename KeyHash  = std::hash<KeyType>,
          typename KeyEqual = std::equal_to<KeyType>>
class HashTbl {
 public:
    //! It is used to make code more concise.
    using Entry = HashEntry<KeyType, DataType>;

    explicit HashTbl(int _initTableSize = DEFAULT_SIZE);
    virtual ~HashTbl();

    bool insert(const KeyType &, const DataType &) throw(std::bad_alloc);
    bool remove(const KeyType &);
    bool retrieve(const KeyType &, DataType &) const;
    void clear(void);
    bool isEmpty(void) const;
    unsigned long int count(void) const;

    void showStructure() const;

 private:
    //! Disable copy constructor (we don't need it in this implementation).
    HashTbl(const HashTbl&);
    //! Assignment method is also disabled.
    const HashTbl &operator=(const HashTbl &);
    //! Rehash
    void rehash(void);
    //! Hash table size.
    unsigned int mSize;
    //! Number of element currently stored in the table.
    unsigned int mCount;
    // std::list<Entry> *mpDataTable;
    //! Actual data strucure, corresponding to a table of collision list for elements.
    std::unique_ptr<std::forward_list<Entry>[]> mpDataTable;

    //! Hash table's default size: 10 table entries.
    static const short DEFAULT_SIZE = 11;
};

}  // namespace MyHashTable

#include "HashTbl.inl"
#endif

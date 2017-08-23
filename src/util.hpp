/// Utility classes.
///
/// @file
#ifndef ARGPARSE_UTIL_HPP
#define ARGPARSE_UTIL_HPP


#include <map>
#include <string>
#include <vector>


namespace argparse
{
    /// Storage for keyed values.
    ///
    /// One or more values can be associated with each key. The get() methods
    /// operate as if there is only one value per key, which is the most common
    /// use case. Use the values() method to access all values a key.
    ///
    class ValueMap
    {
    public:
        /// Default constructor.
        ///
        ValueMap() = default;

        /// Construct an object with a single value.
        ///
        /// @param key
        /// @param value
        ValueMap(const std::string& key, const std::string& value);

        /// Construct an object with multiple values.
        ///
        /// @param key
        /// @param values
        ValueMap(const std::string& key, const std::vector<std::string>& values);


        /// Return all stored keys.
        ///
        /// @return stored keys
        std::vector<std::string> keys() const;

        /// Return the value associated with a key.
        ///
        /// If there are more than one values for this key, only the first
        /// value is returned. If the key does not exist, std::out_of_range is
        /// thrown.
        ///
        /// @param key
        /// @return a single value for this key
        const std::string& get(const std::string& key) const;

        /// Return the value associated with a key or a default.
        ///
        /// If there are more than one values for this key, only the first
        /// value is returned. If the key does not exist, the given default
        /// is returned.
        ///
        /// @param key
        /// @param value default to use if key does not exist
        /// @return a single value for this key
        const std::string& get(const std::string& key, const std::string& value) const;

        /// Return all values associated with a key.
        ///
        /// If the key does not exist, an empty vector is returned.
        ///
        /// @param key
        /// @return all values for this key
        std::vector<std::string> values(const std::string& key) const;

        /// Insert a single value.
        ///
        /// @param key
        /// @param value
        void insert(const std::string& key, const std::string& value);

        /// Insert multiple values.
        ///
        /// @param key
        /// @param values
        void insert(const std::string& key, const std::vector<std::string>& values);

        /// Merge another ValueMap into this one.
        ///
        /// The append parameter controls the handling of duplicate keys. If
        /// true, values in `other` are appending to existing values, otherwise
        /// they replace existing values.
        ///
        /// @param other
        /// @param append append values for duplicate keys
        void merge(const ValueMap& other, bool append=true);

    private:
        typedef std::map<std::string, std::vector<std::string>> MapType;

        MapType data;
    };
}


#endif //ARGPARSE_UTIL_HPP

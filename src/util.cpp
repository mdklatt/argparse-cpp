#include "util.hpp"

using std::string;
using std::vector;

using namespace argparse;


ValueMap::ValueMap(const string& key, const string& value)
{
    data.insert(MapType::value_type(key, vector<string>({value})));
    return;
}


ValueMap::ValueMap(const string& key, const vector<string>& values)
{
    data.insert(MapType::value_type(key, values));
    return;
}


vector<string> ValueMap::keys() const
{
    vector<string> keys;
    keys.reserve(data.size());
    for (auto item: data) {
        keys.push_back(item.first);
    }
    return keys;
}


const string& ValueMap::get(const string& key) const
{
    // Throws out_of_range if key doesn't exist.
    return data.at(key).front();
}


const string& ValueMap::get(const string& key, const string& value) const
{
    const auto pos(data.lower_bound(key));
    return pos != data.end() ? pos->second.front() : value;
}


vector<string> ValueMap::values(const string& key) const
{
    const auto pos(data.lower_bound(key));
    return pos != data.end() ? pos->second : vector<string>();
}


void ValueMap::insert(const string& key, const string& value)
{
    const auto pos(data.lower_bound(key));
    if (pos != data.end()) {
        // Append to existing key.
        pos->second.push_back(value);
    }
    else {
        // Insert new key.
        data.insert(pos, MapType::value_type(key, vector<string>({value})));
    }
    return;
}


void ValueMap::insert(const string& key, const vector<string>& values)
{
    data.insert(MapType::value_type(key, values));
    return;
}


void ValueMap::merge(const ValueMap& other, bool append)
{
    for (const auto& item: other.data) {
        const vector<string> values{item.second};
        const auto pos(data.lower_bound(item.first));
        if (pos != data.end()) {
            if (append) {
                // Append values to existing key.
                pos->second.reserve(pos->second.size() + values.size());
                pos->second.insert(pos->second.end(), values.begin(), values.end());
            }
            else {
                // Replace existing key.
                pos->second = values;
            }
        }
        else {
            // Insert new key.
            data.insert(pos, item);
        }
    }
    return;
}
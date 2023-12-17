#include <iostream>
#include <string>
#include <memory>
#include <set>
#include <filesystem>
#include <ranges>

namespace fs = std::filesystem;

namespace DB
{

class File;
using FileType = std::multiset<File>;
using ExtensionType = std::set<std::string>;

}; // namespace DB

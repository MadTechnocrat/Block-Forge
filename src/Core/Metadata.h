#pragma once

#include <string>
#include "rapidjson/document.h"

/// @class Metadata
/// @brief Handles JSON files and manipulates them.
/// @details This class is made for handling the metadata stored in JSON files.
class Metadata
{
	std::string filename;
	rapidjson::Document document;

	static bool DoesFileExist(const std::string& filename);

public:
	/// @brief Metadata object constructor.
	Metadata() = default;

	/// @brief Metadata object constructor.
	/// @param filename - Filename of the JSON file.
	explicit Metadata(const std::string& filename);

	/// @brief Set filename.
    /// @param filename - Filename of the JSON file.
	void SetFilename(const std::string& filename);

	/// @brief Get filename.
    /// @retval String with a filename of the JSON file.
	std::string GetFilename();

	/// @brief Loads JSON data to the document variable.
	void Load();

	/// @brief Loads JSON data to the document variable using the given filename.
	/// @param filename - Filename of the JSON file.
	void Load(const std::string& filename);

	/// @brief Saves JSON data to the file specified in the filename.
	/// @param overrideFileIfExists - On true allows overriding existing file, otherwise throws exception (std::runtime_error).
	void Save(bool overrideFileIfExists = false) const;
};

/// @overload void Load()

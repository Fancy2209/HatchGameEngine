#ifndef ENGINE_FILESYSTEM_DIRECTORY_H
#define ENGINE_FILESYSTEM_DIRECTORY_H

#include <Engine/Includes/Standard.h>

class Directory {
public:
	static bool Exists(const char* path);
	static bool Create(const char* path);
	static void GetFiles(std::vector<fs::path>* files,
		const char* path,
		const char* searchPattern,
		bool allDirs);
	static std::vector<fs::path>
	GetFiles(const char* path, const char* searchPattern, bool allDirs);
	static void GetDirectories(std::vector<fs::path>* files,
		const char* path,
		const char* searchPattern,
		bool allDirs);
	static std::vector<fs::path>
	GetDirectories(const char* path, const char* searchPattern, bool allDirs);
};

#endif /* ENGINE_FILESYSTEM_DIRECTORY_H */

#pragma once
#include <map>

class ResourceManager;

class ResourceManager {
private:
	ResourceManager();

public:
	ResourceManager(const ResourceManager&) = delete;
	void operator = (const ResourceManager&) = delete;
	~ResourceManager();

	static ResourceManager& Get() {
		static ResourceManager instance;
		return instance;
	}
};
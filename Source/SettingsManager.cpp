#include <vector>

class SettingsManager {
public:

	void uploadSetting();
	void downloadSetting();

private:
		std::vector<std::string> settingsFilePaths();
		void backupLocalSetting(std::string backupFileName);

};
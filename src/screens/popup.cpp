#include <algorithm>

#include <psp2/io/dirent.h>
#include <psp2/io/stat.h>

#include "../main.hpp"
#include "../utils/vhbb/zip.h"
#include "../net/download.hpp"
#include "popup.hpp"

#define columnHeight 168

string toUppercase(string strToConvert) {
    transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}

void Popup::draw(SharedData &sharedData, unsigned int button) {
	vpkName = curlDownloadKeepName(sharedData.vpks[sharedData.cursorY]["url"].get<string>().c_str(), sharedData.vpkConfigPath);
	installFiles.clear();
		
	sharedData.scene = 0;
	state = 0;
}

void Popup::free() {
    vita2d_free_texture(desc);
    vita2d_free_texture(desc2);
}
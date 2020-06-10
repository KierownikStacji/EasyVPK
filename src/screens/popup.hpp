#pragma once

#include <psp2/io/dirent.h>
#include <vector>

#include "../utils/filesystem.hpp"

#include "../main.hpp"

class Popup {
    public:
        void draw(SharedData &sharedData);
		void reset();
        void free();

    private:
		string getDataFileName(const string& s);
        vector<string> installFiles;
        vita2d_texture *desc = vita2d_load_PNG_file("ux0:app/ESVPK0009/resources/desc2.png");
        vita2d_texture *desc2 = vita2d_load_PNG_file("ux0:app/ESVPK0009/resources/desc3.png");
        vita2d_texture *desc3 = vita2d_load_PNG_file("ux0:app/ESVPK0009/resources/desc4.png");
};
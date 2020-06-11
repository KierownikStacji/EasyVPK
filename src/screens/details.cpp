#include "../main.hpp"
#include "../utils/format.hpp"

#include "details.hpp"

#define maxImageHeight 272

void Details::draw(SharedData &sharedData, unsigned int button) {
    if (sharedData.initDetail) {
        cycleCounter = 0;
        imageCycles = 0;
        
        longDescription = formatLongDesc(sharedData.vpks[sharedData.cursorY]["long_description"].get<string>(), sharedData.font, 920, 32);

        sharedData.initDetail = false;
    }

    cycleCounter++;
    if (cycleCounter == 300) {
        cycleCounter = 0;
        if (imageCycles < sharedData.screenshots.size()-1)
			imageCycles++;
        else
			imageCycles = 0;
    }

    if (!sharedData.screenshots.empty()) {        
        if (sharedData.screenshots[imageCycles]) {
            unsigned int height = vita2d_texture_get_height(sharedData.screenshots[imageCycles]);
            
            float size = (float) maxImageHeight / height;

            vita2d_draw_texture_scale(sharedData.screenshots[imageCycles], 470, 10, size, size);
        }
    }

    vita2d_font_draw_textf(sharedData.font, 20, 45, RGBA8(255,255,255,255), 40, "%s %s", sharedData.vpks[sharedData.cursorY]["name"].get<string>().c_str(), sharedData.vpks[sharedData.cursorY]["version"].get<string>().c_str());
    vita2d_font_draw_textf(sharedData.font, 20, 90, RGBA8(215,215,215,255), 20, "by %s", sharedData.vpks[sharedData.cursorY]["author"].get<string>().c_str());
    
    vita2d_font_draw_textf(sharedData.font, 20, 317, RGBA8(255,255,255,255), 30, "%s", longDescription.c_str());

	if (sharedData.vpks[sharedData.cursorY]["data"].get<string>().empty())
		vita2d_draw_texture(desc1, 0, 504);
	else
		vita2d_draw_texture(desc5, 0, 504);

    if (sharedData.scene == 1) {
        switch (button) {
            case SCE_CTRL_CIRCLE:
			    if (sharedData.blockCircle)
					break;
                sharedData.scene = 0;

                break;
            case SCE_CTRL_CROSS:
                if (sharedData.blockCross)
					break;

				sharedData.dl_type_sd = 0; // VPK
                sharedData.scene = 2;
                
                sharedData.blockCross = true;
                sharedData.blockSquare = true;
                sharedData.blockCircle = true;
                break;
			case SCE_CTRL_SQUARE:
			    if (sharedData.blockSquare)
					break;

				sharedData.dl_type_sd = 1; // DATA
                sharedData.scene = 2;
                
                sharedData.blockSquare = true;
                sharedData.blockCross = true;
				sharedData.blockCircle = true;
                break;
        }
    }
}

void Details::free() {
    vita2d_free_texture(desc1);
}
#ifndef FREETYPE_MANAGER_H
#define FREETYPE_MANAGER_H

// #include "text_font.h"
#include "plib/gnw/text.h"

namespace fallout {

extern FontMgr gFtFontManager;

int FtFontsInit();
void FtFontsExit();

} // namespace fallout

#endif /* FONT_MANAGER_H */

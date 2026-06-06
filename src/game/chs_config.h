#ifndef CHS_CONFIG_H
#define CHS_CONFIG_H

// ───────────────────────────────────────────────────────────────────────────
// Build edition selector.
//
// BUILD_CHS == 1  Simplified Chinese (CHS) edition: render text with the
//                 TrueType / FreeType font manager and use Chinese-specific
//                 text layout (character-based line wrapping, no word spaces).
// BUILD_CHS == 0  English (ENG) edition: the original upstream bitmap-font
//                 behaviour, completely unchanged.
//
// Every tunable below only takes effect when BUILD_CHS == 1; the ENG paths keep
// the original upstream literals.
// ───────────────────────────────────────────────────────────────────────────
#define BUILD_CHS 1

// ─── FreeType font renderer (freetype_manager.cc) ──────────────────────────

// The maximum number of interface fonts.
#define FT_FONT_MAX (16)

// Interface fonts are addressed by callers starting at this base (font 0 is
// requested as font 100), matching the bitmap font manager's numbering.
#define FT_FONT_NUM_BASE (100)

// Capacity, in UCS-4 code points, of the shared encoding-conversion buffer.
#define FT_CONV_BUFFER_SIZE (1024)

// Font files are streamed from disk in chunks of this many bytes.
#define FT_FILE_READ_CHUNK (10000)

// Each colour blend-table entry is indexed as
// (intensity << FT_INTENSITY_SHIFT) | pixel.
#define FT_INTENSITY_SHIFT (8)

// Code points strictly between these bounds are rendered as fixed-width,
// word-spaced characters.
#define FT_EXTENDED_ASCII_MIN (128)
#define FT_EXTENDED_ASCII_MAX (256)

// Divisor mapping FreeType's 0..255 coverage onto the colour blend table's
// intensity levels.
#define FT_GRAYSCALE_DIVISOR (26)

// Extra horizontal spacing, in pixels, reserved for the bullet glyph (0x95).
#define FT_BULLET_SPACING (2)

// Directory holding the font pack and its font.ini descriptor.
#define FT_FONT_DIR "fonts/chs"

// ─── Display monitor line wrapping (display.cc) ────────────────────────────

// Maximum length, in bytes, of a single display-monitor line.
#define CHS_DISPLAY_MONITOR_LINE_LENGTH (50)

// Number of (double-byte) characters placed on a display-monitor line before
// wrapping to the next one.
#define CHS_DISPLAY_MONITOR_CHARS_PER_LINE (13)

// ─── Save/load slot list layout (loadsave.cc) ──────────────────────────────

// Vertical advance, in pixels, from a slot's header line to its description.
#define CHS_SLOT_HEADER_HEIGHT (12)

// Vertical advance, in pixels, from a slot's description to the next slot.
#define CHS_SLOT_ENTRY_HEIGHT (24)

// ─── Dialog text wrapping (gdialog.cc) ─────────────────────────────────────

// Approximate average glyph width (px) used to estimate how many characters
// fit on a dialog line: characters-per-line ≈ lineWidth / this value.
#define CHS_DIALOG_AVG_CHAR_WIDTH (6)

// Scratch buffer size, in bytes, for the current wrapped dialog line.
#define CHS_DIALOG_LINE_BUFFER_SIZE (1000)

#endif /* CHS_CONFIG_H */

/* C++ code produced by gperf version 3.0.1 */
/* Command-line: ../../../../third_party/gperf/bin/gperf.exe --key-positions='*' -P -n -m 50 -D  */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif


/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "config.h"
#include "CSSPropertyNames.h"
#include "HashTools.h"
#include <string.h>

#include "wtf/ASCIICType.h"
#include "wtf/text/AtomicString.h"
#include "wtf/text/WTFString.h"

namespace WebCore {
static const char propertyNameStringsPool[] = {
    "display\0"
    "-webkit-animation\0"
    "-webkit-animation-delay\0"
    "-webkit-animation-direction\0"
    "-webkit-animation-duration\0"
    "-webkit-animation-fill-mode\0"
    "-webkit-animation-iteration-count\0"
    "-webkit-animation-name\0"
    "-webkit-animation-play-state\0"
    "-webkit-animation-timing-function\0"
    "animation\0"
    "animation-delay\0"
    "animation-direction\0"
    "animation-duration\0"
    "animation-fill-mode\0"
    "animation-iteration-count\0"
    "animation-name\0"
    "animation-play-state\0"
    "animation-timing-function\0"
    "-webkit-transition\0"
    "-webkit-transition-delay\0"
    "-webkit-transition-duration\0"
    "-webkit-transition-property\0"
    "-webkit-transition-timing-function\0"
    "transition\0"
    "transition-delay\0"
    "transition-duration\0"
    "transition-property\0"
    "transition-timing-function\0"
    "color\0"
    "direction\0"
    "font\0"
    "font-family\0"
    "font-kerning\0"
    "font-size\0"
    "font-style\0"
    "font-variant\0"
    "font-variant-ligatures\0"
    "font-weight\0"
    "text-rendering\0"
    "-webkit-font-feature-settings\0"
    "-webkit-font-smoothing\0"
    "-webkit-locale\0"
    "-webkit-text-orientation\0"
    "-webkit-writing-mode\0"
    "zoom\0"
    "line-height\0"
    "background\0"
    "background-attachment\0"
    "background-blend-mode\0"
    "background-clip\0"
    "background-color\0"
    "background-image\0"
    "background-origin\0"
    "background-position\0"
    "background-position-x\0"
    "background-position-y\0"
    "background-repeat\0"
    "background-repeat-x\0"
    "background-repeat-y\0"
    "background-size\0"
    "border\0"
    "border-bottom\0"
    "border-bottom-color\0"
    "border-bottom-left-radius\0"
    "border-bottom-right-radius\0"
    "border-bottom-style\0"
    "border-bottom-width\0"
    "border-collapse\0"
    "border-color\0"
    "border-image\0"
    "border-image-outset\0"
    "border-image-repeat\0"
    "border-image-slice\0"
    "border-image-source\0"
    "border-image-width\0"
    "border-left\0"
    "border-left-color\0"
    "border-left-style\0"
    "border-left-width\0"
    "border-radius\0"
    "border-right\0"
    "border-right-color\0"
    "border-right-style\0"
    "border-right-width\0"
    "border-spacing\0"
    "border-style\0"
    "border-top\0"
    "border-top-color\0"
    "border-top-left-radius\0"
    "border-top-right-radius\0"
    "border-top-style\0"
    "border-top-width\0"
    "border-width\0"
    "bottom\0"
    "box-shadow\0"
    "box-sizing\0"
    "caption-side\0"
    "clear\0"
    "clip\0"
    "-webkit-clip-path\0"
    "content\0"
    "counter-increment\0"
    "counter-reset\0"
    "cursor\0"
    "empty-cells\0"
    "float\0"
    "font-stretch\0"
    "height\0"
    "image-rendering\0"
    "isolation\0"
    "justify-self\0"
    "left\0"
    "letter-spacing\0"
    "list-style\0"
    "list-style-image\0"
    "list-style-position\0"
    "list-style-type\0"
    "margin\0"
    "margin-bottom\0"
    "margin-left\0"
    "margin-right\0"
    "margin-top\0"
    "mask-source-type\0"
    "max-height\0"
    "max-width\0"
    "min-height\0"
    "min-width\0"
    "mix-blend-mode\0"
    "opacity\0"
    "orphans\0"
    "outline\0"
    "outline-color\0"
    "outline-offset\0"
    "outline-style\0"
    "outline-width\0"
    "object-fit\0"
    "object-position\0"
    "overflow\0"
    "overflow-wrap\0"
    "overflow-x\0"
    "overflow-y\0"
    "padding\0"
    "padding-bottom\0"
    "padding-left\0"
    "padding-right\0"
    "padding-top\0"
    "page\0"
    "page-break-after\0"
    "page-break-before\0"
    "page-break-inside\0"
    "pointer-events\0"
    "position\0"
    "quotes\0"
    "resize\0"
    "right\0"
    "scroll-behavior\0"
    "size\0"
    "src\0"
    "speak\0"
    "table-layout\0"
    "tab-size\0"
    "text-align\0"
    "text-align-last\0"
    "text-decoration\0"
    "text-decoration-line\0"
    "text-decoration-style\0"
    "text-decoration-color\0"
    "text-indent\0"
    "text-justify\0"
    "text-line-through-color\0"
    "text-line-through-mode\0"
    "text-line-through-style\0"
    "text-line-through-width\0"
    "text-overflow\0"
    "text-overline-color\0"
    "text-overline-mode\0"
    "text-overline-style\0"
    "text-overline-width\0"
    "text-shadow\0"
    "text-transform\0"
    "text-underline-color\0"
    "text-underline-mode\0"
    "text-underline-style\0"
    "text-underline-width\0"
    "text-underline-position\0"
    "top\0"
    "touch-action\0"
    "touch-action-delay\0"
    "unicode-bidi\0"
    "unicode-range\0"
    "vertical-align\0"
    "visibility\0"
    "white-space\0"
    "widows\0"
    "width\0"
    "will-change\0"
    "word-break\0"
    "word-spacing\0"
    "word-wrap\0"
    "z-index\0"
    "-webkit-appearance\0"
    "-webkit-aspect-ratio\0"
    "-webkit-backface-visibility\0"
    "-webkit-background-clip\0"
    "-webkit-background-composite\0"
    "-webkit-background-origin\0"
    "-webkit-background-size\0"
    "-webkit-border-after\0"
    "-webkit-border-after-color\0"
    "-webkit-border-after-style\0"
    "-webkit-border-after-width\0"
    "-webkit-border-before\0"
    "-webkit-border-before-color\0"
    "-webkit-border-before-style\0"
    "-webkit-border-before-width\0"
    "-webkit-border-end\0"
    "-webkit-border-end-color\0"
    "-webkit-border-end-style\0"
    "-webkit-border-end-width\0"
    "-webkit-border-fit\0"
    "-webkit-border-horizontal-spacing\0"
    "-webkit-border-image\0"
    "-webkit-border-radius\0"
    "-webkit-border-start\0"
    "-webkit-border-start-color\0"
    "-webkit-border-start-style\0"
    "-webkit-border-start-width\0"
    "-webkit-border-vertical-spacing\0"
    "-webkit-box-align\0"
    "-webkit-box-direction\0"
    "-webkit-box-flex\0"
    "-webkit-box-flex-group\0"
    "-webkit-box-lines\0"
    "-webkit-box-ordinal-group\0"
    "-webkit-box-orient\0"
    "-webkit-box-pack\0"
    "-webkit-box-reflect\0"
    "-webkit-box-shadow\0"
    "-internal-callback\0"
    "-webkit-column-axis\0"
    "-webkit-column-break-after\0"
    "-webkit-column-break-before\0"
    "-webkit-column-break-inside\0"
    "-webkit-column-count\0"
    "column-fill\0"
    "-webkit-column-gap\0"
    "-webkit-column-progression\0"
    "-webkit-column-rule\0"
    "-webkit-column-rule-color\0"
    "-webkit-column-rule-style\0"
    "-webkit-column-rule-width\0"
    "-webkit-column-span\0"
    "-webkit-column-width\0"
    "-webkit-columns\0"
    "-webkit-box-decoration-break\0"
    "-webkit-filter\0"
    "align-content\0"
    "align-items\0"
    "align-self\0"
    "flex\0"
    "flex-basis\0"
    "flex-direction\0"
    "flex-flow\0"
    "flex-grow\0"
    "flex-shrink\0"
    "flex-wrap\0"
    "justify-content\0"
    "-webkit-font-size-delta\0"
    "grid-auto-columns\0"
    "grid-auto-flow\0"
    "grid-auto-rows\0"
    "grid-area\0"
    "grid-column\0"
    "grid-column-end\0"
    "grid-column-start\0"
    "grid-template-columns\0"
    "grid-template-rows\0"
    "grid-row\0"
    "grid-row-end\0"
    "grid-row-start\0"
    "grid-template-areas\0"
    "-webkit-highlight\0"
    "-webkit-hyphenate-character\0"
    "-webkit-line-box-contain\0"
    "-webkit-line-break\0"
    "-webkit-line-clamp\0"
    "-webkit-logical-width\0"
    "-webkit-logical-height\0"
    "-webkit-margin-after-collapse\0"
    "-webkit-margin-before-collapse\0"
    "-webkit-margin-bottom-collapse\0"
    "-webkit-margin-top-collapse\0"
    "-webkit-margin-collapse\0"
    "-webkit-margin-after\0"
    "-webkit-margin-before\0"
    "-webkit-margin-end\0"
    "-webkit-margin-start\0"
    "-webkit-mask\0"
    "-webkit-mask-box-image\0"
    "-webkit-mask-box-image-outset\0"
    "-webkit-mask-box-image-repeat\0"
    "-webkit-mask-box-image-slice\0"
    "-webkit-mask-box-image-source\0"
    "-webkit-mask-box-image-width\0"
    "-webkit-mask-clip\0"
    "-webkit-mask-composite\0"
    "-webkit-mask-image\0"
    "-webkit-mask-origin\0"
    "-webkit-mask-position\0"
    "-webkit-mask-position-x\0"
    "-webkit-mask-position-y\0"
    "-webkit-mask-repeat\0"
    "-webkit-mask-repeat-x\0"
    "-webkit-mask-repeat-y\0"
    "-webkit-mask-size\0"
    "-webkit-max-logical-width\0"
    "-webkit-max-logical-height\0"
    "-webkit-min-logical-width\0"
    "-webkit-min-logical-height\0"
    "order\0"
    "-webkit-padding-after\0"
    "-webkit-padding-before\0"
    "-webkit-padding-end\0"
    "-webkit-padding-start\0"
    "-webkit-perspective\0"
    "-webkit-perspective-origin\0"
    "-webkit-perspective-origin-x\0"
    "-webkit-perspective-origin-y\0"
    "-webkit-print-color-adjust\0"
    "-webkit-rtl-ordering\0"
    "-webkit-ruby-position\0"
    "-webkit-text-combine\0"
    "-webkit-text-decorations-in-effect\0"
    "-webkit-text-emphasis\0"
    "-webkit-text-emphasis-color\0"
    "-webkit-text-emphasis-position\0"
    "-webkit-text-emphasis-style\0"
    "-webkit-text-fill-color\0"
    "-webkit-text-security\0"
    "-webkit-text-stroke\0"
    "-webkit-text-stroke-color\0"
    "-webkit-text-stroke-width\0"
    "-webkit-transform\0"
    "-webkit-transform-origin\0"
    "-webkit-transform-origin-x\0"
    "-webkit-transform-origin-y\0"
    "-webkit-transform-origin-z\0"
    "-webkit-transform-style\0"
    "-webkit-user-drag\0"
    "-webkit-user-modify\0"
    "-webkit-user-select\0"
    "shape-inside\0"
    "shape-outside\0"
    "shape-margin\0"
    "shape-padding\0"
    "shape-image-threshold\0"
    "-webkit-wrap-flow\0"
    "-webkit-wrap-through\0"
    "max-zoom\0"
    "min-zoom\0"
    "orientation\0"
    "user-zoom\0"
    "-webkit-tap-highlight-color\0"
    "-webkit-app-region\0"
    "-internal-marquee-direction\0"
    "-internal-marquee-increment\0"
    "-internal-marquee-repetition\0"
    "-internal-marquee-speed\0"
    "-internal-marquee-style\0"
    "buffered-rendering\0"
    "clip-path\0"
    "clip-rule\0"
    "mask\0"
    "enable-background\0"
    "filter\0"
    "flood-color\0"
    "flood-opacity\0"
    "lighting-color\0"
    "stop-color\0"
    "stop-opacity\0"
    "color-interpolation\0"
    "color-interpolation-filters\0"
    "color-profile\0"
    "color-rendering\0"
    "fill\0"
    "fill-opacity\0"
    "fill-rule\0"
    "marker\0"
    "marker-end\0"
    "marker-mid\0"
    "marker-start\0"
    "mask-type\0"
    "shape-rendering\0"
    "stroke\0"
    "stroke-dasharray\0"
    "stroke-dashoffset\0"
    "stroke-linecap\0"
    "stroke-linejoin\0"
    "stroke-miterlimit\0"
    "stroke-opacity\0"
    "stroke-width\0"
    "alignment-baseline\0"
    "baseline-shift\0"
    "dominant-baseline\0"
    "glyph-orientation-horizontal\0"
    "glyph-orientation-vertical\0"
    "kerning\0"
    "text-anchor\0"
    "vector-effect\0"
    "writing-mode\0"
    "paint-order\0"
};

static const unsigned short propertyNameStringsOffsets[] = {
    0,
    8,
    26,
    50,
    78,
    105,
    133,
    167,
    190,
    219,
    253,
    263,
    279,
    299,
    318,
    338,
    364,
    379,
    400,
    426,
    445,
    470,
    498,
    526,
    561,
    572,
    589,
    609,
    629,
    656,
    662,
    672,
    677,
    689,
    702,
    712,
    723,
    736,
    759,
    771,
    786,
    816,
    839,
    854,
    879,
    900,
    905,
    917,
    928,
    950,
    972,
    988,
    1005,
    1022,
    1040,
    1060,
    1082,
    1104,
    1122,
    1142,
    1162,
    1178,
    1185,
    1199,
    1219,
    1245,
    1272,
    1292,
    1312,
    1328,
    1341,
    1354,
    1374,
    1394,
    1413,
    1433,
    1452,
    1464,
    1482,
    1500,
    1518,
    1532,
    1545,
    1564,
    1583,
    1602,
    1617,
    1630,
    1641,
    1658,
    1681,
    1705,
    1722,
    1739,
    1752,
    1759,
    1770,
    1781,
    1794,
    1800,
    1805,
    1823,
    1831,
    1849,
    1863,
    1870,
    1882,
    1888,
    1901,
    1908,
    1924,
    1934,
    1947,
    1952,
    1967,
    1978,
    1995,
    2015,
    2031,
    2038,
    2052,
    2064,
    2077,
    2088,
    2105,
    2116,
    2126,
    2137,
    2147,
    2162,
    2170,
    2178,
    2186,
    2200,
    2215,
    2229,
    2243,
    2254,
    2270,
    2279,
    2293,
    2304,
    2315,
    2323,
    2338,
    2351,
    2365,
    2377,
    2382,
    2399,
    2417,
    2435,
    2450,
    2459,
    2466,
    2473,
    2479,
    2495,
    2500,
    2504,
    2510,
    2523,
    2532,
    2543,
    2559,
    2575,
    2596,
    2618,
    2640,
    2652,
    2665,
    2689,
    2712,
    2736,
    2760,
    2774,
    2794,
    2813,
    2833,
    2853,
    2865,
    2880,
    2901,
    2921,
    2942,
    2963,
    2987,
    2991,
    3004,
    3023,
    3036,
    3050,
    3065,
    3076,
    3088,
    3095,
    3101,
    3113,
    3124,
    3137,
    3147,
    3155,
    3174,
    3195,
    3223,
    3247,
    3276,
    3302,
    3326,
    3347,
    3374,
    3401,
    3428,
    3450,
    3478,
    3506,
    3534,
    3553,
    3578,
    3603,
    3628,
    3647,
    3681,
    3702,
    3724,
    3745,
    3772,
    3799,
    3826,
    3858,
    3876,
    3898,
    3915,
    3938,
    3956,
    3982,
    4001,
    4018,
    4038,
    4057,
    4076,
    4096,
    4123,
    4151,
    4179,
    4200,
    4212,
    4231,
    4258,
    4278,
    4304,
    4330,
    4356,
    4376,
    4397,
    4413,
    4442,
    4457,
    4471,
    4483,
    4494,
    4499,
    4510,
    4525,
    4535,
    4545,
    4557,
    4567,
    4583,
    4607,
    4625,
    4640,
    4655,
    4665,
    4677,
    4693,
    4711,
    4733,
    4752,
    4761,
    4774,
    4789,
    4809,
    4827,
    4855,
    4880,
    4899,
    4918,
    4940,
    4963,
    4993,
    5024,
    5055,
    5083,
    5107,
    5128,
    5150,
    5169,
    5190,
    5203,
    5226,
    5256,
    5286,
    5315,
    5345,
    5374,
    5392,
    5415,
    5434,
    5454,
    5476,
    5500,
    5524,
    5544,
    5566,
    5588,
    5606,
    5632,
    5659,
    5685,
    5712,
    5718,
    5740,
    5763,
    5783,
    5805,
    5825,
    5852,
    5881,
    5910,
    5937,
    5958,
    5980,
    6001,
    6036,
    6058,
    6086,
    6117,
    6145,
    6169,
    6191,
    6211,
    6237,
    6263,
    6281,
    6306,
    6333,
    6360,
    6387,
    6411,
    6429,
    6449,
    6469,
    6482,
    6496,
    6509,
    6523,
    6545,
    6563,
    6584,
    6593,
    6602,
    6614,
    6624,
    6652,
    6671,
    6699,
    6727,
    6756,
    6780,
    6804,
    6823,
    6833,
    6843,
    6848,
    6866,
    6873,
    6885,
    6899,
    6914,
    6925,
    6938,
    6958,
    6986,
    7000,
    7016,
    7021,
    7034,
    7044,
    7051,
    7062,
    7073,
    7086,
    7096,
    7112,
    7119,
    7136,
    7154,
    7169,
    7185,
    7203,
    7218,
    7231,
    7250,
    7265,
    7283,
    7312,
    7339,
    7347,
    7359,
    7373,
    7386,
};

enum
  {
    TOTAL_KEYWORDS = 444,
    MIN_WORD_LENGTH = 3,
    MAX_WORD_LENGTH = 34,
    MIN_HASH_VALUE = 25,
    MAX_HASH_VALUE = 2736
  };

/* maximum key range = 2712, duplicates = 0 */

class CSSPropertyNamesHash
{
private:
  static inline unsigned int property_hash_function (const char *str, unsigned int len);
public:
  static const struct Property *findPropertyImpl (const char *str, unsigned int len);
};

inline unsigned int
CSSPropertyNamesHash::property_hash_function (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737,    4, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737,    4,    4,  172,
         4,    4,  633,   32,  210,    4,    6,    4,  107,    9,
         4,    5,   89,    7,    6,   72,    4,  259,   61,    4,
       776,  845,   72, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737, 2737,
      2737, 2737, 2737, 2737, 2737, 2737
    };
  register int hval = 0;

  switch (len)
    {
      default:
        hval += asso_values[(unsigned char)str[33]];
      /*FALLTHROUGH*/
      case 33:
        hval += asso_values[(unsigned char)str[32]];
      /*FALLTHROUGH*/
      case 32:
        hval += asso_values[(unsigned char)str[31]];
      /*FALLTHROUGH*/
      case 31:
        hval += asso_values[(unsigned char)str[30]];
      /*FALLTHROUGH*/
      case 30:
        hval += asso_values[(unsigned char)str[29]];
      /*FALLTHROUGH*/
      case 29:
        hval += asso_values[(unsigned char)str[28]];
      /*FALLTHROUGH*/
      case 28:
        hval += asso_values[(unsigned char)str[27]];
      /*FALLTHROUGH*/
      case 27:
        hval += asso_values[(unsigned char)str[26]];
      /*FALLTHROUGH*/
      case 26:
        hval += asso_values[(unsigned char)str[25]];
      /*FALLTHROUGH*/
      case 25:
        hval += asso_values[(unsigned char)str[24]];
      /*FALLTHROUGH*/
      case 24:
        hval += asso_values[(unsigned char)str[23]];
      /*FALLTHROUGH*/
      case 23:
        hval += asso_values[(unsigned char)str[22]];
      /*FALLTHROUGH*/
      case 22:
        hval += asso_values[(unsigned char)str[21]];
      /*FALLTHROUGH*/
      case 21:
        hval += asso_values[(unsigned char)str[20]];
      /*FALLTHROUGH*/
      case 20:
        hval += asso_values[(unsigned char)str[19]];
      /*FALLTHROUGH*/
      case 19:
        hval += asso_values[(unsigned char)str[18]];
      /*FALLTHROUGH*/
      case 18:
        hval += asso_values[(unsigned char)str[17]];
      /*FALLTHROUGH*/
      case 17:
        hval += asso_values[(unsigned char)str[16]];
      /*FALLTHROUGH*/
      case 16:
        hval += asso_values[(unsigned char)str[15]];
      /*FALLTHROUGH*/
      case 15:
        hval += asso_values[(unsigned char)str[14]];
      /*FALLTHROUGH*/
      case 14:
        hval += asso_values[(unsigned char)str[13]];
      /*FALLTHROUGH*/
      case 13:
        hval += asso_values[(unsigned char)str[12]];
      /*FALLTHROUGH*/
      case 12:
        hval += asso_values[(unsigned char)str[11]];
      /*FALLTHROUGH*/
      case 11:
        hval += asso_values[(unsigned char)str[10]];
      /*FALLTHROUGH*/
      case 10:
        hval += asso_values[(unsigned char)str[9]];
      /*FALLTHROUGH*/
      case 9:
        hval += asso_values[(unsigned char)str[8]];
      /*FALLTHROUGH*/
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      /*FALLTHROUGH*/
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      /*FALLTHROUGH*/
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

struct stringpool_t
  {
    char stringpool_str0[sizeof("order")];
    char stringpool_str1[sizeof("border")];
    char stringpool_str2[sizeof("bottom")];
    char stringpool_str3[sizeof("marker")];
    char stringpool_str4[sizeof("animation")];
    char stringpool_str5[sizeof("word-break")];
    char stringpool_str6[sizeof("orientation")];
    char stringpool_str7[sizeof("marker-end")];
    char stringpool_str8[sizeof("marker-mid")];
    char stringpool_str9[sizeof("-webkit-order")];
    char stringpool_str10[sizeof("kerning")];
    char stringpool_str11[sizeof("margin")];
    char stringpool_str12[sizeof("border-bottom")];
    char stringpool_str13[sizeof("grid-row")];
    char stringpool_str14[sizeof("animation-name")];
    char stringpool_str15[sizeof("grid-area")];
    char stringpool_str16[sizeof("-webkit-animation")];
    char stringpool_str17[sizeof("-webkit-border-end")];
    char stringpool_str18[sizeof("grid-row-end")];
    char stringpool_str19[sizeof("writing-mode")];
    char stringpool_str20[sizeof("border-image")];
    char stringpool_str21[sizeof("mask")];
    char stringpool_str22[sizeof("zoom")];
    char stringpool_str23[sizeof("widows")];
    char stringpool_str24[sizeof("margin-bottom")];
    char stringpool_str25[sizeof("stroke")];
    char stringpool_str26[sizeof("top")];
    char stringpool_str27[sizeof("-webkit-animation-name")];
    char stringpool_str28[sizeof("-webkit-margin-end")];
    char stringpool_str29[sizeof("transition")];
    char stringpool_str30[sizeof("min-zoom")];
    char stringpool_str31[sizeof("-webkit-writing-mode")];
    char stringpool_str32[sizeof("-webkit-border-image")];
    char stringpool_str33[sizeof("-webkit-mask")];
    char stringpool_str34[sizeof("image-rendering")];
    char stringpool_str35[sizeof("word-wrap")];
    char stringpool_str36[sizeof("marker-start")];
    char stringpool_str37[sizeof("page")];
    char stringpool_str38[sizeof("border-top")];
    char stringpool_str39[sizeof("paint-order")];
    char stringpool_str40[sizeof("padding")];
    char stringpool_str41[sizeof("-webkit-transition")];
    char stringpool_str42[sizeof("size")];
    char stringpool_str43[sizeof("-webkit-border-start")];
    char stringpool_str44[sizeof("grid-row-start")];
    char stringpool_str45[sizeof("margin-top")];
    char stringpool_str46[sizeof("resize")];
    char stringpool_str47[sizeof("tab-size")];
    char stringpool_str48[sizeof("speak")];
    char stringpool_str49[sizeof("padding-bottom")];
    char stringpool_str50[sizeof("-webkit-line-break")];
    char stringpool_str51[sizeof("-webkit-mask-image")];
    char stringpool_str52[sizeof("-webkit-mask-origin")];
    char stringpool_str53[sizeof("-webkit-margin-start")];
    char stringpool_str54[sizeof("position")];
    char stringpool_str55[sizeof("-webkit-padding-end")];
    char stringpool_str56[sizeof("content")];
    char stringpool_str57[sizeof("border-image-repeat")];
    char stringpool_str58[sizeof("direction")];
    char stringpool_str59[sizeof("isolation")];
    char stringpool_str60[sizeof("-webkit-rtl-ordering")];
    char stringpool_str61[sizeof("width")];
    char stringpool_str62[sizeof("-webkit-mask-repeat")];
    char stringpool_str63[sizeof("stroke-linejoin")];
    char stringpool_str64[sizeof("padding-top")];
    char stringpool_str65[sizeof("dominant-baseline")];
    char stringpool_str66[sizeof("min-width")];
    char stringpool_str67[sizeof("align-items")];
    char stringpool_str68[sizeof("src")];
    char stringpool_str69[sizeof("page-break-inside")];
    char stringpool_str70[sizeof("animation-direction")];
    char stringpool_str71[sizeof("stroke-miterlimit")];
    char stringpool_str72[sizeof("right")];
    char stringpool_str73[sizeof("border-width")];
    char stringpool_str74[sizeof("-webkit-padding-start")];
    char stringpool_str75[sizeof("pointer-events")];
    char stringpool_str76[sizeof("-webkit-app-region")];
    char stringpool_str77[sizeof("-webkit-mask-size")];
    char stringpool_str78[sizeof("-webkit-align-items")];
    char stringpool_str79[sizeof("-webkit-animation-direction")];
    char stringpool_str80[sizeof("border-right")];
    char stringpool_str81[sizeof("clear")];
    char stringpool_str82[sizeof("border-bottom-width")];
    char stringpool_str83[sizeof("color")];
    char stringpool_str84[sizeof("-webkit-border-end-width")];
    char stringpool_str85[sizeof("-webkit-mask-position")];
    char stringpool_str86[sizeof("border-image-width")];
    char stringpool_str87[sizeof("margin-right")];
    char stringpool_str88[sizeof("stroke-width")];
    char stringpool_str89[sizeof("border-color")];
    char stringpool_str90[sizeof("animation-duration")];
    char stringpool_str91[sizeof("quotes")];
    char stringpool_str92[sizeof("align-content")];
    char stringpool_str93[sizeof("border-top-width")];
    char stringpool_str94[sizeof("border-bottom-color")];
    char stringpool_str95[sizeof("grid-template-rows")];
    char stringpool_str96[sizeof("color-rendering")];
    char stringpool_str97[sizeof("-webkit-animation-duration")];
    char stringpool_str98[sizeof("grid-template-areas")];
    char stringpool_str99[sizeof("caption-side")];
    char stringpool_str100[sizeof("clip")];
    char stringpool_str101[sizeof("-webkit-border-end-color")];
    char stringpool_str102[sizeof("alignment-baseline")];
    char stringpool_str103[sizeof("border-radius")];
    char stringpool_str104[sizeof("-webkit-align-content")];
    char stringpool_str105[sizeof("-webkit-border-start-width")];
    char stringpool_str106[sizeof("object-position")];
    char stringpool_str107[sizeof("outline")];
    char stringpool_str108[sizeof("orphans")];
    char stringpool_str109[sizeof("word-spacing")];
    char stringpool_str110[sizeof("padding-right")];
    char stringpool_str111[sizeof("-webkit-aspect-ratio")];
    char stringpool_str112[sizeof("transition-duration")];
    char stringpool_str113[sizeof("-epub-word-break")];
    char stringpool_str114[sizeof("border-spacing")];
    char stringpool_str115[sizeof("-webkit-appearance")];
    char stringpool_str116[sizeof("grid-auto-rows")];
    char stringpool_str117[sizeof("-webkit-border-radius")];
    char stringpool_str118[sizeof("-webkit-user-drag")];
    char stringpool_str119[sizeof("border-top-color")];
    char stringpool_str120[sizeof("-webkit-locale")];
    char stringpool_str121[sizeof("user-zoom")];
    char stringpool_str122[sizeof("-webkit-transition-duration")];
    char stringpool_str123[sizeof("border-image-outset")];
    char stringpool_str124[sizeof("shape-margin")];
    char stringpool_str125[sizeof("-epub-writing-mode")];
    char stringpool_str126[sizeof("border-image-slice")];
    char stringpool_str127[sizeof("shape-rendering")];
    char stringpool_str128[sizeof("-webkit-border-start-color")];
    char stringpool_str129[sizeof("height")];
    char stringpool_str130[sizeof("stop-color")];
    char stringpool_str131[sizeof("unicode-bidi")];
    char stringpool_str132[sizeof("-webkit-shape-margin")];
    char stringpool_str133[sizeof("shape-inside")];
    char stringpool_str134[sizeof("stroke-linecap")];
    char stringpool_str135[sizeof("min-height")];
    char stringpool_str136[sizeof("-webkit-mask-composite")];
    char stringpool_str137[sizeof("background")];
    char stringpool_str138[sizeof("-webkit-mask-clip")];
    char stringpool_str139[sizeof("unicode-range")];
    char stringpool_str140[sizeof("-webkit-shape-inside")];
    char stringpool_str141[sizeof("letter-spacing")];
    char stringpool_str142[sizeof("vertical-align")];
    char stringpool_str143[sizeof("border-right-width")];
    char stringpool_str144[sizeof("cursor")];
    char stringpool_str145[sizeof("shape-padding")];
    char stringpool_str146[sizeof("animation-iteration-count")];
    char stringpool_str147[sizeof("-webkit-line-clamp")];
    char stringpool_str148[sizeof("-webkit-perspective")];
    char stringpool_str149[sizeof("color-interpolation")];
    char stringpool_str150[sizeof("counter-reset")];
    char stringpool_str151[sizeof("background-image")];
    char stringpool_str152[sizeof("background-origin")];
    char stringpool_str153[sizeof("-webkit-shape-padding")];
    char stringpool_str154[sizeof("-webkit-animation-iteration-count")];
    char stringpool_str155[sizeof("-internal-marquee-repetition")];
    char stringpool_str156[sizeof("white-space")];
    char stringpool_str157[sizeof("-webkit-background-origin")];
    char stringpool_str158[sizeof("line-height")];
    char stringpool_str159[sizeof("border-right-color")];
    char stringpool_str160[sizeof("border-collapse")];
    char stringpool_str161[sizeof("-webkit-perspective-origin")];
    char stringpool_str162[sizeof("grid-column")];
    char stringpool_str163[sizeof("border-image-source")];
    char stringpool_str164[sizeof("background-repeat")];
    char stringpool_str165[sizeof("-internal-marquee-speed")];
    char stringpool_str166[sizeof("outline-width")];
    char stringpool_str167[sizeof("grid-column-end")];
    char stringpool_str168[sizeof("enable-background")];
    char stringpool_str169[sizeof("font")];
    char stringpool_str170[sizeof("background-blend-mode")];
    char stringpool_str171[sizeof("-internal-marquee-direction")];
    char stringpool_str172[sizeof("background-size")];
    char stringpool_str173[sizeof("will-change")];
    char stringpool_str174[sizeof("-internal-marquee-increment")];
    char stringpool_str175[sizeof("-webkit-margin-collapse")];
    char stringpool_str176[sizeof("-webkit-columns")];
    char stringpool_str177[sizeof("counter-increment")];
    char stringpool_str178[sizeof("border-bottom-right-radius")];
    char stringpool_str179[sizeof("-webkit-background-size")];
    char stringpool_str180[sizeof("clip-path")];
    char stringpool_str181[sizeof("background-position")];
    char stringpool_str182[sizeof("outline-color")];
    char stringpool_str183[sizeof("-webkit-margin-bottom-collapse")];
    char stringpool_str184[sizeof("-webkit-logical-width")];
    char stringpool_str185[sizeof("lighting-color")];
    char stringpool_str186[sizeof("grid-column-start")];
    char stringpool_str187[sizeof("-webkit-border-fit")];
    char stringpool_str188[sizeof("font-kerning")];
    char stringpool_str189[sizeof("-webkit-border-bottom-right-radius")];
    char stringpool_str190[sizeof("-webkit-column-break-inside")];
    char stringpool_str191[sizeof("-webkit-min-logical-width")];
    char stringpool_str192[sizeof("-webkit-clip-path")];
    char stringpool_str193[sizeof("-webkit-border-after")];
    char stringpool_str194[sizeof("-webkit-column-gap")];
    char stringpool_str195[sizeof("-internal-callback")];
    char stringpool_str196[sizeof("-webkit-border-before")];
    char stringpool_str197[sizeof("-epub-caption-side")];
    char stringpool_str198[sizeof("shape-outside")];
    char stringpool_str199[sizeof("font-variant")];
    char stringpool_str200[sizeof("-webkit-user-select")];
    char stringpool_str201[sizeof("border-top-right-radius")];
    char stringpool_str202[sizeof("-webkit-margin-after")];
    char stringpool_str203[sizeof("left")];
    char stringpool_str204[sizeof("-webkit-margin-before")];
    char stringpool_str205[sizeof("clip-rule")];
    char stringpool_str206[sizeof("float")];
    char stringpool_str207[sizeof("-webkit-margin-top-collapse")];
    char stringpool_str208[sizeof("filter")];
    char stringpool_str209[sizeof("-webkit-column-span")];
    char stringpool_str210[sizeof("-webkit-shape-outside")];
    char stringpool_str211[sizeof("scroll-behavior")];
    char stringpool_str212[sizeof("-webkit-transform")];
    char stringpool_str213[sizeof("-webkit-border-top-right-radius")];
    char stringpool_str214[sizeof("border-left")];
    char stringpool_str215[sizeof("-webkit-filter")];
    char stringpool_str216[sizeof("-webkit-print-color-adjust")];
    char stringpool_str217[sizeof("background-color")];
    char stringpool_str218[sizeof("font-size")];
    char stringpool_str219[sizeof("-webkit-border-vertical-spacing")];
    char stringpool_str220[sizeof("page-break-after")];
    char stringpool_str221[sizeof("margin-left")];
    char stringpool_str222[sizeof("page-break-before")];
    char stringpool_str223[sizeof("text-indent")];
    char stringpool_str224[sizeof("-webkit-column-width")];
    char stringpool_str225[sizeof("overflow")];
    char stringpool_str226[sizeof("-webkit-padding-after")];
    char stringpool_str227[sizeof("-webkit-padding-before")];
    char stringpool_str228[sizeof("-webkit-transform-origin")];
    char stringpool_str229[sizeof("object-fit")];
    char stringpool_str230[sizeof("-webkit-highlight")];
    char stringpool_str231[sizeof("touch-action")];
    char stringpool_str232[sizeof("-webkit-box-orient")];
    char stringpool_str233[sizeof("fill")];
    char stringpool_str234[sizeof("text-rendering")];
    char stringpool_str235[sizeof("-webkit-wrap-through")];
    char stringpool_str236[sizeof("-webkit-border-horizontal-spacing")];
    char stringpool_str237[sizeof("z-index")];
    char stringpool_str238[sizeof("background-clip")];
    char stringpool_str239[sizeof("-webkit-text-orientation")];
    char stringpool_str240[sizeof("max-zoom")];
    char stringpool_str241[sizeof("-webkit-wrap-flow")];
    char stringpool_str242[sizeof("-webkit-column-progression")];
    char stringpool_str243[sizeof("padding-left")];
    char stringpool_str244[sizeof("-webkit-background-composite")];
    char stringpool_str245[sizeof("-webkit-background-clip")];
    char stringpool_str246[sizeof("grid-template-columns")];
    char stringpool_str247[sizeof("font-weight")];
    char stringpool_str248[sizeof("-webkit-transform-origin-z")];
    char stringpool_str249[sizeof("background-attachment")];
    char stringpool_str250[sizeof("-webkit-text-stroke")];
    char stringpool_str251[sizeof("animation-fill-mode")];
    char stringpool_str252[sizeof("-webkit-logical-height")];
    char stringpool_str253[sizeof("overflow-wrap")];
    char stringpool_str254[sizeof("mix-blend-mode")];
    char stringpool_str255[sizeof("text-align")];
    char stringpool_str256[sizeof("-webkit-border-after-width")];
    char stringpool_str257[sizeof("-webkit-border-before-width")];
    char stringpool_str258[sizeof("-webkit-min-logical-height")];
    char stringpool_str259[sizeof("grid-auto-columns")];
    char stringpool_str260[sizeof("-webkit-animation-fill-mode")];
    char stringpool_str261[sizeof("-webkit-font-size-delta")];
    char stringpool_str262[sizeof("-webkit-mask-box-image")];
    char stringpool_str263[sizeof("-webkit-column-rule")];
    char stringpool_str264[sizeof("align-self")];
    char stringpool_str265[sizeof("-webkit-box-align")];
    char stringpool_str266[sizeof("box-sizing")];
    char stringpool_str267[sizeof("-webkit-align-self")];
    char stringpool_str268[sizeof("text-decoration")];
    char stringpool_str269[sizeof("-webkit-box-sizing")];
    char stringpool_str270[sizeof("animation-delay")];
    char stringpool_str271[sizeof("border-left-width")];
    char stringpool_str272[sizeof("-webkit-box-lines")];
    char stringpool_str273[sizeof("text-overline-mode")];
    char stringpool_str274[sizeof("-webkit-border-after-color")];
    char stringpool_str275[sizeof("-webkit-mask-repeat-x")];
    char stringpool_str276[sizeof("max-width")];
    char stringpool_str277[sizeof("-webkit-border-before-color")];
    char stringpool_str278[sizeof("-webkit-text-combine")];
    char stringpool_str279[sizeof("-webkit-font-smoothing")];
    char stringpool_str280[sizeof("-webkit-box-direction")];
    char stringpool_str281[sizeof("mask-type")];
    char stringpool_str282[sizeof("-webkit-column-count")];
    char stringpool_str283[sizeof("-webkit-animation-delay")];
    char stringpool_str284[sizeof("flood-color")];
    char stringpool_str285[sizeof("-webkit-box-decoration-break")];
    char stringpool_str286[sizeof("shape-image-threshold")];
    char stringpool_str287[sizeof("border-style")];
    char stringpool_str288[sizeof("grid-auto-flow")];
    char stringpool_str289[sizeof("transition-delay")];
    char stringpool_str290[sizeof("border-left-color")];
    char stringpool_str291[sizeof("-webkit-mask-box-image-repeat")];
    char stringpool_str292[sizeof("-webkit-mask-repeat-y")];
    char stringpool_str293[sizeof("box-shadow")];
    char stringpool_str294[sizeof("-webkit-box-pack")];
    char stringpool_str295[sizeof("text-shadow")];
    char stringpool_str296[sizeof("-webkit-mask-position-x")];
    char stringpool_str297[sizeof("-webkit-shape-image-threshold")];
    char stringpool_str298[sizeof("border-bottom-style")];
    char stringpool_str299[sizeof("visibility")];
    char stringpool_str300[sizeof("-webkit-transition-delay")];
    char stringpool_str301[sizeof("-webkit-border-end-style")];
    char stringpool_str302[sizeof("-webkit-box-shadow")];
    char stringpool_str303[sizeof("font-stretch")];
    char stringpool_str304[sizeof("opacity")];
    char stringpool_str305[sizeof("display")];
    char stringpool_str306[sizeof("text-decoration-line")];
    char stringpool_str307[sizeof("baseline-shift")];
    char stringpool_str308[sizeof("text-align-last")];
    char stringpool_str309[sizeof("-webkit-line-box-contain")];
    char stringpool_str310[sizeof("color-profile")];
    char stringpool_str311[sizeof("-webkit-text-stroke-width")];
    char stringpool_str312[sizeof("-webkit-opacity")];
    char stringpool_str313[sizeof("-webkit-mask-position-y")];
    char stringpool_str314[sizeof("transition-property")];
    char stringpool_str315[sizeof("border-top-style")];
    char stringpool_str316[sizeof("border-bottom-left-radius")];
    char stringpool_str317[sizeof("animation-play-state")];
    char stringpool_str318[sizeof("-webkit-border-start-style")];
    char stringpool_str319[sizeof("animation-timing-function")];
    char stringpool_str320[sizeof("text-anchor")];
    char stringpool_str321[sizeof("-webkit-transition-property")];
    char stringpool_str322[sizeof("-webkit-mask-box-image-width")];
    char stringpool_str323[sizeof("-webkit-column-rule-width")];
    char stringpool_str324[sizeof("-webkit-border-bottom-left-radius")];
    char stringpool_str325[sizeof("-epub-text-orientation")];
    char stringpool_str326[sizeof("text-underline-mode")];
    char stringpool_str327[sizeof("-webkit-animation-play-state")];
    char stringpool_str328[sizeof("text-overline-width")];
    char stringpool_str329[sizeof("-webkit-text-stroke-color")];
    char stringpool_str330[sizeof("stroke-opacity")];
    char stringpool_str331[sizeof("list-style")];
    char stringpool_str332[sizeof("-webkit-animation-timing-function")];
    char stringpool_str333[sizeof("fill-rule")];
    char stringpool_str334[sizeof("font-variant-ligatures")];
    char stringpool_str335[sizeof("border-top-left-radius")];
    char stringpool_str336[sizeof("-webkit-tap-highlight-color")];
    char stringpool_str337[sizeof("stroke-dasharray")];
    char stringpool_str338[sizeof("max-height")];
    char stringpool_str339[sizeof("transition-timing-function")];
    char stringpool_str340[sizeof("-webkit-column-rule-color")];
    char stringpool_str341[sizeof("-webkit-border-top-left-radius")];
    char stringpool_str342[sizeof("-webkit-column-break-after")];
    char stringpool_str343[sizeof("-webkit-column-break-before")];
    char stringpool_str344[sizeof("list-style-image")];
    char stringpool_str345[sizeof("text-overline-color")];
    char stringpool_str346[sizeof("-webkit-text-emphasis")];
    char stringpool_str347[sizeof("-webkit-transition-timing-function")];
    char stringpool_str348[sizeof("stop-opacity")];
    char stringpool_str349[sizeof("text-decoration-color")];
    char stringpool_str350[sizeof("-webkit-margin-after-collapse")];
    char stringpool_str351[sizeof("-webkit-margin-before-collapse")];
    char stringpool_str352[sizeof("-webkit-mask-box-image-outset")];
    char stringpool_str353[sizeof("border-right-style")];
    char stringpool_str354[sizeof("-webkit-mask-box-image-slice")];
    char stringpool_str355[sizeof("-webkit-ruby-position")];
    char stringpool_str356[sizeof("-webkit-box-ordinal-group")];
    char stringpool_str357[sizeof("table-layout")];
    char stringpool_str358[sizeof("-epub-text-combine")];
    char stringpool_str359[sizeof("color-interpolation-filters")];
    char stringpool_str360[sizeof("text-underline-position")];
    char stringpool_str361[sizeof("-webkit-perspective-origin-x")];
    char stringpool_str362[sizeof("background-repeat-x")];
    char stringpool_str363[sizeof("column-fill")];
    char stringpool_str364[sizeof("list-style-position")];
    char stringpool_str365[sizeof("empty-cells")];
    char stringpool_str366[sizeof("text-underline-width")];
    char stringpool_str367[sizeof("outline-style")];
    char stringpool_str368[sizeof("-webkit-column-axis")];
    char stringpool_str369[sizeof("-webkit-perspective-origin-y")];
    char stringpool_str370[sizeof("background-repeat-y")];
    char stringpool_str371[sizeof("background-position-x")];
    char stringpool_str372[sizeof("-internal-marquee-style")];
    char stringpool_str373[sizeof("-webkit-text-emphasis-position")];
    char stringpool_str374[sizeof("-webkit-max-logical-width")];
    char stringpool_str375[sizeof("text-underline-color")];
    char stringpool_str376[sizeof("-webkit-mask-box-image-source")];
    char stringpool_str377[sizeof("flex")];
    char stringpool_str378[sizeof("background-position-y")];
    char stringpool_str379[sizeof("text-transform")];
    char stringpool_str380[sizeof("-webkit-flex")];
    char stringpool_str381[sizeof("mask-source-type")];
    char stringpool_str382[sizeof("flex-grow")];
    char stringpool_str383[sizeof("-webkit-text-emphasis-color")];
    char stringpool_str384[sizeof("-webkit-flex-grow")];
    char stringpool_str385[sizeof("overflow-x")];
    char stringpool_str386[sizeof("-webkit-transform-origin-x")];
    char stringpool_str387[sizeof("text-overflow")];
    char stringpool_str388[sizeof("buffered-rendering")];
    char stringpool_str389[sizeof("-epub-text-emphasis")];
    char stringpool_str390[sizeof("flex-wrap")];
    char stringpool_str391[sizeof("-webkit-flex-wrap")];
    char stringpool_str392[sizeof("text-line-through-mode")];
    char stringpool_str393[sizeof("overflow-y")];
    char stringpool_str394[sizeof("flex-basis")];
    char stringpool_str395[sizeof("font-style")];
    char stringpool_str396[sizeof("-webkit-transform-origin-y")];
    char stringpool_str397[sizeof("glyph-orientation-vertical")];
    char stringpool_str398[sizeof("vector-effect")];
    char stringpool_str399[sizeof("-webkit-flex-basis")];
    char stringpool_str400[sizeof("-webkit-max-logical-height")];
    char stringpool_str401[sizeof("flex-direction")];
    char stringpool_str402[sizeof("stroke-dashoffset")];
    char stringpool_str403[sizeof("outline-offset")];
    char stringpool_str404[sizeof("-webkit-box-reflect")];
    char stringpool_str405[sizeof("-webkit-border-after-style")];
    char stringpool_str406[sizeof("-webkit-border-before-style")];
    char stringpool_str407[sizeof("glyph-orientation-horizontal")];
    char stringpool_str408[sizeof("-webkit-flex-direction")];
    char stringpool_str409[sizeof("-webkit-font-feature-settings")];
    char stringpool_str410[sizeof("-webkit-transform-style")];
    char stringpool_str411[sizeof("touch-action-delay")];
    char stringpool_str412[sizeof("border-left-style")];
    char stringpool_str413[sizeof("flex-shrink")];
    char stringpool_str414[sizeof("-webkit-flex-shrink")];
    char stringpool_str415[sizeof("text-line-through-width")];
    char stringpool_str416[sizeof("-webkit-user-modify")];
    char stringpool_str417[sizeof("flood-opacity")];
    char stringpool_str418[sizeof("-epub-text-transform")];
    char stringpool_str419[sizeof("-epub-text-emphasis-color")];
    char stringpool_str420[sizeof("text-line-through-color")];
    char stringpool_str421[sizeof("-webkit-text-fill-color")];
    char stringpool_str422[sizeof("fill-opacity")];
    char stringpool_str423[sizeof("-webkit-hyphenate-character")];
    char stringpool_str424[sizeof("-webkit-column-rule-style")];
    char stringpool_str425[sizeof("text-overline-style")];
    char stringpool_str426[sizeof("justify-content")];
    char stringpool_str427[sizeof("text-decoration-style")];
    char stringpool_str428[sizeof("-webkit-justify-content")];
    char stringpool_str429[sizeof("-webkit-backface-visibility")];
    char stringpool_str430[sizeof("list-style-type")];
    char stringpool_str431[sizeof("-webkit-text-security")];
    char stringpool_str432[sizeof("text-underline-style")];
    char stringpool_str433[sizeof("font-family")];
    char stringpool_str434[sizeof("flex-flow")];
    char stringpool_str435[sizeof("-webkit-flex-flow")];
    char stringpool_str436[sizeof("-webkit-text-emphasis-style")];
    char stringpool_str437[sizeof("-webkit-box-flex")];
    char stringpool_str438[sizeof("-webkit-text-decorations-in-effect")];
    char stringpool_str439[sizeof("text-justify")];
    char stringpool_str440[sizeof("justify-self")];
    char stringpool_str441[sizeof("-epub-text-emphasis-style")];
    char stringpool_str442[sizeof("text-line-through-style")];
    char stringpool_str443[sizeof("-webkit-box-flex-group")];
  };
static const struct stringpool_t stringpool_contents =
  {
    "order",
    "border",
    "bottom",
    "marker",
    "animation",
    "word-break",
    "orientation",
    "marker-end",
    "marker-mid",
    "-webkit-order",
    "kerning",
    "margin",
    "border-bottom",
    "grid-row",
    "animation-name",
    "grid-area",
    "-webkit-animation",
    "-webkit-border-end",
    "grid-row-end",
    "writing-mode",
    "border-image",
    "mask",
    "zoom",
    "widows",
    "margin-bottom",
    "stroke",
    "top",
    "-webkit-animation-name",
    "-webkit-margin-end",
    "transition",
    "min-zoom",
    "-webkit-writing-mode",
    "-webkit-border-image",
    "-webkit-mask",
    "image-rendering",
    "word-wrap",
    "marker-start",
    "page",
    "border-top",
    "paint-order",
    "padding",
    "-webkit-transition",
    "size",
    "-webkit-border-start",
    "grid-row-start",
    "margin-top",
    "resize",
    "tab-size",
    "speak",
    "padding-bottom",
    "-webkit-line-break",
    "-webkit-mask-image",
    "-webkit-mask-origin",
    "-webkit-margin-start",
    "position",
    "-webkit-padding-end",
    "content",
    "border-image-repeat",
    "direction",
    "isolation",
    "-webkit-rtl-ordering",
    "width",
    "-webkit-mask-repeat",
    "stroke-linejoin",
    "padding-top",
    "dominant-baseline",
    "min-width",
    "align-items",
    "src",
    "page-break-inside",
    "animation-direction",
    "stroke-miterlimit",
    "right",
    "border-width",
    "-webkit-padding-start",
    "pointer-events",
    "-webkit-app-region",
    "-webkit-mask-size",
    "-webkit-align-items",
    "-webkit-animation-direction",
    "border-right",
    "clear",
    "border-bottom-width",
    "color",
    "-webkit-border-end-width",
    "-webkit-mask-position",
    "border-image-width",
    "margin-right",
    "stroke-width",
    "border-color",
    "animation-duration",
    "quotes",
    "align-content",
    "border-top-width",
    "border-bottom-color",
    "grid-template-rows",
    "color-rendering",
    "-webkit-animation-duration",
    "grid-template-areas",
    "caption-side",
    "clip",
    "-webkit-border-end-color",
    "alignment-baseline",
    "border-radius",
    "-webkit-align-content",
    "-webkit-border-start-width",
    "object-position",
    "outline",
    "orphans",
    "word-spacing",
    "padding-right",
    "-webkit-aspect-ratio",
    "transition-duration",
    "-epub-word-break",
    "border-spacing",
    "-webkit-appearance",
    "grid-auto-rows",
    "-webkit-border-radius",
    "-webkit-user-drag",
    "border-top-color",
    "-webkit-locale",
    "user-zoom",
    "-webkit-transition-duration",
    "border-image-outset",
    "shape-margin",
    "-epub-writing-mode",
    "border-image-slice",
    "shape-rendering",
    "-webkit-border-start-color",
    "height",
    "stop-color",
    "unicode-bidi",
    "-webkit-shape-margin",
    "shape-inside",
    "stroke-linecap",
    "min-height",
    "-webkit-mask-composite",
    "background",
    "-webkit-mask-clip",
    "unicode-range",
    "-webkit-shape-inside",
    "letter-spacing",
    "vertical-align",
    "border-right-width",
    "cursor",
    "shape-padding",
    "animation-iteration-count",
    "-webkit-line-clamp",
    "-webkit-perspective",
    "color-interpolation",
    "counter-reset",
    "background-image",
    "background-origin",
    "-webkit-shape-padding",
    "-webkit-animation-iteration-count",
    "-internal-marquee-repetition",
    "white-space",
    "-webkit-background-origin",
    "line-height",
    "border-right-color",
    "border-collapse",
    "-webkit-perspective-origin",
    "grid-column",
    "border-image-source",
    "background-repeat",
    "-internal-marquee-speed",
    "outline-width",
    "grid-column-end",
    "enable-background",
    "font",
    "background-blend-mode",
    "-internal-marquee-direction",
    "background-size",
    "will-change",
    "-internal-marquee-increment",
    "-webkit-margin-collapse",
    "-webkit-columns",
    "counter-increment",
    "border-bottom-right-radius",
    "-webkit-background-size",
    "clip-path",
    "background-position",
    "outline-color",
    "-webkit-margin-bottom-collapse",
    "-webkit-logical-width",
    "lighting-color",
    "grid-column-start",
    "-webkit-border-fit",
    "font-kerning",
    "-webkit-border-bottom-right-radius",
    "-webkit-column-break-inside",
    "-webkit-min-logical-width",
    "-webkit-clip-path",
    "-webkit-border-after",
    "-webkit-column-gap",
    "-internal-callback",
    "-webkit-border-before",
    "-epub-caption-side",
    "shape-outside",
    "font-variant",
    "-webkit-user-select",
    "border-top-right-radius",
    "-webkit-margin-after",
    "left",
    "-webkit-margin-before",
    "clip-rule",
    "float",
    "-webkit-margin-top-collapse",
    "filter",
    "-webkit-column-span",
    "-webkit-shape-outside",
    "scroll-behavior",
    "-webkit-transform",
    "-webkit-border-top-right-radius",
    "border-left",
    "-webkit-filter",
    "-webkit-print-color-adjust",
    "background-color",
    "font-size",
    "-webkit-border-vertical-spacing",
    "page-break-after",
    "margin-left",
    "page-break-before",
    "text-indent",
    "-webkit-column-width",
    "overflow",
    "-webkit-padding-after",
    "-webkit-padding-before",
    "-webkit-transform-origin",
    "object-fit",
    "-webkit-highlight",
    "touch-action",
    "-webkit-box-orient",
    "fill",
    "text-rendering",
    "-webkit-wrap-through",
    "-webkit-border-horizontal-spacing",
    "z-index",
    "background-clip",
    "-webkit-text-orientation",
    "max-zoom",
    "-webkit-wrap-flow",
    "-webkit-column-progression",
    "padding-left",
    "-webkit-background-composite",
    "-webkit-background-clip",
    "grid-template-columns",
    "font-weight",
    "-webkit-transform-origin-z",
    "background-attachment",
    "-webkit-text-stroke",
    "animation-fill-mode",
    "-webkit-logical-height",
    "overflow-wrap",
    "mix-blend-mode",
    "text-align",
    "-webkit-border-after-width",
    "-webkit-border-before-width",
    "-webkit-min-logical-height",
    "grid-auto-columns",
    "-webkit-animation-fill-mode",
    "-webkit-font-size-delta",
    "-webkit-mask-box-image",
    "-webkit-column-rule",
    "align-self",
    "-webkit-box-align",
    "box-sizing",
    "-webkit-align-self",
    "text-decoration",
    "-webkit-box-sizing",
    "animation-delay",
    "border-left-width",
    "-webkit-box-lines",
    "text-overline-mode",
    "-webkit-border-after-color",
    "-webkit-mask-repeat-x",
    "max-width",
    "-webkit-border-before-color",
    "-webkit-text-combine",
    "-webkit-font-smoothing",
    "-webkit-box-direction",
    "mask-type",
    "-webkit-column-count",
    "-webkit-animation-delay",
    "flood-color",
    "-webkit-box-decoration-break",
    "shape-image-threshold",
    "border-style",
    "grid-auto-flow",
    "transition-delay",
    "border-left-color",
    "-webkit-mask-box-image-repeat",
    "-webkit-mask-repeat-y",
    "box-shadow",
    "-webkit-box-pack",
    "text-shadow",
    "-webkit-mask-position-x",
    "-webkit-shape-image-threshold",
    "border-bottom-style",
    "visibility",
    "-webkit-transition-delay",
    "-webkit-border-end-style",
    "-webkit-box-shadow",
    "font-stretch",
    "opacity",
    "display",
    "text-decoration-line",
    "baseline-shift",
    "text-align-last",
    "-webkit-line-box-contain",
    "color-profile",
    "-webkit-text-stroke-width",
    "-webkit-opacity",
    "-webkit-mask-position-y",
    "transition-property",
    "border-top-style",
    "border-bottom-left-radius",
    "animation-play-state",
    "-webkit-border-start-style",
    "animation-timing-function",
    "text-anchor",
    "-webkit-transition-property",
    "-webkit-mask-box-image-width",
    "-webkit-column-rule-width",
    "-webkit-border-bottom-left-radius",
    "-epub-text-orientation",
    "text-underline-mode",
    "-webkit-animation-play-state",
    "text-overline-width",
    "-webkit-text-stroke-color",
    "stroke-opacity",
    "list-style",
    "-webkit-animation-timing-function",
    "fill-rule",
    "font-variant-ligatures",
    "border-top-left-radius",
    "-webkit-tap-highlight-color",
    "stroke-dasharray",
    "max-height",
    "transition-timing-function",
    "-webkit-column-rule-color",
    "-webkit-border-top-left-radius",
    "-webkit-column-break-after",
    "-webkit-column-break-before",
    "list-style-image",
    "text-overline-color",
    "-webkit-text-emphasis",
    "-webkit-transition-timing-function",
    "stop-opacity",
    "text-decoration-color",
    "-webkit-margin-after-collapse",
    "-webkit-margin-before-collapse",
    "-webkit-mask-box-image-outset",
    "border-right-style",
    "-webkit-mask-box-image-slice",
    "-webkit-ruby-position",
    "-webkit-box-ordinal-group",
    "table-layout",
    "-epub-text-combine",
    "color-interpolation-filters",
    "text-underline-position",
    "-webkit-perspective-origin-x",
    "background-repeat-x",
    "column-fill",
    "list-style-position",
    "empty-cells",
    "text-underline-width",
    "outline-style",
    "-webkit-column-axis",
    "-webkit-perspective-origin-y",
    "background-repeat-y",
    "background-position-x",
    "-internal-marquee-style",
    "-webkit-text-emphasis-position",
    "-webkit-max-logical-width",
    "text-underline-color",
    "-webkit-mask-box-image-source",
    "flex",
    "background-position-y",
    "text-transform",
    "-webkit-flex",
    "mask-source-type",
    "flex-grow",
    "-webkit-text-emphasis-color",
    "-webkit-flex-grow",
    "overflow-x",
    "-webkit-transform-origin-x",
    "text-overflow",
    "buffered-rendering",
    "-epub-text-emphasis",
    "flex-wrap",
    "-webkit-flex-wrap",
    "text-line-through-mode",
    "overflow-y",
    "flex-basis",
    "font-style",
    "-webkit-transform-origin-y",
    "glyph-orientation-vertical",
    "vector-effect",
    "-webkit-flex-basis",
    "-webkit-max-logical-height",
    "flex-direction",
    "stroke-dashoffset",
    "outline-offset",
    "-webkit-box-reflect",
    "-webkit-border-after-style",
    "-webkit-border-before-style",
    "glyph-orientation-horizontal",
    "-webkit-flex-direction",
    "-webkit-font-feature-settings",
    "-webkit-transform-style",
    "touch-action-delay",
    "border-left-style",
    "flex-shrink",
    "-webkit-flex-shrink",
    "text-line-through-width",
    "-webkit-user-modify",
    "flood-opacity",
    "-epub-text-transform",
    "-epub-text-emphasis-color",
    "text-line-through-color",
    "-webkit-text-fill-color",
    "fill-opacity",
    "-webkit-hyphenate-character",
    "-webkit-column-rule-style",
    "text-overline-style",
    "justify-content",
    "text-decoration-style",
    "-webkit-justify-content",
    "-webkit-backface-visibility",
    "list-style-type",
    "-webkit-text-security",
    "text-underline-style",
    "font-family",
    "flex-flow",
    "-webkit-flex-flow",
    "-webkit-text-emphasis-style",
    "-webkit-box-flex",
    "-webkit-text-decorations-in-effect",
    "text-justify",
    "justify-self",
    "-epub-text-emphasis-style",
    "text-line-through-style",
    "-webkit-box-flex-group"
  };
#define stringpool ((const char *) &stringpool_contents)

static const struct Property property_word_list[] =
  {
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str0, CSSPropertyOrder},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str1, CSSPropertyBorder},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str2, CSSPropertyBottom},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str3, CSSPropertyMarker},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str4, CSSPropertyAnimation},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str5, CSSPropertyWordBreak},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str6, CSSPropertyOrientation},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str7, CSSPropertyMarkerEnd},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str8, CSSPropertyMarkerMid},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str9, CSSPropertyOrder},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str10, CSSPropertyKerning},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str11, CSSPropertyMargin},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str12, CSSPropertyBorderBottom},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str13, CSSPropertyGridRow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str14, CSSPropertyAnimationName},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str15, CSSPropertyGridArea},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str16, CSSPropertyWebkitAnimation},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str17, CSSPropertyWebkitBorderEnd},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str18, CSSPropertyGridRowEnd},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str19, CSSPropertyWritingMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str20, CSSPropertyBorderImage},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str21, CSSPropertyMask},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str22, CSSPropertyZoom},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str23, CSSPropertyWidows},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str24, CSSPropertyMarginBottom},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str25, CSSPropertyStroke},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str26, CSSPropertyTop},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str27, CSSPropertyWebkitAnimationName},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str28, CSSPropertyWebkitMarginEnd},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str29, CSSPropertyTransition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str30, CSSPropertyMinZoom},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str31, CSSPropertyWebkitWritingMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str32, CSSPropertyWebkitBorderImage},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str33, CSSPropertyWebkitMask},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str34, CSSPropertyImageRendering},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str35, CSSPropertyWordWrap},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str36, CSSPropertyMarkerStart},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str37, CSSPropertyPage},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str38, CSSPropertyBorderTop},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str39, CSSPropertyPaintOrder},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str40, CSSPropertyPadding},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str41, CSSPropertyWebkitTransition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str42, CSSPropertySize},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str43, CSSPropertyWebkitBorderStart},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str44, CSSPropertyGridRowStart},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str45, CSSPropertyMarginTop},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str46, CSSPropertyResize},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str47, CSSPropertyTabSize},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str48, CSSPropertySpeak},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str49, CSSPropertyPaddingBottom},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str50, CSSPropertyWebkitLineBreak},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str51, CSSPropertyWebkitMaskImage},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str52, CSSPropertyWebkitMaskOrigin},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str53, CSSPropertyWebkitMarginStart},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str54, CSSPropertyPosition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str55, CSSPropertyWebkitPaddingEnd},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str56, CSSPropertyContent},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str57, CSSPropertyBorderImageRepeat},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str58, CSSPropertyDirection},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str59, CSSPropertyIsolation},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str60, CSSPropertyWebkitRtlOrdering},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str61, CSSPropertyWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str62, CSSPropertyWebkitMaskRepeat},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str63, CSSPropertyStrokeLinejoin},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str64, CSSPropertyPaddingTop},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str65, CSSPropertyDominantBaseline},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str66, CSSPropertyMinWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str67, CSSPropertyAlignItems},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str68, CSSPropertySrc},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str69, CSSPropertyPageBreakInside},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str70, CSSPropertyAnimationDirection},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str71, CSSPropertyStrokeMiterlimit},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str72, CSSPropertyRight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str73, CSSPropertyBorderWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str74, CSSPropertyWebkitPaddingStart},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str75, CSSPropertyPointerEvents},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str76, CSSPropertyWebkitAppRegion},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str77, CSSPropertyWebkitMaskSize},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str78, CSSPropertyAlignItems},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str79, CSSPropertyWebkitAnimationDirection},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str80, CSSPropertyBorderRight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str81, CSSPropertyClear},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str82, CSSPropertyBorderBottomWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str83, CSSPropertyColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str84, CSSPropertyWebkitBorderEndWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str85, CSSPropertyWebkitMaskPosition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str86, CSSPropertyBorderImageWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str87, CSSPropertyMarginRight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str88, CSSPropertyStrokeWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str89, CSSPropertyBorderColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str90, CSSPropertyAnimationDuration},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str91, CSSPropertyQuotes},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str92, CSSPropertyAlignContent},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str93, CSSPropertyBorderTopWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str94, CSSPropertyBorderBottomColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str95, CSSPropertyGridTemplateRows},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str96, CSSPropertyColorRendering},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str97, CSSPropertyWebkitAnimationDuration},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str98, CSSPropertyGridTemplateAreas},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str99, CSSPropertyCaptionSide},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str100, CSSPropertyClip},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str101, CSSPropertyWebkitBorderEndColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str102, CSSPropertyAlignmentBaseline},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str103, CSSPropertyBorderRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str104, CSSPropertyAlignContent},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str105, CSSPropertyWebkitBorderStartWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str106, CSSPropertyObjectPosition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str107, CSSPropertyOutline},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str108, CSSPropertyOrphans},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str109, CSSPropertyWordSpacing},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str110, CSSPropertyPaddingRight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str111, CSSPropertyWebkitAspectRatio},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str112, CSSPropertyTransitionDuration},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str113, CSSPropertyWordBreak},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str114, CSSPropertyBorderSpacing},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str115, CSSPropertyWebkitAppearance},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str116, CSSPropertyGridAutoRows},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str117, CSSPropertyWebkitBorderRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str118, CSSPropertyWebkitUserDrag},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str119, CSSPropertyBorderTopColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str120, CSSPropertyWebkitLocale},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str121, CSSPropertyUserZoom},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str122, CSSPropertyWebkitTransitionDuration},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str123, CSSPropertyBorderImageOutset},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str124, CSSPropertyShapeMargin},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str125, CSSPropertyWebkitWritingMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str126, CSSPropertyBorderImageSlice},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str127, CSSPropertyShapeRendering},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str128, CSSPropertyWebkitBorderStartColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str129, CSSPropertyHeight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str130, CSSPropertyStopColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str131, CSSPropertyUnicodeBidi},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str132, CSSPropertyShapeMargin},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str133, CSSPropertyShapeInside},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str134, CSSPropertyStrokeLinecap},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str135, CSSPropertyMinHeight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str136, CSSPropertyWebkitMaskComposite},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str137, CSSPropertyBackground},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str138, CSSPropertyWebkitMaskClip},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str139, CSSPropertyUnicodeRange},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str140, CSSPropertyShapeInside},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str141, CSSPropertyLetterSpacing},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str142, CSSPropertyVerticalAlign},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str143, CSSPropertyBorderRightWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str144, CSSPropertyCursor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str145, CSSPropertyShapePadding},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str146, CSSPropertyAnimationIterationCount},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str147, CSSPropertyWebkitLineClamp},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str148, CSSPropertyWebkitPerspective},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str149, CSSPropertyColorInterpolation},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str150, CSSPropertyCounterReset},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str151, CSSPropertyBackgroundImage},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str152, CSSPropertyBackgroundOrigin},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str153, CSSPropertyShapePadding},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str154, CSSPropertyWebkitAnimationIterationCount},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str155, CSSPropertyInternalMarqueeRepetition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str156, CSSPropertyWhiteSpace},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str157, CSSPropertyWebkitBackgroundOrigin},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str158, CSSPropertyLineHeight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str159, CSSPropertyBorderRightColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str160, CSSPropertyBorderCollapse},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str161, CSSPropertyWebkitPerspectiveOrigin},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str162, CSSPropertyGridColumn},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str163, CSSPropertyBorderImageSource},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str164, CSSPropertyBackgroundRepeat},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str165, CSSPropertyInternalMarqueeSpeed},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str166, CSSPropertyOutlineWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str167, CSSPropertyGridColumnEnd},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str168, CSSPropertyEnableBackground},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str169, CSSPropertyFont},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str170, CSSPropertyBackgroundBlendMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str171, CSSPropertyInternalMarqueeDirection},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str172, CSSPropertyBackgroundSize},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str173, CSSPropertyWillChange},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str174, CSSPropertyInternalMarqueeIncrement},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str175, CSSPropertyWebkitMarginCollapse},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str176, CSSPropertyWebkitColumns},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str177, CSSPropertyCounterIncrement},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str178, CSSPropertyBorderBottomRightRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str179, CSSPropertyWebkitBackgroundSize},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str180, CSSPropertyClipPath},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str181, CSSPropertyBackgroundPosition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str182, CSSPropertyOutlineColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str183, CSSPropertyWebkitMarginBottomCollapse},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str184, CSSPropertyWebkitLogicalWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str185, CSSPropertyLightingColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str186, CSSPropertyGridColumnStart},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str187, CSSPropertyWebkitBorderFit},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str188, CSSPropertyFontKerning},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str189, CSSPropertyBorderBottomRightRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str190, CSSPropertyWebkitColumnBreakInside},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str191, CSSPropertyWebkitMinLogicalWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str192, CSSPropertyWebkitClipPath},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str193, CSSPropertyWebkitBorderAfter},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str194, CSSPropertyWebkitColumnGap},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str195, CSSPropertyInternalCallback},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str196, CSSPropertyWebkitBorderBefore},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str197, CSSPropertyCaptionSide},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str198, CSSPropertyShapeOutside},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str199, CSSPropertyFontVariant},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str200, CSSPropertyWebkitUserSelect},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str201, CSSPropertyBorderTopRightRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str202, CSSPropertyWebkitMarginAfter},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str203, CSSPropertyLeft},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str204, CSSPropertyWebkitMarginBefore},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str205, CSSPropertyClipRule},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str206, CSSPropertyFloat},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str207, CSSPropertyWebkitMarginTopCollapse},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str208, CSSPropertyFilter},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str209, CSSPropertyWebkitColumnSpan},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str210, CSSPropertyShapeOutside},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str211, CSSPropertyScrollBehavior},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str212, CSSPropertyWebkitTransform},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str213, CSSPropertyBorderTopRightRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str214, CSSPropertyBorderLeft},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str215, CSSPropertyWebkitFilter},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str216, CSSPropertyWebkitPrintColorAdjust},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str217, CSSPropertyBackgroundColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str218, CSSPropertyFontSize},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str219, CSSPropertyWebkitBorderVerticalSpacing},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str220, CSSPropertyPageBreakAfter},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str221, CSSPropertyMarginLeft},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str222, CSSPropertyPageBreakBefore},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str223, CSSPropertyTextIndent},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str224, CSSPropertyWebkitColumnWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str225, CSSPropertyOverflow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str226, CSSPropertyWebkitPaddingAfter},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str227, CSSPropertyWebkitPaddingBefore},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str228, CSSPropertyWebkitTransformOrigin},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str229, CSSPropertyObjectFit},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str230, CSSPropertyWebkitHighlight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str231, CSSPropertyTouchAction},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str232, CSSPropertyWebkitBoxOrient},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str233, CSSPropertyFill},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str234, CSSPropertyTextRendering},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str235, CSSPropertyWebkitWrapThrough},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str236, CSSPropertyWebkitBorderHorizontalSpacing},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str237, CSSPropertyZIndex},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str238, CSSPropertyBackgroundClip},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str239, CSSPropertyWebkitTextOrientation},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str240, CSSPropertyMaxZoom},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str241, CSSPropertyWebkitWrapFlow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str242, CSSPropertyWebkitColumnProgression},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str243, CSSPropertyPaddingLeft},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str244, CSSPropertyWebkitBackgroundComposite},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str245, CSSPropertyWebkitBackgroundClip},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str246, CSSPropertyGridTemplateColumns},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str247, CSSPropertyFontWeight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str248, CSSPropertyWebkitTransformOriginZ},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str249, CSSPropertyBackgroundAttachment},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str250, CSSPropertyWebkitTextStroke},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str251, CSSPropertyAnimationFillMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str252, CSSPropertyWebkitLogicalHeight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str253, CSSPropertyOverflowWrap},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str254, CSSPropertyMixBlendMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str255, CSSPropertyTextAlign},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str256, CSSPropertyWebkitBorderAfterWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str257, CSSPropertyWebkitBorderBeforeWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str258, CSSPropertyWebkitMinLogicalHeight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str259, CSSPropertyGridAutoColumns},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str260, CSSPropertyWebkitAnimationFillMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str261, CSSPropertyWebkitFontSizeDelta},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str262, CSSPropertyWebkitMaskBoxImage},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str263, CSSPropertyWebkitColumnRule},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str264, CSSPropertyAlignSelf},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str265, CSSPropertyWebkitBoxAlign},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str266, CSSPropertyBoxSizing},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str267, CSSPropertyAlignSelf},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str268, CSSPropertyTextDecoration},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str269, CSSPropertyBoxSizing},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str270, CSSPropertyAnimationDelay},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str271, CSSPropertyBorderLeftWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str272, CSSPropertyWebkitBoxLines},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str273, CSSPropertyTextOverlineMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str274, CSSPropertyWebkitBorderAfterColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str275, CSSPropertyWebkitMaskRepeatX},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str276, CSSPropertyMaxWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str277, CSSPropertyWebkitBorderBeforeColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str278, CSSPropertyWebkitTextCombine},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str279, CSSPropertyWebkitFontSmoothing},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str280, CSSPropertyWebkitBoxDirection},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str281, CSSPropertyMaskType},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str282, CSSPropertyWebkitColumnCount},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str283, CSSPropertyWebkitAnimationDelay},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str284, CSSPropertyFloodColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str285, CSSPropertyWebkitBoxDecorationBreak},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str286, CSSPropertyShapeImageThreshold},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str287, CSSPropertyBorderStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str288, CSSPropertyGridAutoFlow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str289, CSSPropertyTransitionDelay},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str290, CSSPropertyBorderLeftColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str291, CSSPropertyWebkitMaskBoxImageRepeat},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str292, CSSPropertyWebkitMaskRepeatY},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str293, CSSPropertyBoxShadow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str294, CSSPropertyWebkitBoxPack},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str295, CSSPropertyTextShadow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str296, CSSPropertyWebkitMaskPositionX},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str297, CSSPropertyShapeImageThreshold},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str298, CSSPropertyBorderBottomStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str299, CSSPropertyVisibility},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str300, CSSPropertyWebkitTransitionDelay},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str301, CSSPropertyWebkitBorderEndStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str302, CSSPropertyWebkitBoxShadow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str303, CSSPropertyFontStretch},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str304, CSSPropertyOpacity},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str305, CSSPropertyDisplay},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str306, CSSPropertyTextDecorationLine},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str307, CSSPropertyBaselineShift},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str308, CSSPropertyTextAlignLast},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str309, CSSPropertyWebkitLineBoxContain},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str310, CSSPropertyColorProfile},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str311, CSSPropertyWebkitTextStrokeWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str312, CSSPropertyOpacity},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str313, CSSPropertyWebkitMaskPositionY},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str314, CSSPropertyTransitionProperty},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str315, CSSPropertyBorderTopStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str316, CSSPropertyBorderBottomLeftRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str317, CSSPropertyAnimationPlayState},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str318, CSSPropertyWebkitBorderStartStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str319, CSSPropertyAnimationTimingFunction},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str320, CSSPropertyTextAnchor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str321, CSSPropertyWebkitTransitionProperty},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str322, CSSPropertyWebkitMaskBoxImageWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str323, CSSPropertyWebkitColumnRuleWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str324, CSSPropertyBorderBottomLeftRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str325, CSSPropertyWebkitTextOrientation},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str326, CSSPropertyTextUnderlineMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str327, CSSPropertyWebkitAnimationPlayState},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str328, CSSPropertyTextOverlineWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str329, CSSPropertyWebkitTextStrokeColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str330, CSSPropertyStrokeOpacity},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str331, CSSPropertyListStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str332, CSSPropertyWebkitAnimationTimingFunction},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str333, CSSPropertyFillRule},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str334, CSSPropertyFontVariantLigatures},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str335, CSSPropertyBorderTopLeftRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str336, CSSPropertyWebkitTapHighlightColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str337, CSSPropertyStrokeDasharray},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str338, CSSPropertyMaxHeight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str339, CSSPropertyTransitionTimingFunction},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str340, CSSPropertyWebkitColumnRuleColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str341, CSSPropertyBorderTopLeftRadius},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str342, CSSPropertyWebkitColumnBreakAfter},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str343, CSSPropertyWebkitColumnBreakBefore},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str344, CSSPropertyListStyleImage},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str345, CSSPropertyTextOverlineColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str346, CSSPropertyWebkitTextEmphasis},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str347, CSSPropertyWebkitTransitionTimingFunction},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str348, CSSPropertyStopOpacity},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str349, CSSPropertyTextDecorationColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str350, CSSPropertyWebkitMarginAfterCollapse},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str351, CSSPropertyWebkitMarginBeforeCollapse},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str352, CSSPropertyWebkitMaskBoxImageOutset},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str353, CSSPropertyBorderRightStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str354, CSSPropertyWebkitMaskBoxImageSlice},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str355, CSSPropertyWebkitRubyPosition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str356, CSSPropertyWebkitBoxOrdinalGroup},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str357, CSSPropertyTableLayout},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str358, CSSPropertyWebkitTextCombine},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str359, CSSPropertyColorInterpolationFilters},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str360, CSSPropertyTextUnderlinePosition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str361, CSSPropertyWebkitPerspectiveOriginX},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str362, CSSPropertyBackgroundRepeatX},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str363, CSSPropertyColumnFill},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str364, CSSPropertyListStylePosition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str365, CSSPropertyEmptyCells},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str366, CSSPropertyTextUnderlineWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str367, CSSPropertyOutlineStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str368, CSSPropertyWebkitColumnAxis},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str369, CSSPropertyWebkitPerspectiveOriginY},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str370, CSSPropertyBackgroundRepeatY},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str371, CSSPropertyBackgroundPositionX},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str372, CSSPropertyInternalMarqueeStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str373, CSSPropertyWebkitTextEmphasisPosition},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str374, CSSPropertyWebkitMaxLogicalWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str375, CSSPropertyTextUnderlineColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str376, CSSPropertyWebkitMaskBoxImageSource},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str377, CSSPropertyFlex},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str378, CSSPropertyBackgroundPositionY},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str379, CSSPropertyTextTransform},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str380, CSSPropertyFlex},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str381, CSSPropertyMaskSourceType},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str382, CSSPropertyFlexGrow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str383, CSSPropertyWebkitTextEmphasisColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str384, CSSPropertyFlexGrow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str385, CSSPropertyOverflowX},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str386, CSSPropertyWebkitTransformOriginX},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str387, CSSPropertyTextOverflow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str388, CSSPropertyBufferedRendering},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str389, CSSPropertyWebkitTextEmphasis},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str390, CSSPropertyFlexWrap},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str391, CSSPropertyFlexWrap},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str392, CSSPropertyTextLineThroughMode},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str393, CSSPropertyOverflowY},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str394, CSSPropertyFlexBasis},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str395, CSSPropertyFontStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str396, CSSPropertyWebkitTransformOriginY},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str397, CSSPropertyGlyphOrientationVertical},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str398, CSSPropertyVectorEffect},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str399, CSSPropertyFlexBasis},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str400, CSSPropertyWebkitMaxLogicalHeight},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str401, CSSPropertyFlexDirection},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str402, CSSPropertyStrokeDashoffset},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str403, CSSPropertyOutlineOffset},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str404, CSSPropertyWebkitBoxReflect},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str405, CSSPropertyWebkitBorderAfterStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str406, CSSPropertyWebkitBorderBeforeStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str407, CSSPropertyGlyphOrientationHorizontal},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str408, CSSPropertyFlexDirection},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str409, CSSPropertyWebkitFontFeatureSettings},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str410, CSSPropertyWebkitTransformStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str411, CSSPropertyTouchActionDelay},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str412, CSSPropertyBorderLeftStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str413, CSSPropertyFlexShrink},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str414, CSSPropertyFlexShrink},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str415, CSSPropertyTextLineThroughWidth},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str416, CSSPropertyWebkitUserModify},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str417, CSSPropertyFloodOpacity},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str418, CSSPropertyTextTransform},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str419, CSSPropertyWebkitTextEmphasisColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str420, CSSPropertyTextLineThroughColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str421, CSSPropertyWebkitTextFillColor},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str422, CSSPropertyFillOpacity},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str423, CSSPropertyWebkitHyphenateCharacter},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str424, CSSPropertyWebkitColumnRuleStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str425, CSSPropertyTextOverlineStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str426, CSSPropertyJustifyContent},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str427, CSSPropertyTextDecorationStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str428, CSSPropertyJustifyContent},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str429, CSSPropertyWebkitBackfaceVisibility},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str430, CSSPropertyListStyleType},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str431, CSSPropertyWebkitTextSecurity},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str432, CSSPropertyTextUnderlineStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str433, CSSPropertyFontFamily},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str434, CSSPropertyFlexFlow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str435, CSSPropertyFlexFlow},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str436, CSSPropertyWebkitTextEmphasisStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str437, CSSPropertyWebkitBoxFlex},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str438, CSSPropertyWebkitTextDecorationsInEffect},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str439, CSSPropertyTextJustify},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str440, CSSPropertyJustifySelf},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str441, CSSPropertyWebkitTextEmphasisStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str442, CSSPropertyTextLineThroughStyle},
    {(int)(long)&((struct stringpool_t *)0)->stringpool_str443, CSSPropertyWebkitBoxFlexGroup}
  };

static const short lookup[] =
  {
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,   0,  -1,  -1,  -1,   1,
     -1,   2,  -1,   3,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,   4,  -1,  -1,   5,  -1,  -1,   6,   7,
     -1,  -1,  -1,  -1,   8,  -1,  -1,   9,  10,  11,
     -1,  -1,  -1,  -1,  12,  13,  -1,  14,  15,  -1,
     -1,  -1,  -1,  -1,  16,  -1,  -1,  17,  -1,  -1,
     -1,  18,  -1,  -1,  19,  -1,  20,  -1,  -1,  21,
     -1,  22,  -1,  23,  24,  25,  -1,  -1,  26,  27,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  28,  -1,  -1,
     -1,  29,  30,  -1,  -1,  -1,  31,  -1,  32,  -1,
     -1,  33,  -1,  -1,  -1,  34,  35,  36,  -1,  37,
     -1,  38,  -1,  -1,  39,  -1,  -1,  -1,  -1,  -1,
     -1,  40,  -1,  41,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  42,  -1,  -1,  43,  -1,  -1,  -1,  44,
     -1,  45,  46,  -1,  -1,  -1,  -1,  -1,  47,  -1,
     -1,  -1,  -1,  48,  -1,  -1,  49,  50,  51,  -1,
     52,  -1,  -1,  -1,  -1,  53,  -1,  54,  -1,  55,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  56,  -1,  -1,
     -1,  57,  -1,  -1,  -1,  -1,  -1,  58,  -1,  59,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  60,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  61,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  62,  63,  -1,  -1,
     -1,  -1,  -1,  64,  -1,  65,  -1,  66,  67,  -1,
     68,  69,  -1,  70,  71,  -1,  72,  -1,  -1,  73,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  74,  -1,  75,
     -1,  -1,  -1,  76,  -1,  -1,  -1,  77,  -1,  -1,
     78,  -1,  -1,  -1,  -1,  79,  -1,  -1,  -1,  80,
     -1,  -1,  -1,  81,  82,  83,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  84,  -1,  -1,
     -1,  -1,  85,  -1,  -1,  -1,  86,  -1,  -1,  87,
     -1,  -1,  -1,  -1,  -1,  88,  -1,  -1,  89,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  90,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  91,  92,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  93,  -1,  94,  -1,  -1,  95,  96,  97,  98,
     99,  -1, 100,  -1,  -1,  -1, 101,  -1,  -1, 102,
     -1,  -1, 103,  -1, 104, 105, 106, 107,  -1,  -1,
    108,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    109, 110,  -1,  -1, 111, 112,  -1,  -1,  -1, 113,
    114,  -1, 115, 116, 117,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 118,  -1,  -1,  -1,  -1,  -1,  -1,
    119, 120,  -1,  -1,  -1,  -1, 121, 122, 123,  -1,
     -1,  -1, 124,  -1,  -1,  -1,  -1,  -1, 125, 126,
     -1, 127,  -1,  -1, 128,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 129,  -1,  -1,  -1,  -1, 130,
     -1,  -1, 131,  -1, 132, 133,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 134,  -1, 135,  -1,  -1,  -1, 136,
     -1,  -1,  -1,  -1, 137,  -1,  -1, 138,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1, 139, 140,  -1,  -1,
    141,  -1,  -1,  -1,  -1,  -1,  -1, 142,  -1, 143,
    144,  -1,  -1,  -1, 145,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 146,  -1,  -1, 147,  -1,  -1,  -1,
     -1, 148,  -1, 149,  -1,  -1,  -1,  -1, 150,  -1,
     -1, 151,  -1, 152,  -1,  -1, 153,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1, 154,  -1,  -1,  -1,  -1,
    155, 156,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1, 157,  -1, 158, 159,  -1,
     -1,  -1,  -1, 160,  -1,  -1,  -1,  -1,  -1,  -1,
    161,  -1,  -1,  -1,  -1,  -1, 162,  -1, 163, 164,
     -1,  -1,  -1,  -1,  -1, 165,  -1, 166,  -1,  -1,
     -1,  -1, 167,  -1,  -1, 168,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1, 169, 170,  -1, 171,
    172,  -1, 173, 174,  -1, 175,  -1,  -1,  -1,  -1,
    176,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 177,
     -1,  -1,  -1,  -1,  -1,  -1,  -1, 178,  -1,  -1,
     -1,  -1, 179, 180,  -1, 181, 182,  -1,  -1,  -1,
    183,  -1,  -1, 184,  -1,  -1, 185,  -1,  -1,  -1,
    186,  -1,  -1,  -1,  -1,  -1, 187,  -1, 188, 189,
    190,  -1,  -1,  -1, 191, 192, 193, 194,  -1, 195,
     -1, 196,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 197, 198,  -1, 199,  -1,  -1,
    200,  -1,  -1,  -1, 201,  -1, 202,  -1, 203,  -1,
     -1, 204, 205, 206,  -1,  -1,  -1, 207, 208,  -1,
     -1, 209,  -1,  -1,  -1,  -1,  -1, 210,  -1,  -1,
     -1, 211,  -1,  -1,  -1, 212, 213,  -1,  -1,  -1,
     -1, 214,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    215, 216,  -1, 217,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1, 218,  -1,  -1,  -1,  -1,  -1, 219,  -1,
    220, 221,  -1,  -1,  -1, 222, 223,  -1, 224,  -1,
     -1,  -1,  -1,  -1,  -1, 225,  -1,  -1, 226,  -1,
     -1,  -1,  -1, 227, 228,  -1,  -1,  -1,  -1,  -1,
    229,  -1,  -1,  -1,  -1, 230,  -1, 231, 232,  -1,
     -1, 233,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    234,  -1,  -1,  -1,  -1, 235,  -1, 236, 237,  -1,
    238,  -1, 239,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 240,  -1,  -1,  -1, 241,  -1,
     -1, 242,  -1, 243, 244,  -1,  -1,  -1,  -1,  -1,
     -1,  -1, 245,  -1,  -1,  -1,  -1, 246, 247,  -1,
    248,  -1,  -1,  -1,  -1,  -1,  -1, 249,  -1, 250,
     -1,  -1,  -1, 251,  -1,  -1,  -1,  -1,  -1,  -1,
     -1, 252, 253,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1, 254, 255,  -1,  -1, 256,  -1,  -1,  -1,
     -1, 257, 258,  -1, 259, 260,  -1,  -1,  -1,  -1,
     -1, 261,  -1,  -1,  -1,  -1,  -1, 262, 263,  -1,
     -1, 264, 265,  -1,  -1,  -1,  -1, 266,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 267, 268,  -1,  -1,  -1,  -1, 269,
    270, 271, 272, 273,  -1, 274, 275,  -1,  -1, 276,
    277,  -1,  -1,  -1,  -1,  -1, 278, 279, 280,  -1,
     -1,  -1,  -1,  -1,  -1, 281, 282,  -1,  -1,  -1,
     -1,  -1, 283,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 284,  -1,  -1,  -1,  -1,  -1, 285,
     -1,  -1, 286,  -1,  -1, 287,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1, 288,  -1,  -1,  -1, 289,
    290,  -1, 291,  -1,  -1, 292,  -1,  -1, 293,  -1,
    294, 295, 296,  -1, 297,  -1,  -1,  -1,  -1,  -1,
    298,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 299,
     -1, 300,  -1, 301,  -1,  -1,  -1,  -1,  -1,  -1,
    302,  -1, 303, 304,  -1, 305,  -1, 306,  -1,  -1,
    307,  -1,  -1,  -1, 308,  -1,  -1,  -1,  -1,  -1,
     -1, 309,  -1,  -1,  -1,  -1,  -1, 310,  -1, 311,
     -1,  -1,  -1,  -1,  -1, 312,  -1,  -1,  -1,  -1,
     -1, 313,  -1, 314,  -1,  -1,  -1, 315,  -1, 316,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 317,  -1,  -1,  -1,  -1,  -1,  -1,
     -1, 318, 319, 320,  -1, 321,  -1, 322, 323,  -1,
     -1, 324,  -1,  -1, 325,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 326, 327,  -1, 328, 329,  -1,
     -1,  -1, 330, 331, 332,  -1,  -1,  -1,  -1,  -1,
     -1, 333,  -1, 334,  -1,  -1, 335,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1, 336,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 337,  -1,  -1, 338,  -1,  -1,
     -1, 339,  -1,  -1,  -1,  -1,  -1, 340, 341, 342,
     -1,  -1,  -1,  -1, 343,  -1,  -1,  -1,  -1,  -1,
    344,  -1,  -1,  -1,  -1,  -1, 345,  -1, 346,  -1,
     -1,  -1,  -1, 347,  -1,  -1,  -1, 348,  -1,  -1,
     -1,  -1,  -1, 349,  -1,  -1,  -1,  -1,  -1,  -1,
    350,  -1,  -1,  -1,  -1, 351,  -1,  -1,  -1, 352,
     -1,  -1,  -1,  -1,  -1, 353,  -1,  -1,  -1,  -1,
    354,  -1,  -1,  -1,  -1,  -1,  -1, 355,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    356, 357,  -1,  -1,  -1,  -1,  -1,  -1, 358,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1, 359,  -1, 360,
    361,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 362,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1, 363,  -1,  -1, 364,  -1,  -1, 365, 366,  -1,
     -1,  -1,  -1, 367,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 368, 369,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 370,  -1,
     -1,  -1,  -1,  -1,  -1, 371,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 372,  -1,  -1,  -1,  -1, 373,
     -1,  -1,  -1,  -1,  -1,  -1, 374, 375,  -1, 376,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    377,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 378, 379,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1, 380,  -1,  -1,  -1,  -1, 381,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1, 382,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1, 383,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 384,  -1, 385,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 386,  -1,  -1, 387,  -1, 388,
    389,  -1,  -1,  -1,  -1,  -1,  -1, 390,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 391,
     -1,  -1,  -1,  -1,  -1,  -1,  -1, 392,  -1,  -1,
     -1,  -1,  -1,  -1, 393,  -1,  -1,  -1,  -1,  -1,
    394,  -1, 395, 396,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1, 397,  -1,  -1,  -1,  -1, 398,  -1,  -1,  -1,
     -1,  -1, 399,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 400,  -1,  -1,  -1,  -1,  -1,
     -1, 401,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    402,  -1, 403,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1, 404, 405,  -1,  -1,  -1,  -1, 406,  -1,  -1,
    407,  -1,  -1, 408,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1, 409,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1, 410,  -1,  -1,  -1, 411,  -1, 412,  -1,  -1,
     -1,  -1,  -1,  -1, 413,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1, 414,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1, 415,  -1,  -1,  -1,  -1,  -1, 416,  -1,  -1,
     -1, 417,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 418,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 419,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    420,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 421,  -1,  -1,  -1, 422,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1, 423,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 424,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 425, 426,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    427,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1, 428,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1, 429,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 430,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
    431,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 432,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1, 433,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 434,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1, 435,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 436,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1, 437,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1, 438,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1, 439,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 440,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1, 441,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1, 442,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1, 443
  };

const struct Property *
CSSPropertyNamesHash::findPropertyImpl (register const char *str, register unsigned int len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = property_hash_function (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = property_word_list[index].nameOffset + stringpool;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                return &property_word_list[index];
            }
        }
    }
  return 0;
}

const Property* findProperty(register const char* str, register unsigned int len)
{
    return CSSPropertyNamesHash::findPropertyImpl(str, len);
}

const char* getPropertyName(CSSPropertyID id)
{
    if (id < firstCSSProperty)
        return 0;
    int index = id - firstCSSProperty;
    if (index >= numCSSProperties)
        return 0;
    return propertyNameStringsPool + propertyNameStringsOffsets[index];
}

const AtomicString& getPropertyNameAtomicString(CSSPropertyID id)
{
    if (id < firstCSSProperty)
        return nullAtom;
    int index = id - firstCSSProperty;
    if (index >= numCSSProperties)
        return nullAtom;

    static AtomicString* propertyStrings = new AtomicString[numCSSProperties]; // Intentionally never destroyed.
    AtomicString& propertyString = propertyStrings[index];
    if (propertyString.isNull()) {
        const char* propertyName = propertyNameStringsPool + propertyNameStringsOffsets[index];
        propertyString = AtomicString(propertyName, strlen(propertyName), AtomicString::ConstructFromLiteral);
    }
    return propertyString;
}

String getPropertyNameString(CSSPropertyID id)
{
    // We share the StringImpl with the AtomicStrings.
    return getPropertyNameAtomicString(id).string();
}

String getJSPropertyName(CSSPropertyID id)
{
    char result[maxCSSPropertyNameLength + 1];
    const char* cssPropertyName = getPropertyName(id);
    const char* propertyNamePointer = cssPropertyName;
    if (!propertyNamePointer)
        return emptyString();

    char* resultPointer = result;
    while (char character = *propertyNamePointer++) {
        if (character == '-') {
            char nextCharacter = *propertyNamePointer++;
            if (!nextCharacter)
                break;
            character = (propertyNamePointer - 2 != cssPropertyName) ? toASCIIUpper(nextCharacter) : nextCharacter;
        }
        *resultPointer++ = character;
    }
    *resultPointer = '\0';
    return String(result);
}

bool isInternalProperty(CSSPropertyID id)
{
    switch (id) {
        case CSSPropertyInternalCallback:
case CSSPropertyInternalMarqueeDirection:
case CSSPropertyInternalMarqueeIncrement:
case CSSPropertyInternalMarqueeRepetition:
case CSSPropertyInternalMarqueeSpeed:
case CSSPropertyInternalMarqueeStyle:
            return true;
        default:
            return false;
    }
}

} // namespace WebCore

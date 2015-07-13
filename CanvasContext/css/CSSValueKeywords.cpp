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
#include "CSSValueKeywords.h"
#include "HashTools.h"
#include <string.h>

namespace WebCore {
static const char valueListStringPool[] = {
"\0"
    "inherit\0"
    "initial\0"
    "none\0"
    "hidden\0"
    "inset\0"
    "groove\0"
    "outset\0"
    "ridge\0"
    "dotted\0"
    "dashed\0"
    "solid\0"
    "double\0"
    "caption\0"
    "icon\0"
    "menu\0"
    "message-box\0"
    "small-caption\0"
    "-webkit-mini-control\0"
    "-webkit-small-control\0"
    "-webkit-control\0"
    "status-bar\0"
    "italic\0"
    "oblique\0"
    "all\0"
    "small-caps\0"
    "common-ligatures\0"
    "no-common-ligatures\0"
    "discretionary-ligatures\0"
    "no-discretionary-ligatures\0"
    "historical-ligatures\0"
    "no-historical-ligatures\0"
    "contextual\0"
    "no-contextual\0"
    "normal\0"
    "bold\0"
    "bolder\0"
    "lighter\0"
    "100\0"
    "200\0"
    "300\0"
    "400\0"
    "500\0"
    "600\0"
    "700\0"
    "800\0"
    "900\0"
    "xx-small\0"
    "x-small\0"
    "small\0"
    "medium\0"
    "large\0"
    "x-large\0"
    "xx-large\0"
    "-webkit-xxx-large\0"
    "smaller\0"
    "larger\0"
    "wider\0"
    "narrower\0"
    "ultra-condensed\0"
    "extra-condensed\0"
    "condensed\0"
    "semi-condensed\0"
    "semi-expanded\0"
    "expanded\0"
    "extra-expanded\0"
    "ultra-expanded\0"
    "serif\0"
    "sans-serif\0"
    "cursive\0"
    "fantasy\0"
    "monospace\0"
    "-webkit-body\0"
    "-webkit-pictograph\0"
    "aqua\0"
    "black\0"
    "blue\0"
    "fuchsia\0"
    "gray\0"
    "green\0"
    "lime\0"
    "maroon\0"
    "navy\0"
    "olive\0"
    "orange\0"
    "purple\0"
    "red\0"
    "silver\0"
    "teal\0"
    "white\0"
    "yellow\0"
    "transparent\0"
    "-webkit-link\0"
    "-webkit-activelink\0"
    "activeborder\0"
    "activecaption\0"
    "appworkspace\0"
    "background\0"
    "buttonface\0"
    "buttonhighlight\0"
    "buttonshadow\0"
    "buttontext\0"
    "captiontext\0"
    "graytext\0"
    "highlight\0"
    "highlighttext\0"
    "inactiveborder\0"
    "inactivecaption\0"
    "inactivecaptiontext\0"
    "infobackground\0"
    "infotext\0"
    "menutext\0"
    "scrollbar\0"
    "threeddarkshadow\0"
    "threedface\0"
    "threedhighlight\0"
    "threedlightshadow\0"
    "threedshadow\0"
    "window\0"
    "windowframe\0"
    "windowtext\0"
    "-internal-active-list-box-selection\0"
    "-internal-active-list-box-selection-text\0"
    "-internal-inactive-list-box-selection\0"
    "-internal-inactive-list-box-selection-text\0"
    "-webkit-focus-ring-color\0"
    "currentcolor\0"
    "grey\0"
    "-webkit-text\0"
    "repeat\0"
    "repeat-x\0"
    "repeat-y\0"
    "no-repeat\0"
    "clear\0"
    "copy\0"
    "source-over\0"
    "source-in\0"
    "source-out\0"
    "source-atop\0"
    "destination-over\0"
    "destination-in\0"
    "destination-out\0"
    "destination-atop\0"
    "xor\0"
    "plus-darker\0"
    "plus-lighter\0"
    "baseline\0"
    "middle\0"
    "sub\0"
    "super\0"
    "text-top\0"
    "text-bottom\0"
    "top\0"
    "bottom\0"
    "-webkit-baseline-middle\0"
    "-webkit-auto\0"
    "left\0"
    "right\0"
    "center\0"
    "justify\0"
    "-webkit-left\0"
    "-webkit-right\0"
    "-webkit-center\0"
    "-webkit-match-parent\0"
    "inter-word\0"
    "distribute\0"
    "outside\0"
    "inside\0"
    "disc\0"
    "circle\0"
    "square\0"
    "decimal\0"
    "decimal-leading-zero\0"
    "arabic-indic\0"
    "binary\0"
    "bengali\0"
    "cambodian\0"
    "khmer\0"
    "devanagari\0"
    "gujarati\0"
    "gurmukhi\0"
    "kannada\0"
    "lower-hexadecimal\0"
    "lao\0"
    "malayalam\0"
    "mongolian\0"
    "myanmar\0"
    "octal\0"
    "oriya\0"
    "persian\0"
    "urdu\0"
    "telugu\0"
    "tibetan\0"
    "thai\0"
    "upper-hexadecimal\0"
    "lower-roman\0"
    "upper-roman\0"
    "lower-greek\0"
    "lower-alpha\0"
    "lower-latin\0"
    "upper-alpha\0"
    "upper-latin\0"
    "afar\0"
    "ethiopic-halehame-aa-et\0"
    "ethiopic-halehame-aa-er\0"
    "amharic\0"
    "ethiopic-halehame-am-et\0"
    "amharic-abegede\0"
    "ethiopic-abegede-am-et\0"
    "cjk-earthly-branch\0"
    "cjk-heavenly-stem\0"
    "ethiopic\0"
    "ethiopic-halehame-gez\0"
    "ethiopic-abegede\0"
    "ethiopic-abegede-gez\0"
    "hangul-consonant\0"
    "hangul\0"
    "lower-norwegian\0"
    "oromo\0"
    "ethiopic-halehame-om-et\0"
    "sidama\0"
    "ethiopic-halehame-sid-et\0"
    "somali\0"
    "ethiopic-halehame-so-et\0"
    "tigre\0"
    "ethiopic-halehame-tig\0"
    "tigrinya-er\0"
    "ethiopic-halehame-ti-er\0"
    "tigrinya-er-abegede\0"
    "ethiopic-abegede-ti-er\0"
    "tigrinya-et\0"
    "ethiopic-halehame-ti-et\0"
    "tigrinya-et-abegede\0"
    "ethiopic-abegede-ti-et\0"
    "upper-greek\0"
    "upper-norwegian\0"
    "asterisks\0"
    "footnotes\0"
    "hebrew\0"
    "armenian\0"
    "lower-armenian\0"
    "upper-armenian\0"
    "georgian\0"
    "cjk-ideographic\0"
    "hiragana\0"
    "katakana\0"
    "hiragana-iroha\0"
    "katakana-iroha\0"
    "inline\0"
    "block\0"
    "list-item\0"
    "inline-block\0"
    "table\0"
    "inline-table\0"
    "table-row-group\0"
    "table-header-group\0"
    "table-footer-group\0"
    "table-row\0"
    "table-column-group\0"
    "table-column\0"
    "table-cell\0"
    "table-caption\0"
    "-webkit-box\0"
    "-webkit-inline-box\0"
    "flex\0"
    "inline-flex\0"
    "grid\0"
    "inline-grid\0"
    "lazy-block\0"
    "-webkit-flex\0"
    "-webkit-inline-flex\0"
    "auto\0"
    "crosshair\0"
    "default\0"
    "pointer\0"
    "move\0"
    "vertical-text\0"
    "cell\0"
    "context-menu\0"
    "alias\0"
    "progress\0"
    "no-drop\0"
    "not-allowed\0"
    "-webkit-zoom-in\0"
    "-webkit-zoom-out\0"
    "e-resize\0"
    "ne-resize\0"
    "nw-resize\0"
    "n-resize\0"
    "se-resize\0"
    "sw-resize\0"
    "s-resize\0"
    "w-resize\0"
    "ew-resize\0"
    "ns-resize\0"
    "nesw-resize\0"
    "nwse-resize\0"
    "col-resize\0"
    "row-resize\0"
    "text\0"
    "wait\0"
    "help\0"
    "all-scroll\0"
    "-webkit-grab\0"
    "-webkit-grabbing\0"
    "ltr\0"
    "rtl\0"
    "capitalize\0"
    "uppercase\0"
    "lowercase\0"
    "visible\0"
    "collapse\0"
    "a3\0"
    "a4\0"
    "a5\0"
    "above\0"
    "absolute\0"
    "always\0"
    "avoid\0"
    "b4\0"
    "b5\0"
    "below\0"
    "bidi-override\0"
    "blink\0"
    "both\0"
    "close-quote\0"
    "crop\0"
    "cross\0"
    "embed\0"
    "fixed\0"
    "hand\0"
    "hide\0"
    "higher\0"
    "invert\0"
    "-webkit-isolate\0"
    "-webkit-isolate-override\0"
    "-webkit-plaintext\0"
    "landscape\0"
    "ledger\0"
    "legal\0"
    "letter\0"
    "level\0"
    "line-through\0"
    "local\0"
    "loud\0"
    "lower\0"
    "mix\0"
    "no-close-quote\0"
    "no-open-quote\0"
    "nowrap\0"
    "open-quote\0"
    "overlay\0"
    "overline\0"
    "portrait\0"
    "pre\0"
    "pre-line\0"
    "pre-wrap\0"
    "-internal-presence\0"
    "relative\0"
    "scroll\0"
    "separate\0"
    "show\0"
    "static\0"
    "thick\0"
    "thin\0"
    "underline\0"
    "wavy\0"
    "-webkit-nowrap\0"
    "stretch\0"
    "start\0"
    "end\0"
    "clone\0"
    "slice\0"
    "reverse\0"
    "horizontal\0"
    "vertical\0"
    "inline-axis\0"
    "block-axis\0"
    "single\0"
    "multiple\0"
    "flex-start\0"
    "flex-end\0"
    "space-between\0"
    "space-around\0"
    "row\0"
    "row-reverse\0"
    "column\0"
    "column-reverse\0"
    "wrap-reverse\0"
    "forwards\0"
    "backwards\0"
    "ahead\0"
    "up\0"
    "down\0"
    "slow\0"
    "fast\0"
    "infinite\0"
    "slide\0"
    "alternate\0"
    "read-only\0"
    "read-write\0"
    "read-write-plaintext-only\0"
    "element\0"
    "ignore\0"
    "intrinsic\0"
    "min-intrinsic\0"
    "-webkit-min-content\0"
    "-webkit-max-content\0"
    "-webkit-fill-available\0"
    "-webkit-fit-content\0"
    "min-content\0"
    "max-content\0"
    "clip\0"
    "ellipsis\0"
    "discard\0"
    "dot-dash\0"
    "dot-dot-dash\0"
    "wave\0"
    "continuous\0"
    "skip-white-space\0"
    "break-all\0"
    "break-word\0"
    "space\0"
    "loose\0"
    "strict\0"
    "after-white-space\0"
    "checkbox\0"
    "radio\0"
    "push-button\0"
    "square-button\0"
    "button\0"
    "button-bevel\0"
    "inner-spin-button\0"
    "-webkit-input-speech-button\0"
    "listbox\0"
    "listitem\0"
    "media-enter-fullscreen-button\0"
    "media-exit-fullscreen-button\0"
    "media-fullscreen-volume-slider\0"
    "media-fullscreen-volume-slider-thumb\0"
    "media-mute-button\0"
    "media-play-button\0"
    "media-overlay-play-button\0"
    "media-toggle-closed-captions-button\0"
    "media-slider\0"
    "media-sliderthumb\0"
    "media-volume-slider-container\0"
    "media-volume-slider\0"
    "media-volume-sliderthumb\0"
    "media-controls-background\0"
    "media-controls-fullscreen-background\0"
    "media-current-time-display\0"
    "media-time-remaining-display\0"
    "menulist\0"
    "menulist-button\0"
    "menulist-text\0"
    "menulist-textfield\0"
    "meter\0"
    "progress-bar\0"
    "progress-bar-value\0"
    "slider-horizontal\0"
    "slider-vertical\0"
    "sliderthumb-horizontal\0"
    "sliderthumb-vertical\0"
    "caret\0"
    "searchfield\0"
    "searchfield-decoration\0"
    "searchfield-results-decoration\0"
    "searchfield-cancel-button\0"
    "textfield\0"
    "relevancy-level-indicator\0"
    "continuous-capacity-level-indicator\0"
    "discrete-capacity-level-indicator\0"
    "rating-level-indicator\0"
    "textarea\0"
    "caps-lock-indicator\0"
    "round\0"
    "border\0"
    "border-box\0"
    "content\0"
    "content-box\0"
    "padding\0"
    "padding-box\0"
    "margin-box\0"
    "contain\0"
    "cover\0"
    "logical\0"
    "visual\0"
    "lines\0"
    "alternate-reverse\0"
    "running\0"
    "paused\0"
    "flat\0"
    "preserve-3d\0"
    "ease\0"
    "linear\0"
    "ease-in\0"
    "ease-out\0"
    "ease-in-out\0"
    "step-start\0"
    "step-middle\0"
    "step-end\0"
    "document\0"
    "reset\0"
    "zoom\0"
    "visiblepainted\0"
    "visiblefill\0"
    "visiblestroke\0"
    "painted\0"
    "fill\0"
    "stroke\0"
    "bounding-box\0"
    "spell-out\0"
    "digits\0"
    "literal-punctuation\0"
    "no-punctuation\0"
    "antialiased\0"
    "subpixel-antialiased\0"
    "optimizespeed\0"
    "optimizelegibility\0"
    "geometricprecision\0"
    "economy\0"
    "exact\0"
    "floating\0"
    "fullscreen\0"
    "maximized\0"
    "minimized\0"
    "windowed\0"
    "no-limit\0"
    "lr\0"
    "rl\0"
    "tb\0"
    "lr-tb\0"
    "rl-tb\0"
    "tb-rl\0"
    "horizontal-tb\0"
    "vertical-rl\0"
    "vertical-lr\0"
    "horizontal-bt\0"
    "after\0"
    "before\0"
    "over\0"
    "under\0"
    "filled\0"
    "open\0"
    "dot\0"
    "double-circle\0"
    "triangle\0"
    "sesame\0"
    "ellipse\0"
    "closest-side\0"
    "closest-corner\0"
    "farthest-side\0"
    "farthest-corner\0"
    "sideways\0"
    "sideways-right\0"
    "upright\0"
    "vertical-right\0"
    "font\0"
    "glyphs\0"
    "inline-box\0"
    "replaced\0"
    "on\0"
    "off\0"
    "optimizequality\0"
    "-webkit-optimize-contrast\0"
    "nonzero\0"
    "evenodd\0"
    "outside-shape\0"
    "at\0"
    "maximum\0"
    "wrap\0"
    "alphabetic\0"
    "sticky\0"
    "coarse\0"
    "fine\0"
    "filter-box\0"
    "detached\0"
    "multiply\0"
    "screen\0"
    "darken\0"
    "lighten\0"
    "color-dodge\0"
    "color-burn\0"
    "hard-light\0"
    "soft-light\0"
    "difference\0"
    "exclusion\0"
    "hue\0"
    "saturation\0"
    "color\0"
    "luminosity\0"
    "scale-down\0"
    "balance\0"
    "-webkit-paged-x\0"
    "-webkit-paged-y\0"
    "drag\0"
    "no-drag\0"
    "span\0"
    "each-line\0"
    "progressive\0"
    "interlace\0"
    "markers\0"
    "-internal-extend-to-zoom\0"
    "isolate\0"
    "script\0"
    "pan-x\0"
    "pan-y\0"
    "manipulation\0"
    "self-start\0"
    "self-end\0"
    "true\0"
    "safe\0"
    "instant\0"
    "smooth\0"
    "contents\0"
    "scroll-position\0"
    "aliceblue\0"
    "alpha\0"
    "antiquewhite\0"
    "aquamarine\0"
    "azure\0"
    "beige\0"
    "bisque\0"
    "blanchedalmond\0"
    "blueviolet\0"
    "brown\0"
    "burlywood\0"
    "cadetblue\0"
    "chartreuse\0"
    "chocolate\0"
    "coral\0"
    "cornflowerblue\0"
    "cornsilk\0"
    "crimson\0"
    "cyan\0"
    "darkblue\0"
    "darkcyan\0"
    "darkgoldenrod\0"
    "darkgray\0"
    "darkgreen\0"
    "darkgrey\0"
    "darkkhaki\0"
    "darkmagenta\0"
    "darkolivegreen\0"
    "darkorange\0"
    "darkorchid\0"
    "darkred\0"
    "darksalmon\0"
    "darkseagreen\0"
    "darkslateblue\0"
    "darkslategray\0"
    "darkslategrey\0"
    "darkturquoise\0"
    "darkviolet\0"
    "deeppink\0"
    "deepskyblue\0"
    "dimgray\0"
    "dimgrey\0"
    "dodgerblue\0"
    "firebrick\0"
    "floralwhite\0"
    "forestgreen\0"
    "gainsboro\0"
    "ghostwhite\0"
    "gold\0"
    "goldenrod\0"
    "greenyellow\0"
    "honeydew\0"
    "hotpink\0"
    "indianred\0"
    "indigo\0"
    "ivory\0"
    "khaki\0"
    "lavender\0"
    "lavenderblush\0"
    "lawngreen\0"
    "lemonchiffon\0"
    "lightblue\0"
    "lightcoral\0"
    "lightcyan\0"
    "lightgoldenrodyellow\0"
    "lightgray\0"
    "lightgreen\0"
    "lightgrey\0"
    "lightpink\0"
    "lightsalmon\0"
    "lightseagreen\0"
    "lightskyblue\0"
    "lightslategray\0"
    "lightslategrey\0"
    "lightsteelblue\0"
    "lightyellow\0"
    "limegreen\0"
    "linen\0"
    "luminance\0"
    "magenta\0"
    "mediumaquamarine\0"
    "mediumblue\0"
    "mediumorchid\0"
    "mediumpurple\0"
    "mediumseagreen\0"
    "mediumslateblue\0"
    "mediumspringgreen\0"
    "mediumturquoise\0"
    "mediumvioletred\0"
    "midnightblue\0"
    "mintcream\0"
    "mistyrose\0"
    "moccasin\0"
    "navajowhite\0"
    "oldlace\0"
    "olivedrab\0"
    "orangered\0"
    "orchid\0"
    "palegoldenrod\0"
    "palegreen\0"
    "paleturquoise\0"
    "palevioletred\0"
    "papayawhip\0"
    "peachpuff\0"
    "peru\0"
    "pink\0"
    "plum\0"
    "powderblue\0"
    "rosybrown\0"
    "royalblue\0"
    "saddlebrown\0"
    "salmon\0"
    "sandybrown\0"
    "seagreen\0"
    "seashell\0"
    "sienna\0"
    "skyblue\0"
    "slateblue\0"
    "slategray\0"
    "slategrey\0"
    "snow\0"
    "springgreen\0"
    "steelblue\0"
    "tan\0"
    "thistle\0"
    "tomato\0"
    "turquoise\0"
    "violet\0"
    "wheat\0"
    "whitesmoke\0"
    "yellowgreen\0"
    "accumulate\0"
    "new\0"
    "srgb\0"
    "linearrgb\0"
    "crispedges\0"
    "butt\0"
    "miter\0"
    "bevel\0"
    "before-edge\0"
    "after-edge\0"
    "central\0"
    "text-before-edge\0"
    "text-after-edge\0"
    "ideographic\0"
    "hanging\0"
    "mathematical\0"
    "use-script\0"
    "no-change\0"
    "reset-size\0"
    "dynamic\0"
    "non-scaling-stroke\0"
};

static const unsigned short valueListStringOffsets[] = {
  0,
  1,
  9,
  17,
  22,
  29,
  35,
  42,
  49,
  55,
  62,
  69,
  75,
  82,
  90,
  95,
  100,
  112,
  126,
  147,
  169,
  185,
  196,
  203,
  211,
  215,
  226,
  243,
  263,
  287,
  314,
  335,
  359,
  370,
  384,
  391,
  396,
  403,
  411,
  415,
  419,
  423,
  427,
  431,
  435,
  439,
  443,
  447,
  456,
  464,
  470,
  477,
  483,
  491,
  500,
  518,
  526,
  533,
  539,
  548,
  564,
  580,
  590,
  605,
  619,
  628,
  643,
  658,
  664,
  675,
  683,
  691,
  701,
  714,
  733,
  738,
  744,
  749,
  757,
  762,
  768,
  773,
  780,
  785,
  791,
  798,
  805,
  809,
  816,
  821,
  827,
  834,
  846,
  859,
  878,
  891,
  905,
  918,
  929,
  940,
  956,
  969,
  980,
  992,
  1001,
  1011,
  1025,
  1040,
  1056,
  1076,
  1091,
  1100,
  1109,
  1119,
  1136,
  1147,
  1163,
  1181,
  1194,
  1201,
  1213,
  1224,
  1260,
  1301,
  1339,
  1382,
  1407,
  1420,
  1425,
  1438,
  1445,
  1454,
  1463,
  1473,
  1479,
  1484,
  1496,
  1506,
  1517,
  1529,
  1546,
  1561,
  1577,
  1594,
  1598,
  1610,
  1623,
  1632,
  1639,
  1643,
  1649,
  1658,
  1670,
  1674,
  1681,
  1705,
  1718,
  1723,
  1729,
  1736,
  1744,
  1757,
  1771,
  1786,
  1807,
  1818,
  1829,
  1837,
  1844,
  1849,
  1856,
  1863,
  1871,
  1892,
  1905,
  1912,
  1920,
  1930,
  1936,
  1947,
  1956,
  1965,
  1973,
  1991,
  1995,
  2005,
  2015,
  2023,
  2029,
  2035,
  2043,
  2048,
  2055,
  2063,
  2068,
  2086,
  2098,
  2110,
  2122,
  2134,
  2146,
  2158,
  2170,
  2175,
  2199,
  2223,
  2231,
  2255,
  2271,
  2294,
  2313,
  2331,
  2340,
  2362,
  2379,
  2400,
  2417,
  2424,
  2440,
  2446,
  2470,
  2477,
  2502,
  2509,
  2533,
  2539,
  2561,
  2573,
  2597,
  2617,
  2640,
  2652,
  2676,
  2696,
  2719,
  2731,
  2747,
  2757,
  2767,
  2774,
  2783,
  2798,
  2813,
  2822,
  2838,
  2847,
  2856,
  2871,
  2886,
  2893,
  2899,
  2909,
  2922,
  2928,
  2941,
  2957,
  2976,
  2995,
  3005,
  3024,
  3037,
  3048,
  3062,
  3074,
  3093,
  3098,
  3110,
  3115,
  3127,
  3138,
  3151,
  3171,
  3176,
  3186,
  3194,
  3202,
  3207,
  3221,
  3226,
  3239,
  3245,
  3254,
  3262,
  3274,
  3290,
  3307,
  3316,
  3326,
  3336,
  3345,
  3355,
  3365,
  3374,
  3383,
  3393,
  3403,
  3415,
  3427,
  3438,
  3449,
  3454,
  3459,
  3464,
  3475,
  3488,
  3505,
  3509,
  3513,
  3524,
  3534,
  3544,
  3552,
  3561,
  3564,
  3567,
  3570,
  3576,
  3585,
  3592,
  3598,
  3601,
  3604,
  3610,
  3624,
  3630,
  3635,
  3647,
  3652,
  3658,
  3664,
  3670,
  3675,
  3680,
  3687,
  3694,
  3710,
  3735,
  3753,
  3763,
  3770,
  3776,
  3783,
  3789,
  3802,
  3808,
  3813,
  3819,
  3823,
  3838,
  3852,
  3859,
  3870,
  3878,
  3887,
  3896,
  3900,
  3909,
  3918,
  3937,
  3946,
  3953,
  3962,
  3967,
  3974,
  3980,
  3985,
  3995,
  4000,
  4015,
  4023,
  4029,
  4033,
  4039,
  4045,
  4053,
  4064,
  4073,
  4085,
  4096,
  4103,
  4112,
  4123,
  4132,
  4146,
  4159,
  4163,
  4175,
  4182,
  4197,
  4210,
  4219,
  4229,
  4235,
  4238,
  4243,
  4248,
  4253,
  4262,
  4268,
  4278,
  4288,
  4299,
  4325,
  4333,
  4340,
  4350,
  4364,
  4384,
  4404,
  4427,
  4447,
  4459,
  4471,
  4476,
  4485,
  4493,
  4502,
  4515,
  4520,
  4531,
  4548,
  4558,
  4569,
  4575,
  4581,
  4588,
  4606,
  4615,
  4621,
  4633,
  4647,
  4654,
  4667,
  4685,
  4713,
  4721,
  4730,
  4760,
  4789,
  4820,
  4857,
  4875,
  4893,
  4919,
  4955,
  4968,
  4986,
  5016,
  5036,
  5061,
  5087,
  5124,
  5151,
  5180,
  5189,
  5205,
  5219,
  5238,
  5244,
  5257,
  5276,
  5294,
  5310,
  5333,
  5354,
  5360,
  5372,
  5395,
  5426,
  5452,
  5462,
  5488,
  5524,
  5558,
  5581,
  5590,
  5610,
  5616,
  5623,
  5634,
  5642,
  5654,
  5662,
  5674,
  5685,
  5693,
  5699,
  5707,
  5714,
  5720,
  5738,
  5746,
  5753,
  5758,
  5770,
  5775,
  5782,
  5790,
  5799,
  5811,
  5822,
  5834,
  5843,
  5852,
  5858,
  5863,
  5878,
  5890,
  5904,
  5912,
  5917,
  5924,
  5937,
  5947,
  5954,
  5974,
  5989,
  6001,
  6022,
  6036,
  6055,
  6074,
  6082,
  6088,
  6097,
  6108,
  6118,
  6128,
  6137,
  6146,
  6149,
  6152,
  6155,
  6161,
  6167,
  6173,
  6187,
  6199,
  6211,
  6225,
  6231,
  6238,
  6243,
  6249,
  6256,
  6261,
  6265,
  6279,
  6288,
  6295,
  6303,
  6316,
  6331,
  6345,
  6361,
  6370,
  6385,
  6393,
  6408,
  6413,
  6420,
  6431,
  6440,
  6443,
  6447,
  6463,
  6489,
  6497,
  6505,
  6519,
  6522,
  6530,
  6535,
  6546,
  6553,
  6560,
  6565,
  6576,
  6585,
  6594,
  6601,
  6608,
  6616,
  6628,
  6639,
  6650,
  6661,
  6672,
  6682,
  6686,
  6697,
  6703,
  6714,
  6725,
  6733,
  6749,
  6765,
  6770,
  6778,
  6783,
  6793,
  6805,
  6815,
  6823,
  6848,
  6856,
  6863,
  6869,
  6875,
  6888,
  6899,
  6908,
  6913,
  6918,
  6926,
  6933,
  6942,
  6958,
  6968,
  6974,
  6987,
  6998,
  7004,
  7010,
  7017,
  7032,
  7043,
  7049,
  7059,
  7069,
  7080,
  7090,
  7096,
  7111,
  7120,
  7128,
  7133,
  7142,
  7151,
  7165,
  7174,
  7184,
  7193,
  7203,
  7215,
  7230,
  7241,
  7252,
  7260,
  7271,
  7284,
  7298,
  7312,
  7326,
  7340,
  7351,
  7360,
  7372,
  7380,
  7388,
  7399,
  7409,
  7421,
  7433,
  7443,
  7454,
  7459,
  7469,
  7481,
  7490,
  7498,
  7508,
  7515,
  7521,
  7527,
  7536,
  7550,
  7560,
  7573,
  7583,
  7594,
  7604,
  7625,
  7635,
  7646,
  7656,
  7666,
  7678,
  7692,
  7705,
  7720,
  7735,
  7750,
  7762,
  7772,
  7778,
  7788,
  7796,
  7813,
  7824,
  7837,
  7850,
  7865,
  7881,
  7899,
  7915,
  7931,
  7944,
  7954,
  7964,
  7973,
  7985,
  7993,
  8003,
  8013,
  8020,
  8034,
  8044,
  8058,
  8072,
  8083,
  8093,
  8098,
  8103,
  8108,
  8119,
  8129,
  8139,
  8151,
  8158,
  8169,
  8178,
  8187,
  8194,
  8202,
  8212,
  8222,
  8232,
  8237,
  8249,
  8259,
  8263,
  8271,
  8278,
  8288,
  8295,
  8301,
  8312,
  8324,
  8335,
  8339,
  8344,
  8354,
  8365,
  8370,
  8376,
  8382,
  8394,
  8405,
  8413,
  8430,
  8446,
  8458,
  8466,
  8479,
  8490,
  8500,
  8511,
  8519,
};

/* maximum key range = 5669, duplicates = 0 */

class CSSValueKeywordsHash
{
private:
  static inline unsigned int value_hash_function (const char *str, unsigned int len);
public:
  static const struct Value *findValueImpl (const char *str, unsigned int len);
};

inline unsigned int
CSSValueKeywordsHash::value_hash_function (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687,   67,  414, 5687, 5687,    9,
        20,   10,   19,   12,   11,   18,   17,   16, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687,   13,   73,   14,
       218,   11,  168,  589,   88,   13,  519,  782,   34,   10,
        10,    9,   11, 1205,  100,    9,    9,   51, 1017, 1629,
       881,  994, 1456,   11, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687, 5687,
      5687, 5687, 5687, 5687, 5687, 5687, 5687
    };
  register int hval = 0;

  switch (len)
    {
      default:
        hval += asso_values[(unsigned char)str[41]];
      /*FALLTHROUGH*/
      case 41:
        hval += asso_values[(unsigned char)str[40]];
      /*FALLTHROUGH*/
      case 40:
        hval += asso_values[(unsigned char)str[39]];
      /*FALLTHROUGH*/
      case 39:
        hval += asso_values[(unsigned char)str[38]];
      /*FALLTHROUGH*/
      case 38:
        hval += asso_values[(unsigned char)str[37]];
      /*FALLTHROUGH*/
      case 37:
        hval += asso_values[(unsigned char)str[36]];
      /*FALLTHROUGH*/
      case 36:
        hval += asso_values[(unsigned char)str[35]];
      /*FALLTHROUGH*/
      case 35:
        hval += asso_values[(unsigned char)str[34]];
      /*FALLTHROUGH*/
      case 34:
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
        hval += asso_values[(unsigned char)str[12]+1];
      /*FALLTHROUGH*/
      case 12:
        hval += asso_values[(unsigned char)str[11]];
      /*FALLTHROUGH*/
      case 11:
        hval += asso_values[(unsigned char)str[10]+1];
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
        hval += asso_values[(unsigned char)str[2]+1];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]+1];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

struct stringpool_t
  {
    char stringpool_str0[sizeof("on")];
    char stringpool_str1[sizeof("tb")];
    char stringpool_str2[sizeof("a5")];
    char stringpool_str3[sizeof("a4")];
    char stringpool_str4[sizeof("100")];
    char stringpool_str5[sizeof("300")];
    char stringpool_str6[sizeof("600")];
    char stringpool_str7[sizeof("500")];
    char stringpool_str8[sizeof("end")];
    char stringpool_str9[sizeof("a3")];
    char stringpool_str10[sizeof("all")];
    char stringpool_str11[sizeof("900")];
    char stringpool_str12[sizeof("800")];
    char stringpool_str13[sizeof("700")];
    char stringpool_str14[sizeof("400")];
    char stringpool_str15[sizeof("200")];
    char stringpool_str16[sizeof("none")];
    char stringpool_str17[sizeof("lr")];
    char stringpool_str18[sizeof("crop")];
    char stringpool_str19[sizeof("oromo")];
    char stringpool_str20[sizeof("inset")];
    char stringpool_str21[sizeof("cross")];
    char stringpool_str22[sizeof("clone")];
    char stringpool_str23[sizeof("tomato")];
    char stringpool_str24[sizeof("at")];
    char stringpool_str25[sizeof("inline")];
    char stringpool_str26[sizeof("instant")];
    char stringpool_str27[sizeof("content")];
    char stringpool_str28[sizeof("ellipse")];
    char stringpool_str29[sizeof("loose")];
    char stringpool_str30[sizeof("contain")];
    char stringpool_str31[sizeof("coral")];
    char stringpool_str32[sizeof("contents")];
    char stringpool_str33[sizeof("b5")];
    char stringpool_str34[sizeof("b4")];
    char stringpool_str35[sizeof("ellipsis")];
    char stringpool_str36[sizeof("normal")];
    char stringpool_str37[sizeof("armenian")];
    char stringpool_str38[sizeof("somali")];
    char stringpool_str39[sizeof("tan")];
    char stringpool_str40[sizeof("ltr")];
    char stringpool_str41[sizeof("monospace")];
    char stringpool_str42[sizeof("isolate")];
    char stringpool_str43[sizeof("oldlace")];
    char stringpool_str44[sizeof("ease")];
    char stringpool_str45[sizeof("strict")];
    char stringpool_str46[sizeof("column")];
    char stringpool_str47[sizeof("thai")];
    char stringpool_str48[sizeof("rl")];
    char stringpool_str49[sizeof("collapse")];
    char stringpool_str50[sizeof("caret")];
    char stringpool_str51[sizeof("lao")];
    char stringpool_str52[sizeof("maroon")];
    char stringpool_str53[sizeof("salmon")];
    char stringpool_str54[sizeof("urdu")];
    char stringpool_str55[sizeof("chocolate")];
    char stringpool_str56[sizeof("ethiopic")];
    char stringpool_str57[sizeof("smooth")];
    char stringpool_str58[sizeof("table")];
    char stringpool_str59[sizeof("color")];
    char stringpool_str60[sizeof("absolute")];
    char stringpool_str61[sizeof("small")];
    char stringpool_str62[sizeof("rtl")];
    char stringpool_str63[sizeof("bottom")];
    char stringpool_str64[sizeof("inherit")];
    char stringpool_str65[sizeof("static")];
    char stringpool_str66[sizeof("portrait")];
    char stringpool_str67[sizeof("amharic")];
    char stringpool_str68[sizeof("srgb")];
    char stringpool_str69[sizeof("under")];
    char stringpool_str70[sizeof("closest-side")];
    char stringpool_str71[sizeof("continuous")];
    char stringpool_str72[sizeof("pre")];
    char stringpool_str73[sizeof("antialiased")];
    char stringpool_str74[sizeof("stretch")];
    char stringpool_str75[sizeof("ease-in")];
    char stringpool_str76[sizeof("font")];
    char stringpool_str77[sizeof("italic")];
    char stringpool_str78[sizeof("balance")];
    char stringpool_str79[sizeof("radio")];
    char stringpool_str80[sizeof("logical")];
    char stringpool_str81[sizeof("magenta")];
    char stringpool_str82[sizeof("coarse")];
    char stringpool_str83[sizeof("sesame")];
    char stringpool_str84[sizeof("both")];
    char stringpool_str85[sizeof("cell")];
    char stringpool_str86[sizeof("alternate")];
    char stringpool_str87[sizeof("element")];
    char stringpool_str88[sizeof("ignore")];
    char stringpool_str89[sizeof("intrinsic")];
    char stringpool_str90[sizeof("persian")];
    char stringpool_str91[sizeof("baseline")];
    char stringpool_str92[sizeof("menu")];
    char stringpool_str93[sizeof("peru")];
    char stringpool_str94[sizeof("ease-out")];
    char stringpool_str95[sizeof("start")];
    char stringpool_str96[sizeof("footnotes")];
    char stringpool_str97[sizeof("inline-table")];
    char stringpool_str98[sizeof("underline")];
    char stringpool_str99[sizeof("icon")];
    char stringpool_str100[sizeof("interlace")];
    char stringpool_str101[sizeof("manipulation")];
    char stringpool_str102[sizeof("fast")];
    char stringpool_str103[sizeof("flat")];
    char stringpool_str104[sizeof("solid")];
    char stringpool_str105[sizeof("medium")];
    char stringpool_str106[sizeof("embed")];
    char stringpool_str107[sizeof("crosshair")];
    char stringpool_str108[sizeof("screen")];
    char stringpool_str109[sizeof("script")];
    char stringpool_str110[sizeof("smaller")];
    char stringpool_str111[sizeof("inside")];
    char stringpool_str112[sizeof("small-caps")];
    char stringpool_str113[sizeof("help")];
    char stringpool_str114[sizeof("red")];
    char stringpool_str115[sizeof("dot")];
    char stringpool_str116[sizeof("slateblue")];
    char stringpool_str117[sizeof("teal")];
    char stringpool_str118[sizeof("cadetblue")];
    char stringpool_str119[sizeof("reset")];
    char stringpool_str120[sizeof("moccasin")];
    char stringpool_str121[sizeof("all-scroll")];
    char stringpool_str122[sizeof("table-cell")];
    char stringpool_str123[sizeof("menulist")];
    char stringpool_str124[sizeof("clear")];
    char stringpool_str125[sizeof("transparent")];
    char stringpool_str126[sizeof("local")];
    char stringpool_str127[sizeof("center")];
    char stringpool_str128[sizeof("bold")];
    char stringpool_str129[sizeof("scroll")];
    char stringpool_str130[sizeof("pre-line")];
    char stringpool_str131[sizeof("octal")];
    char stringpool_str132[sizeof("table-column")];
    char stringpool_str133[sizeof("legal")];
    char stringpool_str134[sizeof("saturation")];
    char stringpool_str135[sizeof("meter")];
    char stringpool_str136[sizeof("central")];
    char stringpool_str137[sizeof("serif")];
    char stringpool_str138[sizeof("ease-in-out")];
    char stringpool_str139[sizeof("letter")];
    char stringpool_str140[sizeof("hand")];
    char stringpool_str141[sizeof("chartreuse")];
    char stringpool_str142[sizeof("landscape")];
    char stringpool_str143[sizeof("indianred")];
    char stringpool_str144[sizeof("mathematical")];
    char stringpool_str145[sizeof("border")];
    char stringpool_str146[sizeof("bolder")];
    char stringpool_str147[sizeof("ahead")];
    char stringpool_str148[sizeof("seashell")];
    char stringpool_str149[sizeof("mediumblue")];
    char stringpool_str150[sizeof("cambodian")];
    char stringpool_str151[sizeof("steelblue")];
    char stringpool_str152[sizeof("color-burn")];
    char stringpool_str153[sizeof("step-start")];
    char stringpool_str154[sizeof("closest-corner")];
    char stringpool_str155[sizeof("use-script")];
    char stringpool_str156[sizeof("status-bar")];
    char stringpool_str157[sizeof("mediumpurple")];
    char stringpool_str158[sizeof("sans-serif")];
    char stringpool_str159[sizeof("threedface")];
    char stringpool_str160[sizeof("scrollbar")];
    char stringpool_str161[sizeof("condensed")];
    char stringpool_str162[sizeof("no-limit")];
    char stringpool_str163[sizeof("dotted")];
    char stringpool_str164[sizeof("each-line")];
    char stringpool_str165[sizeof("document")];
    char stringpool_str166[sizeof("lr-tb")];
    char stringpool_str167[sizeof("step-end")];
    char stringpool_str168[sizeof("thin")];
    char stringpool_str169[sizeof("clip")];
    char stringpool_str170[sizeof("orchid")];
    char stringpool_str171[sizeof("self-start")];
    char stringpool_str172[sizeof("slice")];
    char stringpool_str173[sizeof("alias")];
    char stringpool_str174[sizeof("ethiopic-abegede")];
    char stringpool_str175[sizeof("tb-rl")];
    char stringpool_str176[sizeof("lime")];
    char stringpool_str177[sizeof("sidama")];
    char stringpool_str178[sizeof("crimson")];
    char stringpool_str179[sizeof("lines")];
    char stringpool_str180[sizeof("linen")];
    char stringpool_str181[sizeof("tibetan")];
    char stringpool_str182[sizeof("no-repeat")];
    char stringpool_str183[sizeof("circle")];
    char stringpool_str184[sizeof("thistle")];
    char stringpool_str185[sizeof("rl-tb")];
    char stringpool_str186[sizeof("initial")];
    char stringpool_str187[sizeof("listitem")];
    char stringpool_str188[sizeof("dashed")];
    char stringpool_str189[sizeof("destination-out")];
    char stringpool_str190[sizeof("accumulate")];
    char stringpool_str191[sizeof("hide")];
    char stringpool_str192[sizeof("mediumslateblue")];
    char stringpool_str193[sizeof("indigo")];
    char stringpool_str194[sizeof("destination-atop")];
    char stringpool_str195[sizeof("self-end")];
    char stringpool_str196[sizeof("infinite")];
    char stringpool_str197[sizeof("pointer")];
    char stringpool_str198[sizeof("decimal")];
    char stringpool_str199[sizeof("dot-dash")];
    char stringpool_str200[sizeof("no-punctuation")];
    char stringpool_str201[sizeof("list-item")];
    char stringpool_str202[sizeof("safe")];
    char stringpool_str203[sizeof("linear")];
    char stringpool_str204[sizeof("farthest-corner")];
    char stringpool_str205[sizeof("searchfield")];
    char stringpool_str206[sizeof("miter")];
    char stringpool_str207[sizeof("mintcream")];
    char stringpool_str208[sizeof("mongolian")];
    char stringpool_str209[sizeof("orange")];
    char stringpool_str210[sizeof("lemonchiffon")];
    char stringpool_str211[sizeof("fine")];
    char stringpool_str212[sizeof("large")];
    char stringpool_str213[sizeof("min-content")];
    char stringpool_str214[sizeof("tigre")];
    char stringpool_str215[sizeof("sienna")];
    char stringpool_str216[sizeof("fill")];
    char stringpool_str217[sizeof("aliceblue")];
    char stringpool_str218[sizeof("ethiopic-abegede-ti-et")];
    char stringpool_str219[sizeof("ethiopic-abegede-am-et")];
    char stringpool_str220[sizeof("progress")];
    char stringpool_str221[sizeof("peachpuff")];
    char stringpool_str222[sizeof("lighten")];
    char stringpool_str223[sizeof("disc")];
    char stringpool_str224[sizeof("after")];
    char stringpool_str225[sizeof("slide")];
    char stringpool_str226[sizeof("no-drop")];
    char stringpool_str227[sizeof("afar")];
    char stringpool_str228[sizeof("detached")];
    char stringpool_str229[sizeof("green")];
    char stringpool_str230[sizeof("blanchedalmond")];
    char stringpool_str231[sizeof("table-caption")];
    char stringpool_str232[sizeof("left")];
    char stringpool_str233[sizeof("middle")];
    char stringpool_str234[sizeof("right")];
    char stringpool_str235[sizeof("small-caption")];
    char stringpool_str236[sizeof("larger")];
    char stringpool_str237[sizeof("lightsalmon")];
    char stringpool_str238[sizeof("floating")];
    char stringpool_str239[sizeof("media-slider")];
    char stringpool_str240[sizeof("palegreen")];
    char stringpool_str241[sizeof("gold")];
    char stringpool_str242[sizeof("ethiopic-abegede-ti-er")];
    char stringpool_str243[sizeof("hangul")];
    char stringpool_str244[sizeof("inline-grid")];
    char stringpool_str245[sizeof("lighter")];
    char stringpool_str246[sizeof("painted")];
    char stringpool_str247[sizeof("digits")];
    char stringpool_str248[sizeof("hidden")];
    char stringpool_str249[sizeof("ethiopic-halehame-so-et")];
    char stringpool_str250[sizeof("ethiopic-halehame-om-et")];
    char stringpool_str251[sizeof("ethiopic-halehame-ti-et")];
    char stringpool_str252[sizeof("ethiopic-halehame-am-et")];
    char stringpool_str253[sizeof("ethiopic-halehame-aa-et")];
    char stringpool_str254[sizeof("no-common-ligatures")];
    char stringpool_str255[sizeof("stroke")];
    char stringpool_str256[sizeof("telugu")];
    char stringpool_str257[sizeof("cornsilk")];
    char stringpool_str258[sizeof("drag")];
    char stringpool_str259[sizeof("block")];
    char stringpool_str260[sizeof("higher")];
    char stringpool_str261[sizeof("bengali")];
    char stringpool_str262[sizeof("xor")];
    char stringpool_str263[sizeof("lightblue")];
    char stringpool_str264[sizeof("lightcoral")];
    char stringpool_str265[sizeof("ledger")];
    char stringpool_str266[sizeof("khmer")];
    char stringpool_str267[sizeof("padding")];
    char stringpool_str268[sizeof("semi-condensed")];
    char stringpool_str269[sizeof("forestgreen")];
    char stringpool_str270[sizeof("before")];
    char stringpool_str271[sizeof("black")];
    char stringpool_str272[sizeof("ethiopic-halehame-ti-er")];
    char stringpool_str273[sizeof("searchfield-decoration")];
    char stringpool_str274[sizeof("ethiopic-halehame-aa-er")];
    char stringpool_str275[sizeof("ultra-condensed")];
    char stringpool_str276[sizeof("filled")];
    char stringpool_str277[sizeof("hotpink")];
    char stringpool_str278[sizeof("step-middle")];
    char stringpool_str279[sizeof("seagreen")];
    char stringpool_str280[sizeof("dot-dot-dash")];
    char stringpool_str281[sizeof("row")];
    char stringpool_str282[sizeof("markers")];
    char stringpool_str283[sizeof("asterisks")];
    char stringpool_str284[sizeof("min-intrinsic")];
    char stringpool_str285[sizeof("hangul-consonant")];
    char stringpool_str286[sizeof("palegoldenrod")];
    char stringpool_str287[sizeof("distribute")];
    char stringpool_str288[sizeof("nowrap")];
    char stringpool_str289[sizeof("orangered")];
    char stringpool_str290[sizeof("arabic-indic")];
    char stringpool_str291[sizeof("lower")];
    char stringpool_str292[sizeof("sub")];
    char stringpool_str293[sizeof("pan-x")];
    char stringpool_str294[sizeof("contextual")];
    char stringpool_str295[sizeof("true")];
    char stringpool_str296[sizeof("plum")];
    char stringpool_str297[sizeof("inline-axis")];
    char stringpool_str298[sizeof("new")];
    char stringpool_str299[sizeof("progress-bar")];
    char stringpool_str300[sizeof("above")];
    char stringpool_str301[sizeof("literal-punctuation")];
    char stringpool_str302[sizeof("line-through")];
    char stringpool_str303[sizeof("destination-in")];
    char stringpool_str304[sizeof("ethiopic-halehame-sid-et")];
    char stringpool_str305[sizeof("default")];
    char stringpool_str306[sizeof("mediumseagreen")];
    char stringpool_str307[sizeof("lowercase")];
    char stringpool_str308[sizeof("auto")];
    char stringpool_str309[sizeof("discard")];
    char stringpool_str310[sizeof("context-menu")];
    char stringpool_str311[sizeof("purple")];
    char stringpool_str312[sizeof("inline-box")];
    char stringpool_str313[sizeof("media-sliderthumb")];
    char stringpool_str314[sizeof("exact")];
    char stringpool_str315[sizeof("darken")];
    char stringpool_str316[sizeof("outset")];
    char stringpool_str317[sizeof("dodgerblue")];
    char stringpool_str318[sizeof("blue")];
    char stringpool_str319[sizeof("multiple")];
    char stringpool_str320[sizeof("kannada")];
    char stringpool_str321[sizeof("down")];
    char stringpool_str322[sizeof("luminance")];
    char stringpool_str323[sizeof("aqua")];
    char stringpool_str324[sizeof("menutext")];
    char stringpool_str325[sizeof("butt")];
    char stringpool_str326[sizeof("azure")];
    char stringpool_str327[sizeof("pan-y")];
    char stringpool_str328[sizeof("no-change")];
    char stringpool_str329[sizeof("maximum")];
    char stringpool_str330[sizeof("darksalmon")];
    char stringpool_str331[sizeof("button")];
    char stringpool_str332[sizeof("malayalam")];
    char stringpool_str333[sizeof("single")];
    char stringpool_str334[sizeof("goldenrod")];
    char stringpool_str335[sizeof("text")];
    char stringpool_str336[sizeof("lower-latin")];
    char stringpool_str337[sizeof("off")];
    char stringpool_str338[sizeof("hard-light")];
    char stringpool_str339[sizeof("break-all")];
    char stringpool_str340[sizeof("triangle")];
    char stringpool_str341[sizeof("mediumorchid")];
    char stringpool_str342[sizeof("mediumspringgreen")];
    char stringpool_str343[sizeof("content-box")];
    char stringpool_str344[sizeof("top")];
    char stringpool_str345[sizeof("semi-expanded")];
    char stringpool_str346[sizeof("flex")];
    char stringpool_str347[sizeof("geometricprecision")];
    char stringpool_str348[sizeof("palevioletred")];
    char stringpool_str349[sizeof("ridge")];
    char stringpool_str350[sizeof("ideographic")];
    char stringpool_str351[sizeof("lower-roman")];
    char stringpool_str352[sizeof("inline-block")];
    char stringpool_str353[sizeof("square")];
    char stringpool_str354[sizeof("darkblue")];
    char stringpool_str355[sizeof("source-in")];
    char stringpool_str356[sizeof("hiragana")];
    char stringpool_str357[sizeof("up")];
    char stringpool_str358[sizeof("threedhighlight")];
    char stringpool_str359[sizeof("max-content")];
    char stringpool_str360[sizeof("economy")];
    char stringpool_str361[sizeof("non-scaling-stroke")];
    char stringpool_str362[sizeof("hue")];
    char stringpool_str363[sizeof("fantasy")];
    char stringpool_str364[sizeof("text-top")];
    char stringpool_str365[sizeof("vertical")];
    char stringpool_str366[sizeof("loud")];
    char stringpool_str367[sizeof("searchfield-cancel-button")];
    char stringpool_str368[sizeof("limegreen")];
    char stringpool_str369[sizeof("span")];
    char stringpool_str370[sizeof("source-out")];
    char stringpool_str371[sizeof("aquamarine")];
    char stringpool_str372[sizeof("space")];
    char stringpool_str373[sizeof("oblique")];
    char stringpool_str374[sizeof("textarea")];
    char stringpool_str375[sizeof("pink")];
    char stringpool_str376[sizeof("lower-alpha")];
    char stringpool_str377[sizeof("outside")];
    char stringpool_str378[sizeof("alpha")];
    char stringpool_str379[sizeof("caption")];
    char stringpool_str380[sizeof("grid")];
    char stringpool_str381[sizeof("thick")];
    char stringpool_str382[sizeof("currentcolor")];
    char stringpool_str383[sizeof("paused")];
    char stringpool_str384[sizeof("inline-flex")];
    char stringpool_str385[sizeof("relative")];
    char stringpool_str386[sizeof("lower-armenian")];
    char stringpool_str387[sizeof("exclusion")];
    char stringpool_str388[sizeof("push-button")];
    char stringpool_str389[sizeof("no-drag")];
    char stringpool_str390[sizeof("round")];
    char stringpool_str391[sizeof("farthest-side")];
    char stringpool_str392[sizeof("beige")];
    char stringpool_str393[sizeof("searchfield-results-decoration")];
    char stringpool_str394[sizeof("double")];
    char stringpool_str395[sizeof("ethiopic-halehame-tig")];
    char stringpool_str396[sizeof("text-bottom")];
    char stringpool_str397[sizeof("hanging")];
    char stringpool_str398[sizeof("buttonface")];
    char stringpool_str399[sizeof("hiragana-iroha")];
    char stringpool_str400[sizeof("deeppink")];
    char stringpool_str401[sizeof("fullscreen")];
    char stringpool_str402[sizeof("vertical-lr")];
    char stringpool_str403[sizeof("gainsboro")];
    char stringpool_str404[sizeof("open")];
    char stringpool_str405[sizeof("blink")];
    char stringpool_str406[sizeof("x-small")];
    char stringpool_str407[sizeof("crispedges")];
    char stringpool_str408[sizeof("powderblue")];
    char stringpool_str409[sizeof("darkred")];
    char stringpool_str410[sizeof("color-dodge")];
    char stringpool_str411[sizeof("soft-light")];
    char stringpool_str412[sizeof("preserve-3d")];
    char stringpool_str413[sizeof("flex-start")];
    char stringpool_str414[sizeof("linearrgb")];
    char stringpool_str415[sizeof("alphabetic")];
    char stringpool_str416[sizeof("border-box")];
    char stringpool_str417[sizeof("vertical-rl")];
    char stringpool_str418[sizeof("lightgreen")];
    char stringpool_str419[sizeof("darkslateblue")];
    char stringpool_str420[sizeof("scroll-position")];
    char stringpool_str421[sizeof("menulist-text")];
    char stringpool_str422[sizeof("amharic-abegede")];
    char stringpool_str423[sizeof("zoom")];
    char stringpool_str424[sizeof("media-enter-fullscreen-button")];
    char stringpool_str425[sizeof("georgian")];
    char stringpool_str426[sizeof("repeat")];
    char stringpool_str427[sizeof("table-column-group")];
    char stringpool_str428[sizeof("highlight")];
    char stringpool_str429[sizeof("square-button")];
    char stringpool_str430[sizeof("mix")];
    char stringpool_str431[sizeof("darkorchid")];
    char stringpool_str432[sizeof("fuchsia")];
    char stringpool_str433[sizeof("separate")];
    char stringpool_str434[sizeof("infotext")];
    char stringpool_str435[sizeof("flex-end")];
    char stringpool_str436[sizeof("listbox")];
    char stringpool_str437[sizeof("menulist-button")];
    char stringpool_str438[sizeof("oriya")];
    char stringpool_str439[sizeof("cyan")];
    char stringpool_str440[sizeof("lightpink")];
    char stringpool_str441[sizeof("close-quote")];
    char stringpool_str442[sizeof("olive")];
    char stringpool_str443[sizeof("spell-out")];
    char stringpool_str444[sizeof("column-reverse")];
    char stringpool_str445[sizeof("violet")];
    char stringpool_str446[sizeof("nonzero")];
    char stringpool_str447[sizeof("mediumaquamarine")];
    char stringpool_str448[sizeof("textfield")];
    char stringpool_str449[sizeof("visual")];
    char stringpool_str450[sizeof("groove")];
    char stringpool_str451[sizeof("lightseagreen")];
    char stringpool_str452[sizeof("difference")];
    char stringpool_str453[sizeof("horizontal")];
    char stringpool_str454[sizeof("snow")];
    char stringpool_str455[sizeof("slow")];
    char stringpool_str456[sizeof("after-edge")];
    char stringpool_str457[sizeof("move")];
    char stringpool_str458[sizeof("show")];
    char stringpool_str459[sizeof("khaki")];
    char stringpool_str460[sizeof("gray")];
    char stringpool_str461[sizeof("silver")];
    char stringpool_str462[sizeof("skyblue")];
    char stringpool_str463[sizeof("mistyrose")];
    char stringpool_str464[sizeof("myanmar")];
    char stringpool_str465[sizeof("read-only")];
    char stringpool_str466[sizeof("visible")];
    char stringpool_str467[sizeof("destination-over")];
    char stringpool_str468[sizeof("firebrick")];
    char stringpool_str469[sizeof("col-resize")];
    char stringpool_str470[sizeof("binary")];
    char stringpool_str471[sizeof("lawngreen")];
    char stringpool_str472[sizeof("wrap")];
    char stringpool_str473[sizeof("brown")];
    char stringpool_str474[sizeof("dynamic")];
    char stringpool_str475[sizeof("margin-box")];
    char stringpool_str476[sizeof("inactiveborder")];
    char stringpool_str477[sizeof("katakana")];
    char stringpool_str478[sizeof("outside-shape")];
    char stringpool_str479[sizeof("running")];
    char stringpool_str480[sizeof("mediumvioletred")];
    char stringpool_str481[sizeof("grey")];
    char stringpool_str482[sizeof("replaced")];
    char stringpool_str483[sizeof("cover")];
    char stringpool_str484[sizeof("lightcyan")];
    char stringpool_str485[sizeof("invert")];
    char stringpool_str486[sizeof("space-around")];
    char stringpool_str487[sizeof("royalblue")];
    char stringpool_str488[sizeof("inner-spin-button")];
    char stringpool_str489[sizeof("darkmagenta")];
    char stringpool_str490[sizeof("darkgreen")];
    char stringpool_str491[sizeof("slategrey")];
    char stringpool_str492[sizeof("slategray")];
    char stringpool_str493[sizeof("no-historical-ligatures")];
    char stringpool_str494[sizeof("darkorange")];
    char stringpool_str495[sizeof("ultra-expanded")];
    char stringpool_str496[sizeof("wheat")];
    char stringpool_str497[sizeof("tigrinya-er")];
    char stringpool_str498[sizeof("table-footer-group")];
    char stringpool_str499[sizeof("filter-box")];
    char stringpool_str500[sizeof("lower-greek")];
    char stringpool_str501[sizeof("reset-size")];
    char stringpool_str502[sizeof("katakana-iroha")];
    char stringpool_str503[sizeof("bisque")];
    char stringpool_str504[sizeof("block-axis")];
    char stringpool_str505[sizeof("tigrinya-et")];
    char stringpool_str506[sizeof("level")];
    char stringpool_str507[sizeof("not-allowed")];
    char stringpool_str508[sizeof("avoid")];
    char stringpool_str509[sizeof("lightsteelblue")];
    char stringpool_str510[sizeof("below")];
    char stringpool_str511[sizeof("visiblefill")];
    char stringpool_str512[sizeof("extra-condensed")];
    char stringpool_str513[sizeof("media-mute-button")];
    char stringpool_str514[sizeof("over")];
    char stringpool_str515[sizeof("activecaption")];
    char stringpool_str516[sizeof("fixed")];
    char stringpool_str517[sizeof("bevel")];
    char stringpool_str518[sizeof("always")];
    char stringpool_str519[sizeof("menulist-textfield")];
    char stringpool_str520[sizeof("s-resize")];
    char stringpool_str521[sizeof("n-resize")];
    char stringpool_str522[sizeof("e-resize")];
    char stringpool_str523[sizeof("narrower")];
    char stringpool_str524[sizeof("table-row")];
    char stringpool_str525[sizeof("progressive")];
    char stringpool_str526[sizeof("message-box")];
    char stringpool_str527[sizeof("checkbox")];
    char stringpool_str528[sizeof("cjk-ideographic")];
    char stringpool_str529[sizeof("upright")];
    char stringpool_str530[sizeof("olivedrab")];
    char stringpool_str531[sizeof("overline")];
    char stringpool_str532[sizeof("double-circle")];
    char stringpool_str533[sizeof("table-header-group")];
    char stringpool_str534[sizeof("darkgoldenrod")];
    char stringpool_str535[sizeof("common-ligatures")];
    char stringpool_str536[sizeof("no-open-quote")];
    char stringpool_str537[sizeof("activeborder")];
    char stringpool_str538[sizeof("darkseagreen")];
    char stringpool_str539[sizeof("before-edge")];
    char stringpool_str540[sizeof("pre-wrap")];
    char stringpool_str541[sizeof("hebrew")];
    char stringpool_str542[sizeof("x-large")];
    char stringpool_str543[sizeof("reverse")];
    char stringpool_str544[sizeof("ns-resize")];
    char stringpool_str545[sizeof("padding-box")];
    char stringpool_str546[sizeof("lightslategray")];
    char stringpool_str547[sizeof("alternate-reverse")];
    char stringpool_str548[sizeof("buttontext")];
    char stringpool_str549[sizeof("lavender")];
    char stringpool_str550[sizeof("horizontal-tb")];
    char stringpool_str551[sizeof("cursive")];
    char stringpool_str552[sizeof("lazy-block")];
    char stringpool_str553[sizeof("multiply")];
    char stringpool_str554[sizeof("darkcyan")];
    char stringpool_str555[sizeof("plus-lighter")];
    char stringpool_str556[sizeof("visiblepainted")];
    char stringpool_str557[sizeof("luminosity")];
    char stringpool_str558[sizeof("background")];
    char stringpool_str559[sizeof("-webkit-control")];
    char stringpool_str560[sizeof("buttonhighlight")];
    char stringpool_str561[sizeof("forwards")];
    char stringpool_str562[sizeof("glyphs")];
    char stringpool_str563[sizeof("lightslategrey")];
    char stringpool_str564[sizeof("darkviolet")];
    char stringpool_str565[sizeof("saddlebrown")];
    char stringpool_str566[sizeof("white")];
    char stringpool_str567[sizeof("-webkit-auto")];
    char stringpool_str568[sizeof("horizontal-bt")];
    char stringpool_str569[sizeof("se-resize")];
    char stringpool_str570[sizeof("ne-resize")];
    char stringpool_str571[sizeof("blueviolet")];
    char stringpool_str572[sizeof("inter-word")];
    char stringpool_str573[sizeof("media-volume-slider")];
    char stringpool_str574[sizeof("-webkit-isolate")];
    char stringpool_str575[sizeof("copy")];
    char stringpool_str576[sizeof("paleturquoise")];
    char stringpool_str577[sizeof("wait")];
    char stringpool_str578[sizeof("threedshadow")];
    char stringpool_str579[sizeof("floralwhite")];
    char stringpool_str580[sizeof("media-current-time-display")];
    char stringpool_str581[sizeof("plus-darker")];
    char stringpool_str582[sizeof("minimized")];
    char stringpool_str583[sizeof("evenodd")];
    char stringpool_str584[sizeof("wider")];
    char stringpool_str585[sizeof("table-row-group")];
    char stringpool_str586[sizeof("source-over")];
    char stringpool_str587[sizeof("scale-down")];
    char stringpool_str588[sizeof("media-fullscreen-volume-slider")];
    char stringpool_str589[sizeof("captiontext")];
    char stringpool_str590[sizeof("media-controls-background")];
    char stringpool_str591[sizeof("turquoise")];
    char stringpool_str592[sizeof("super")];
    char stringpool_str593[sizeof("-internal-presence")];
    char stringpool_str594[sizeof("sticky")];
    char stringpool_str595[sizeof("-webkit-center")];
    char stringpool_str596[sizeof("ghostwhite")];
    char stringpool_str597[sizeof("-webkit-match-parent")];
    char stringpool_str598[sizeof("midnightblue")];
    char stringpool_str599[sizeof("read-write")];
    char stringpool_str600[sizeof("xx-small")];
    char stringpool_str601[sizeof("slider-vertical")];
    char stringpool_str602[sizeof("-webkit-right")];
    char stringpool_str603[sizeof("lower-hexadecimal")];
    char stringpool_str604[sizeof("no-contextual")];
    char stringpool_str605[sizeof("lightgrey")];
    char stringpool_str606[sizeof("lightgray")];
    char stringpool_str607[sizeof("-webkit-min-content")];
    char stringpool_str608[sizeof("dimgrey")];
    char stringpool_str609[sizeof("dimgray")];
    char stringpool_str610[sizeof("media-volume-sliderthumb")];
    char stringpool_str611[sizeof("-webkit-small-control")];
    char stringpool_str612[sizeof("vertical-text")];
    char stringpool_str613[sizeof("repeat-x")];
    char stringpool_str614[sizeof("source-atop")];
    char stringpool_str615[sizeof("media-volume-slider-container")];
    char stringpool_str616[sizeof("row-reverse")];
    char stringpool_str617[sizeof("infobackground")];
    char stringpool_str618[sizeof("gujarati")];
    char stringpool_str619[sizeof("button-bevel")];
    char stringpool_str620[sizeof("springgreen")];
    char stringpool_str621[sizeof("historical-ligatures")];
    char stringpool_str622[sizeof("gurmukhi")];
    char stringpool_str623[sizeof("repeat-y")];
    char stringpool_str624[sizeof("vertical-right")];
    char stringpool_str625[sizeof("graytext")];
    char stringpool_str626[sizeof("media-fullscreen-volume-slider-thumb")];
    char stringpool_str627[sizeof("text-after-edge")];
    char stringpool_str628[sizeof("media-toggle-closed-captions-button")];
    char stringpool_str629[sizeof("progress-bar-value")];
    char stringpool_str630[sizeof("uppercase")];
    char stringpool_str631[sizeof("highlighttext")];
    char stringpool_str632[sizeof("-webkit-fit-content")];
    char stringpool_str633[sizeof("row-resize")];
    char stringpool_str634[sizeof("deepskyblue")];
    char stringpool_str635[sizeof("expanded")];
    char stringpool_str636[sizeof("ethiopic-abegede-gez")];
    char stringpool_str637[sizeof("lightyellow")];
    char stringpool_str638[sizeof("-webkit-left")];
    char stringpool_str639[sizeof("-webkit-mini-control")];
    char stringpool_str640[sizeof("navy")];
    char stringpool_str641[sizeof("upper-latin")];
    char stringpool_str642[sizeof("justify")];
    char stringpool_str643[sizeof("nwse-resize")];
    char stringpool_str644[sizeof("open-quote")];
    char stringpool_str645[sizeof("ivory")];
    char stringpool_str646[sizeof("greenyellow")];
    char stringpool_str647[sizeof("visiblestroke")];
    char stringpool_str648[sizeof("darkkhaki")];
    char stringpool_str649[sizeof("extra-expanded")];
    char stringpool_str650[sizeof("devanagari")];
    char stringpool_str651[sizeof("sliderthumb-horizontal")];
    char stringpool_str652[sizeof("darkgrey")];
    char stringpool_str653[sizeof("darkgray")];
    char stringpool_str654[sizeof("upper-roman")];
    char stringpool_str655[sizeof("-webkit-baseline-middle")];
    char stringpool_str656[sizeof("media-controls-fullscreen-background")];
    char stringpool_str657[sizeof("maximized")];
    char stringpool_str658[sizeof("ethiopic-halehame-gez")];
    char stringpool_str659[sizeof("bidi-override")];
    char stringpool_str660[sizeof("text-before-edge")];
    char stringpool_str661[sizeof("capitalize")];
    char stringpool_str662[sizeof("yellow")];
    char stringpool_str663[sizeof("upper-alpha")];
    char stringpool_str664[sizeof("after-white-space")];
    char stringpool_str665[sizeof("no-close-quote")];
    char stringpool_str666[sizeof("media-play-button")];
    char stringpool_str667[sizeof("upper-armenian")];
    char stringpool_str668[sizeof("tigrinya-er-abegede")];
    char stringpool_str669[sizeof("-webkit-grab")];
    char stringpool_str670[sizeof("-webkit-link")];
    char stringpool_str671[sizeof("sw-resize")];
    char stringpool_str672[sizeof("nw-resize")];
    char stringpool_str673[sizeof("ew-resize")];
    char stringpool_str674[sizeof("cjk-earthly-branch")];
    char stringpool_str675[sizeof("subpixel-antialiased")];
    char stringpool_str676[sizeof("tigrinya-et-abegede")];
    char stringpool_str677[sizeof("sliderthumb-vertical")];
    char stringpool_str678[sizeof("rosybrown")];
    char stringpool_str679[sizeof("threedlightshadow")];
    char stringpool_str680[sizeof("inactivecaption")];
    char stringpool_str681[sizeof("overlay")];
    char stringpool_str682[sizeof("darkolivegreen")];
    char stringpool_str683[sizeof("honeydew")];
    char stringpool_str684[sizeof("caps-lock-indicator")];
    char stringpool_str685[sizeof("bounding-box")];
    char stringpool_str686[sizeof("optimizespeed")];
    char stringpool_str687[sizeof("rating-level-indicator")];
    char stringpool_str688[sizeof("whitesmoke")];
    char stringpool_str689[sizeof("media-time-remaining-display")];
    char stringpool_str690[sizeof("xx-large")];
    char stringpool_str691[sizeof("wrap-reverse")];
    char stringpool_str692[sizeof("break-word")];
    char stringpool_str693[sizeof("cornflowerblue")];
    char stringpool_str694[sizeof("-webkit-text")];
    char stringpool_str695[sizeof("-webkit-plaintext")];
    char stringpool_str696[sizeof("backwards")];
    char stringpool_str697[sizeof("-webkit-pictograph")];
    char stringpool_str698[sizeof("sandybrown")];
    char stringpool_str699[sizeof("-webkit-box")];
    char stringpool_str700[sizeof("buttonshadow")];
    char stringpool_str701[sizeof("-webkit-paged-x")];
    char stringpool_str702[sizeof("-webkit-nowrap")];
    char stringpool_str703[sizeof("antiquewhite")];
    char stringpool_str704[sizeof("-webkit-body")];
    char stringpool_str705[sizeof("-webkit-inline-box")];
    char stringpool_str706[sizeof("slider-horizontal")];
    char stringpool_str707[sizeof("mediumturquoise")];
    char stringpool_str708[sizeof("sideways")];
    char stringpool_str709[sizeof("darkturquoise")];
    char stringpool_str710[sizeof("darkslategrey")];
    char stringpool_str711[sizeof("darkslategray")];
    char stringpool_str712[sizeof("lavenderblush")];
    char stringpool_str713[sizeof("media-exit-fullscreen-button")];
    char stringpool_str714[sizeof("-webkit-paged-y")];
    char stringpool_str715[sizeof("-webkit-inline-flex")];
    char stringpool_str716[sizeof("space-between")];
    char stringpool_str717[sizeof("-webkit-flex")];
    char stringpool_str718[sizeof("wave")];
    char stringpool_str719[sizeof("no-discretionary-ligatures")];
    char stringpool_str720[sizeof("-internal-active-list-box-selection")];
    char stringpool_str721[sizeof("continuous-capacity-level-indicator")];
    char stringpool_str722[sizeof("upper-greek")];
    char stringpool_str723[sizeof("threeddarkshadow")];
    char stringpool_str724[sizeof("-webkit-max-content")];
    char stringpool_str725[sizeof("discretionary-ligatures")];
    char stringpool_str726[sizeof("cjk-heavenly-stem")];
    char stringpool_str727[sizeof("-webkit-grabbing")];
    char stringpool_str728[sizeof("-webkit-focus-ring-color")];
    char stringpool_str729[sizeof("w-resize")];
    char stringpool_str730[sizeof("yellowgreen")];
    char stringpool_str731[sizeof("nesw-resize")];
    char stringpool_str732[sizeof("lightskyblue")];
    char stringpool_str733[sizeof("-webkit-isolate-override")];
    char stringpool_str734[sizeof("discrete-capacity-level-indicator")];
    char stringpool_str735[sizeof("-internal-extend-to-zoom")];
    char stringpool_str736[sizeof("-webkit-input-speech-button")];
    char stringpool_str737[sizeof("decimal-leading-zero")];
    char stringpool_str738[sizeof("inactivecaptiontext")];
    char stringpool_str739[sizeof("-internal-inactive-list-box-selection")];
    char stringpool_str740[sizeof("-webkit-optimize-contrast")];
    char stringpool_str741[sizeof("-webkit-fill-available")];
    char stringpool_str742[sizeof("upper-hexadecimal")];
    char stringpool_str743[sizeof("-webkit-zoom-in")];
    char stringpool_str744[sizeof("optimizelegibility")];
    char stringpool_str745[sizeof("burlywood")];
    char stringpool_str746[sizeof("window")];
    char stringpool_str747[sizeof("-webkit-zoom-out")];
    char stringpool_str748[sizeof("papayawhip")];
    char stringpool_str749[sizeof("skip-white-space")];
    char stringpool_str750[sizeof("lower-norwegian")];
    char stringpool_str751[sizeof("navajowhite")];
    char stringpool_str752[sizeof("windowed")];
    char stringpool_str753[sizeof("media-overlay-play-button")];
    char stringpool_str754[sizeof("wavy")];
    char stringpool_str755[sizeof("-internal-active-list-box-selection-text")];
    char stringpool_str756[sizeof("windowframe")];
    char stringpool_str757[sizeof("sideways-right")];
    char stringpool_str758[sizeof("relevancy-level-indicator")];
    char stringpool_str759[sizeof("-webkit-activelink")];
    char stringpool_str760[sizeof("lightgoldenrodyellow")];
    char stringpool_str761[sizeof("-internal-inactive-list-box-selection-text")];
    char stringpool_str762[sizeof("read-write-plaintext-only")];
    char stringpool_str763[sizeof("windowtext")];
    char stringpool_str764[sizeof("appworkspace")];
    char stringpool_str765[sizeof("-webkit-xxx-large")];
    char stringpool_str766[sizeof("optimizequality")];
    char stringpool_str767[sizeof("upper-norwegian")];
  };
static const struct stringpool_t stringpool_contents =
  {
    "on",
    "tb",
    "a5",
    "a4",
    "100",
    "300",
    "600",
    "500",
    "end",
    "a3",
    "all",
    "900",
    "800",
    "700",
    "400",
    "200",
    "none",
    "lr",
    "crop",
    "oromo",
    "inset",
    "cross",
    "clone",
    "tomato",
    "at",
    "inline",
    "instant",
    "content",
    "ellipse",
    "loose",
    "contain",
    "coral",
    "contents",
    "b5",
    "b4",
    "ellipsis",
    "normal",
    "armenian",
    "somali",
    "tan",
    "ltr",
    "monospace",
    "isolate",
    "oldlace",
    "ease",
    "strict",
    "column",
    "thai",
    "rl",
    "collapse",
    "caret",
    "lao",
    "maroon",
    "salmon",
    "urdu",
    "chocolate",
    "ethiopic",
    "smooth",
    "table",
    "color",
    "absolute",
    "small",
    "rtl",
    "bottom",
    "inherit",
    "static",
    "portrait",
    "amharic",
    "srgb",
    "under",
    "closest-side",
    "continuous",
    "pre",
    "antialiased",
    "stretch",
    "ease-in",
    "font",
    "italic",
    "balance",
    "radio",
    "logical",
    "magenta",
    "coarse",
    "sesame",
    "both",
    "cell",
    "alternate",
    "element",
    "ignore",
    "intrinsic",
    "persian",
    "baseline",
    "menu",
    "peru",
    "ease-out",
    "start",
    "footnotes",
    "inline-table",
    "underline",
    "icon",
    "interlace",
    "manipulation",
    "fast",
    "flat",
    "solid",
    "medium",
    "embed",
    "crosshair",
    "screen",
    "script",
    "smaller",
    "inside",
    "small-caps",
    "help",
    "red",
    "dot",
    "slateblue",
    "teal",
    "cadetblue",
    "reset",
    "moccasin",
    "all-scroll",
    "table-cell",
    "menulist",
    "clear",
    "transparent",
    "local",
    "center",
    "bold",
    "scroll",
    "pre-line",
    "octal",
    "table-column",
    "legal",
    "saturation",
    "meter",
    "central",
    "serif",
    "ease-in-out",
    "letter",
    "hand",
    "chartreuse",
    "landscape",
    "indianred",
    "mathematical",
    "border",
    "bolder",
    "ahead",
    "seashell",
    "mediumblue",
    "cambodian",
    "steelblue",
    "color-burn",
    "step-start",
    "closest-corner",
    "use-script",
    "status-bar",
    "mediumpurple",
    "sans-serif",
    "threedface",
    "scrollbar",
    "condensed",
    "no-limit",
    "dotted",
    "each-line",
    "document",
    "lr-tb",
    "step-end",
    "thin",
    "clip",
    "orchid",
    "self-start",
    "slice",
    "alias",
    "ethiopic-abegede",
    "tb-rl",
    "lime",
    "sidama",
    "crimson",
    "lines",
    "linen",
    "tibetan",
    "no-repeat",
    "circle",
    "thistle",
    "rl-tb",
    "initial",
    "listitem",
    "dashed",
    "destination-out",
    "accumulate",
    "hide",
    "mediumslateblue",
    "indigo",
    "destination-atop",
    "self-end",
    "infinite",
    "pointer",
    "decimal",
    "dot-dash",
    "no-punctuation",
    "list-item",
    "safe",
    "linear",
    "farthest-corner",
    "searchfield",
    "miter",
    "mintcream",
    "mongolian",
    "orange",
    "lemonchiffon",
    "fine",
    "large",
    "min-content",
    "tigre",
    "sienna",
    "fill",
    "aliceblue",
    "ethiopic-abegede-ti-et",
    "ethiopic-abegede-am-et",
    "progress",
    "peachpuff",
    "lighten",
    "disc",
    "after",
    "slide",
    "no-drop",
    "afar",
    "detached",
    "green",
    "blanchedalmond",
    "table-caption",
    "left",
    "middle",
    "right",
    "small-caption",
    "larger",
    "lightsalmon",
    "floating",
    "media-slider",
    "palegreen",
    "gold",
    "ethiopic-abegede-ti-er",
    "hangul",
    "inline-grid",
    "lighter",
    "painted",
    "digits",
    "hidden",
    "ethiopic-halehame-so-et",
    "ethiopic-halehame-om-et",
    "ethiopic-halehame-ti-et",
    "ethiopic-halehame-am-et",
    "ethiopic-halehame-aa-et",
    "no-common-ligatures",
    "stroke",
    "telugu",
    "cornsilk",
    "drag",
    "block",
    "higher",
    "bengali",
    "xor",
    "lightblue",
    "lightcoral",
    "ledger",
    "khmer",
    "padding",
    "semi-condensed",
    "forestgreen",
    "before",
    "black",
    "ethiopic-halehame-ti-er",
    "searchfield-decoration",
    "ethiopic-halehame-aa-er",
    "ultra-condensed",
    "filled",
    "hotpink",
    "step-middle",
    "seagreen",
    "dot-dot-dash",
    "row",
    "markers",
    "asterisks",
    "min-intrinsic",
    "hangul-consonant",
    "palegoldenrod",
    "distribute",
    "nowrap",
    "orangered",
    "arabic-indic",
    "lower",
    "sub",
    "pan-x",
    "contextual",
    "true",
    "plum",
    "inline-axis",
    "new",
    "progress-bar",
    "above",
    "literal-punctuation",
    "line-through",
    "destination-in",
    "ethiopic-halehame-sid-et",
    "default",
    "mediumseagreen",
    "lowercase",
    "auto",
    "discard",
    "context-menu",
    "purple",
    "inline-box",
    "media-sliderthumb",
    "exact",
    "darken",
    "outset",
    "dodgerblue",
    "blue",
    "multiple",
    "kannada",
    "down",
    "luminance",
    "aqua",
    "menutext",
    "butt",
    "azure",
    "pan-y",
    "no-change",
    "maximum",
    "darksalmon",
    "button",
    "malayalam",
    "single",
    "goldenrod",
    "text",
    "lower-latin",
    "off",
    "hard-light",
    "break-all",
    "triangle",
    "mediumorchid",
    "mediumspringgreen",
    "content-box",
    "top",
    "semi-expanded",
    "flex",
    "geometricprecision",
    "palevioletred",
    "ridge",
    "ideographic",
    "lower-roman",
    "inline-block",
    "square",
    "darkblue",
    "source-in",
    "hiragana",
    "up",
    "threedhighlight",
    "max-content",
    "economy",
    "non-scaling-stroke",
    "hue",
    "fantasy",
    "text-top",
    "vertical",
    "loud",
    "searchfield-cancel-button",
    "limegreen",
    "span",
    "source-out",
    "aquamarine",
    "space",
    "oblique",
    "textarea",
    "pink",
    "lower-alpha",
    "outside",
    "alpha",
    "caption",
    "grid",
    "thick",
    "currentcolor",
    "paused",
    "inline-flex",
    "relative",
    "lower-armenian",
    "exclusion",
    "push-button",
    "no-drag",
    "round",
    "farthest-side",
    "beige",
    "searchfield-results-decoration",
    "double",
    "ethiopic-halehame-tig",
    "text-bottom",
    "hanging",
    "buttonface",
    "hiragana-iroha",
    "deeppink",
    "fullscreen",
    "vertical-lr",
    "gainsboro",
    "open",
    "blink",
    "x-small",
    "crispedges",
    "powderblue",
    "darkred",
    "color-dodge",
    "soft-light",
    "preserve-3d",
    "flex-start",
    "linearrgb",
    "alphabetic",
    "border-box",
    "vertical-rl",
    "lightgreen",
    "darkslateblue",
    "scroll-position",
    "menulist-text",
    "amharic-abegede",
    "zoom",
    "media-enter-fullscreen-button",
    "georgian",
    "repeat",
    "table-column-group",
    "highlight",
    "square-button",
    "mix",
    "darkorchid",
    "fuchsia",
    "separate",
    "infotext",
    "flex-end",
    "listbox",
    "menulist-button",
    "oriya",
    "cyan",
    "lightpink",
    "close-quote",
    "olive",
    "spell-out",
    "column-reverse",
    "violet",
    "nonzero",
    "mediumaquamarine",
    "textfield",
    "visual",
    "groove",
    "lightseagreen",
    "difference",
    "horizontal",
    "snow",
    "slow",
    "after-edge",
    "move",
    "show",
    "khaki",
    "gray",
    "silver",
    "skyblue",
    "mistyrose",
    "myanmar",
    "read-only",
    "visible",
    "destination-over",
    "firebrick",
    "col-resize",
    "binary",
    "lawngreen",
    "wrap",
    "brown",
    "dynamic",
    "margin-box",
    "inactiveborder",
    "katakana",
    "outside-shape",
    "running",
    "mediumvioletred",
    "grey",
    "replaced",
    "cover",
    "lightcyan",
    "invert",
    "space-around",
    "royalblue",
    "inner-spin-button",
    "darkmagenta",
    "darkgreen",
    "slategrey",
    "slategray",
    "no-historical-ligatures",
    "darkorange",
    "ultra-expanded",
    "wheat",
    "tigrinya-er",
    "table-footer-group",
    "filter-box",
    "lower-greek",
    "reset-size",
    "katakana-iroha",
    "bisque",
    "block-axis",
    "tigrinya-et",
    "level",
    "not-allowed",
    "avoid",
    "lightsteelblue",
    "below",
    "visiblefill",
    "extra-condensed",
    "media-mute-button",
    "over",
    "activecaption",
    "fixed",
    "bevel",
    "always",
    "menulist-textfield",
    "s-resize",
    "n-resize",
    "e-resize",
    "narrower",
    "table-row",
    "progressive",
    "message-box",
    "checkbox",
    "cjk-ideographic",
    "upright",
    "olivedrab",
    "overline",
    "double-circle",
    "table-header-group",
    "darkgoldenrod",
    "common-ligatures",
    "no-open-quote",
    "activeborder",
    "darkseagreen",
    "before-edge",
    "pre-wrap",
    "hebrew",
    "x-large",
    "reverse",
    "ns-resize",
    "padding-box",
    "lightslategray",
    "alternate-reverse",
    "buttontext",
    "lavender",
    "horizontal-tb",
    "cursive",
    "lazy-block",
    "multiply",
    "darkcyan",
    "plus-lighter",
    "visiblepainted",
    "luminosity",
    "background",
    "-webkit-control",
    "buttonhighlight",
    "forwards",
    "glyphs",
    "lightslategrey",
    "darkviolet",
    "saddlebrown",
    "white",
    "-webkit-auto",
    "horizontal-bt",
    "se-resize",
    "ne-resize",
    "blueviolet",
    "inter-word",
    "media-volume-slider",
    "-webkit-isolate",
    "copy",
    "paleturquoise",
    "wait",
    "threedshadow",
    "floralwhite",
    "media-current-time-display",
    "plus-darker",
    "minimized",
    "evenodd",
    "wider",
    "table-row-group",
    "source-over",
    "scale-down",
    "media-fullscreen-volume-slider",
    "captiontext",
    "media-controls-background",
    "turquoise",
    "super",
    "-internal-presence",
    "sticky",
    "-webkit-center",
    "ghostwhite",
    "-webkit-match-parent",
    "midnightblue",
    "read-write",
    "xx-small",
    "slider-vertical",
    "-webkit-right",
    "lower-hexadecimal",
    "no-contextual",
    "lightgrey",
    "lightgray",
    "-webkit-min-content",
    "dimgrey",
    "dimgray",
    "media-volume-sliderthumb",
    "-webkit-small-control",
    "vertical-text",
    "repeat-x",
    "source-atop",
    "media-volume-slider-container",
    "row-reverse",
    "infobackground",
    "gujarati",
    "button-bevel",
    "springgreen",
    "historical-ligatures",
    "gurmukhi",
    "repeat-y",
    "vertical-right",
    "graytext",
    "media-fullscreen-volume-slider-thumb",
    "text-after-edge",
    "media-toggle-closed-captions-button",
    "progress-bar-value",
    "uppercase",
    "highlighttext",
    "-webkit-fit-content",
    "row-resize",
    "deepskyblue",
    "expanded",
    "ethiopic-abegede-gez",
    "lightyellow",
    "-webkit-left",
    "-webkit-mini-control",
    "navy",
    "upper-latin",
    "justify",
    "nwse-resize",
    "open-quote",
    "ivory",
    "greenyellow",
    "visiblestroke",
    "darkkhaki",
    "extra-expanded",
    "devanagari",
    "sliderthumb-horizontal",
    "darkgrey",
    "darkgray",
    "upper-roman",
    "-webkit-baseline-middle",
    "media-controls-fullscreen-background",
    "maximized",
    "ethiopic-halehame-gez",
    "bidi-override",
    "text-before-edge",
    "capitalize",
    "yellow",
    "upper-alpha",
    "after-white-space",
    "no-close-quote",
    "media-play-button",
    "upper-armenian",
    "tigrinya-er-abegede",
    "-webkit-grab",
    "-webkit-link",
    "sw-resize",
    "nw-resize",
    "ew-resize",
    "cjk-earthly-branch",
    "subpixel-antialiased",
    "tigrinya-et-abegede",
    "sliderthumb-vertical",
    "rosybrown",
    "threedlightshadow",
    "inactivecaption",
    "overlay",
    "darkolivegreen",
    "honeydew",
    "caps-lock-indicator",
    "bounding-box",
    "optimizespeed",
    "rating-level-indicator",
    "whitesmoke",
    "media-time-remaining-display",
    "xx-large",
    "wrap-reverse",
    "break-word",
    "cornflowerblue",
    "-webkit-text",
    "-webkit-plaintext",
    "backwards",
    "-webkit-pictograph",
    "sandybrown",
    "-webkit-box",
    "buttonshadow",
    "-webkit-paged-x",
    "-webkit-nowrap",
    "antiquewhite",
    "-webkit-body",
    "-webkit-inline-box",
    "slider-horizontal",
    "mediumturquoise",
    "sideways",
    "darkturquoise",
    "darkslategrey",
    "darkslategray",
    "lavenderblush",
    "media-exit-fullscreen-button",
    "-webkit-paged-y",
    "-webkit-inline-flex",
    "space-between",
    "-webkit-flex",
    "wave",
    "no-discretionary-ligatures",
    "-internal-active-list-box-selection",
    "continuous-capacity-level-indicator",
    "upper-greek",
    "threeddarkshadow",
    "-webkit-max-content",
    "discretionary-ligatures",
    "cjk-heavenly-stem",
    "-webkit-grabbing",
    "-webkit-focus-ring-color",
    "w-resize",
    "yellowgreen",
    "nesw-resize",
    "lightskyblue",
    "-webkit-isolate-override",
    "discrete-capacity-level-indicator",
    "-internal-extend-to-zoom",
    "-webkit-input-speech-button",
    "decimal-leading-zero",
    "inactivecaptiontext",
    "-internal-inactive-list-box-selection",
    "-webkit-optimize-contrast",
    "-webkit-fill-available",
    "upper-hexadecimal",
    "-webkit-zoom-in",
    "optimizelegibility",
    "burlywood",
    "window",
    "-webkit-zoom-out",
    "papayawhip",
    "skip-white-space",
    "lower-norwegian",
    "navajowhite",
    "windowed",
    "media-overlay-play-button",
    "wavy",
    "-internal-active-list-box-selection-text",
    "windowframe",
    "sideways-right",
    "relevancy-level-indicator",
    "-webkit-activelink",
    "lightgoldenrodyellow",
    "-internal-inactive-list-box-selection-text",
    "read-write-plaintext-only",
    "windowtext",
    "appworkspace",
    "-webkit-xxx-large",
    "optimizequality",
    "upper-norwegian"
  };
#define stringpool ((const char *) &stringpool_contents)
const struct Value *
CSSValueKeywordsHash::findValueImpl (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 768,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 42,
      MIN_HASH_VALUE = 18,
      MAX_HASH_VALUE = 5686
    };

  static const struct Value value_word_list[] =
    {
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str0, CSSValueOn},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str1, CSSValueTb},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str2, CSSValueA5},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str3, CSSValueA4},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str4, CSSValue100},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str5, CSSValue300},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str6, CSSValue600},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str7, CSSValue500},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str8, CSSValueEnd},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str9, CSSValueA3},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str10, CSSValueAll},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str11, CSSValue900},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str12, CSSValue800},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str13, CSSValue700},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str14, CSSValue400},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str15, CSSValue200},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str16, CSSValueNone},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str17, CSSValueLr},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str18, CSSValueCrop},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str19, CSSValueOromo},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str20, CSSValueInset},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str21, CSSValueCross},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str22, CSSValueClone},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str23, CSSValueTomato},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str24, CSSValueAt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str25, CSSValueInline},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str26, CSSValueInstant},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str27, CSSValueContent},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str28, CSSValueEllipse},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str29, CSSValueLoose},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str30, CSSValueContain},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str31, CSSValueCoral},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str32, CSSValueContents},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str33, CSSValueB5},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str34, CSSValueB4},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str35, CSSValueEllipsis},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str36, CSSValueNormal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str37, CSSValueArmenian},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str38, CSSValueSomali},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str39, CSSValueTan},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str40, CSSValueLtr},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str41, CSSValueMonospace},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str42, CSSValueIsolate},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str43, CSSValueOldlace},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str44, CSSValueEase},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str45, CSSValueStrict},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str46, CSSValueColumn},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str47, CSSValueThai},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str48, CSSValueRl},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str49, CSSValueCollapse},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str50, CSSValueCaret},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str51, CSSValueLao},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str52, CSSValueMaroon},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str53, CSSValueSalmon},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str54, CSSValueUrdu},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str55, CSSValueChocolate},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str56, CSSValueEthiopic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str57, CSSValueSmooth},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str58, CSSValueTable},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str59, CSSValueColor},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str60, CSSValueAbsolute},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str61, CSSValueSmall},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str62, CSSValueRtl},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str63, CSSValueBottom},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str64, CSSValueInherit},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str65, CSSValueStatic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str66, CSSValuePortrait},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str67, CSSValueAmharic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str68, CSSValueSrgb},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str69, CSSValueUnder},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str70, CSSValueClosestSide},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str71, CSSValueContinuous},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str72, CSSValuePre},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str73, CSSValueAntialiased},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str74, CSSValueStretch},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str75, CSSValueEaseIn},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str76, CSSValueFont},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str77, CSSValueItalic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str78, CSSValueBalance},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str79, CSSValueRadio},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str80, CSSValueLogical},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str81, CSSValueMagenta},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str82, CSSValueCoarse},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str83, CSSValueSesame},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str84, CSSValueBoth},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str85, CSSValueCell},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str86, CSSValueAlternate},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str87, CSSValueElement},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str88, CSSValueIgnore},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str89, CSSValueIntrinsic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str90, CSSValuePersian},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str91, CSSValueBaseline},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str92, CSSValueMenu},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str93, CSSValuePeru},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str94, CSSValueEaseOut},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str95, CSSValueStart},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str96, CSSValueFootnotes},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str97, CSSValueInlineTable},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str98, CSSValueUnderline},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str99, CSSValueIcon},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str100, CSSValueInterlace},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str101, CSSValueManipulation},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str102, CSSValueFast},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str103, CSSValueFlat},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str104, CSSValueSolid},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str105, CSSValueMedium},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str106, CSSValueEmbed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str107, CSSValueCrosshair},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str108, CSSValueScreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str109, CSSValueScript},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str110, CSSValueSmaller},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str111, CSSValueInside},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str112, CSSValueSmallCaps},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str113, CSSValueHelp},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str114, CSSValueRed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str115, CSSValueDot},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str116, CSSValueSlateblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str117, CSSValueTeal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str118, CSSValueCadetblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str119, CSSValueReset},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str120, CSSValueMoccasin},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str121, CSSValueAllScroll},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str122, CSSValueTableCell},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str123, CSSValueMenulist},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str124, CSSValueClear},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str125, CSSValueTransparent},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str126, CSSValueLocal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str127, CSSValueCenter},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str128, CSSValueBold},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str129, CSSValueScroll},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str130, CSSValuePreLine},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str131, CSSValueOctal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str132, CSSValueTableColumn},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str133, CSSValueLegal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str134, CSSValueSaturation},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str135, CSSValueMeter},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str136, CSSValueCentral},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str137, CSSValueSerif},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str138, CSSValueEaseInOut},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str139, CSSValueLetter},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str140, CSSValueHand},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str141, CSSValueChartreuse},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str142, CSSValueLandscape},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str143, CSSValueIndianred},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str144, CSSValueMathematical},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str145, CSSValueBorder},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str146, CSSValueBolder},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str147, CSSValueAhead},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str148, CSSValueSeashell},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str149, CSSValueMediumblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str150, CSSValueCambodian},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str151, CSSValueSteelblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str152, CSSValueColorBurn},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str153, CSSValueStepStart},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str154, CSSValueClosestCorner},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str155, CSSValueUseScript},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str156, CSSValueStatusBar},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str157, CSSValueMediumpurple},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str158, CSSValueSansSerif},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str159, CSSValueThreedface},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str160, CSSValueScrollbar},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str161, CSSValueCondensed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str162, CSSValueNoLimit},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str163, CSSValueDotted},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str164, CSSValueEachLine},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str165, CSSValueDocument},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str166, CSSValueLrTb},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str167, CSSValueStepEnd},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str168, CSSValueThin},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str169, CSSValueClip},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str170, CSSValueOrchid},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str171, CSSValueSelfStart},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str172, CSSValueSlice},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str173, CSSValueAlias},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str174, CSSValueEthiopicAbegede},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str175, CSSValueTbRl},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str176, CSSValueLime},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str177, CSSValueSidama},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str178, CSSValueCrimson},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str179, CSSValueLines},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str180, CSSValueLinen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str181, CSSValueTibetan},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str182, CSSValueNoRepeat},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str183, CSSValueCircle},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str184, CSSValueThistle},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str185, CSSValueRlTb},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str186, CSSValueInitial},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str187, CSSValueListitem},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str188, CSSValueDashed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str189, CSSValueDestinationOut},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str190, CSSValueAccumulate},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str191, CSSValueHide},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str192, CSSValueMediumslateblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str193, CSSValueIndigo},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str194, CSSValueDestinationAtop},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str195, CSSValueSelfEnd},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str196, CSSValueInfinite},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str197, CSSValuePointer},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str198, CSSValueDecimal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str199, CSSValueDotDash},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str200, CSSValueNoPunctuation},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str201, CSSValueListItem},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str202, CSSValueSafe},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str203, CSSValueLinear},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str204, CSSValueFarthestCorner},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str205, CSSValueSearchfield},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str206, CSSValueMiter},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str207, CSSValueMintcream},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str208, CSSValueMongolian},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str209, CSSValueOrange},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str210, CSSValueLemonchiffon},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str211, CSSValueFine},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str212, CSSValueLarge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str213, CSSValueMinContent},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str214, CSSValueTigre},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str215, CSSValueSienna},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str216, CSSValueFill},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str217, CSSValueAliceblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str218, CSSValueEthiopicAbegedeTiEt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str219, CSSValueEthiopicAbegedeAmEt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str220, CSSValueProgress},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str221, CSSValuePeachpuff},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str222, CSSValueLighten},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str223, CSSValueDisc},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str224, CSSValueAfter},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str225, CSSValueSlide},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str226, CSSValueNoDrop},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str227, CSSValueAfar},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str228, CSSValueDetached},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str229, CSSValueGreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str230, CSSValueBlanchedalmond},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str231, CSSValueTableCaption},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str232, CSSValueLeft},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str233, CSSValueMiddle},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str234, CSSValueRight},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str235, CSSValueSmallCaption},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str236, CSSValueLarger},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str237, CSSValueLightsalmon},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str238, CSSValueFloating},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str239, CSSValueMediaSlider},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str240, CSSValuePalegreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str241, CSSValueGold},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str242, CSSValueEthiopicAbegedeTiEr},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str243, CSSValueHangul},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str244, CSSValueInlineGrid},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str245, CSSValueLighter},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str246, CSSValuePainted},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str247, CSSValueDigits},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str248, CSSValueHidden},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str249, CSSValueEthiopicHalehameSoEt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str250, CSSValueEthiopicHalehameOmEt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str251, CSSValueEthiopicHalehameTiEt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str252, CSSValueEthiopicHalehameAmEt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str253, CSSValueEthiopicHalehameAaEt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str254, CSSValueNoCommonLigatures},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str255, CSSValueStroke},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str256, CSSValueTelugu},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str257, CSSValueCornsilk},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str258, CSSValueDrag},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str259, CSSValueBlock},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str260, CSSValueHigher},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str261, CSSValueBengali},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str262, CSSValueXor},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str263, CSSValueLightblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str264, CSSValueLightcoral},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str265, CSSValueLedger},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str266, CSSValueKhmer},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str267, CSSValuePadding},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str268, CSSValueSemiCondensed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str269, CSSValueForestgreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str270, CSSValueBefore},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str271, CSSValueBlack},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str272, CSSValueEthiopicHalehameTiEr},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str273, CSSValueSearchfieldDecoration},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str274, CSSValueEthiopicHalehameAaEr},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str275, CSSValueUltraCondensed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str276, CSSValueFilled},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str277, CSSValueHotpink},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str278, CSSValueStepMiddle},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str279, CSSValueSeagreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str280, CSSValueDotDotDash},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str281, CSSValueRow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str282, CSSValueMarkers},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str283, CSSValueAsterisks},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str284, CSSValueMinIntrinsic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str285, CSSValueHangulConsonant},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str286, CSSValuePalegoldenrod},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str287, CSSValueDistribute},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str288, CSSValueNowrap},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str289, CSSValueOrangered},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str290, CSSValueArabicIndic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str291, CSSValueLower},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str292, CSSValueSub},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str293, CSSValuePanX},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str294, CSSValueContextual},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str295, CSSValueTrue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str296, CSSValuePlum},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str297, CSSValueInlineAxis},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str298, CSSValueNew},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str299, CSSValueProgressBar},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str300, CSSValueAbove},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str301, CSSValueLiteralPunctuation},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str302, CSSValueLineThrough},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str303, CSSValueDestinationIn},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str304, CSSValueEthiopicHalehameSidEt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str305, CSSValueDefault},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str306, CSSValueMediumseagreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str307, CSSValueLowercase},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str308, CSSValueAuto},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str309, CSSValueDiscard},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str310, CSSValueContextMenu},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str311, CSSValuePurple},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str312, CSSValueInlineBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str313, CSSValueMediaSliderthumb},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str314, CSSValueExact},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str315, CSSValueDarken},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str316, CSSValueOutset},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str317, CSSValueDodgerblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str318, CSSValueBlue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str319, CSSValueMultiple},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str320, CSSValueKannada},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str321, CSSValueDown},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str322, CSSValueLuminance},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str323, CSSValueAqua},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str324, CSSValueMenutext},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str325, CSSValueButt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str326, CSSValueAzure},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str327, CSSValuePanY},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str328, CSSValueNoChange},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str329, CSSValueMaximum},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str330, CSSValueDarksalmon},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str331, CSSValueButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str332, CSSValueMalayalam},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str333, CSSValueSingle},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str334, CSSValueGoldenrod},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str335, CSSValueText},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str336, CSSValueLowerLatin},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str337, CSSValueOff},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str338, CSSValueHardLight},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str339, CSSValueBreakAll},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str340, CSSValueTriangle},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str341, CSSValueMediumorchid},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str342, CSSValueMediumspringgreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str343, CSSValueContentBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str344, CSSValueTop},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str345, CSSValueSemiExpanded},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str346, CSSValueFlex},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str347, CSSValueGeometricprecision},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str348, CSSValuePalevioletred},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str349, CSSValueRidge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str350, CSSValueIdeographic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str351, CSSValueLowerRoman},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str352, CSSValueInlineBlock},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str353, CSSValueSquare},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str354, CSSValueDarkblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str355, CSSValueSourceIn},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str356, CSSValueHiragana},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str357, CSSValueUp},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str358, CSSValueThreedhighlight},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str359, CSSValueMaxContent},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str360, CSSValueEconomy},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str361, CSSValueNonScalingStroke},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str362, CSSValueHue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str363, CSSValueFantasy},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str364, CSSValueTextTop},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str365, CSSValueVertical},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str366, CSSValueLoud},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str367, CSSValueSearchfieldCancelButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str368, CSSValueLimegreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str369, CSSValueSpan},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str370, CSSValueSourceOut},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str371, CSSValueAquamarine},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str372, CSSValueSpace},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str373, CSSValueOblique},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str374, CSSValueTextarea},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str375, CSSValuePink},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str376, CSSValueLowerAlpha},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str377, CSSValueOutside},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str378, CSSValueAlpha},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str379, CSSValueCaption},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str380, CSSValueGrid},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str381, CSSValueThick},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str382, CSSValueCurrentcolor},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str383, CSSValuePaused},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str384, CSSValueInlineFlex},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str385, CSSValueRelative},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str386, CSSValueLowerArmenian},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str387, CSSValueExclusion},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str388, CSSValuePushButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str389, CSSValueNoDrag},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str390, CSSValueRound},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str391, CSSValueFarthestSide},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str392, CSSValueBeige},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str393, CSSValueSearchfieldResultsDecoration},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str394, CSSValueDouble},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str395, CSSValueEthiopicHalehameTig},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str396, CSSValueTextBottom},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str397, CSSValueHanging},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str398, CSSValueButtonface},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str399, CSSValueHiraganaIroha},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str400, CSSValueDeeppink},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str401, CSSValueFullscreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str402, CSSValueVerticalLr},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str403, CSSValueGainsboro},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str404, CSSValueOpen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str405, CSSValueBlink},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str406, CSSValueXSmall},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str407, CSSValueCrispedges},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str408, CSSValuePowderblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str409, CSSValueDarkred},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str410, CSSValueColorDodge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str411, CSSValueSoftLight},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str412, CSSValuePreserve3d},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str413, CSSValueFlexStart},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str414, CSSValueLinearrgb},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str415, CSSValueAlphabetic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str416, CSSValueBorderBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str417, CSSValueVerticalRl},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str418, CSSValueLightgreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str419, CSSValueDarkslateblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str420, CSSValueScrollPosition},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str421, CSSValueMenulistText},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str422, CSSValueAmharicAbegede},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str423, CSSValueZoom},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str424, CSSValueMediaEnterFullscreenButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str425, CSSValueGeorgian},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str426, CSSValueRepeat},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str427, CSSValueTableColumnGroup},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str428, CSSValueHighlight},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str429, CSSValueSquareButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str430, CSSValueMix},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str431, CSSValueDarkorchid},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str432, CSSValueFuchsia},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str433, CSSValueSeparate},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str434, CSSValueInfotext},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str435, CSSValueFlexEnd},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str436, CSSValueListbox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str437, CSSValueMenulistButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str438, CSSValueOriya},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str439, CSSValueCyan},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str440, CSSValueLightpink},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str441, CSSValueCloseQuote},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str442, CSSValueOlive},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str443, CSSValueSpellOut},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str444, CSSValueColumnReverse},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str445, CSSValueViolet},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str446, CSSValueNonzero},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str447, CSSValueMediumaquamarine},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str448, CSSValueTextfield},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str449, CSSValueVisual},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str450, CSSValueGroove},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str451, CSSValueLightseagreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str452, CSSValueDifference},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str453, CSSValueHorizontal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str454, CSSValueSnow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str455, CSSValueSlow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str456, CSSValueAfterEdge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str457, CSSValueMove},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str458, CSSValueShow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str459, CSSValueKhaki},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str460, CSSValueGray},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str461, CSSValueSilver},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str462, CSSValueSkyblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str463, CSSValueMistyrose},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str464, CSSValueMyanmar},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str465, CSSValueReadOnly},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str466, CSSValueVisible},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str467, CSSValueDestinationOver},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str468, CSSValueFirebrick},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str469, CSSValueColResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str470, CSSValueBinary},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str471, CSSValueLawngreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str472, CSSValueWrap},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str473, CSSValueBrown},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str474, CSSValueDynamic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str475, CSSValueMarginBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str476, CSSValueInactiveborder},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str477, CSSValueKatakana},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str478, CSSValueOutsideShape},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str479, CSSValueRunning},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str480, CSSValueMediumvioletred},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str481, CSSValueGrey},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str482, CSSValueReplaced},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str483, CSSValueCover},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str484, CSSValueLightcyan},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str485, CSSValueInvert},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str486, CSSValueSpaceAround},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str487, CSSValueRoyalblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str488, CSSValueInnerSpinButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str489, CSSValueDarkmagenta},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str490, CSSValueDarkgreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str491, CSSValueSlategrey},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str492, CSSValueSlategray},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str493, CSSValueNoHistoricalLigatures},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str494, CSSValueDarkorange},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str495, CSSValueUltraExpanded},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str496, CSSValueWheat},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str497, CSSValueTigrinyaEr},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str498, CSSValueTableFooterGroup},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str499, CSSValueFilterBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str500, CSSValueLowerGreek},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str501, CSSValueResetSize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str502, CSSValueKatakanaIroha},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str503, CSSValueBisque},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str504, CSSValueBlockAxis},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str505, CSSValueTigrinyaEt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str506, CSSValueLevel},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str507, CSSValueNotAllowed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str508, CSSValueAvoid},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str509, CSSValueLightsteelblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str510, CSSValueBelow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str511, CSSValueVisiblefill},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str512, CSSValueExtraCondensed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str513, CSSValueMediaMuteButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str514, CSSValueOver},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str515, CSSValueActivecaption},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str516, CSSValueFixed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str517, CSSValueBevel},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str518, CSSValueAlways},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str519, CSSValueMenulistTextfield},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str520, CSSValueSResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str521, CSSValueNResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str522, CSSValueEResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str523, CSSValueNarrower},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str524, CSSValueTableRow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str525, CSSValueProgressive},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str526, CSSValueMessageBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str527, CSSValueCheckbox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str528, CSSValueCjkIdeographic},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str529, CSSValueUpright},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str530, CSSValueOlivedrab},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str531, CSSValueOverline},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str532, CSSValueDoubleCircle},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str533, CSSValueTableHeaderGroup},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str534, CSSValueDarkgoldenrod},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str535, CSSValueCommonLigatures},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str536, CSSValueNoOpenQuote},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str537, CSSValueActiveborder},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str538, CSSValueDarkseagreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str539, CSSValueBeforeEdge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str540, CSSValuePreWrap},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str541, CSSValueHebrew},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str542, CSSValueXLarge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str543, CSSValueReverse},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str544, CSSValueNsResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str545, CSSValuePaddingBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str546, CSSValueLightslategray},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str547, CSSValueAlternateReverse},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str548, CSSValueButtontext},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str549, CSSValueLavender},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str550, CSSValueHorizontalTb},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str551, CSSValueCursive},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str552, CSSValueLazyBlock},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str553, CSSValueMultiply},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str554, CSSValueDarkcyan},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str555, CSSValuePlusLighter},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str556, CSSValueVisiblepainted},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str557, CSSValueLuminosity},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str558, CSSValueBackground},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str559, CSSValueWebkitControl},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str560, CSSValueButtonhighlight},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str561, CSSValueForwards},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str562, CSSValueGlyphs},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str563, CSSValueLightslategrey},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str564, CSSValueDarkviolet},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str565, CSSValueSaddlebrown},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str566, CSSValueWhite},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str567, CSSValueWebkitAuto},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str568, CSSValueHorizontalBt},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str569, CSSValueSeResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str570, CSSValueNeResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str571, CSSValueBlueviolet},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str572, CSSValueInterWord},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str573, CSSValueMediaVolumeSlider},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str574, CSSValueWebkitIsolate},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str575, CSSValueCopy},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str576, CSSValuePaleturquoise},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str577, CSSValueWait},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str578, CSSValueThreedshadow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str579, CSSValueFloralwhite},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str580, CSSValueMediaCurrentTimeDisplay},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str581, CSSValuePlusDarker},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str582, CSSValueMinimized},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str583, CSSValueEvenodd},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str584, CSSValueWider},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str585, CSSValueTableRowGroup},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str586, CSSValueSourceOver},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str587, CSSValueScaleDown},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str588, CSSValueMediaFullscreenVolumeSlider},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str589, CSSValueCaptiontext},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str590, CSSValueMediaControlsBackground},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str591, CSSValueTurquoise},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str592, CSSValueSuper},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str593, CSSValueInternalPresence},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str594, CSSValueSticky},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str595, CSSValueWebkitCenter},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str596, CSSValueGhostwhite},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str597, CSSValueWebkitMatchParent},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str598, CSSValueMidnightblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str599, CSSValueReadWrite},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str600, CSSValueXxSmall},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str601, CSSValueSliderVertical},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str602, CSSValueWebkitRight},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str603, CSSValueLowerHexadecimal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str604, CSSValueNoContextual},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str605, CSSValueLightgrey},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str606, CSSValueLightgray},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str607, CSSValueWebkitMinContent},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str608, CSSValueDimgrey},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str609, CSSValueDimgray},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str610, CSSValueMediaVolumeSliderthumb},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str611, CSSValueWebkitSmallControl},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str612, CSSValueVerticalText},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str613, CSSValueRepeatX},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str614, CSSValueSourceAtop},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str615, CSSValueMediaVolumeSliderContainer},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str616, CSSValueRowReverse},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str617, CSSValueInfobackground},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str618, CSSValueGujarati},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str619, CSSValueButtonBevel},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str620, CSSValueSpringgreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str621, CSSValueHistoricalLigatures},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str622, CSSValueGurmukhi},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str623, CSSValueRepeatY},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str624, CSSValueVerticalRight},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str625, CSSValueGraytext},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str626, CSSValueMediaFullscreenVolumeSliderThumb},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str627, CSSValueTextAfterEdge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str628, CSSValueMediaToggleClosedCaptionsButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str629, CSSValueProgressBarValue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str630, CSSValueUppercase},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str631, CSSValueHighlighttext},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str632, CSSValueWebkitFitContent},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str633, CSSValueRowResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str634, CSSValueDeepskyblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str635, CSSValueExpanded},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str636, CSSValueEthiopicAbegedeGez},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str637, CSSValueLightyellow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str638, CSSValueWebkitLeft},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str639, CSSValueWebkitMiniControl},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str640, CSSValueNavy},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str641, CSSValueUpperLatin},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str642, CSSValueJustify},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str643, CSSValueNwseResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str644, CSSValueOpenQuote},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str645, CSSValueIvory},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str646, CSSValueGreenyellow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str647, CSSValueVisiblestroke},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str648, CSSValueDarkkhaki},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str649, CSSValueExtraExpanded},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str650, CSSValueDevanagari},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str651, CSSValueSliderthumbHorizontal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str652, CSSValueDarkgrey},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str653, CSSValueDarkgray},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str654, CSSValueUpperRoman},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str655, CSSValueWebkitBaselineMiddle},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str656, CSSValueMediaControlsFullscreenBackground},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str657, CSSValueMaximized},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str658, CSSValueEthiopicHalehameGez},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str659, CSSValueBidiOverride},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str660, CSSValueTextBeforeEdge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str661, CSSValueCapitalize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str662, CSSValueYellow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str663, CSSValueUpperAlpha},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str664, CSSValueAfterWhiteSpace},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str665, CSSValueNoCloseQuote},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str666, CSSValueMediaPlayButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str667, CSSValueUpperArmenian},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str668, CSSValueTigrinyaErAbegede},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str669, CSSValueWebkitGrab},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str670, CSSValueWebkitLink},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str671, CSSValueSwResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str672, CSSValueNwResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str673, CSSValueEwResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str674, CSSValueCjkEarthlyBranch},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str675, CSSValueSubpixelAntialiased},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str676, CSSValueTigrinyaEtAbegede},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str677, CSSValueSliderthumbVertical},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str678, CSSValueRosybrown},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str679, CSSValueThreedlightshadow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str680, CSSValueInactivecaption},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str681, CSSValueOverlay},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str682, CSSValueDarkolivegreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str683, CSSValueHoneydew},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str684, CSSValueCapsLockIndicator},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str685, CSSValueBoundingBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str686, CSSValueOptimizespeed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str687, CSSValueRatingLevelIndicator},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str688, CSSValueWhitesmoke},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str689, CSSValueMediaTimeRemainingDisplay},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str690, CSSValueXxLarge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str691, CSSValueWrapReverse},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str692, CSSValueBreakWord},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str693, CSSValueCornflowerblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str694, CSSValueWebkitText},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str695, CSSValueWebkitPlaintext},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str696, CSSValueBackwards},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str697, CSSValueWebkitPictograph},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str698, CSSValueSandybrown},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str699, CSSValueWebkitBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str700, CSSValueButtonshadow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str701, CSSValueWebkitPagedX},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str702, CSSValueWebkitNowrap},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str703, CSSValueAntiquewhite},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str704, CSSValueWebkitBody},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str705, CSSValueWebkitInlineBox},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str706, CSSValueSliderHorizontal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str707, CSSValueMediumturquoise},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str708, CSSValueSideways},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str709, CSSValueDarkturquoise},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str710, CSSValueDarkslategrey},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str711, CSSValueDarkslategray},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str712, CSSValueLavenderblush},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str713, CSSValueMediaExitFullscreenButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str714, CSSValueWebkitPagedY},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str715, CSSValueWebkitInlineFlex},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str716, CSSValueSpaceBetween},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str717, CSSValueWebkitFlex},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str718, CSSValueWave},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str719, CSSValueNoDiscretionaryLigatures},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str720, CSSValueInternalActiveListBoxSelection},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str721, CSSValueContinuousCapacityLevelIndicator},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str722, CSSValueUpperGreek},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str723, CSSValueThreeddarkshadow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str724, CSSValueWebkitMaxContent},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str725, CSSValueDiscretionaryLigatures},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str726, CSSValueCjkHeavenlyStem},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str727, CSSValueWebkitGrabbing},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str728, CSSValueWebkitFocusRingColor},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str729, CSSValueWResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str730, CSSValueYellowgreen},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str731, CSSValueNeswResize},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str732, CSSValueLightskyblue},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str733, CSSValueWebkitIsolateOverride},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str734, CSSValueDiscreteCapacityLevelIndicator},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str735, CSSValueInternalExtendToZoom},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str736, CSSValueWebkitInputSpeechButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str737, CSSValueDecimalLeadingZero},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str738, CSSValueInactivecaptiontext},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str739, CSSValueInternalInactiveListBoxSelection},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str740, CSSValueWebkitOptimizeContrast},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str741, CSSValueWebkitFillAvailable},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str742, CSSValueUpperHexadecimal},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str743, CSSValueWebkitZoomIn},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str744, CSSValueOptimizelegibility},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str745, CSSValueBurlywood},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str746, CSSValueWindow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str747, CSSValueWebkitZoomOut},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str748, CSSValuePapayawhip},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str749, CSSValueSkipWhiteSpace},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str750, CSSValueLowerNorwegian},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str751, CSSValueNavajowhite},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str752, CSSValueWindowed},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str753, CSSValueMediaOverlayPlayButton},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str754, CSSValueWavy},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str755, CSSValueInternalActiveListBoxSelectionText},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str756, CSSValueWindowframe},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str757, CSSValueSidewaysRight},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str758, CSSValueRelevancyLevelIndicator},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str759, CSSValueWebkitActivelink},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str760, CSSValueLightgoldenrodyellow},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str761, CSSValueInternalInactiveListBoxSelectionText},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str762, CSSValueReadWritePlaintextOnly},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str763, CSSValueWindowtext},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str764, CSSValueAppworkspace},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str765, CSSValueWebkitXxxLarge},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str766, CSSValueOptimizequality},
      {(int)(long)&((struct stringpool_t *)0)->stringpool_str767, CSSValueUpperNorwegian}
    };

  static const short lookup[] =
    {
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,  -1,
       -1,  -1,  -1,   1,   2,   3,  -1,   4,   5,   6,
        7,   8,   9,  10,  11,  12,  13,  14,  15,  -1,
       -1,  16,  -1,  17,  -1,  18,  -1,  -1,  19,  -1,
       -1,  20,  21,  -1,  -1,  -1,  22,  -1,  -1,  -1,
       -1,  23,  -1,  -1,  24,  -1,  25,  -1,  -1,  -1,
       -1,  -1,  26,  27,  -1,  28,  29,  -1,  -1,  30,
       -1,  31,  32,  -1,  33,  34,  35,  36,  -1,  37,
       38,  39,  -1,  -1,  40,  -1,  -1,  41,  -1,  -1,
       42,  -1,  43,  -1,  44,  45,  46,  -1,  47,  -1,
       48,  -1,  -1,  49,  -1,  -1,  50,  -1,  51,  -1,
       52,  53,  54,  -1,  -1,  -1,  -1,  -1,  55,  -1,
       -1,  -1,  -1,  -1,  -1,  56,  57,  -1,  -1,  -1,
       -1,  58,  -1,  -1,  59,  -1,  -1,  -1,  -1,  -1,
       60,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       61,  62,  -1,  63,  -1,  -1,  -1,  -1,  64,  65,
       -1,  -1,  -1,  -1,  -1,  66,  67,  -1,  -1,  68,
       -1,  -1,  69,  -1,  70,  -1,  71,  -1,  72,  -1,
       73,  74,  -1,  -1,  75,  -1,  -1,  76,  77,  -1,
       -1,  -1,  -1,  -1,  78,  -1,  79,  80,  -1,  -1,
       -1,  -1,  -1,  -1,  81,  -1,  -1,  -1,  82,  -1,
       83,  -1,  -1,  84,  -1,  -1,  85,  -1,  86,  87,
       88,  -1,  89,  90,  91,  -1,  -1,  -1,  92,  93,
       94,  -1,  95,  -1,  -1,  -1,  -1,  96,  -1,  97,
       98,  -1,  99,  -1,  -1,  -1, 100, 101,  -1, 102,
      103, 104,  -1, 105, 106,  -1, 107,  -1, 108, 109,
       -1, 110,  -1, 111, 112,  -1,  -1, 113,  -1, 114,
      115, 116,  -1,  -1, 117,  -1,  -1, 118,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 119, 120,  -1,
      121, 122,  -1, 123,  -1, 124, 125,  -1,  -1,  -1,
      126, 127, 128, 129,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 130,  -1, 131,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 132, 133, 134,  -1,
      135,  -1,  -1,  -1,  -1,  -1,  -1, 136,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 137,  -1,  -1,
       -1,  -1, 138, 139,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 140,  -1,
       -1, 141, 142,  -1,  -1,  -1,  -1,  -1, 143, 144,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 145, 146,  -1, 147, 148,  -1,  -1,  -1,
       -1,  -1, 149, 150,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 151,  -1,  -1, 152, 153,  -1,  -1,  -1,
      154, 155,  -1,  -1,  -1, 156,  -1, 157,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 158,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 159,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 160,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 161,  -1,  -1, 162,  -1,  -1,  -1, 163,  -1,
       -1,  -1,  -1,  -1,  -1, 164,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 165, 166,
       -1,  -1,  -1,  -1,  -1, 167,  -1,  -1,  -1,  -1,
       -1, 168,  -1,  -1, 169, 170,  -1,  -1,  -1,  -1,
       -1,  -1, 171, 172, 173,  -1,  -1,  -1, 174,  -1,
       -1, 175,  -1,  -1, 176, 177,  -1,  -1,  -1,  -1,
      178,  -1, 179, 180,  -1, 181,  -1,  -1,  -1,  -1,
      182,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 183,  -1,  -1, 184,  -1, 185,  -1,  -1,  -1,
      186,  -1,  -1,  -1, 187,  -1,  -1, 188, 189,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 190, 191,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 192,  -1,  -1, 193,  -1,  -1,  -1,  -1, 194,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 195,  -1,  -1,  -1,  -1,  -1, 196,  -1,  -1,
       -1, 197,  -1,  -1, 198, 199,  -1,  -1,  -1, 200,
       -1, 201, 202,  -1,  -1,  -1, 203,  -1, 204, 205,
       -1, 206,  -1,  -1,  -1, 207,  -1,  -1, 208,  -1,
       -1, 209,  -1, 210,  -1,  -1,  -1, 211,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 212,  -1,  -1, 213,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 214,  -1, 215,
       -1, 216,  -1,  -1,  -1,  -1, 217,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 218, 219,  -1,  -1,  -1, 220,
       -1,  -1, 221,  -1,  -1,  -1,  -1,  -1,  -1, 222,
      223,  -1,  -1,  -1, 224,  -1,  -1, 225,  -1,  -1,
       -1,  -1,  -1, 226,  -1, 227,  -1,  -1,  -1,  -1,
       -1, 228,  -1,  -1,  -1,  -1,  -1, 229,  -1,  -1,
      230,  -1, 231,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      232,  -1,  -1, 233, 234,  -1,  -1,  -1,  -1,  -1,
       -1, 235,  -1,  -1,  -1,  -1, 236,  -1,  -1,  -1,
       -1,  -1, 237, 238, 239,  -1, 240,  -1, 241,  -1,
       -1,  -1,  -1,  -1,  -1, 242,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 243,  -1, 244,  -1,  -1, 245,
       -1, 246,  -1,  -1,  -1,  -1, 247, 248,  -1, 249,
      250,  -1,  -1, 251, 252,  -1,  -1, 253, 254,  -1,
       -1, 255,  -1,  -1,  -1,  -1,  -1,  -1, 256,  -1,
       -1,  -1, 257,  -1,  -1,  -1,  -1,  -1,  -1, 258,
      259,  -1,  -1,  -1, 260,  -1,  -1,  -1,  -1, 261,
       -1, 262,  -1,  -1,  -1,  -1,  -1, 263, 264,  -1,
       -1,  -1,  -1, 265,  -1,  -1, 266,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 267,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 268,  -1,  -1,  -1, 269,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      270,  -1, 271,  -1, 272, 273,  -1,  -1, 274, 275,
      276,  -1,  -1,  -1,  -1,  -1, 277, 278,  -1,  -1,
       -1, 279,  -1,  -1,  -1,  -1,  -1,  -1, 280,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 281,  -1, 282,  -1,  -1, 283,  -1,  -1,
      284,  -1,  -1, 285,  -1, 286,  -1,  -1,  -1,  -1,
       -1,  -1, 287,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 288,  -1,  -1,  -1,
      289,  -1,  -1,  -1,  -1,  -1, 290, 291,  -1,  -1,
      292, 293, 294,  -1,  -1,  -1, 295,  -1, 296, 297,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 298,
       -1,  -1, 299,  -1,  -1,  -1, 300,  -1,  -1,  -1,
      301,  -1,  -1, 302,  -1,  -1, 303,  -1,  -1,  -1,
       -1, 304, 305, 306, 307,  -1,  -1,  -1,  -1,  -1,
      308, 309, 310, 311,  -1,  -1, 312, 313,  -1,  -1,
       -1, 314,  -1, 315,  -1,  -1, 316,  -1,  -1, 317,
       -1, 318,  -1,  -1,  -1, 319,  -1,  -1, 320,  -1,
      321,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 322,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 323,  -1,  -1,  -1,  -1, 324,  -1,
      325,  -1, 326,  -1, 327,  -1,  -1,  -1,  -1,  -1,
      328, 329,  -1,  -1,  -1,  -1,  -1, 330,  -1, 331,
      332, 333,  -1,  -1,  -1,  -1, 334,  -1,  -1,  -1,
      335,  -1, 336,  -1,  -1,  -1,  -1, 337, 338,  -1,
       -1,  -1,  -1, 339, 340,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 341,  -1,  -1, 342,  -1, 343,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 344, 345, 346, 347, 348,
      349,  -1,  -1, 350,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 351,  -1,  -1,  -1, 352,
      353, 354, 355,  -1, 356,  -1, 357, 358, 359,  -1,
       -1,  -1,  -1, 360,  -1, 361,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 362,  -1, 363, 364, 365,  -1,  -1,
      366,  -1,  -1,  -1, 367,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 368,  -1, 369, 370,  -1,
      371,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 372, 373,  -1,  -1,  -1, 374,  -1,  -1,
       -1, 375,  -1, 376,  -1,  -1,  -1,  -1, 377, 378,
       -1,  -1,  -1, 379,  -1, 380,  -1, 381, 382, 383,
      384, 385,  -1, 386,  -1,  -1,  -1,  -1,  -1, 387,
       -1,  -1, 388,  -1,  -1, 389, 390, 391,  -1,  -1,
      392, 393,  -1,  -1, 394, 395, 396,  -1,  -1,  -1,
       -1, 397,  -1,  -1,  -1, 398,  -1,  -1, 399,  -1,
       -1, 400,  -1,  -1, 401,  -1,  -1, 402,  -1,  -1,
       -1, 403, 404,  -1, 405, 406,  -1,  -1,  -1,  -1,
      407, 408,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 409,  -1, 410,  -1,  -1,  -1,  -1, 411,  -1,
       -1,  -1,  -1,  -1, 412,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 413,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 414, 415,
       -1,  -1, 416,  -1, 417,  -1,  -1,  -1,  -1, 418,
      419,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 420,  -1,  -1,  -1, 421,
       -1,  -1,  -1, 422,  -1,  -1,  -1,  -1, 423,  -1,
      424,  -1,  -1, 425,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 426,  -1,  -1,  -1,
      427,  -1,  -1,  -1,  -1,  -1, 428,  -1,  -1, 429,
       -1,  -1,  -1, 430, 431,  -1, 432,  -1, 433,  -1,
      434,  -1,  -1, 435, 436,  -1,  -1,  -1,  -1, 437,
       -1,  -1,  -1,  -1, 438,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 439, 440,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 441,  -1, 442,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 443,  -1,  -1, 444,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 445,  -1,  -1,  -1,  -1, 446,  -1,  -1,  -1,
       -1, 447,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 448,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 449,  -1,  -1, 450,  -1, 451,  -1,
       -1, 452, 453,  -1,  -1,  -1,  -1,  -1, 454, 455,
      456, 457, 458, 459,  -1, 460, 461,  -1, 462,  -1,
      463,  -1, 464, 465,  -1,  -1, 466,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 467,  -1,  -1, 468,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 469,  -1,  -1,  -1,  -1,  -1, 470,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 471,
       -1,  -1, 472,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 473, 474, 475,  -1, 476, 477,  -1,  -1,
       -1,  -1,  -1,  -1, 478,  -1,  -1,  -1, 479,  -1,
       -1, 480,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      481,  -1,  -1, 482,  -1, 483,  -1,  -1,  -1, 484,
       -1, 485,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 486,
       -1,  -1,  -1, 487,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 488,  -1,  -1,  -1, 489,  -1,  -1,
       -1,  -1,  -1, 490,  -1,  -1, 491,  -1, 492,  -1,
       -1,  -1,  -1, 493, 494,  -1,  -1,  -1,  -1,  -1,
       -1, 495,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 496, 497,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 498,  -1, 499,  -1, 500,
       -1,  -1,  -1, 501,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 502,  -1,  -1,  -1,  -1,  -1,  -1, 503,  -1,
       -1,  -1,  -1, 504,  -1, 505, 506,  -1,  -1,  -1,
      507,  -1,  -1,  -1, 508,  -1,  -1,  -1, 509, 510,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 511,  -1, 512, 513,  -1, 514, 515,  -1,  -1,
      516,  -1,  -1,  -1,  -1, 517,  -1,  -1,  -1,  -1,
      518,  -1,  -1, 519,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 520, 521, 522,  -1,  -1,  -1,  -1,  -1,
       -1, 523,  -1,  -1,  -1,  -1, 524, 525,  -1,  -1,
       -1,  -1, 526,  -1, 527,  -1,  -1,  -1,  -1,  -1,
       -1, 528,  -1,  -1, 529,  -1,  -1,  -1,  -1,  -1,
      530,  -1,  -1,  -1, 531,  -1,  -1,  -1, 532,  -1,
      533,  -1, 534,  -1,  -1,  -1, 535, 536,  -1,  -1,
       -1, 537,  -1, 538,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 539,  -1,  -1,  -1,  -1, 540,  -1,
      541,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 542,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 543,  -1,
       -1,  -1,  -1, 544,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 545, 546,
       -1,  -1,  -1,  -1,  -1, 547,  -1,  -1,  -1, 548,
       -1,  -1,  -1,  -1,  -1,  -1, 549,  -1,  -1, 550,
      551, 552,  -1,  -1,  -1,  -1,  -1,  -1, 553,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 554,  -1, 555,  -1, 556, 557,  -1,
       -1,  -1,  -1, 558,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 559,  -1, 560,  -1, 561,  -1,  -1,
       -1,  -1,  -1, 562, 563,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 564, 565,  -1,  -1,  -1,
       -1, 566,  -1,  -1, 567,  -1,  -1,  -1,  -1,  -1,
      568, 569, 570,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 571,  -1,  -1, 572,  -1,  -1,
       -1,  -1,  -1, 573,  -1,  -1,  -1,  -1,  -1,  -1,
      574,  -1,  -1,  -1, 575,  -1, 576,  -1,  -1,  -1,
      577,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 578,
       -1,  -1,  -1, 579,  -1, 580,  -1, 581,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 582,
       -1,  -1,  -1, 583,  -1,  -1,  -1,  -1,  -1,  -1,
      584,  -1,  -1,  -1, 585, 586,  -1,  -1, 587,  -1,
       -1,  -1,  -1,  -1, 588, 589,  -1, 590,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 591,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 592,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 593,  -1, 594,
       -1, 595,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 596, 597,  -1, 598,  -1,  -1,  -1, 599, 600,
       -1, 601,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      602,  -1,  -1,  -1,  -1,  -1,  -1, 603,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 604,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 605,  -1, 606, 607,  -1,  -1,  -1,  -1,
       -1, 608,  -1, 609, 610,  -1,  -1,  -1, 611,  -1,
       -1,  -1,  -1, 612, 613,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 614,  -1,  -1,  -1, 615,
       -1,  -1,  -1,  -1,  -1, 616,  -1,  -1,  -1,  -1,
      617,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 618,  -1,  -1, 619,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 620,  -1, 621,  -1, 622,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 623,  -1,  -1,
       -1,  -1,  -1,  -1, 624, 625,  -1,  -1,  -1,  -1,
       -1,  -1, 626,  -1, 627,  -1,  -1,  -1,  -1,  -1,
       -1, 628,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 629,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 630,
       -1,  -1,  -1,  -1,  -1, 631,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 632,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 633,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 634,  -1,  -1,  -1,
      635,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 636,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 637,  -1, 638, 639,  -1, 640,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 641,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 642,
       -1,  -1,  -1,  -1,  -1, 643,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 644,  -1,  -1, 645,  -1,  -1,
      646,  -1,  -1,  -1,  -1, 647,  -1,  -1,  -1,  -1,
      648,  -1,  -1,  -1,  -1, 649, 650,  -1,  -1,  -1,
       -1,  -1, 651,  -1,  -1,  -1, 652,  -1, 653,  -1,
      654, 655,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 656,  -1, 657,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      658,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 659,  -1,  -1,  -1, 660,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 661,  -1,  -1, 662,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 663,  -1,
       -1,  -1,  -1, 664,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 665,  -1,  -1, 666,  -1,  -1, 667,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 668,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 669,  -1,  -1, 670,  -1,
       -1,  -1,  -1,  -1, 671, 672, 673,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 674,  -1,  -1,  -1, 675,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 676, 677,
       -1,  -1,  -1,  -1,  -1, 678,  -1, 679, 680,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 681,  -1,  -1,
       -1,  -1,  -1, 682,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 683, 684, 685,  -1,  -1,  -1,  -1, 686,  -1,
      687,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 688,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 689,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 690,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 691,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 692,  -1,
       -1, 693,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 694,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      695,  -1,  -1,  -1,  -1, 696,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 697, 698,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 699, 700,  -1,  -1,
       -1,  -1, 701,  -1, 702, 703,  -1, 704,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 705,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 706,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 707,  -1, 708,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 709,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 710,  -1, 711,  -1,  -1,  -1,  -1,
       -1,  -1, 712,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 713,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 714,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 715,  -1, 716,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 717,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 718,  -1,  -1,  -1,  -1,  -1,  -1, 719,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 720,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 721,  -1,  -1, 722,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      723,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      724,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 725,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 726,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 727,  -1,  -1,  -1,  -1,  -1, 728,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 729,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 730,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      731,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 732,  -1,
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
       -1,  -1,  -1,  -1,  -1,  -1, 733,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 734,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 735,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 736,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 737,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 738,  -1,
       -1,  -1,  -1,  -1, 739,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 740,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      741,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 742,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 743,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 744, 745,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 746,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 747,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      748,  -1,  -1,  -1,  -1,  -1, 749,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 750,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      751,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 752,  -1,  -1, 753,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 754,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 755,  -1,  -1,  -1,  -1,  -1,
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
       -1,  -1, 756,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 757,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 758,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      759,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 760,  -1,
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
       -1, 761,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 762,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 763,  -1,  -1,  -1,  -1,  -1,  -1,
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
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 764,  -1,  -1,  -1,  -1,
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
       -1,  -1,  -1,  -1,  -1,  -1, 765,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 766,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 767
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = value_hash_function (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = value_word_list[index].nameOffset + stringpool;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                return &value_word_list[index];
            }
        }
    }
  return 0;
}

const Value* findValue(register const char* str, register unsigned int len)
{
    return CSSValueKeywordsHash::findValueImpl(str, len);
}

const char* getValueName(unsigned short id)
{
    if (id >= numCSSValueKeywords || id <= 0)
        return 0;
    return valueListStringPool + valueListStringOffsets[id];
}

bool isValueAllowedInMode(unsigned short id, CSSParserMode mode)
{
    // FIXME: Investigate whether we can deprecate the former
    // two as only QuirksOrUASheet is used in CSSValueKeyword.in
    switch (id) {
        case CSSValueInternalActiveListBoxSelection:
        case CSSValueInternalActiveListBoxSelectionText:
        case CSSValueInternalInactiveListBoxSelection:
        case CSSValueInternalInactiveListBoxSelectionText:
        case CSSValueInternalPresence:
        case CSSValueInternalExtendToZoom:
            return isUASheetBehavior(mode);
        
            return isQuirksModeBehavior(mode);
        case CSSValueWebkitFocusRingColor:
    case CSSValueWebkitText:
            return isUASheetBehavior(mode) || isQuirksModeBehavior(mode);
        default:
            return true;
    }
}

} // namespace WebCore

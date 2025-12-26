/**
 * ColorFormat.h
 * Definitions for RGB and HSL color format conversions.
 */

// Macros for minimum and maximum
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

/**
 * RGB color structure
 * r, g, b components are in the range [0, 255]
 */
typedef struct rgb {
  float r, g, b;
} RGB;

/**
 * HSL color structure
 * h, s, l components are in the range [0, 1]
 */
typedef struct hsl {
  float h, s, l;
} HSL;

/*
 * Converts an RGB color value to HSL. Conversion formula
 * adapted from http://en.wikipedia.org/wiki/HSL_color_space.
 * 
 * @param r Red component (0-255)
 * @param g Green component (0-255)
 * @param b Blue component (0-255)
 * @return HSL struct with h, s, l components (0-1)
 */
HSL rgb2hsl(float r, float g, float b);

/*
 * Converts an HUE to r, g or b.
 * 
 * @param p Temporary value
 * @param q Temporary value
 * @param t Temporary value
 * @return Corresponding RGB component (0-1)
 */
float hue2rgb(float p, float q, float t);

/*
 * Converts an HSL color value to RGB. Conversion formula
 * adapted from http://en.wikipedia.org/wiki/HSL_color_space.
 * 
 * @param h Hue component (0-1)
 * @param s Saturation component (0-1)
 * @param l Lightness component (0-1)
 * @return RGB struct with r, g, b components (0-255)
 */
RGB hsl2rgb(float h, float s, float l);
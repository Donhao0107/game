#include "Image.h"

Image::Image(LPCTSTR imagePath) {
	loadimage(&image, imagePath);
}

Image::operator IMAGE() {
	return image;
}

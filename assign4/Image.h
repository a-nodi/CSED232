#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <cstdint>
#include <cassert>
#include "SharedPtr.h"

///////////////////////////////////////////////////////////////////////////
// RGB pixel type
//    Usage:
//      - RGB<float> rgb(0.5f, 0.1f, 0.3f);
//        rgb[0] = 0.2f; // or equivalently, rgb.r = 0.2f;
template<typename ValType>
struct RGB
{
	union {
		ValType data[3];
		struct {
			ValType r, g, b;
		};
	};

	RGB() {}
	RGB(ValType r_, ValType g_, ValType b_) : r(r_), g(g_), b(b_) {}

	ValType operator[](int idx) const { return data[idx]; }
	ValType& operator[](int idx) { return data[idx]; }
};

typedef RGB<uint8_t>	RGB8b;
typedef RGB<float>		RGBf;


///////////////////////////////////////////////////////////////////////////
// Image class template
//
template<typename PixelType>
class Image
{
private:
	size_t m_width, m_height;
	SharedArray<PixelType> m_buff;
	
public:
	////////////////////////////////////////////
	// constructors & destructor
	////////////////////////////////////////////
	
	Image() : m_width(0), m_height(0) {} // Default constructor

	Image(size_t _width, size_t _height) : m_width(_width), m_height(_height) {
		/*
		* Constuctor that gets images width and height
		* 
		* :param size_t _width: width of image
		* :param size_t _height: height of image
		* 
		* :return void:
		*/

		m_buff = SharedArray<PixelType>(new PixelType[m_width * m_height]); // Allocate image space
	}

	Image(size_t _width, size_t _height, const PixelType& val) : m_width(_width), m_height(_height) {
		/*
		* Constuctor that gets images width and height and initializing value
		*
		* :param size_t _width: width of image
		* :param size_t _height: height of image
		* :param const PixelType& val: initializing value
		* 
		* :return void:
		*/

		m_buff = SharedArray<PixelType>(new PixelType[m_width * m_height]); // Allocate image space and initialize with val
		
		// Initialize copy pixels
		for (int i = 0; i < m_height; i++) {
			for (int j = 0; j < m_width; j++) {
				m_buff[i * m_width + j] = val;
			}
		}
	}

	explicit Image(const Image<PixelType>& img) {
		/*
		* Copy Constuctor
		* 
		* :param const Image<PixelType>& img: Image that will be copied
		* 
		* :return void:
		*/

		// Copy width and height
		m_width = img.m_width;
		m_height = img.m_height;

		m_buff = SharedArray<PixelType>(new PixelType[m_width * m_height]); // Allocate new image space
		
		// Deep copy pixels
		for (int i = 0; i < m_height; i++) {
			for (int j = 0; j < m_width; j++) {
				m_buff[i * m_width + j] = img[j][i]; // Pixel-wise copy
			}
		}
	}

	~Image() { } // Default Destructor
	////////////////////////////////////////////
	// assignment operator
	////////////////////////////////////////////
	
	Image<PixelType>& operator=(const Image<PixelType>& img) {
		/*
		* Assignment operator
		* 
		* :param const Image<PixelType>& img: that will be copied
		* 
		* :return Image<PixelType>& *this: Image itself
		*/

		if (this == &img) return *this; // Assigned itself

		// Copy width and height
		m_width = img.m_width;
		m_height = img.m_height;

		m_buff = SharedArray<PixelType>(new PixelType[m_width * m_height]); // Allocate new image space
		
		// Deep copy pixels
		for (int i = 0; i < m_height; i++) {
			for (int j = 0; j < m_width; j++) {
				m_buff[i * m_width + j] = img[i][j]; // Pixel-wise copy
			}
		}
		
		return *this;
	}

	////////////////////////////////////////////
	// element access operators
	////////////////////////////////////////////
	PixelType* operator[](int y) { return &m_buff[y * m_width]; }
	const PixelType* operator[](int y) const { return &m_buff[y * m_width]; }

	////////////////////////////////////////////
	// other methods
	////////////////////////////////////////////

	// Accessor of width and height
	size_t width() const { return m_width; }
	size_t height() const { return m_height; }
	
};

// ======= ADD CODE HERE IF NEEDED =========


// Miscellaneous functions
void convert_pixel_type(const Image<RGB8b>& src, Image<RGBf>& dst);
void convert_pixel_type(const Image<RGBf>& src, Image<RGB8b>& dst);

bool load_bmp(const char* path, Image<RGB8b>& img);
bool save_bmp(const char* path, const Image<RGB8b>& img);

#endif

// Raytracer.cpp : Defines the entry point for the application.
//

//C:\Users\harsukh\source\repos\raytracer\Raytracer\out\build\x64-debug\Raytracer>

#include "Raytracer.h"

using namespace std;

int PPMimage()
{
	//Image 

	int img_width = 256;
	int img_height = 256;

	//Render

	cout << "P3\n" << img_width << " " << img_height << "\n255\n";

	for (int j = 0; j < img_height; ++j) {
		for (int i = 0; i < img_width; ++i) {
			auto r = double(i) / (img_width - 1);
			auto g = double(j) / (img_height - 1);
			auto b = 0;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			cout << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
	return 0;
}

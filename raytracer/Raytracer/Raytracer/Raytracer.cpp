//==============================================================================================
// Originally written in 2016 by Peter Shirley <ptrshrl@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication
// along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==============================================================================================

#include "utility.h"

#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"



int main() {
    hittable_list world;
    auto yellow = make_shared<metal>(color(1, 0.9, 0.3), 1.0);
    auto white = make_shared<metal>(color(1, 1,1), 1.0);
    auto glass = make_shared<dielectric>(1.5);
    auto blue = make_shared<metal>(color(0.161, 0.667, 1), 1.0);
    auto ground_material = make_shared<lambertian>(color(0.0,0,0));
    //world.add(make_shared<sphere>(point3(0, -1500, 0), 1000, ground_material));
    world.add(make_shared<sphere>(point3(0, -1000, 0), 1000, make_shared<metal>(color(0.85, 0.9, 1), 0.0)));
    /*world.add(make_shared<sphere>(point3(4, 2, -8), 2, make_shared<dielectric>(1.5)));
    world.add(make_shared<sphere>(point3(4, 2, -8), 1.8,yellow));*/
    world.add(make_shared<sphere>(point3(0, 3, 0), 3, blue));

    //world.add(make_shared<sphere>(point3(0, 1, -10),1, yellow ));
    //world.add(make_shared<sphere>(point3(0, 1, -10),1, glass));
    //world.add(make_shared<sphere>(point3(7, 2, -2),2, blue));
    //world.add(make_shared<sphere>(point3(-6, 2, -1),2, blue));

    /*/world.add(make_shared<sphere>(point3(-8, 1, -10), 1, blue));
    world.add(make_shared<sphere>(point3(-7, 1, 2), 1, blue));
    world.add(make_shared<sphere>(point3(7, 1,-5), 1, blue));*/
    //world.add(make_shared<sphere>(point3(-2, 1,-10), 1, blue));


    
    /*for (int a = -4; a < 4; a++) {
        for (int b = -4; b < 4; b++) {
            
            point3 center(a*4, 2, b*4);
            world.add(make_shared<sphere>(center, 2.0, glass));
            world.add(make_shared<sphere>(center, 1.8, blue));

        }
    }*/

    /*auto material1 = make_shared<dielectric>(1.5);
    auto material2 = make_shared<metal>(color(0.6 + random_double() * 0.5, 0.506, 1), 1.0);
    world.add(make_shared<sphere>(point3(0, 53, 1), 1.3, make_shared<metal>(color(0.3 + random_double(), 0.3, 1), 1.0)));
    world.add(make_shared<sphere>(point3(1.3, 54.5, 0), 0.8, make_shared<metal>(color(0.3 + random_double(), 0.3, 1), 0.8)));
    world.add(make_shared<sphere>(point3(-0.8, 56, 0.4), 1.0, make_shared<metal>(color(0.3 + random_double() , 0.3, 1), 0.8)));
    for (int a = -3; a < 3; a++) {
        for (int b = -2; b < 2; b++) {
            auto mat = make_shared<metal>(color(0.3+random_double(), 0.4, 1), 1.0);
            point3 center(random_double()*2+a, 54 + random_double()*2+b, random_double()*5-3);
            world.add(make_shared<sphere>(center, random_double()*0.3, mat));
        }
    }*/
    
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());
            color col(random_double(), 0.82, 1);
            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(col);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
                else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(col, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
                else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    
    camera cam;

    cam.aspect_ratio = 4.0 /5.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 10;
    cam.max_depth = 20;

    cam.vfov = 60;
    cam.lookfrom = point3(13,3,-23);
    cam.lookat = point3(0, 0, 0);
    cam.vup = vec3(0, 1, 0);

    cam.defocus_angle = 0.6;
    cam.focus_dist = 10;
    
    cam.render(world);
}
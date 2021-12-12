#include "lodepng.h"
#include "fastimage.h"
#include <bits/stdc++.h>
#include <omp.h>

using namespace std;


/*********************************
Image encode and decode
*********************************/

void encode(const char* filename, Image img) {
  unsigned error = lodepng::encode(filename, img.image, img.width, img.height);
  // unsigned error = lodepng::encode(filename, image, width, height);
  if(error) cout<<"encoder error "<<error<< ": "<<lodepng_error_text(error)<<endl;
}

Image decode(const char* filename) {
  Image img;
  unsigned error = lodepng::decode(img.image, img.width, img.height, filename);
  if(error) cout<<"decoder error "<<error << ": "<<lodepng_error_text(error)<<endl;
  return img;
}




/*********************************
Image brightening
*********************************/

Image serialBrighten(Image in_img) {

  Image out_img(in_img.getSize(), in_img.height, in_img.width);
  for(int i=0; i< in_img.getSize(); i++) {
    out_img.image[i] = min(1.5*in_img.image[i], 255.0);
  }
  return out_img;
  
} 

Image brighten(Image in_img) {

  Image out_img(in_img.getSize(), in_img.height, in_img.width);
  #pragma omp parallel for
  for(int i=0; i< in_img.getSize(); i++) {
    out_img.image[i] = min(1.5*in_img.image[i], 255.0);
  }
  return out_img;
  
}






#include <bits/stdc++.h>
#include "../fastimage.h"

using namespace std;

int main(int argc, char *argv[]) {

  const char* filename = argc > 1 ? argv[1] : "../input.png";

  Image img = decode(filename);
  img = brighten(img);
  encode("../output.png", img);

  return 0;

}
class Image {
    public:
        std::vector<unsigned char> image;
        unsigned height;
        unsigned width;

        Image() {}

        Image(int s, unsigned h, unsigned w) {
            image.resize(s);
            height = h;
            width = w;
        }

        int getSize() {
            return image.size();
        }
};

void encode(const char* filename, Image img);
Image decode(const char* filename);

Image brighten(Image in_img);
Image serialBrighten(Image in_img);


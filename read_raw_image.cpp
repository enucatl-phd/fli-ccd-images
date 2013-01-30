#include "read_raw_image.h"

void read_raw_image(std::string file_name, int header_bytes, TH2& image) {
    //open binary file
    std::ifstream file(file_name.c_str(), std::ios::binary);
    //get size of image
    int columns = image.GetNbinsX();
    int rows = image.GetNbinsY();
    //skip header bytes
    file.seekg(header_bytes);
    Reader<uint16_t> reader;
    uint16_t value = 0;
    int i = 1;
    int j = 0;
    //load the values into the histogram
    while(reader(file, value)) {
        if (j < rows)
            j++;
        else {
            j = 1;
            if (i < columns) i++;
            else i = 1;
        }
        image.SetBinContent(i, j, value);
    }
    file.close();
}

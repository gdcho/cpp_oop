#include <iostream>
#include "video_manipulation_package.hpp"

using namespace std;

/*
 *  The Facade. The VideoConverter defines a simple interface to the
    complicated video_manipulation_package. The VideoConverter deals
    with the interface provided by this complex package so that the
    rest of the system won't have to.
 */
struct VideoConverter {

    /*
     *  A simple interface that hides the complicated /complex procedure
        to convert a video file.
        :param filename: a string, path to the file
        :param dest_format: a string, MP4 or OGG
        :return: a VideoFile in the specified format.
     */
    static VideoFile convert(string filename,string dest_format="MP4") {
        VideoFile video_file = VideoFile(filename);
        Codec source_codec = CodecFactory().extract(&video_file);
        Codec dest_codec;

        if (dest_format == "MP4")
            dest_codec = MPEG4CompressionCodec();
        else
            dest_codec = OggCompressionCodec();

        BitrateReader::read(filename, &source_codec);
        BitrateReader::convert(filename, &dest_codec);
        AudioMixer().fix(filename);
    }
};

int main() {
    //client only calls a single convert function. Complexity is hidden within the VideoConverter facade
    VideoConverter::convert("dog_bloopers.mp4", ".ogg");
    return 0;
}
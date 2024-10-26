//
// Created by A00257049 on 2020-11-03.
//

#ifndef VIDEO_PACKAGE_FACADE_EXAMPLE_VIDEO_MANIPULATION_PACKAGE_HPP
#define VIDEO_PACKAGE_FACADE_EXAMPLE_VIDEO_MANIPULATION_PACKAGE_HPP

#include <iostream>
using namespace std;

struct VideoFile {
    VideoFile(string filename) {
        cout << "Video file object create from " << filename << endl;
    }
};

struct Codec {

};

struct OggCompressionCodec : public Codec {
    OggCompressionCodec() {
        cout << "OGG Codec created" << endl;
    }
};

struct MPEG4CompressionCodec : public Codec {
    MPEG4CompressionCodec() {
        cout << "MPEG4 Codec created" << endl;
    }
};

struct CodecFactory {
    MPEG4CompressionCodec extract(VideoFile* f) {
        cout << "Creating codec from video file: " << typeid(*f).name() << endl;
        return MPEG4CompressionCodec{};
    }
};

struct BitrateReader {
    static void read(string filename, Codec* source_codec) {
        cout << "Reading " << filename << " via a " << typeid(*source_codec).name() << " into a buffer" << endl;
    }

    static void convert(string filename, Codec* destination_codec) {
        cout << "writing file from " << filename << " and converting it via"
        << typeid(*destination_codec).name() << endl;
    }
};

struct AudioMixer {
    void fix(string filename) {
        cout << "Fixing audio levels in converted video" << endl;
    }
};

#endif //VIDEO_PACKAGE_FACADE_EXAMPLE_VIDEO_MANIPULATION_PACKAGE_HPP

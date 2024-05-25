#include "basecamerabuilder.h"

BaseCameraBuilder::BaseCameraBuilder(std::shared_ptr<FileCarcassModelReader> &reader)
    : _reader(reader) {}

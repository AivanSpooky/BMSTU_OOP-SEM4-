#include "basescenebuilder.h"

BaseSceneBuilder::BaseSceneBuilder(std::shared_ptr<FileCarcassModelReader> &reader)
    : _reader(reader) {}
